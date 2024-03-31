#ifndef JUPITER_FLIGHT_SIMULATION_SUBFUNCTION_H
#define JUPITER_FLIGHT_SIMULATION_SUBFUNCTION_H

#include <vector>
#include "gauss.h"

extern double const ALPHA;
extern double const A_0;
extern double const R_0;
extern double t1;


void subfunction(
        int dimension,
        double x0,
        std::vector<double> y,
        std::vector<double>& dy,
        int& exit_signal,
        unsigned int step_number,
        Matrix& result);

#endif
