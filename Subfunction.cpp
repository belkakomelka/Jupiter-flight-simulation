#include "Subfunction.h"
#include <fstream>

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
    dy[7] = 0; // dPFi/dt

    // запишем функцию Понтрягина
    double H_PONTRYAGIN = (y[4] * dy[0] + y[5] * dy[1] + y[6] * dy[2] + y[7] * dy[3]) / T - 1;

    constants::result[step_number + 1][9] = H_PONTRYAGIN;
    constants::result[step_number + 1][10] = teta;
    constants::result[step_number + 1][11] = tetagrad;
    constants::result[step_number + 1][12] = x0 * constants::t1;

}

void getResidual(const std::vector<double> &x, std::vector<double> &residuals){
    // x - массив неизвестных
    // residuals - массив невязок
    // vector<double> x{PU / constants::PU_0, PV / constants::PV_0, PR / constants::PR_0, t1 / constants::t10};

    double iteration = 1000;
    double X0 = 0;
    double delX = 1/iteration;
    double PU = x[0] * constants::PU_0;
    double PV = x[1] * constants::PV_0;
    double PR = x[2] * constants::PR_0;
    constants::t1 = x[3] * constants::t10;

//    for (int i = 0; i < 4; i++){
//        std::cout << x[i] << " ";
//    }
//    std::cout << std::endl;

    double PFi = 0;

    double teta = atan((3*PU - sqrt(9 * pow(PU, 2) + 8 * pow(PV, 2) )) / 4 / PV);
    double tetagrad= teta * 180 / M_PI;

    double H_PONTRYAGIN =  PU*(pow(constants::V_0, 2) / constants::R_0 - constants::A_0 + constants::ALPHA * pow(cos(teta),3))
                           + PV*(-constants::V_0 * constants::U_0/ constants::R_0 - constants::ALPHA * pow(cos(teta),2) * sin(teta))
                           + PR * constants::U_0 + PFi * (constants::V_0 / constants::R_0) - 1;

    double tabs = X0 * constants::t1;

    vector<double> y{constants::U_0, constants::V_0, constants::R_0, constants::FiZ, PU, PV, PR, PFi};

    constants::result[0][9] = H_PONTRYAGIN;
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

    std::ofstream fout;
    fout.open("jup_perigeliy_res.csv", std::ios_base::app);
    fout << "RK4 result:" << std::endl;
    fout.setf(std::ios::left);
    //fout.width(14);
    fout << "t,";
   // fout.width(14);
    fout << "u,";
   // fout.width(14);
    fout << "v,";
   // fout.width(14);
    fout << "R,";
   // fout.width(14);
    fout << "phi,";
  //  fout.width(14);
    fout << "psi_u,";
  //  fout.width(14);
    fout << "psi_v,";
  //  fout.width(14);
    fout << "psi_R,";
   // fout.width(14);
    fout << "psi_phi,";
  //  fout.width(14);
    fout << "H,";
  //  fout.width(14);
    fout << "Teta,";
   // fout.width(14);
    fout << "TetaGrad,";
   // fout.width(14);
    fout << "t_abs" << '\n';
    for (int i = 0; i <= iteration; i++)
    {
        for (int j = 0; j < 13; j++)
        {
//            fout.precision(6);
//            fout.width(14);
            fout << constants::result[i][j];
            if (j != 12){
                fout << ",";
            }
        }
        fout << '\n';
    }
    fout << '\n';

//    fout << "Residuals: " << std::endl;
//    fout.width(12);
//    fout << "u";
//    fout.width(12);
//    fout << "v";
//    fout.width(12);
//    fout << "R";
//    fout.width(12);
//    fout << "H";
//    fout << std::endl;
//    for (auto residual : residuals)
//    {
//        fout.precision(6);
//        fout.width(12);
//        fout << residual;
//    }
//    fout << std::endl << std::endl;
//    fout.close();

//
//    for (int i = 0; i < 4; i++){
//        std::cout << residuals[i] << " ";
//    }
//    std::cout << std::endl;
}