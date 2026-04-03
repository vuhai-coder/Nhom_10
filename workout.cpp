#include "workout.h"
#include <iostream>
#include <iomanip>
using namespace std;

string Workout::chonNhomBaiTap() {
    int chon;
    while (true) {
        cout << "1. Nhom nguc\n";
        cout << "2. Nhom lung\n";
        cout << "3. Nhom chan\n";
        cout << "4. Nhom vai\n";
        cout << "5. Nhom tay truoc\n";
        cout << "6. Nhom tay sau\n";
        cout << "7. Nhom bung\n";
        cout << "Chon nhom: ";
        cin >> chon;

        if (cin.fail() || chon < 1 || chon > 7) {
            cout << "Sai! Nhap lai!\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        cin.ignore(1000, '\n');

        if (chon == 1) return "Nguc";
        if (chon == 2) return "Lung";
        if (chon == 3) return "Chan";
        if (chon == 4) return "Vai";
        if (chon == 5) return "Tay truoc";
        if (chon == 6) return "Tay sau";
        return "Bung";
    }
}

// ===================== CHON BAI TAP =====================

string Workout::chonTenBaiTapTheoNhom(string nhom) {
    int chon;

    if (nhom == "Nguc") {
        while (true) {
            cout << "1. Day nguc\n2. Day nguc tren\n3. Chong day\nNhap: ";
            cin >> chon;

            if (cin.fail() || chon < 1 || chon > 3) {
                cout << "Sai! Nhap lai!\n";
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }

            cin.ignore(1000, '\n');

            if (chon == 1) return "Day nguc";
            if (chon == 2) return "Day nguc tren";
            return "Chong day";
        }
    }

    if (nhom == "Lung") {
        while (true) {
            cout << "1. Hit xa\n2. Keo xuong\n3. Keo ta don\nNhap: ";
            cin >> chon;

            if (cin.fail() || chon < 1 || chon > 3) {
                cout << "Sai! Nhap lai!\n";
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }

            cin.ignore(1000, '\n');

            if (chon == 1) return "Hit xa";
            if (chon == 2) return "Keo xuong";
            return "Keo ta don";
        }
    }

    if (nhom == "Chan") {
        while (true) {
            cout << "1. Squat\n2. Day chan\n3. Lunges(Buoc chung chan)\nNhap: ";
            cin >> chon;

            if (cin.fail() || chon < 1 || chon > 3) {
                cout << "Sai! Nhap lai!\n";
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }

            cin.ignore(1000, '\n');

            if (chon == 1) return "Squat";
            if (chon == 2) return "Day chan";
            return "Lunges(Buoc chung chan)";
        }
    }

    if (nhom == "Vai") {
        while (true) {
            cout << "1. Day vai\n2. Nang ngang\n3. Nang truoc\nNhap: ";
            cin >> chon;

            if (cin.fail() || chon < 1 || chon > 3) {
                cout << "Sai! Nhap lai!\n";
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }

            cin.ignore(1000, '\n');

            if (chon == 1) return "Day vai";
            if (chon == 2) return "Nang ngang";
            return "Nang truoc";
        }
    }

    if (nhom == "Tay truoc") {
        while (true) {
            cout << "1. Gap tay truoc\n2. Gap ta don\n3. Hammer Curl(Cuon ta kieu bua)\nNhap: ";
            cin >> chon;

            if (cin.fail() || chon < 1 || chon > 3) {
                cout << "Sai! Nhap lai!\n";
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }

            cin.ignore(1000, '\n');

            if (chon == 1) return "Gap tay truoc";
            if (chon == 2) return "Gap ta don";
            return "Hammer Curl(Cuon ta kieu bua)";
        }
    }

    if (nhom == "Tay sau") {
        while (true) {
            cout << "1. Day cap\n2. Dips\n3. Day qua dau\nNhap: ";
            cin >> chon;

            if (cin.fail() || chon < 1 || chon > 3) {
                cout << "Sai! Nhap lai!\n";
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }

            cin.ignore(1000, '\n');

            if (chon == 1) return "Day cap";
            if (chon == 2) return "Dips";
            return "Day qua dau";
        }
    }

    if (nhom == "Bung") {
        while (true) {
            cout << "1. Plank\n2. Gap bung\n3. Nang chan\nNhap: ";
            cin >> chon;

            if (cin.fail() || chon < 1 || chon > 3) {
                cout << "Sai! Nhap lai!\n";
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }

            cin.ignore(1000, '\n');

            if (chon == 1) return "Plank";
            if (chon == 2) return "Gap bung";
            return "Nang chan";
        }
    }

    return "";
}

// ===================== NHAP =====================

int Workout::nhapSoNguyenDuong() {
    int x;
    while (true) {
        cout << "Nhap thoi gian (phut): ";
        cin >> x;

        if (cin.fail() || x <= 0) {
            cout << "Sai! Nhap lai!\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        cin.ignore(1000, '\n');
        return x;
    }
}

void Workout::nhap() {
    nhomBaiTap = chonNhomBaiTap();
    tenBaiTap = chonTenBaiTapTheoNhom(nhomBaiTap);
    thoiGian = nhapSoNguyenDuong();
}

// ===================== CALO =====================

double Workout::layCaloMoiPhut() {
    if (tenBaiTap == "Day nguc") return 8;
    if (tenBaiTap == "Day nguc tren") return 7;
    if (tenBaiTap == "Chong day") return 6;

    if (tenBaiTap == "Hit xa") return 8;
    if (tenBaiTap == "Keo xuong") return 7;
    if (tenBaiTap == "Keo ta don") return 8;

    if (tenBaiTap == "Squat") return 9;
    if (tenBaiTap == "Day chan") return 8;
    if (tenBaiTap == "Lunges(Buoc chung chan)") return 8;

    if (tenBaiTap == "Day vai") return 7;
    if (tenBaiTap == "Nang ngang") return 5;
    if (tenBaiTap == "Nang truoc") return 5;

    if (tenBaiTap == "Gap tay truoc") return 4;
    if (tenBaiTap == "Gap ta don") return 5;
    if (tenBaiTap == "Hammer Curl(Cuon ta kieu bua)") return 5;

    if (tenBaiTap == "Day cap") return 5;
    if (tenBaiTap == "Dips") return 8;
    if (tenBaiTap == "Day qua dau") return 5;

    if (tenBaiTap == "Plank") return 4;
    if (tenBaiTap == "Gap bung") return 5;
    if (tenBaiTap == "Nang chan") return 6;

    return 0;
}

double Workout::tinhCalo() {
    return thoiGian * layCaloMoiPhut();
}

// ===================== HIEN THI =====================

void Workout::hienThi() {
    cout << left
        << setw(30) << tenBaiTap
        << setw(15) << nhomBaiTap
        << setw(10) << thoiGian
        << setw(15) << layCaloMoiPhut()
        << setw(10) << tinhCalo()
        << endl;
}