
#include <common_operations.h>


std::vector< std::vector<double> > CommonOperations::calculateT(double alpha, double a, double d, double theta)
{
    size_t column_count = 4;
    size_t row_count = 4;
    double init_value = 0.0;
    std::vector< std::vector<double> > T;
    //now we have an empty 2D-matrix of size (0,0). Resizing it with one single command:
    T.resize( column_count , std::vector<double>( row_count , init_value ) );

    alpha *= M_PI / 180.0;
    theta *= M_PI / 180.0;

    T[0][0] = cos(theta);
    T[1][0] = -sin(theta);
    T[2][0] = 0;
    T[3][0] = a;
    
    T[0][1] = cos(alpha) * sin(theta);
    T[1][1] = cos(alpha) * cos(theta);
    T[2][1] = -sin(alpha);
    T[3][1] = -d * sin(alpha);
    
    T[0][2] = sin(alpha) * sin(theta);
    T[1][2] = sin(alpha) * cos(theta);
    T[2][2] = cos(alpha);
    T[3][2] = d * cos(alpha);
    
    T[0][3] = 0;
    T[1][3] = 0;
    T[2][3] = 0;
    T[3][3] = 1;

    return T;
}

std::vector< std::vector<double> > CommonOperations::multiplySquareMatrix(std::vector< std::vector<double> > matrixA, std::vector< std::vector<double> > matrixB)
{
    if(matrixA.size() == 0 || matrixA.size() != matrixB.size()) {
        throw std::runtime_error("An invalid square matrix multiplication operation was requested!");
    }
    else if(matrixA[0].size() != matrixA.size() || matrixB.size() != matrixB[0].size() )
    {
        throw std::runtime_error("A non square matrix multiplication operation was requested!");
    }
    size_t column_count = matrixA.size();
    size_t row_count = matrixA[0].size();
    double init_value = 0.0;
    std::vector< std::vector<double> > result;
    result.resize( column_count , std::vector<double>( row_count , init_value ) );
    
    for (size_t i = 0; i < column_count; i++)
    {
        for (size_t j = 0; j < row_count; j++)
        {
            result[i][j] = 0;
            for (size_t k = 0; k < column_count; k++)
            {
                result[i][j] += (matrixA[i][k]*matrixB[k][j]);
            }
        }
    }
    
    return result;
}

void CommonOperations::printMatrix(const std::vector<std::vector<double>>& matrix )
{
    for (size_t j = 0; j < matrix.size(); j++)
    {
        for (size_t i = 0; i < matrix[j].size(); i++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void CommonOperations::printArray(const double* array, const size_t& size)
{
    for(size_t i = 0; i < size; i++)
    {
        std::cout << " " << array[i];
    }
    std::cout << "\n";
}