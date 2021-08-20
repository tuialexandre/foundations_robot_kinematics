#ifndef COMMON_OPERATIONS_H_
#define COMMON_OPERATIONS_H_

#include <math.h>
#include <vector>
#include <iostream>

namespace CommonOperations{
    std::vector< std::vector<double> > calculateT(double alpha, double a, double d, double theta);
    std::vector< std::vector<double> > multiplySquareMatrix (std::vector< std::vector<double> > matrixA, std::vector< std::vector<double> > matrixB);
    void printMatrix(const std::vector<std::vector<double>>& matrix );
    void printArray(const double* array, const size_t& size);
};
#endif