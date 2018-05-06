/*
 * lines.hpp
 *
 *  Created on: 19.04.2018
 *      Author: mroeder
 */

#ifndef LINES_HPP_
#define LINES_HPP_

#include <list>
#include <chrono>

/*
 * The namespace for this exercise.
 */
namespace lines {
	/** Representation of a point. */
	struct point {
		/** The x coordinate. */
		double x;
		/** The y coordinate. */
		double y;
	};
	/** Representation of a line. */
	struct line {
		/** Starting point. */
		point first;
		/** Ending point. */
		point second;
	};
	/** The calculated ccws. */
	struct ccw_profile {
		/** First line to starting point second line. */
		double ccw11;
		/** First line to ending point second line. */
		double ccw12;
		/** Second line to starting point first line. */
		double ccw21;
		/** Second line to ending point first line. */
		double ccw22;
	};
	/** Representation of a file check result. */
	struct result {
		/** Number of intersections. */
		unsigned long count;
		/** Duration in milliseconds. */
		unsigned long duration;
	};
	/** Parses a file to a list of lines.
	 * param file_name A char pointer to the absolute path of the File.
	 * return The list of parsed lines.
	 */
	std::list<line> from_file(const char * file_name);
	/** Calculates the CCW for the given points.
	 * param p The starting point of the line.
	 * param q The ending point of the line.
	 * param r The point to check against the line.
	 * return The calculated ccw.
	 */
	double ccw(point & p, point & q, point & r);
	/** Checks if two lines are intersecting.
	 * param first The first line.
	 * param second The second line.
	 * return True if the lines are intersecting, else false.
	 */
	bool intersecting(line & first, line & second);
	/** Checks an entire file (list) and counts intersections.
	 * param file The list of lines.
	 * return The file check result.
	 */
	result check_file(std::list<line> & file);
	/** The current time in milliseconds. */
	unsigned long current_time_milliseconds(void);
}

/** Type definition for a list of lines. */
typedef std::list<lines::line> line_list;
/** Type definition for an iterator for a list of lines. */
typedef line_list::iterator line_it;

#endif /* LINES_HPP_ */
