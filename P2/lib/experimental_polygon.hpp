/*
 * experimental_polygon.hpp
 *
 *  Created on: 14.05.2018
 *      Author: mroeder
 */

#ifndef EXPERIMENTAL_POLYGON_HPP_
#define EXPERIMENTAL_POLYGON_HPP_

#include <vector>
#include <string>

namespace experimental {
	class Polygon {
	public:

		struct Vertex {
			double x;
			double y;
		};

		class Edge {
		public:
			Edge(Vertex & start, Vertex & end);
			virtual ~Edge();
			double ccw(Vertex & other);
		private:
			Vertex m_start;
			Vertex m_end;
		};

		Polygon();
		virtual ~Polygon();

		void append_vertex(Vertex & vertex);
		void append_hole(Polygon & other);
		template<typename Func> void each_vertex(Func func);
		template<typename Func> void each_edge(Func func);
		template<typename Func> void each_hole(Func func);

		double area(void);
		bool matches(Vertex & other);
		bool matches(double x, double y);
	private:
		std::vector<Vertex> m_vertices;
		std::vector<Polygon> m_holes;
		short int signum(double value);
		Vertex max_coordinates();
	};
}




#endif /* EXPERIMENTAL_POLYGON_HPP_ */
