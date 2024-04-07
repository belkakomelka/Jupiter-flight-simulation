#ifndef JUPITER_FLIGHT_SIMULATION_SUBFUNCTION_H
#define JUPITER_FLIGHT_SIMULATION_SUBFUNCTION_H

#include <vector>
#include "gauss.h"
#include "constants.h"
#include "RK4.h"

void subfunction(
        int dimension,
        double x0,
        const std::vector<double>& y,
        std::vector<double>& dy,
        int& exit_signal,
        unsigned int step_number,
        Matrix& result);

void getResidual(const std::vector<double> &x, std::vector<double> &residual);

#endif
