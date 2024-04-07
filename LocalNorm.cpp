#include "LocalNorm.h"
#include <cmath>

double getLocalNorm(std::vector<double>& residuals, const Matrix& A){
    double norm = 0;
    for (int i = 0; i < residuals.size(); i++)
    {
        double z = 0;
        for (int j = 0; j < residuals.size(); j++)
            z += A[i][j] * A[i][j];
        norm += residuals[i] * residuals[i] / z;
    }
    norm = sqrt(norm);
    return norm;
}