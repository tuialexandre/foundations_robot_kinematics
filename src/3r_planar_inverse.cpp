#include "3r_planar.h"

using namespace std;

// Paramethers: Link lengths and Actuator Position and Orientation (in degrees)
void CalculateInverse3R(double a1, double a2, double actuator_angle, double actuator_x, double actuator_y)
{
	cout << "Planar Robot 3R - Inverse Kinematics " << "\n";
	cout << "--------------------------------" << "\n";
	cout << "Inputs:" << "\n";
	cout << "a1 = " << a1 << "\n";
	cout << "a2 = " << a2 << "\n";
	cout << "Actuator Angle (in degrees)= " << actuator_angle << "\n";
	cout << "Actuator PosX = " << actuator_x << "\n";
	cout << "Actuator PosY = " << actuator_y << "\n";
	cout << "--------------------------------" << "\n";
	
	int columnCount = 4;
	int rowCount = 4;
	double initValue = 0.0;
	vector< vector<double> > T;
	//now we have an empty 2D-matrix of size (0,0). Resizing it with one single command:
	T.resize(rowCount, vector<double>(columnCount, initValue));

	actuator_angle *= M_PI / 180.0; // Convert to Rads

	// T Matrix
	T[0][0] = cos(actuator_angle); 	// r11 
	T[0][1] = -sin(actuator_angle);	// r12
	T[0][2] = 0;	// r13
	T[0][3] = actuator_x;	// px
	
	T[1][0] = sin(actuator_angle);	// r21
	T[1][1] = cos(actuator_angle);	// r22
	T[1][2] = 0;	// r23
	T[1][3] = actuator_y;	// py
	
	T[2][0] = 0;	// r31
	T[2][1] = 0;	// r32
	T[2][2] = 1;	// r33
	T[2][3] = 0;	// pz
	
	T[3][0] = 0;
	T[3][1] = 0;
	T[3][2] = 0;
	T[3][3] = 1;
	
	double c2 = (actuator_x*actuator_x + actuator_y*actuator_y - a1*a1 - a2*a2)/ (2*a1*a2);
	if(c2 >= -1 || c2 <= 1) // Calculated angle must be a real value
	{
		// Calculate Theta 2
		double theta2a = acos(c2);
		double theta2b = -theta2a;
		
		// Theta 1
		double theta1a = atan2(actuator_y, actuator_x) - atan2(a2*sin(theta2a), a1 + a2*cos(theta2a));
		double theta1b = atan2(actuator_y, actuator_x) - atan2(a2*sin(theta2b), a1 + a2*cos(theta2b));
		
		// Theta 3
		double theta3a = atan2(T[1][0],T[0][0]) - theta1a - theta2a;
		double theta3b = atan2(T[1][0],T[0][0]) - theta1b - theta2b;
		
		cout << "Solutions (rad):" << "\n";
		cout << theta1a << " ";
		cout << theta2a << " ";
		cout << theta3a << "\n";
		cout << theta1b << " ";
		cout << theta2b << " ";
		cout << theta3b << "\n";
		cout << "--------------------------------" << "\n";
		
	}
	else
	{
		cout << "Invalid Input - Target Actuator is Out of Range" << "\n";
	}
	
}


int main(int argc, char** argv) {
    ros::init(argc, argv, "three_r_planar_inverse_node");
    ros::NodeHandle nh;
	ros::Rate loop_rate(10);

	CalculateInverse3R(3, 3, 0, 4, 2);

    ros::shutdown();
	return 0;
}
