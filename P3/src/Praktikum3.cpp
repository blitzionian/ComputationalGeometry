#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <chrono>
#include "line.hpp"

#include <line_sweep.hpp>

using namespace std;
using namespace std::chrono;

const string FILE_1 = "input/s_1000_1.dat";
const string FILE_2 = "input/s_10000_1.dat";
const string FILE_3 = "input/s_100000_1.dat";
const string FILE_4 = "input/s_1000_10.dat";

void calculateFile(string file);
int64_t currentTime(void);

int main() {
	calculateFile(FILE_1);
	calculateFile(FILE_2);
	calculateFile(FILE_3);
	calculateFile(FILE_4);

	return 0;
}

void calculateFile(string file) {
	cout << endl << "Starte mit Berechnung File: " << file << endl << endl;

	std::vector<Line*> lines = line_sweep::from_file(file);
	line_sweep::filter_special_cases(lines);

	int64_t start = currentTime();

	vector<Point*> intersections = line_sweep::intersections(lines);

	int64_t duration = currentTime() - start;
	cout << "Duration: " << duration << endl;
	cout << "Count: " << intersections.size() << endl;
}

int64_t currentTime() {
	return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}
