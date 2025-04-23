#ifndef CTAMGIAC_H
#define CTAMGIAC_H
#include "Diem.h"
#include <bits/stdc++.h>
using namespace std;

class cTamGiac
{
    public:
        cTamGiac();
        cTamGiac(Diem A, Diem  B, Diem C);
        void NhapTamGiac();
        void TinhDoDaiCanhTamGiac();
        void Kiemtra();
        double chuVi();
        double dienTich();
        void TinhTien();
        Diem CongThucQuayQuanhDiem(Diem P,double do_radian, Diem O);
        void Quay();
        Diem ZoomInZoomOut(Diem u,double k, Diem P);
        void PhongToThuNho();
        virtual ~cTamGiac();
    private:
        Diem A;
        Diem B;
        Diem C;
        double canh1, canh2,canh3;
};

#endif // CTAMGIAC_H
