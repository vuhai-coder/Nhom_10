#pragma once
#include "person.h"

class member : public person {
private:
    float weight;
    float height;
    int goiindex;
    int trainerIndex;
    int dsWorkout[100];
    int soWorkout;

public:
    member();

    void setWeight(float w);
    void setHeight(float h);

    float getWeight();
    float getHeight();

    void chongoi(int index);
    int laygoi();

    void chonTrainer(int index);
    int layTrainer();

    void themWorkout(int index);
    int laySoWorkout();
    int layWorkoutTai(int vitri);

    void nhap();
    void xuat();
    float tinhBMI();
};
