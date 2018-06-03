#ifndef P3_LINE_SWEEP_HPP
#define P3_LINE_SWEEP_HPP

#include <vector>
#include <line.hpp>
#include <string>

namespace line_sweep {

	std::vector<Line*> filter_special_cases(std::vector<Line*> & in);
	std::vector<Point*> intersections(std::vector<Line*> & segments);
	std::vector<Line*> from_file(std::string & path);

}

#endif //P3_LINE_SWEEP_HPP
