#include "Diem.h"
#include "cTamGiac.h"
#include <bits/stdc++.h>
using namespace std;
Diem::Diem(){}
 Diem::Diem(double x, double y) : x(x), y(y){}
void Diem::Nhap(){
    cout << "Nhap toa do x : "; cin >> x;
    cout << "Nhap toa do y : "; cin >> y;
}
double Diem::getX(){
    return x;
}
double Diem::getY(){
    return y;
}
double Diem::kc(Diem u){
    return sqrt(pow(u.x - x,2)+pow(u.y - y, 2));
}
void Diem::Xuat(){
    cout << "(" << x << "," << y << ")" << endl;
}
void Diem::TinhTien(double dx, double dy) {
    x += dx;
    y += dy;
}
Diem::~Diem(){}
