/*
 * parse_cities.cpp
 *
 *  Created on: 07.05.2018
 *      Author: mroeder
 */

#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <parse_cities.hpp>

using namespace city_parser;
using namespace rapidxml;

inline std::string file_to_string(const char * path);

template<typename Func> void city_parser::each_city(xml_document<> & doc, Func func) {
	for (xml_node<> * path_node = doc.first_node(ROOT)->first_node(FIELD); path_node;
			path_node = path_node->next_sibling()) {
		std::string type = path_node->first_attribute(NODE_TYPE_FIELD)->value();

		if (type == CITY_NODE_TYPE) {
			func(path_node->first_attribute(CITY_NAME)->value(), atof(path_node->first_attribute(CITY_X)->value()),
					atof(path_node->first_attribute(CITY_Y)->value()));
		}
	}
}

city_list city_parser::from_file(const char * path) {
	city_list result;

	std::string content = file_to_string(path);
	char ary[content.size()];
	strcpy(ary, content.c_str());
	xml_document<> doc;
	doc.parse<0>(ary);

	each_city(doc, [&result] (char * name, double x, double y) {
		result.push_back(city {name,Point(x,y)});
	});

	return result;
}

inline std::string file_to_string(const char * path) {
	std::ifstream t(path);
	std::string str;
	t.seekg(0, std::ios::end);
	str.reserve(t.tellg());
	t.seekg(0, std::ios::beg);
	str.assign((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
	return str;
}

