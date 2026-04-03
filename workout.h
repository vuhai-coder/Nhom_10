#pragma once
#include <string>
using namespace std;

class Workout {
private:
    string tenBaiTap;
    string nhomBaiTap;
    int thoiGian;
public:
    string chonNhomBaiTap();
    string chonTenBaiTapTheoNhom(string nhom);
    int nhapSoNguyenDuong();
    void nhap();
    double layCaloMoiPhut();
    double tinhCalo();
    void hienThi();
};