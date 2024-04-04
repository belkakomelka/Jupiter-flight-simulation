#ifndef JUPITER_FLIGHT_SIMULATION_CONSTANTS_H
#define JUPITER_FLIGHT_SIMULATION_CONSTANTS_H

namespace constants{
    double const FiZ = 0; // полярный полярный угол Земли
    double const R_0 = 149600000; // радиус орбиты Земли
    double const R_F = 777900000; // радиус орбиты Юпитера
    double const V_0 = 29.765; // начальная тангенциальная скорость ракеты км/сек
    double const U_0 = 0; // начальная радиальная скорость ракеты км/сек
    double const V_Z = 29.765; // орбитальная скорость Земли км/сек
    double const V_F = 13.07; // орбитальная скорость Юптера км/сек
    double const ALPHA = 0.001;  // ускорение от паруса, м/сек**
    double const t10 = 3650; // суммарное время, нулевое приближение  (в сутках)
    double const A_0 = 0.0059361; //гравитационная постоянная*Mc/R0**2
    double const PU_0 = 695;    // сопряженная переменная
    double const PV_0 = 1383.0;    // сопряженная переменная
    double const PR_0 = -0.00001; // сопряженная переменная
    static double t1 = t10;
    int dimension = 4;  //   количество переменных в методе Ньютона
    int iterations = 1000;  // !общее количество шагов в Рунге-Кутта

    std::vector<std::vector<double>> result(
            iterations + 1, std::vector<double>(dimension + 5, 0));
}

#endif //JUPITER_FLIGHT_SIMULATION_CONSTANTS_H
