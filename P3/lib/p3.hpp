#ifndef LIB_P3_HPP_
#define LIB_P3_HPP_

#include <vector>
#include <line.hpp>

using namespace std;

void readInputFile(string file, vector<Line*>* lines);
void calculateFile(string file);
int64_t currentTime(void);
bool isSpecialCase(Line lineToCheck);
vector<Line*>* searchAndFilterForDoublePoints(vector<Line*>* lines);
bool vectorContains(vector<Point> data, Point pointToSearch);

#endif /* LIB_P3_HPP_ */
