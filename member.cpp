#include "member.h"
#include <iostream>
#include <iomanip>
using namespace std;

member::member() : weight(0), height(0), goiindex(-1), trainerIndex(-1), soWorkout(0) {
    for (int i = 0; i < 100; i++) {
        dsWorkout[i] = -1;
    }
}

void member::setWeight(float w) {
    weight = w;
}

void member::setHeight(float h) {
    height = h;
}

float member::getWeight() {
    return weight;
}

float member::getHeight() {
    return height;
}

void member::chongoi(int index) {
    goiindex = index;
}

int member::laygoi() {
    return goiindex;
}

void member::chonTrainer(int index) {
    trainerIndex = index;
}

int member::layTrainer() {
    return trainerIndex;
}

void member::themWorkout(int index) {
    if (soWorkout < 100) {
        dsWorkout[soWorkout] = index;
        soWorkout++;
    }
}

int member::laySoWorkout() {
    return soWorkout;
}

int member::layWorkoutTai(int vitri) {
    if (vitri >= 0 && vitri < soWorkout) {
        return dsWorkout[vitri];
    }
    return -1;
}

void member::resetWorkout() {
    soWorkout = 0;
    for (int i = 0; i < 100; i++) {
        dsWorkout[i] = -1;
    }
}

void member::nhap() {
    person::nhap();

    cout << "Nhap can nang: ";
    while (!(cin >> weight) || weight <= 0) {
        cin.clear();
        cin.ignore();
        cout << "Nhap lai can nang: ";
    }

    cout << "Nhap chieu cao: ";
    while (!(cin >> height) || height <= 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Nhap lai chieu cao: ";
    }
}

float member::tinhBMI() {
    if (height == 0) return 0;
    return weight / (height * height);
}

void member::xuat() {
    cout << left
        << setw(15) << getID()
        << setw(20) << getName()
        << setw(10) << getAge()
        << setw(12) << weight
        << setw(12) << height
        << setw(10) << tinhBMI()
        << endl;
}
