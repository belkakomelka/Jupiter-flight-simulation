#ifndef GAUSS_ITERSYSTEMSOLVER_H
#define GAUSS_ITERSYSTEMSOLVER_H

#include <iostream>
#include <vector>
#include <string>

using std::vector;

typedef vector<vector<double> > Matrix;

void solveSystem(
	const Matrix& LU, vector<double>& B, 
	const vector<int>& T, vector<double>& X);

#endif
