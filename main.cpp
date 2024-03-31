#include <iostream>
#include <cmath>
#include "Modyfied_Newton.h"
#include "residuals.h"

double const FiZ = 0; // полярный полярный угол Земли
double const R_0 = 149600000; // радиус орбиты Земли
double const R_F = 777900000; // радиус орбиты Юпитера
double const V_0 = 29.765; // начальная тангенциальная скорость ракеты км/сек
double const U_0 = 0; // начальная радиальная скорость ракеты км/сек
double const V_Z = 29.765; // орбитальная скорость Земли км/сек
double const V_F = 13.07; // орбитальная скорость Юптера км/сек
double const ALPHA = 0.001;  // ускорение от паруса, м/сек**
double const t10 = 3650; // суммарное время, нулевое приближение  (в сутках)
double t1 = t10; // суммарное время, нулевое приближение  (в сутках)
double const A_0 = 0.0059361; //гравитационная постоянная*Mc/R0**2
double PU_0 = 695;    // сопряженная переменная
double PV_0 = 1383.0;    // сопряженная переменная
double PR_0=-0.00001; // сопряженная переменная
double PU = PU_0;    // сопряженная переменная
double PV = PV_0;  // сопряженная переменная
double PR = PR_0;   // сопряженная переменная
double PFI = 0.0;  // сопряженная переменная
int dimension = 4;  //   количество переменных в методе Ньютона
int iterations = 1000;  // !общее количество шагов в Рунге-Кутта
double NS1=0;   // счетчик итераций в методе Ньютона

double teta = atan((3*PU - sqrt(9 * pow(PU, 2) + 8 * pow(PV, 2) )) / 4 / PV);
double tetagrad= teta * 180 / M_PI;
double U = U_0;
double V = V_0;
double R = R_0;
double Fi = FiZ;

int main() {
    // параметры пристрелки
    vector<double> x{PU / PU_0, PV / PV_0, PR / PR_0, t1 / t10};
    std::vector<double> residuals;
    // todo вывод начальных
    newtonModyfied(&getResidual, dimension, x, residuals, iterations);
    // todo вывод результатов
    return 0;
}
