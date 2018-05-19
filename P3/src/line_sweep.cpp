//
// Created by mroeder on 18.05.18.
//
#include <algorithm>
#include <line_sweep.hpp>
#include <event_queue.hpp>

inline void remove_line(std::vector<Line *> & data, Line * to_remove);
inline bool same_end_points(Line * left, Line * right);
inline bool overlap(Line * left, Line * right);

// TODO: (@Markus) Review & correct
std::vector<Line*> line_sweep::filter_special_cases(std::vector<Line *> &in) {
    // coordinates must not have the same x value (case vertical and case zero length)
    std::vector<Line *> cpy(in);
    std::remove_if(cpy.begin(),cpy.end(),[] (Line * current) {
        return current->getStartPoint()->getX() == current->getEndPoint()->getX();
    });
    std::vector<Line *> out(cpy);
    // pair comparison
    for(unsigned int i = 0; i < cpy.size(); ++i) {
        Line * left = cpy[i];
        for(unsigned int j = 1; j < cpy.size(); ++j) {
            Line * right = cpy[j];
            if(same_end_points(left,right)){ // case intersecting in end point.
                remove_line(out,right);
            } else if (overlap(left,right)) { // case overlapping
                remove_line(out,right);
            }
        }
    }

    return out;
}

// TODO: implement sweep line algorithm
std::vector<Point*> line_sweep::intersections(std::vector<Line*> & segments) {
    Event_Queue x(segments);
    std::vector<Line*> sl;
    std::vector<Point*> l;
    while(!x.empty()) {
        Event_Queue::node e = x.pop();
        switch(e.event) {
            case SEGMENT_START: {
                Line *seg_e = e.line;
                sl.push_back(seg_e);
                break;
            }
            case SEGMENT_END: {
                break;
            }
            case INTERSECTION: {
                break;
            }
        }
    }

    return l;
}

inline bool same_end_points(Line * left, Line * right) {
    return *(left->getEndPoint()) == *(right->getEndPoint());
}

inline void remove_line(std::vector<Line *> & data, Line * to_remove) {
    data.erase(find(data.begin(),data.end(),to_remove));
}

inline bool overlap(Line * left, Line * right) {
    bool answer = 0.0 == left -> ccw(right -> getStartPoint()) && 0.0 == left -> ccw(right -> getEndPoint());
    if(answer) {
        answer &= left -> contains(*(right->getStartPoint())) || left -> contains(*(right->getEndPoint()));
    }
    return answer;
}


