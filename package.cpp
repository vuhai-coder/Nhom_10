#include "package.h"
#include <iostream>
#include <iomanip>
using namespace std;

Package::Package() {
    id = "";
    name = "";
    price = 0;
    thoihan = 0;
}

void Package::nhap() {
    cout << "Nhap ID goi: ";
    getline(cin, id);
    while (id.empty()) {
        cout << "Nhap lai ID goi: ";
        getline(cin, id);
    }

    cout << "Nhap ten goi: ";
    getline(cin, name);
    while (name.empty()) {
        cout << "Nhap lai ten goi: ";
        getline(cin, name);
    }

    cout << "Nhap gia: ";
    while (!(cin >> price) || price <= 0) {
        cin.ignore();
        cout << "Nhap lai gia: ";
    }

    cout << "Nhap thoi han (thang): ";
    while (!(cin >> thoihan) || thoihan <= 0) {
        cin.ignore();
        cout << "Nhap lai thoi han: ";
    }
    cin.ignore();
}

void Package::xuat() {
    cout << left
        << setw(15) << id
        << setw(20) << name
        << setw(12) << price
        << setw(10) << thoihan
        << endl;
}

string Package::getID() {
    return id;
}

string Package::getName() {
    return name;
}

float Package::getPrice() {
    return price;
}

int Package::getthoihan() {
    return thoihan;
}
