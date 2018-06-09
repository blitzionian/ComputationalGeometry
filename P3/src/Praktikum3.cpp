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

const string FILE_TEST1 = "input/s_50000_1.dat";
const string FILE_TEST2 = "input/s_50000_2.dat";
const string FILE_TEST3 = "input/s_25000_1.dat";
const string FILE_TEST4 = "input/s_25000_2.dat";

int main() {
//	calculateFile(FILE_1);
//	cout << endl;
//	calculateFile(FILE_2);
//	cout << endl;
//	calculateFile(FILE_3);
//	cout << endl;
//	calculateFile(FILE_4);

//	cout << endl;
//	calculateFile(FILE_TEST1);
//	cout << endl;
//	calculateFile(FILE_TEST2);
//	cout << endl;
	calculateFile(FILE_TEST3);
	cout << endl;
	calculateFile(FILE_TEST4);

	return 0;
}
