#include "Subfunction.h"

void subfunction(
        int dimension,
        double x0,
        const std::vector<double>& y,
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

    std::cout << "SUBFUNCTION_FUNCTION" << std::endl;
    double U = y[0];
    double V = y[1];
    double R = y[2];
    double FI = y[3];
    double PU = y[4];
    double PV = y[5];
    double PR = y[6];
    double PFi = y[7];
    double T = constants::t1 * 86400;

    double teta = atan((3*PU - sqrt(9 * pow(PU, 2) + 8 * pow(PV, 2) )) / 4 / PV);

    double tetagrad= teta * 180 / M_PI;
//    std::cout << "teta = " << teta << std::endl;
//    std::cout << "tetagrad = " << tetagrad << std::endl;

    // Пи-система
    dy[0] = (pow(V, 2) / R - constants::A_0 * pow(constants::R_0/R, 2)
            + constants::ALPHA * pow(constants::R_0/R, 2) * pow(cos(teta), 3)) * T; // dU/dt
    dy[1] = (- V * U / R - constants::ALPHA * pow(constants::R_0/R, 2) * sin(teta) * pow(cos(teta), 2)) * T; // dV/dt
    dy[2] = U * T; // dR/dt
    dy[3] = (V / R) * T; // dFi/dt
    dy[4] = (V / R * PV - PR) * T; // dPU/dt
    dy[5] = (PV * U / R - 2 * V * PU / R - PFi / R) * T; // dPV/dt
    dy[6] = (PU * pow(V / R, 2) - PU * 2 * constants::A_0 * pow(constants::R_0, 2) / pow(R,3)
            + PU * 2 * constants::ALPHA * pow(constants::R_0, 2) / pow(R,3) * pow(cos(teta), 3)
            - PV * U * V / pow(R, 2) - PV * 2 * constants::ALPHA * sin(teta) * pow(cos(teta), 2) * pow(constants::R_0, 2) / pow(R,3)
            + PFi * V / pow(R, 2)) * T; // dPR/dt

//    double first =  PU * pow(V / R, 2);
//    double second =  - PU * 2 * constants::A_0 * pow(constants::R_0, 2) / pow(R,3);
//    double third =  PU * 2 * constants::ALPHA * pow(constants::R_0, 2) / pow(R,3) * pow(cos(teta), 3) ;
//    double fourth = - PV * U * V / pow(R, 2);
//    double fith =  PV * 2 * constants::ALPHA * sin(teta) * pow(cos(teta), 2) * pow(constants::R_0, 2) / pow(R,3);
//
//    double final = first * T + second * T + third * T + fourth * T + fith * T;
//    std::cout << "final = " << final << std::endl;
////   DY(7)= (-PU*A0*2.*R0**2.*1.d6/R**3.+  &
////          PU*alfa*2.*R0**2.*1.d6/R**3.*dcos(teta)**3. -  &
////          PV*U*V/R/R-PV*alfa*2.*R0**2.*1.d6/R**3.*  &
////		  dcos(teta)**2.*dsin(teta)+PFi*V/R/R)*T
//
//    std::cout << "dy[6] = " << dy[6] << std::endl;
//    std::cout << "PU * pow(V / R, 2) = " << PU * pow(V / R, 2) << std::endl;
//    std::cout << "- PU * 2 * constants::A_0 * pow(constants::R_0, 2) / pow(R,3) = " << - PU * 2 * constants::A_0 * pow(constants::R_0, 2) / pow(R,3) << std::endl;
//    std::cout << "PU * 2 * constants::ALPHA * pow(constants::R_0, 2) / pow(R,3) * pow(cos(teta), 3) = " << PU * 2 * constants::ALPHA * pow(constants::R_0, 2) / pow(R,3) * pow(cos(teta), 3) << std::endl;
//
//    std::cout << " - PV * U * V / pow(R, 2)= " <<  - PV * U * V / pow(R, 2) << std::endl;
//    std::
//
//
//    << " PV * 2 * constants::ALPHA * sin(teta) * pow(cos(teta), 2) * pow(constants::R_0, 2) / pow(R,3) " <<  PV * 2 * constants::ALPHA * sin(teta) * pow(cos(teta), 2) * pow(constants::R_0, 2) / pow(R,3) << std::endl;

//    std::cout << "pow(V / R, 2) = " << PU * pow(V / R, 2) << std::endl;
//    std::cout << "- 2 * constants::A_0 * pow(constants::R_0, 2) / pow(R,3) = " << (- 2 * constants::A_0 * pow(constants::R_0, 2) / pow(R,3)) * PU << std::endl;
//    std::cout << "2 * constants::ALPHA * pow(constants::R_0, 2) / pow(R,3) * pow(cos(teta), 3) = " << 2 * constants::ALPHA * pow(constants::R_0, 2) / pow(R,3) * pow(cos(teta), 3) * PU << std::endl;
//    std::cout << "pow(cos(teta), 3) = " << pow(cos(teta), 3)<< std::endl;
//    std::cout << "cos(teta) = " << cos(teta)<< std::endl;
//
//    std::cout << "- PV * (U * V / pow(R, 2)) = " << - PV * (U * V / pow(R, 2))<< std::endl;
//    std::cout << "- PV * (- 2 * constants::ALPHA * sin(teta) * pow(cos(teta), 2)\n"
//                 "            * pow(constants::R_0, 2) / pow(R,3))) = " <<- PV * (- 2 * constants::ALPHA * sin(teta) * pow(cos(teta), 2)
//                                                                                                      * pow(constants::R_0, 2) / pow(R,3))<< std::endl;
//
//
//
//
//    std::cout << "PU * pow(V / R, 2) - PU * 2 * constants::A_0 * pow(constants::R_0, 2) / pow(R,3)\n"
//                 "            + PU *2 * constants::ALPHA * pow(constants::R_0, 2) / pow(R,3) * pow(cos(teta), 3) = " << PU * pow(V / R, 2) - PU * 2 * constants::A_0 * pow(constants::R_0, 2) / pow(R,3)
//                                                                                                                        + PU *2 * constants::ALPHA * pow(constants::R_0, 2) / pow(R,3) * pow(cos(teta), 3)<< std::endl;
//    std::cout << "  - PV * U * V / pow(R, 2) + PV * 2 * constants::ALPHA * sin(teta) * pow(cos(teta), 2)\n"
//                 "            * pow(constants::R_0, 2) / pow(R,3) = " <<  - PV * U * V / pow(R, 2) + PV * 2 * constants::ALPHA * sin(teta) * pow(cos(teta), 2)
//                                                                                                     * pow(constants::R_0, 2) / pow(R,3) << std::endl;
//
//    std::cout << "PFi * V / pow(R, 2) = " << PFi * V / pow(R, 2) << std::endl;

    dy[7] = 0; // dPFi/dt

//    std::cout << "dy[0] = " << dy[0] << std::endl;
//    std::cout << "dy[1] = " << dy[1] << std::endl;
//    std::cout << "dy[2] = " << dy[2] << std::endl;
//    std::cout << "dy[3] = " << dy[3] << std::endl;
//    std::cout << "dy[4] = " << dy[4] << std::endl;
//    std::cout << "dy[5] = " << dy[5] << std::endl;
//    std::cout << "dy[6] = " << dy[6] << std::endl;
//    std::cout << "dy[7] = " << dy[7] << std::endl;

    // запишем функцию Понтрягина
    double H_PONTRYAGIN = (y[4] * dy[0] + y[5] * dy[1] + y[6] * dy[2] + y[7] * dy[3]) / T - 1;

    constants::result[step_number + 1][9] = H_PONTRYAGIN;
    constants::result[step_number + 1][10] = teta;
    constants::result[step_number + 1][11] = tetagrad;
    constants::result[step_number + 1][12] = x0 * constants::t1;

    std::cout << std::endl;
}

