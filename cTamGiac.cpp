#include "cTamGiac.h"
#include "Diem.h"
#include <bits/stdc++.h>
using namespace std;
cTamGiac::cTamGiac(){}
cTamGiac::cTamGiac(Diem A, Diem  B, Diem C): A(A),B(B), C(C){
    this->canh1 = 0;
    this->canh2 = 0;
    this->canh3 = 0;
}
void cTamGiac::NhapTamGiac(){
    cout << "Nhap dinh A " << endl;
    A.Nhap();
    cout << "Nhap dinh B " << endl;
    B.Nhap();
    cout << "Nhap dinh C " << endl;
    C.Nhap();
}
void cTamGiac::TinhDoDaiCanhTamGiac(){
    canh1 = A.kc(B);
    canh2 = B.kc(C);
    canh3 = C.kc(A);
    cout << "Do dai 3 canh cua tam giac lan luot la : " << canh1 << " " <<canh2 << " " << canh3 << endl;
}
void cTamGiac::Kiemtra(){
    //Kiểm tra điều kiện tồn tại tam giác
        if(((canh1+canh2)>canh3) && ((canh1+canh3)>canh2) && ((canh2+canh3)>canh1)){
            cout << "Tam giac ton tai" << endl;
        }
        else {
            cout << "Khong ton tai tam giac" << endl;
            exit(0);
        }
        //Phân loại tam giác
        bool ktVuongCan = false;
        bool ktThuong = true;
        if(canh1 == canh2 && canh2 == canh3){
            cout << "Phan loai : tam giac deu" << endl;
            ktThuong = false;
        }
        else if((canh1==canh2 && canh1==canh3 && canh2 != canh3) || (canh2==canh1 && canh2==canh3 && canh1 != canh3) || (canh3==canh1 && canh3==canh2 && canh1 != canh2)){
            cout << "Phan loai : Tam giac can" << endl;
            ktVuongCan = true;
            ktThuong = false;
        }
        if((pow(canh1,2)+pow(canh2,2)==pow(canh3,2))&&(pow(canh1,2)+pow(canh3,2)==pow(canh2,2)) && (pow(canh2,2)+pow(canh3,2)==pow(canh1,2))){
            cout << "Phan loai : Tam giac vuong" << endl;
            ktThuong = false;
            if(!ktVuongCan){
                cout << "=>Vay tam giac vua vuong vua can la tam giac vuong can" << endl;
            }
        }
        if(ktThuong){
            cout << "Phan loai : Tam giac thuong" << endl;
        }
}
double cTamGiac::chuVi(){
    return (canh1+canh2+canh3);
}
double cTamGiac::dienTich(){
    double p = (canh1+canh2+canh3)/2.0;
    cout << "Dien tich tam giac : ";
    return sqrt(p*(p-canh1)*(p-canh2)*(p-canh3));
}
void cTamGiac::TinhTien(){
    double dx, dy;
    cout << "Nhap khoang cach toa do tinh tien :";
    cin >> dx>>dy;
    A.TinhTien(dx,dy);
    B.TinhTien(dx,dy);
    C.TinhTien(dx,dy);
    cout << "Doi tam giac di mot doan (" <<dx<<","<<dy<<") : " << endl;
    cout << "A: ";A.Xuat();
    cout << "B: ";B.Xuat();
    cout << "C: ";C.Xuat();
}
Diem cTamGiac::CongThucQuayQuanhDiem(Diem P,double do_radian, Diem O){
    //Dời điểm quay về gốc tọa độ
    double x = P.getX() - O.getX();
    double y = P.getY() - O.getY();

    double xResult = x*cos(do_radian) - y*sin(do_radian);
    double yResult = x*sin(do_radian) + y*cos(do_radian);

    return Diem(xResult+O.getX(),yResult+O.getY());
}
void cTamGiac::Quay(){
    double do_radian;
    cout<< "Nhap so do muon quay : ";
    cin >> do_radian;
    do_radian = do_radian*M_PI/180.0;
    double x0, y0;
    cout << "Nhap toa do diem muon quay quanh : ";
    cin >> x0 >> y0;
    Diem tam(x0,y0);
    A = CongThucQuayQuanhDiem(A,do_radian,tam);
    B = CongThucQuayQuanhDiem(B,do_radian,tam);
    C = CongThucQuayQuanhDiem(C,do_radian,tam);
    cout << "Toa do 3 diem sau khi quay" <<endl;
    cout << "A";A.Xuat();
    cout << "B";B.Xuat();
    cout << "C";C.Xuat();
}
Diem cTamGiac::ZoomInZoomOut(Diem u,double k, Diem p){
    return Diem((u.getX()-p.getX())*k+p.getX(),(u.getY()-p.getY())*k+p.getY());
}
void cTamGiac::PhongToThuNho(){
    //Nhập tỷ lệ k
    double k;
    cout << "Nhap he so k (k>1:phong to, 0<k<1:thu nho) muon thay doi kich thuoc : ";
    while(true){
        cin >> k;
        if(k>1) {
          cout <<"Ban chon phong to"  <<endl;
          break;
        }
        else if(k > 0 && k < 1) {
          cout << "Ban chon thu nho" << endl;
          break;
        }
        else if(k == 1) {
          cout << "Khong co thay doi kich thuoc (k = 1)" << endl;
          break;
        }
        else {
          cout << "He so k khong hop le! Nhap lai: ";
        }
    }
    //Nhập điểm tùy ý P(px,py)
    double px, py;
    cout << "Ban muon phong to/thu nho quanh diem nao ? Tra loi: ";
    cin >> px>>py;
    Diem P(px,py);
    A = ZoomInZoomOut(A, k, P);
    B = ZoomInZoomOut(B, k, P);
    C = ZoomInZoomOut(C, k, P);
    //Thực hiện phóng to/thu nhỏ với hệ số tỷ lệ k quanh điểm P(px,py)
    cout << "Toa do 3 dinh cua tam giac sau khi phong to/thu nho"<<endl;
    cout << "A";A.Xuat();
    cout << "B";B.Xuat();
    cout << "C";C.Xuat();
}
cTamGiac::~cTamGiac(){}

