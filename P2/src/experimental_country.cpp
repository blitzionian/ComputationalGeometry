/*
 * experimental_country.cpp
 *
 *  Created on: 14.05.2018
 *      Author: mroeder
 */

#include <experimental_country.hpp>

experimental::Country::Country(std::string & name) {
	m_name = name;
}

experimental::Country::~Country() {
}

std::string experimental::Country::name() {
	return m_name;
}

void experimental::Country::append_state(experimental::State & state) {
	m_states.push_back(state);
}

template<typename Func> void experimental::Country::each_state(Func func) {
	for(unsigned int i = 0; i < m_states.size(); ++i) {
		func(m_states[i]);
	}
}

std::vector<experimental::State> experimental::Country::matches(double x, double y) {
	std::vector<State> result;
	each_state([&result,&x,&y](State & state) {
		if(state.matches(x,y)) {
			result.push_back(state);
		}
	});
	return result;
}


