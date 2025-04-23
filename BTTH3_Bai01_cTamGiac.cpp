#include <bits/stdc++.h>
#include "Diem.h"
#include "cTamGiac.h"
using namespace std;

int main()
{
    cTamGiac t;
    t.NhapTamGiac();
    t.TinhDoDaiCanhTamGiac();
    t.Kiemtra();
    cout << t.chuVi() << endl;
    cout << t.dienTich() << endl;
    cout << endl;
    t.TinhTien();
    cout << endl;
    t.Quay();
    cout << endl;
    t.PhongToThuNho();
    return 0;
    return 0;
}
/* Mẫy Input và Output
//Kiem tra lan 1
Nhap dinh A
Nhap toa do x : 2
Nhap toa do y : 3
Nhap dinh B
Nhap toa do x : 4
Nhap toa do y : 5
Nhap dinh C
Nhap toa do x : 6
Nhap toa do y : 7
Do dai 3 canh cua tam giac lan luot la : 2.82843 2.82843 5.65685
Khong ton tai tam giac

//Kiem tra lan 2
Nhap dinh A
Nhap toa do x : 1
Nhap toa do y : 4
Nhap dinh B
Nhap toa do x : 8.3
Nhap toa do y : 5
Nhap dinh C
Nhap toa do x : 6
Nhap toa do y : 1
Do dai 3 canh cua tam giac lan luot la : 7.36817 4.61411 5.83095
Tam giac ton tai
Phan loai : Tam giac thuong
17.8132
Dien tich tam giac : 13.45

Nhap khoang cach toa do tinh tien :4 5
Doi tam giac di mot doan (4,5) :
A: (5,9)
B: (12.3,10)
C: (10,6)

Nhap so do muon quay : 45
Nhap toa do diem muon quay quanh : 1 2
Toa do 3 diem sau khi quay
A(-1.12132,9.77817)
B(3.33345,15.6472)
C(4.53553,11.1924)

Nhap he so k (k>1:phong to, 0<k<1:thu nho) muon thay doi kich thuoc : 1.2
Ban chon phong to
Ban muon phong to/thu nho quanh diem nao ? Tra loi: 2 3
Toa do 3 dinh cua tam giac sau khi phong to/thu nho
A(-1.74558,11.1338)
B(3.60014,18.1766)
C(5.04264,12.8309)
*/
