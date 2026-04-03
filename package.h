#pragma once
#include <string>
using namespace std;

class Package {
private:
    string id;
    string name;
    float price;
    int thoihan;

public:
    Package();
    void nhap();
    void xuat();
    string getID();
    string getName();
    float getPrice();
    int getthoihan();
};