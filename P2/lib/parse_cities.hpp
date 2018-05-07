/*
 * parse_cities.hpp
 *
 *  Created on: 07.05.2018
 *      Author: mroeder
 */

#ifndef PARSE_CITIES_HPP_
#define PARSE_CITIES_HPP_
#define ROOT "svg"
#define FIELD "path"
#define CITY_NODE_TYPE "arc"
#define NODE_TYPE_FIELD "sodipodi:type"
#define CITY_NAME "id"
#define CITY_X "sodipodi:cx"
#define CITY_Y "sodipodi:cy"

#include <list>
#include <rapidxml.hpp>
#include <point.hpp>

namespace city_parser {
	struct city {
		std::string name;
		Point coordinate;
	};

	typedef std::list<city> city_list;
	typedef city_list::iterator city_itr;

	template<typename Func> void each_city(rapidxml::xml_document<> & doc,Func func);
	city_list from_file(const char * path);



}





#endif /* PARSE_CITIES_HPP_ */
