#ifndef THREE_R_PLANAR_H_
#define THREE_R_PLANAR_H_

#include "common_operations.h"
#include <ros/ros.h>

class PlanarRobot3R
{
    const static size_t joints_count{3};
public:
	std::array<double, joints_count> alpha;
	std::array<double, joints_count> a;
	std::array<double, joints_count> d;
	std::array<double, joints_count> theta;
	
	void PrintParameters(void);
	void CalculateTs(void);
};


#endif