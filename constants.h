#ifndef JUPITER_FLIGHT_SIMULATION_CONSTANTS_H
#define JUPITER_FLIGHT_SIMULATION_CONSTANTS_H
#pragma once

#include <vector>

namespace constants{
    extern double const FiZ; // полярный полярный угол Земли
    extern double const R_0; // радиус орбиты Земли
    extern double const R_F; // радиус орбиты Юпитера
    extern double const V_0; // начальная тангенциальная скорость ракеты км/сек
    extern double const U_0; // начальная радиальная скорость ракеты км/сек
    extern double const V_Z; // орбитальная скорость Земли км/сек
    extern double const V_F; // орбитальная скорость Юптера км/сек
    extern double const ALPHA;  // ускорение от паруса, м/сек**
    extern double const t10; // суммарное время, нулевое приближение  (в сутках)
    extern double const A_0; //гравитационная постоянная*Mc/R0**2
    extern double const PU_0;    // сопряженная переменная
    extern double const PV_0;    // сопряженная переменная
    extern double const PR_0; // сопряженная переменная
    extern double t1;
    extern int dimension;  //   количество переменных в методе Ньютона
    extern int iterations;  // !общее количество шагов в Рунге-Кутта

    extern std::vector<std::vector<double> > result;
}

#endif //JUPITER_FLIGHT_SIMULATION_CONSTANTS_H
