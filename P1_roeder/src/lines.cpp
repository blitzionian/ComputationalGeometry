//============================================================================
// Name      		: lines.cpp
// Author			: mroeder (mroeder@hm.edu)
// Version			: 0.5.0
// OS				: Ubuntu x64 16.04 LTS
// CPU				: Intel® Core™ i5 CPU M 520 @ 2.40GHz × 4
// Compiler			: gcc version 5.4.0
// Language Level 	: c++ 11
// Description 		: Implementation of the line intersection exercise.
//============================================================================

#include <fstream>
#include <lines.hpp>
#include <algorithm>

inline bool same_direction(double ccw1, double ccw2);
inline bool in_x_bounds(lines::line & line, lines::point & point);
inline bool in_y_bounds(lines::line & line, lines::point & point);
inline bool in_bounds(lines::line & line, lines::point & point);
inline bool on_line_check(lines::line & first, lines::line & second, lines::ccw_profile & ccws);
inline bool any_ccw_zero(lines::ccw_profile & ccws);


line_list lines::from_file(const char * file_name) {
	std::ifstream infile(file_name);
	line_list result;
	double x1, y1, x2, y2;
	while(infile >> x1 >> y1 >> x2 >> y2) {
		point first = {x1, y1};
		point second = {x2, y2};
		line current = {first, second};
		result.push_back(current);
	}
	return result;
}

double lines::ccw(lines::point & p, lines::point & q, lines::point & r) {
	return ((p.x * q.y) - (p.y * q.x))
			+ ((q.x * r.y) - (q.y * r.x))
			+ ((p.y * r.x) - (p.x * r.y));
}

bool lines::intersecting(lines::line & first, lines::line & second) {
	bool retval = false;
	lines::ccw_profile ccws = {
		ccw(first.first,first.second,second.first),
		ccw(first.first,first.second,second.second),
		ccw(second.first,second.second,first.first),
		ccw(second.first,second.second,first.second)
	};
	if(any_ccw_zero(ccws)) {
		// special case: one ccw is zero => one point must be part of the other line, else, no match.
		retval = on_line_check(first,second,ccws);
	} else {
		// result is pairwise compare of ccws only different directions
		retval = !same_direction(ccws.ccw11,ccws.ccw12) && !same_direction(ccws.ccw21,ccws.ccw22);
	}
	return retval;
}

lines::result lines::check_file(line_list & file) {
	result retval;
	unsigned int count = 0;
	unsigned long before = current_time_milliseconds();
	for(line_it outer = file.begin(); outer != file.end(); ++outer) {
		line_it inner(outer);
		++inner;
		while(inner != file.end()) {
			if(intersecting(*outer,*inner)){
				++count;
			}
			++inner;
		}
	}
	unsigned long after = current_time_milliseconds();
	retval.count = count;
	retval.duration = after - before;
	return retval;
}


unsigned long lines::current_time_milliseconds(void) {
	std::chrono::milliseconds ms = std::chrono::duration_cast< std::chrono::milliseconds >(
		std::chrono::system_clock::now().time_since_epoch()
	);
	return ms.count();
}


inline bool same_direction(double ccw1, double ccw2) {
	return (ccw1 > 0 && ccw2 > 0) || (ccw1 < 0 && ccw2 < 0);
}

inline bool in_x_bounds(lines::line & line, lines::point & point) {
	double min_x = std::min(line.first.x,line.second.x);
	double max_x = std::max(line.first.x,line.second.x);
	return point.x >= min_x && point.x <= max_x;
}

inline bool in_y_bounds(lines::line & line, lines::point & point) {
	double min_y = std::min(line.first.y,line.second.y);
	double max_y = std::max(line.first.y,line.second.y);
	return point.y >= min_y && point.y <= max_y;
}

inline bool in_bounds(lines::line & line, lines::point & point) {
	return in_x_bounds(line,point) && in_y_bounds(line,point);
}

inline bool on_line_check(lines::line & first, lines::line & second, lines::ccw_profile & ccws) {
	if(0 == ccws.ccw11 && in_bounds(first,second.first)){
		return true;
	}
	if(0 == ccws.ccw12 && in_bounds(first,second.second)){
		return true;
	}

	if(0 == ccws.ccw21 && in_bounds(second,first.first)) {
		return true;
	}

	if(0 == ccws.ccw22 && in_bounds(second,first.second)) {
		return true;
	}
	return false;
}

inline bool any_ccw_zero(lines::ccw_profile & ccws) {
	return 0.0 == ccws.ccw11 || 0.0 == ccws.ccw12 || 0.0 == ccws.ccw21 || 0.0 == ccws.ccw22;
}
