#ifndef NIRS9_GETLOCALNORM_H
#define NIRS9_GETLOCALNORM_H

#include <vector>

typedef std::vector<std::vector<double>> Matrix;

double getLocalNorm(std::vector<double>& residuals, const Matrix& A);


#endif //NIRS9_GETLOCALNORM_H
