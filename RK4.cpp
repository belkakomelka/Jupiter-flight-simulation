#include "RK4.h"

void RK4(
    void (*subfunction)(
        int dimension,
        double x0,
        const vector<double>& y,
        vector<double>& dy,
        int& exit_signal,
        unsigned int step_number,
		Matrix& result),
    unsigned int dimension_rk,
    int steps,
    double x0,
    double dx,
    vector<double> y,
    int& exit_signal,
    int& step_counter,
    Matrix& result)
{
    step_counter = 0;
    double x = x0;
    exit_signal = 0;

    vector<double> ak1(dimension_rk, 0);
    vector<double> ak2(dimension_rk, 0);
    vector<double> ak3(dimension_rk, 0);
    vector<double> ak4(dimension_rk, 0);
    vector<double> y1(dimension_rk, 0);

    //result = Matrix(steps + 1, vector<double>(dimension_rk + 5, 0));

    result[0][0] = x; // относительно время

    std::cout << "RK4_FUNCTION" << std::endl;

    for (int i = 0; i < dimension_rk; i++)
        result[0][i + 1] = y[i];

    vector<double> dy(dimension_rk, 0);

    for (int i = 0; i < steps; i++)
	{
        subfunction(dimension_rk, x, y, dy, exit_signal, step_counter, result);
        if (exit_signal == 1)
            break;
        for (int j = 0; j < dimension_rk; j++)
		{
            ak1[j] = dx * dy[j];
            y1[j] = y[j] + ak1[j] / 2.0;
        }

        double x1 = x + dx / 2.0;

        subfunction(dimension_rk, x1, y1, dy, exit_signal, step_counter, result);
        for (int j = 0; j < dimension_rk; j++)
		{
            ak2[j] = dx * dy[j];
            y1[j] = y[j] + ak2[j] / 2.0;
        }

        subfunction(dimension_rk, x1, y1, dy, exit_signal, step_counter, result);
        for (int j = 0; j < dimension_rk; j++)
		{
            ak3[j] = dx * dy[j];
            y1[j] = y[j] + ak3[j];
        }

        subfunction(dimension_rk, x + dx, y1, dy, exit_signal, step_counter, result);

        result[i + 1][0] = x + dx;

		for (int j = 0; j < dimension_rk; j++)
		{
            ak4[j] = dx * dy[j];
            y[j] += (ak1[j] + 2.0 * ak2[j] + 2.0 * ak3[j] + ak4[j]) / 6.0;
            result[i + 1][j + 1] = y[j];
        }

        std::cout << std::endl;
        x += dx;
        step_counter++;

        std::cout << std::endl;
        std::cout << "RESULT" << std::endl;
        for (int j = 0; j < 12; j++){
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;

    }
    std::cout << std::endl;
}