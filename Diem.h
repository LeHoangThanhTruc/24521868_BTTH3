#ifndef DIEM_H
#define DIEM_H
#include <bits/stdc++.h>
using namespace std;

class Diem
{
    public:
        Diem();
        Diem(double x, double y);
        void Nhap();
        double getX();
        double getY();
        double kc(Diem u);
        void Xuat();
        void TinhTien(double dx, double dy);
        virtual ~Diem();
    private:
        double x, y;
};

#endif // DIEM_H
