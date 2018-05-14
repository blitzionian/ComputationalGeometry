/*
 * experimental_polygon.cpp
 *
 *  Created on: 14.05.2018
 *      Author: mroeder
 */
#include <algorithm>
#include <stdlib.h>
#include <experimental_polygon.hpp>

experimental::Polygon::Edge::Edge(experimental::Polygon::Vertex & start, experimental::Polygon::Vertex & end) {
	m_start = start;
	m_end = end;
}

experimental::Polygon::Edge::~Edge() {
}

double experimental::Polygon::Edge::ccw(experimental::Polygon::Vertex & other) {
	return ((m_start.x * m_end.y) - (m_start.y * m_end.x))
				+ ((m_end.x * other.y) - (m_end.y * other.x))
				+ ((m_start.y * other.x) - (m_start.x * other.y));
}

experimental::Polygon::Polygon() {
}

experimental::Polygon::~Polygon() {
}

void experimental::Polygon::append_vertex(experimental::Polygon::Vertex & other) {
	m_vertices.push_back(other);
}

void experimental::Polygon::append_hole(experimental::Polygon & other) {
	m_holes.push_back(other);
}

template<typename Func> void experimental::Polygon::each_vertex(Func func) {
	for(std::vector<Vertex>::iterator it = m_vertices.begin(); it != m_vertices.end(); ++it) {
		func(*it);
	}
}

template<typename Func> void experimental::Polygon::each_hole(Func func) {
	for(std::vector<Polygon>::iterator it = m_holes.begin(); it != m_holes.end(); ++it) {
		func(*it);
	}
}

template<typename Func> void experimental::Polygon::each_edge(Func func) {
	for(std::vector<Vertex>::iterator it = m_vertices.begin(); it != m_vertices.end(); ++it) {
		std::vector<Vertex>::iterator next(it);
		++next;
		if(next != m_vertices.end()) {
			func(Edge(*it,*next));
		} else {
			func(Edge(*it, *m_vertices.begin()));
		}
	}
}

double experimental::Polygon::area() {
	double result = 0;
	// TODO: area calculation
	each_hole([&result](Polygon & poly) {
		result -= poly.area();
	});
	return result;
}

bool experimental::Polygon::matches(experimental::Polygon::Vertex & other) {
	bool answer = false;
	Vertex outer = max_coordinates();
	outer.x += 10.0;
	outer.y += 10.0;
	Edge outer_ref(outer,other);
	unsigned int i = 0;
	while(0.0 == outer_ref.ccw(m_vertices[i]) && i < m_vertices.size()) {
		++i;
	}
	if(i < m_vertices.size()) {
		Vertex pi = m_vertices[i];
		int s = 0;
		short int lr = signum(outer_ref.ccw(pi));
		for(unsigned int j = i + 1; j < m_vertices.size(); ++j) {
			Vertex pj = m_vertices[j];
			short int lrnew = signum(outer_ref.ccw(pj));
			if(2 == abs(lrnew - lr)) {
				lr = lrnew;
				Edge inner_ref(m_vertices[j-1],pj);
				if(inner_ref.ccw(outer) * inner_ref.ccw(other) <= 0.0) {
					++s;
				}
			}
		}
		answer = (s % 2 != 0);
	}
	// check for holes
	if(answer) {
		each_hole([&answer,&other](Polygon & h){
			answer &= h.matches(other);
		});
	}
	return answer;
}

bool experimental::Polygon::matches(double x, double y) {
	Vertex v = {x,y};
	return matches(v);
}

short int experimental::Polygon::signum(double value) {
	short int result = 0;
	if(value > 0.0) {
		result = 1;
	}
	if(value < 0.0) {
		result = -1;
	}
	return result;
}

experimental::Polygon::Vertex experimental::Polygon::max_coordinates() {
	Vertex result {0,0};
	each_vertex([&result](Vertex & v){
		if(v.x > result.x){
			result.x = v.x;
		}
		if(v.y > result.y) {
			result.y = v.y;
		}
	});
	return result;
}









