/*
 * experimental_state.hpp
 *
 *  Created on: 14.05.2018
 *      Author: mroeder
 */

#ifndef EXPERIMENTAL_STATE_HPP_
#define EXPERIMENTAL_STATE_HPP_

#include <string>
#include <vector>
#include <experimental_polygon.hpp>


namespace experimental {
	class State {

	public:
		State(std::string & name);
		virtual ~State();
		std::string name();
		void append_polygon(Polygon & polygon);
		template<typename Func> void each_polygon(Func func);
		double area();
		bool matches(double x, double y);
	private:
		std::string m_name;
		std::vector<Polygon> m_polygons;
	};
}

#endif /* EXPERIMENTAL_STATE_HPP_ */
