#ifndef SRC_CROSSPOINTS_HPP_
#define SRC_CROSSPOINTS_HPP_

#include <vector>
#include <crosspoint.hpp>

using namespace std;

class Crosspoints {
public:
	Crosspoints();
	virtual ~Crosspoints();

	void add(Crosspoint* crosspoint);
	int size();

private:
	vector<Crosspoint*> crosspoints;
};

#endif /* SRC_CROSSPOINTS_HPP_ */
