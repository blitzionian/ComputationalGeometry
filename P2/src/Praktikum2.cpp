#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <chrono>

#include <stdio.h>
#include <string.h>
#include <math.h>

#define NANOSVG_IMPLEMENTATION
#include "nanosvg.h"

//#include "rapidxml_ns.hpp"
//#include <svgpp/policy/xml/rapidxml_ns.hpp>
//#include "svgpp/svgpp.hpp"

using namespace std;
//using namespace svgpp;

const char* FILE_1 = "input/DeutschlandMitStaedten.svg";

int main() {
	struct NSVGimage* image;
	image = nsvgParseFromFile(FILE_1, "px", 96);
	printf("size: %f x %f\n", image->width, image->height);
	// Use...
	NSVGshape* shape;
	for (shape = image->shapes; shape != NULL; shape = shape->next) {
		NSVGpath* path;
		for (path = shape->paths; path != NULL; path = path->next) {
			for (int i = 0; i < path->npts - 1; i += 3) {
				float* p = &path->pts[i * 2];

				cout << p[0] << " " << p[1] << endl;
//				drawCubicBez(p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7]);
			}
		}
	}
	// Delete
	nsvgDelete(image);
}

//typedef rapidxml_ns::xml_node<> const * xml_element_t;
//void loadSvg(xml_element_t xml_root_element);
//
//class Context {
//public:
//	void on_enter_element(tag::element::any) {
//		cout << "enter" << endl;
//	}
//
//	void on_exit_element() {
//	}
//
//	void path_move_to(double x, double y, tag::coordinate::absolute) {
//	}
//
//	void path_line_to(double x, double y, tag::coordinate::absolute) {
//		cout << x << " : " << y << endl;
//	}
//
//	void path_cubic_bezier_to(double x1, double y1, double x2, double y2, double x, double y,
//			tag::coordinate::absolute) {
//	}
//
//	void path_quadratic_bezier_to(double x1, double y1, double x, double y, tag::coordinate::absolute) {
//	}
//
//	void path_elliptical_arc_to(double rx, double ry, double x_axis_rotation, bool large_arc_flag, bool sweep_flag,
//			double x, double y, tag::coordinate::absolute) {
//	}
//
//	void path_close_subpath() {
//	}
//
//	void path_exit() {
//	}
//};
//
//typedef boost::mpl::set<
//// SVG Structural Elements
//		tag::element::svg, tag::element::g,
//		// SVG Shape Elements
//		tag::element::path>::type processed_elements_t;
//
//int main() {
//
//	cout << "Hallo!" << endl;
//
//	FILE *f = fopen(FILE_1, "rb");
//	fseek(f, 0, SEEK_END);
//	long fsize = ftell(f);
//	fseek(f, 0, SEEK_SET);
//
//	char *text = (char *) malloc(fsize + 1);
//	fread(text, fsize, 1, f);
//	fclose(f);
//
//	text[fsize] = 0;
//
////	std::ifstream in(FILE_1);
////	std::string contents((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
////	char text = contents.c_str();
//
//	rapidxml_ns::xml_document<> doc;
//	doc.parse<0>(text);
//
//	loadSvg(doc.first_node("svg"));
//
////	cout << doc;
//
//	return 0;
//}
//
//void loadSvg(xml_element_t xml_root_element) {
//	Context context;
//	svgpp::document_traversal<processed_elements<processed_elements_t>,
//			processed_attributes<traits::shapes_attributes_by_element> >::load_document(xml_root_element, context);
//
//}

