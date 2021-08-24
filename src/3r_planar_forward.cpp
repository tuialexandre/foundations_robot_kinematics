#include "3r_planar.h"

using namespace std;

void PlanarRobot3R::PrintParameters(void)
{
	cout << "alpha: ";
	CommonOperations::printArray(alpha.data(), alpha.size());
	cout << "a: ";
	CommonOperations::printArray(a.data(), a.size());
	cout << "d: ";
	CommonOperations::printArray(d.data(), d.size());
	cout << "theta: ";
	CommonOperations::printArray(theta.data(), theta.size());
}

void PlanarRobot3R::CalculateTs(void)
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

PlanarRobot3R robot1 = {{0.0, 0.0, 0.0}, {3.0, 3.0, 1.0}, {0.0, 0.0, 0.0}, {10.0, 30.0, 15.0}};

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