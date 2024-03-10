#include "residuals.h"

void getResidual(const std::vector<double> &x, std::vector<double> &residuals){

}
//    void (*function)(
//        int dimension,
//        double x0,
//        vector<double> y,
//        vector<double>& dy,
//        int& exit_signal,
//        unsigned int step_number,
//		Matrix& result),
//    unsigned int dimension,
//    int steps,
//    double x0,
//    double dx,
//    vector<double> y,
//    int& exit_signal,
//    int& step_counter,
//    Matrix& result)



//subroutine HEBQZKI(N, XX, F)
//
// N      -  количество уравнений и неизвестных в системе уравнений
// XX(N)  -  массив неизвестных
//  F(N)   -  массив нев€зок
//
//implicit real*8 (a-h, o-z)
//
//real*8 XX(N), F(N), Y(8), Res(N5+1, 9)
//integer priznak
//
//common /all0/ U, V, U0, V0, R, Fi, PU0, PV0, PR0, PU, PV, PR, PFi, &
//t1, t10, VM, RM, FiM, &
//FiZ, alfa, epsd, A0, R0, Hpontr,  tabs,  Res1(1001, 13), N5
//        external RK4, FUN2, fun, dixotomy
//
//
//        N1=N5
//N6=8
//
//X0=0.d0
//delX=1.d0/N1
//PU=XX(1)*PU0
//PV=XX(2)*PV0
//PR=XX(3)*PR0
//
//
//t1=XX(4)*t10
//PFi=0.d0
//
//teta=datan((3.*PU-dsqrt(9.*PU*PU+8.*PV*PV))/4./PV)
//tetagrad=TETA*180./3.1415927
//
//T=t1*86400.d0
//Hpontr=   &
//                  PU*(V0*V0/R0*1.d3-A0*(R0/R0)**2.+alfa*(R0/R0)**2.*dcos(teta)**3.)+ &
//                                                                                             PV*(-V0*U0/R0*1.d3-alfa*(R0/R0)**2.*dcos(teta)**2.*dsin(teta))+  &
//                                                                                                                                                                      PR*U0*1.d3+ PFi*(V0/R0)-1.d0
//tabs=X0*t1
//
//Y(1)=U0*1.d3
//Y(2)=V0*1.d3
//Y(3)=R0*1.d3
//Y(4)=FiZ
//        Y(5)=PU
//        Y(6)=PV
//        Y(7)=PR
//        Y(8)=PFi
//
//        Res=0.d0
//
//RES1(1,10)=Hpontr   ! запись дополнительных переменных
//        RES1(1,11)=TETA  ! запись дополнительных переменных
//        RES1(1,12)=TETAgrad  ! запись дополнительных переменных
//        RES1(1,13)=tabs     ! запись дополнительных переменных
//
//
//        call RK4(FUN2, N6, N1, X0, delX, Y, priznak, Nstep, RES)
//
//
//
//do i=1, N1+1
//do j=1, N6+1
//Res1(i,j)=Res(i,j)
//end do
//end do
//
//F(1)=Y(1)/1.d0
//F(2)=(Y(2)-VM*1000.d0)/(VM*1000.d0)
//F(3)=(Y(3)-RM*1000.d0)/(RM*1000.d0)
//F(4)=Hpontr/1.d0
//
//end