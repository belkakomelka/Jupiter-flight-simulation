#ifndef GAUSS_MODYFIED_NEWTON_H
#define GAUSS_MODYFIED_NEWTON_H

#include <algorithm>

#include "gauss.h"
#include "iterSystemSolver.h"

// ������� ������� ���������� �������������� ���������
//
// ������� ���������
//		getResidual - ������� ���������� �������
//		dimension   - ���������� ���������� ����������
//		x           - ��������� ����������
//		residuals   - ������� (��������� ������)
//		iteration   - ����� ��������
//
void newtonModyfied(
    void (*getResidual) (
        const vector<double>&,
        vector<double>&),
    unsigned int dimension,
    vector<double>& x,
    vector<double>& residuals,
    int& iteration);

#endif //GAUSS_MODYFIED_NEWTON_H
