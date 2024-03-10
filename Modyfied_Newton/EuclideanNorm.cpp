#include "EuclideanNorm.h"
#include <cmath>

// Вычисление евклидовой нормы
// Входные параметры residuals - вектор невязок
// Результат norm - евклидова норма

double getEuclideanNorm(std::vector<double>& residuals){
    double norm = 0;
    for (int i = 0; i < residuals.size(); i++)
        norm += residuals[i] * residuals[i];
    norm = sqrt(norm);
    return norm;
}