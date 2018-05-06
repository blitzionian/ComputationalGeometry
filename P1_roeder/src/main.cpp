//============================================================================
// Name      		: main.cpp
// Author			: mroeder (mroeder@hm.edu)
// Version			: 0.5.0
// OS				: Ubuntu x64 16.04 LTS
// CPU				: Intel® Core™ i5 CPU M 520 @ 2.40GHz × 4
// Compiler			: gcc version 5.4.0
// Language Level 	: c++ 11
// Description 		: Program entry of the line intersection exercise.
//============================================================================

#include <iostream>
#include <sstream>
#include <lines.hpp>

using namespace std;

const string FILE_1 = "s_1000_1.dat";
const string FILE_2 = "s_10000_1.dat";
const string FILE_3 = "s_100000_1.dat";

inline string cout_line(string name, lines::result & result);
inline string abs_file(char * dir, const string name);

/** Program Entry.
 * Expects file path as last argument.
 */
int main(int ac, char ** av) {
	list<lines::line> file_1 = lines::from_file(abs_file(av[ac - 1],FILE_1).c_str());
	list<lines::line> file_2 = lines::from_file(abs_file(av[ac - 1],FILE_2).c_str());
	list<lines::line> file_3 = lines::from_file(abs_file(av[ac - 1],FILE_3).c_str());

	lines::result retval_1 = lines::check_file(file_1);
	lines::result retval_2 = lines::check_file(file_2);
	lines::result retval_3 = lines::check_file(file_3);

	cout << "{" << endl
		 << cout_line("s_1000_1.dat",retval_1) << "," << endl
		 << cout_line("s_10000_1.dat",retval_2) << "," << endl
		 << cout_line("s_100000_1.dat",retval_3) << endl
		 << "}" << endl;

	return 0;
}

inline string cout_line(string name, lines::result & result) {
	stringstream retval;
	retval << "\"" << name << "\": {\"duration\": \"";
	unsigned long duration = result.duration;
	unsigned long min = duration / 60000;
	if(min > 0) {
		retval << min << "min ";
	}
	duration = duration % 60000;
	unsigned long sec = duration / 1000;
	if(sec > 0) {
		retval << sec << "sec ";
	}
	unsigned long ms = duration % 1000;
	retval << ms << "ms\", \"count\": " << result.count << "}";
	return retval.str();
}

inline string abs_file(char * dir, const string name) {
	stringstream retval;
	retval << dir << name;
	return retval.str();
}


