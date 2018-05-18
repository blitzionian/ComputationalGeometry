//
// Created by mroeder on 18.05.18.
//

#ifndef P3_LINE_SWEEP_HPP
#define P3_LINE_SWEEP_HPP

#include <vector>
#include <line.hpp>

namespace line_sweep {

    std::vector<Line*> filter_special_cases(std::vector<Line*> & in);

}

#endif //P3_LINE_SWEEP_HPP
