#ifndef GAUSS_RK4_H
#define GAUSS_RK4_H

#include <vector>
#include "gauss.h"
#include "Subfunction.h"

void RK4(
        void (*subfunction)(
        int dimension,
        double x0,
        const vector<double>& y,
        vector<double>& dy,
        int& exit_signal,
        unsigned int step_number, Matrix& result),
        unsigned int dimension_rk, int steps,
        double x0, double dx, vector<double> y,
        int& exit_signal, int& step_counter, Matrix& result);

#endif //GAUSS_RK4_H
