#include "person.h"
#include <iostream>
#include <iomanip>
using namespace std;

person::person() {
    id = 0;
    name = "";
    age = 0;
}

void person::setID(int s) {
    id = s;
}

void person::setName(string n) {
    name = n;
}

void person::setAge(int a) {
    age = a;
}

void person::nhap() {
    cout << "Nhap ID: ";
    while (!(cin >> id) || id < 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Nhap lai ID: ";
    }

    cin.ignore(1000, '\n');

    cout << "Nhap ten: ";
    getline(cin, name);
    while (name.empty()) {
        cout << "Nhap lai ten: ";
        getline(cin, name);
    }

    cout << "Nhap tuoi: ";
    while (!(cin >> age) || age <= 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Nhap lai tuoi: ";
    }
}

void person::xuat() {
    cout << left
        << setw(10) << id
        << setw(20) << name
        << setw(10) << age
        << endl;
}

int person::getID() {
    return id;
}

string person::getName() {
    return name;
}

int person::getAge() {
    return age;
}
