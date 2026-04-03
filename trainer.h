#pragma once
#include "person.h"
#include <string>
using namespace std;

class trainer : public person {
private:
    string chuyenMon;

public:
    trainer();
    void nhap();
    void xuat();

    string getChuyenMon();
};