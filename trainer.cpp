#include "trainer.h"
#include <iostream>
#include <iomanip>
using namespace std;

trainer::trainer() {
    chuyenMon = "";
}

void trainer::nhap() {
    person::nhap();
    cin.ignore();
    cout << "Nhap chuyen mon: ";
    getline(cin, chuyenMon);
    while (chuyenMon.empty()) {
        cout << "Nhap lai chuyen mon: ";
        getline(cin, chuyenMon);
    }
}

void trainer::xuat() {
    cout << left
        << setw(15) << getID()
        << setw(15) << getName()
        << setw(10) << getAge()
        << setw(20) << chuyenMon
        << endl;
}

string trainer::getChuyenMon() {
    return chuyenMon;
}