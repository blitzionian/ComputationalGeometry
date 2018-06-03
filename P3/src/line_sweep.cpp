#include <algorithm>
#include <fstream>
#include <line_sweep.hpp>
#include <sweep_line_data.hpp>

inline void remove_line(std::vector<Line *> & data, Line * to_remove);
inline bool same_end_points(Line * left, Line * right);
inline bool overlap(Line * left, Line * right);
inline void insert_if_intersecting(line_sweep::SweepLineData & data, Line * segA, Line * segB);
inline void treat_start(line_sweep::SweepLineData & x, line_sweep::SweepLineData & y,
		line_sweep::SweepLineData::iterator & current);
inline void treat_end(line_sweep::SweepLineData & x, line_sweep::SweepLineData & y,
		line_sweep::SweepLineData::iterator & current);
inline void treat_intersection(line_sweep::SweepLineData & x, line_sweep::SweepLineData & y,
		std::vector<Point*> & intersections, line_sweep::SweepLineData::iterator & current);

// TODO: (@Markus) Review & correct
std::vector<Line*> line_sweep::filter_special_cases(std::vector<Line *> &in) {
	// coordinates must not have the same x value (case vertical and case zero length)
	std::vector<Line *> cpy(in);
	std::remove_if(cpy.begin(), cpy.end(), [] (Line * current) {
		return current->getStartPoint()->getX() == current->getEndPoint()->getX();
	});
	std::vector<Line *> out(cpy);
	// pair comparison
	for (unsigned int i = 0; i < cpy.size(); ++i) {
		Line * left = cpy[i];
		for (unsigned int j = 1; j < cpy.size(); ++j) {
			Line * right = cpy[j];
			if (same_end_points(left, right)) { // case intersecting in end point.
				remove_line(out, right);
			} else if (overlap(left, right)) { // case overlapping
				remove_line(out, right);
			}
		}
	}

	return out;
}

typedef line_sweep::SweepLineData::node sl_node;
std::vector<Point*> line_sweep::intersections(std::vector<Line*> & segments) {
	SweepLineData x(segments, [](sl_node & left, sl_node & right) {
		return left.point->getX() < right.point->getX();
	});
	SweepLineData y(segments.size(), [](sl_node & top, sl_node & bottom) {
		return top.point->getX() < bottom.point->getX();
	});
	std::vector<Point*> intersections;
	while (!x.empty()) {
		auto current = x.begin();
		switch (current->event) {
		case SEGMENT_START: {
			treat_start(x, y, current);
			break;
		}
		case SEGMENT_END: {
			treat_end(x, y, current);
			break;
		}
		case INTERSECTION: {
			treat_intersection(x, y, intersections, current);
			break;
		}
		}
		x.pop();
	}

	return intersections;
}

std::vector<Line*> line_sweep::from_file(std::string &path) {
	std::vector<Line*> result;
	std::ifstream infile(path.c_str());
	double x1, y1, x2, y2;
	while (infile >> x1 >> y1 >> x2 >> y2) {
		auto first = new Point(x1, y1);
		auto second = new Point(x2, y2);
		result.push_back(Line::segment(first, second));
	}
	return result;
}

inline bool same_end_points(Line * left, Line * right) {
	return *(left->getEndPoint()) == *(right->getEndPoint());
}

inline void remove_line(std::vector<Line *> & data, Line * to_remove) {
	data.erase(find(data.begin(), data.end(), to_remove));
}

inline bool overlap(Line * left, Line * right) {
	bool answer = 0.0 == left->ccw(right->getStartPoint()) && 0.0 == left->ccw(right->getEndPoint());
	if (answer) {
		answer &= left->contains(*(right->getStartPoint())) || left->contains(*(right->getEndPoint()));
	}
	return answer;
}

inline void insert_if_intersecting(line_sweep::SweepLineData & data, Line * segA, Line * segB) {
	Point * i = segA->intersection_point(segB);
	if (i) {
		if (!data.contains(i)) {
			auto in = data.insert(line_sweep::event_type::INTERSECTION, i, nullptr);
			(*in).top = segA;
			(*in).bottom = segB;
		}
	}
}

inline void treat_start(line_sweep::SweepLineData & x, line_sweep::SweepLineData & y,
		line_sweep::SweepLineData::iterator & current) {
	Line * segE = current->line;
	auto ynode = y.insert(line_sweep::event_type::SEGMENT_START, current->point, segE);
	line_sweep::SweepLineData::neighbours n = y.next_neighbours(ynode);
	if (n.first != y.end()) {
		Line * segA = (*n.first).line;
		insert_if_intersecting(x, segA, segE);
	}
	if (n.second != y.end()) {
		Line * segB = (*n.second).line;
		insert_if_intersecting(x, segE, segB);
	}
}

inline void treat_end(line_sweep::SweepLineData & x, line_sweep::SweepLineData & y,
		line_sweep::SweepLineData::iterator & current) {
	Line * segE = current->line;
	line_sweep::SweepLineData::neighbours n = y.next_neighbours(current);
	if (n.first != y.end() && n.second != y.end()) {
		Line * segA = (*n.first).line;
		Line * segB = (*n.second).line;
		insert_if_intersecting(x, segA, segB);
	}
	y.remove(segE);
}

inline void treat_intersection(line_sweep::SweepLineData & x, line_sweep::SweepLineData & y,
		std::vector<Point*> & intersections, line_sweep::SweepLineData::iterator & current) {
	intersections.push_back(current->point);
	auto top = y.find_by_line(current->top);
	auto bottom = y.find_by_line(current->bottom);
	if (top != y.end() && bottom != y.end()) {
		y.swap(top, bottom);
		auto segA = y.next_neighbours(bottom).first;
		if (segA != y.end()) {
			insert_if_intersecting(x, bottom->line, segA->line);
		}
		auto segB = y.next_neighbours(top).second;
		if (segB != y.end()) {
			insert_if_intersecting(x, top->line, segB->line);
		}
	}
}

