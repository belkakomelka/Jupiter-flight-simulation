#include "Subfunction.h"

void subfunction(
        int dimension,
        double x0,
        std::vector<double> y,
        std::vector<double>& dy,
        int& exit_signal,
        unsigned int step_number,
        Matrix& result){
//    dimension    - количество параметров
//    steps        - количество шагов
//    x0           - начальное время
//    dx           - шаг по времени
//    y            - вектор начальных условий
//    exit_signal  - сигнал для выхода (0)
//    step_counter - номер шага
//    result       - результирующая матрица

    double U = y[0];
    double V = y[1];
    double R = y[2];
    double FI = y[3];
    double PU = y[4];
    double PV = y[5];
    double PR = y[6];
    double PFi = y[7];
    double t = x0 * 86400;

    double teta = atan((3*PU - sqrt(9 * pow(PU, 2) + 8 * pow(PV, 2) )) / 4 / PV);

    double tetagrad= teta * 180 / M_PI;

    // Пи-система
    dy[0] = (pow(V, 2) / R - A_0 * pow(R_0/R, 2)
            + ALPHA * pow(R_0/R, 2) * pow(cos(teta), 3)) * t; // dU/dt
    dy[1] = (- V * U / R - ALPHA * pow(R_0/R, 2) * sin(teta) * pow(cos(teta), 2)) * t; // dV/dt
    dy[2] = U * t; // dR/dt
    dy[3] = (V / R) * t; // dFi/dt
    dy[4] = (V / R * PV - PR) * t; // dPU/dt
    dy[5] = (PV * U / R - 2 * V * PU / R -PFi / R) * t; // dPV/dt
    dy[6] = (PV * U / R-2 * V * PU / R - PFi / R) * t; // dPV/dt
    dy[7] = (PU * (pow(V / R, 2) - 2 * A_0 * pow(R_0, 2) / pow(R,3) + 2 * ALPHA * pow(cos(teta), 3) * pow(R_0, 2) / pow(R,3))
            - PV * (U * V / R + 2 * ALPHA * sin(teta) * pow(cos(teta), 2) * pow(R_0, 2) / pow(R,3))) * t; // dPR/dt
    dy[8] = 0; // dPFi/dt

    // запишем функцию Понтрягина
    double H_PONTRYAGIN = (y[4] * dy[0] + y[5] * dy[1] + y[6] * dy[2] + y[7] * dy[3]) * t - 1;

    result[step_number + 1][dimension + 1] = H_PONTRYAGIN;
    result[step_number + 1][dimension + 2] = teta;
    result[step_number + 1][dimension + 3] = tetagrad;
    result[step_number + 1][dimension + 4] = x0 * t1;
}