#include "Modyfied_Newton.h"
#include "Subfunction.h"
#include "constants.h"

int main() {
    double PU = constants::PU_0;    // сопряженная переменная
    double PV = constants::PV_0;  // сопряженная переменная
    double PR = constants::PR_0;   // сопряженная переменная
    double PFI = 0.0;  // сопряженная переменная
    double NS1 = 0;   // счетчик итераций в методе Ньютона
    double t1 = constants::t10; // суммарное время, нулевое приближение  (в сутках)
//    double teta = atan((3*PU - sqrt(9 * pow(PU, 2) + 8 * pow(PV, 2) )) / 4 / PV);
//    double tetagrad= teta * 180 / M_PI;
//    double U = constants::U_0;
//    double V = constants::V_0;
//    double R = constants::R_0;
//    double Fi = constants::FiZ;
    // параметры пристрелки
    vector<double> x{PU / constants::PU_0, PV / constants::PV_0, PR / constants::PR_0, t1 / constants::t10};
    std::vector<double> residuals;
    // todo вывод начальных
    newtonModyfied(&getResidual, constants::dimension, x, residuals, constants::iterations);
    // todo вывод результатов
    return 0;
}
