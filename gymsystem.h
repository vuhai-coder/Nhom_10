#pragma once
#include "member.h"
#include "trainer.h"
#include "package.h"
#include "workout.h"

class GymSystem {
private:
    member m[100];
    trainer t[50];
    Package p[50];
    Workout w[100];

    int nm;
    int nt;
    int np;
    int nw;

public:
    GymSystem();

    void menu();
    void menuMember();
    void menuTrainer();
    void menuPackage();
    void menuWorkout();

    void nhapMember();
    void xuatMember();
    void timMember();
    void xoaMember();
    void suaMember();

    void nhapTrainer();
    void xuatTrainer();

    void nhapPackage();
    void xuatPackage();

    void nhapWorkout();
    void xuatWorkout();
};
