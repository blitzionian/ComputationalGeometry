#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <chrono>

#include <p3.hpp>

using namespace std;
using namespace std::chrono;

const string FILE_1 = "input/s_1000_1.dat";
const string FILE_2 = "input/s_1000_10.dat";
const string FILE_3 = "input/s_10000_1.dat";
const string FILE_4 = "input/s_100000_1.dat";

int main() {
	calculateFile(FILE_1);
	cout << endl;
	calculateFile(FILE_2);
	cout << endl;
	calculateFile(FILE_3);
	cout << endl;
	calculateFile(FILE_4);

	return 0;
}
