#pragma once
#include <string>
using namespace std;

class person {
protected:
    int id;
    string name;
    int age;

public:
    person();
    void nhap();
    void xuat();

    int getID();
    string getName();
    int getAge();

    void setID(int s);
    void setName(string s);
    void setAge(int a);
};