void getResidual(const std::vector<double> &x, std::vector<double> &residuals){
    // x - массив неизвестных
    // residuals - массив невязок
    // vector<double> x{PU / constants::PU_0, PV / constants::PV_0, PR / constants::PR_0, t1 / constants::t10};

    double iteration = 1000;
    std::cout << "RESIDUAL_FUNCTION" << std::endl;
    double X0 = 0;
    double delX = 1/iteration;
    double PU = x[0] * constants::PU_0;
    double PV = x[1] * constants::PV_0;
    double PR = x[2] * constants::PR_0;
    constants::t1 = x[3] * constants::t10;
    double PFi = 0;

    double teta = atan((3*PU - sqrt(9 * pow(PU, 2) + 8 * pow(PV, 2) )) / 4 / PV);
    double tetagrad= teta * 180 / M_PI;
// по слагаемым вывести todo
//    std::cout << "pow(constants::V_0, 2) / constants::R_0 = " << pow(constants::V_0, 2) / constants::R_0 << std::endl;
//    std::cout << "constants::A_0 + constants::ALPHA * pow(cos(teta),3) = " << constants::A_0 + constants::ALPHA * pow(cos(teta),3) << std::endl;
//    std::cout << "PU*(pow(constants::V_0, 2) / constants::R_0 - constants::A_0 + constants::ALPHA * pow(cos(teta),3)) = " << PU*(pow(constants::V_0, 2) / constants::R_0 - constants::A_0 + constants::ALPHA * pow(cos(teta),3))<< std::endl;
//    std::cout << "-constants::V_0 * constants::U_0/ constants::R_0 = " << -constants::V_0 * constants::U_0/ constants::R_0 << std::endl;
//    std::cout << "- constants::ALPHA * pow(cos(teta),2) * sin(teta) = " << - constants::ALPHA * pow(cos(teta),2) * sin(teta) << std::endl;
//    std::cout << "PV*(-constants::V_0 * constants::U_0/ constants::R_0 - constants::ALPHA * pow(cos(teta),2) * sin(teta)) = " << PV*(-constants::V_0 * constants::U_0/ constants::R_0 - constants::ALPHA * pow(cos(teta),2) * sin(teta)) << std::endl;
//    std::cout << "PR * constants::U_0 =  " << PR * constants::U_0 << std::endl;
//    std::cout << "PFi * (constants::V_0 / constants::R_0) =  " << PFi * (constants::V_0 / constants::R_0) << std::endl;
//

    double H_PONTRYAGIN =  PU*(pow(constants::V_0, 2) / constants::R_0 - constants::A_0 + constants::ALPHA * pow(cos(teta),3))
                           + PV*(-constants::V_0 * constants::U_0/ constants::R_0 - constants::ALPHA * pow(cos(teta),2) * sin(teta))
                           + PR * constants::U_0 + PFi * (constants::V_0 / constants::R_0) - 1;
// Hpontr=   &
//PU*(V0*V0/R0*1.d3-A0+alfa*dcos(teta)**3.)+ &
//  PV*(-V0*U0/R0*1.d3-alfa*(R0/R0)**2.*dcos(teta)**2.*dsin(teta))+  &
//	  PR*U0*1.d3+ PFi*(V0/R0)-1.d0
    std::cout << "H_PONTRYAGIN = " << H_PONTRYAGIN << std::endl;

    double tabs = X0 * constants::t1;

    vector<double> y{constants::U_0, constants::V_0, constants::R_0, constants::FiZ, PU, PV, PR, PFi};

    constants::result[0][9] = H_PONTRYAGIN; // todo не сошелся понтрягин
    constants::result[0][10] = teta;
    constants::result[0][11] = tetagrad;
    constants::result[0][12] = tabs;

    int exit_signal = 0;
    int step_counter = 0;
    int parametresNumber = 8;
    double firstTime = 0;

    RK4(subfunction, parametresNumber, iteration, firstTime, delX, y,
        exit_signal, step_counter, constants::result);

    residuals.resize(x.size());
    residuals[0] = constants::result[iteration][1];
    residuals[1] = (constants::result[iteration][2] - constants::V_F) / constants::V_F;
    residuals[2] = (constants::result[iteration][3] - constants::R_F) / constants::R_F;
    residuals[3] = constants::result[iteration][9];

    std::cout << std::endl;
}