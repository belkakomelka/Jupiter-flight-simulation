//
// Created by Камиля on 04.04.2024.
//
#include "constants.h"

const double constants::ALPHA = 0.001;

const double constants::FiZ = 0; // полярный полярный угол Земли
const double constants::R_0 = 149600000; // радиус орбиты Земли
const double constants::R_F = 777900000; // радиус орбиты Юпитера
const double constants::V_0 = 29.765; // начальная тангенциальная скорость ракеты км/сек
const double constants::U_0 = 0; // начальная радиальная скорость ракеты км/сек
const double constants::V_Z = 29.765; // орбитальная скорость Земли км/сек
const double constants::V_F = 13.07; // орбитальная скорость Юптера км/сек
const double constants::t10 = 3650; // суммарное время, нулевое приближение  (в сутках)
const double constants::A_0 = 0.0059361; //гравитационная постоянная*Mc/R0**2
const double constants::PU_0 = 695;    // сопряженная переменная
const double constants::PV_0 = 1383.0;    // сопряженная переменная
const double constants::PR_0 = -0.00001; // сопряженная переменная
double constants::t1 = t10;
int constants::dimension = 4;  //   количество переменных в методе Ньютона
int constants:: iterations = 1000;  // !общее количество шагов в Рунге-Кутта

std::vector<std::vector<double>> constants::result(
        constants::iterations + 1, std::vector<double>(constants::dimension + 9, 0));