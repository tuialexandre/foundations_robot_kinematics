#include "3r_planar.h"

using namespace std;

class PlanarRobot3R
{
public:
	double alpha[3];
	double a[3];
	double d[3];
	double theta[3];
	int numberOfJoints;
	
	void PrintParameters(void)
	{
		cout << "alpha: ";
		CommonOperations::printArray(alpha, numberOfJoints);
		cout << "a: ";
		CommonOperations::printArray(a, numberOfJoints);
		cout << "d: ";
		CommonOperations::printArray(d, numberOfJoints);
		cout << "theta: ";
		CommonOperations::printArray(theta, numberOfJoints);
	}
	void CalculateTs(void)
	{
		vector< vector<double> > T01 = CommonOperations::calculateT(alpha[0], a[0], d[0], theta[0]);
		vector< vector<double> > T12 = CommonOperations::calculateT(alpha[1], a[1], d[1], theta[1]);
		vector< vector<double> > T23 = CommonOperations::calculateT(alpha[2], a[2], d[2], theta[2]);
		
		vector< vector<double> > T02 = CommonOperations::multiplySquareMatrix(T01, T12);
		vector< vector<double> > T03 = CommonOperations::multiplySquareMatrix(T02, T23);
		
		cout << "T01: " << "\n";
		CommonOperations::printMatrix(T01);
		cout << "\n";
		cout << "T12: " << "\n";
		CommonOperations::printMatrix(T12);
		cout << "\n";
		cout << "T23: " << "\n";
		CommonOperations::printMatrix(T23);
		cout << "\n";
		cout << "T03: " << "\n";
		CommonOperations::printMatrix(T03);
	}
};

PlanarRobot3R robot1 = {{0.0, 0.0, 0.0}, {3.0, 3.0, 1.0}, {0.0, 0.0, 0.0}, {10.0, 30.0, 15.0} , 3};

int main(int argc, char** argv) {
    ros::init(argc, argv, "three_r_planar_forward_node");
    ros::NodeHandle nh;
	ros::Rate loop_rate(10);

	cout << "3R Planar Robot - Forward Kinematics" << "\n";
	cout << "--------------------------------" << "\n";
	robot1.PrintParameters();
	cout << "--------------------------------" << "\n";
	robot1.CalculateTs();
	cout << "--------------------------------" << "\n";

	ros::shutdown();
	
	return 0;
}