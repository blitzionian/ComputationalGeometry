//
// Created by mroeder on 18.05.18.
//
#include <algorithm>
#include <line_sweep.hpp>

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

    // move out into in
    return out;
}


inline bool same_end_points(Line * left, Line * right) {
    return *(left->getEndPoint()) == *(right->getEndPoint());
}

inline void remove_line(std::vector<Line *> & data, Line * to_remove) {
    long index = find(data.begin(),data.end(),to_remove) - data.begin();
    data.erase(data.begin() + index);
}

inline bool overlap(Line * left, Line * right) {
    bool answer = 0.0 == left -> ccw(right -> getStartPoint()) && 0.0 == left -> ccw(right -> getEndPoint());
    if(answer) {
        answer &= left -> contains(*(right->getStartPoint())) || left -> contains(*(right->getEndPoint()));
    }
    return answer;
}

