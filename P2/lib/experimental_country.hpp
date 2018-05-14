/*
 * experimental_country.hpp
 *
 *  Created on: 14.05.2018
 *      Author: mroeder
 */

#ifndef EXPERIMENTAL_COUNTRY_HPP_
#define EXPERIMENTAL_COUNTRY_HPP_

#include <string>
#include <vector>
#include <experimental_state.hpp>

namespace experimental {
	class Country {
	public:
		Country(std::string & name);
		virtual ~Country();
		std::string name();
		void append_state(State & state);
		template<typename Func> void each_state(Func func);
		std::vector<State> matches(double x, double y);
	private:
		std::string m_name;
		std::vector<State> m_states;
	};
}



#endif /* EXPERIMENTAL_COUNTRY_HPP_ */
