/*
 * experimental_state.cpp
 *
 *  Created on: 14.05.2018
 *      Author: mroeder
 */

#include <experimental_state.hpp>

experimental::State::State(std::string & name) {
	m_name = name;
}

experimental::State::~State() {
}

std::string experimental::State::name() {
	return m_name;
}

void experimental::State::append_polygon(experimental::Polygon & polygon) {
	m_polygons.push_back(polygon);
}

template<typename Func> void experimental::State::each_polygon(Func func) {
	for(unsigned int i = 0; i < m_polygons.size(); ++i) {
		func(m_polygons[i]);
	}
}

double experimental::State::area(){
	double result = 0.0;
	each_polygon([&result](Polygon & poly) {
		result += poly.area();
	});
	return result;
}

bool experimental::State::matches(double x, double y) {
	bool answer = false;
	each_polygon([&answer,&x,&y](Polygon & poly) {
		answer &= poly.matches(x,y);
	});
	return answer;
}



