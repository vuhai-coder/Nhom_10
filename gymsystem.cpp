#include "gymsystem.h"
#include <iostream>
#include <iomanip>
using namespace std;

GymSystem::GymSystem() {
    nm = 0;
    nt = 0;
    np = 0;
    nw = 0;
}

void GymSystem::nhapMember() {
    if (np == 0) {
        cout << "Chua co goi nao. Hay nhap package truoc.\n";
        return;
    }

    if (nt == 0) {
        cout << "Chua co trainer nao. Hay nhap trainer truoc.\n";
        return;
    }

    if (nw == 0) {
        cout << "Chua co workout nao. Hay nhap workout truoc.\n";
        return;
    }

    int sl;
    cout << "Nhap so luong member: ";
    while (!(cin >> sl) || sl <= 0 || nm + sl > 100) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Nhap lai so luong member: ";
    }

    for (int i = 0; i < sl; i++) {
        cout << "\n--- Nhap member thu " << nm + 1 << " ---\n";
        m[nm].nhap();

        cout << "\n=== DANH SACH GOI ===\n";
        for (int j = 0; j < np; j++) {
            cout << "Goi so " << j << ":\n";
            p[j].xuat();
            cout << "------------------\n";
        }

        int chonGoi;
        do {
            cout << "Chon goi (0 -> " << np - 1 << "): ";
            cin >> chonGoi;
        } while (chonGoi < 0 || chonGoi >= np);
        m[nm].chongoi(chonGoi);

        cout << "\n=== DANH SACH TRAINER ===\n";
        for (int j = 0; j < nt; j++) {
            cout << "Trainer so " << j << ":\n";
            t[j].xuat();
            cout << "------------------\n";
        }

        int chonTrainer;
        do {
            cout << "Chon trainer (0 -> " << nt - 1 << "): ";
            cin >> chonTrainer;
        } while (chonTrainer < 0 || chonTrainer >= nt);
        m[nm].chonTrainer(chonTrainer);

        cout << "\n=== DANH SACH WORKOUT ===\n";
        for (int j = 0; j < nw; j++) {
            cout << j << ". ";
            w[j].hienThi();
        }

        int soLuongWorkoutChon;
        cout << "Nhap so workout muon chon: ";
        while (!(cin >> soLuongWorkoutChon) || soLuongWorkoutChon <= 0 || soLuongWorkoutChon > nw) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Nhap lai so workout muon chon: ";
        }

        for (int k = 0; k < soLuongWorkoutChon; k++) {
            int chonWorkout;
            do {
                cout << "Chon workout thu " << k + 1 << " (0 -> " << nw - 1 << "): ";
                cin >> chonWorkout;
            } while (chonWorkout < 0 || chonWorkout >= nw);

            m[nm].themWorkout(chonWorkout);
        }

        nm++;
    }
}

void GymSystem::xuatMember() {
    if (nm == 0) {
        cout << "Danh sach member rong.\n";
        return;
    }

    cout << "\n============================== DANH SACH MEMBER ==============================\n";
    cout << left
        << setw(10) << "ID"
        << setw(20) << "Ten"
        << setw(10) << "Tuoi"
        << setw(12) << "Can nang"
        << setw(12) << "Chieu cao"
        << setw(12) << "BMI"
        << setw(12) << "Goi"
        << setw(12) << "Trainer"
        << endl;

    for (int i = 0; i < nm; i++) {
        cout << left
            << setw(10) << m[i].getID()
            << setw(20) << m[i].getName()
            << setw(10) << m[i].getAge()
            << setw(12) << m[i].getWeight()
            << setw(12) << m[i].getHeight()
            << setw(12) << m[i].tinhBMI();

        int idxGoi = m[i].laygoi();
        if (idxGoi >= 0 && idxGoi < np) {
            string goi = p[idxGoi].getName() +
                "(" + to_string(p[idxGoi].getthoihan()) + " thang)";
            cout << setw(12) << goi;
        }
        else {
            cout << setw(12) << "Chua chon";
        }

        int idxTrainer = m[i].layTrainer();
        if (idxTrainer >= 0 && idxTrainer < nt)
            cout << setw(12) << t[idxTrainer].getName();
        else
            cout << setw(12) << "Chua chon";
        cout << endl;
        cout << "   Workout: ";
        int sw = m[i].laySoWorkout();
        if (sw == 0) {
            cout << "Chua chon workout nao.";
        }
        else {
            for (int j = 0; j < sw; j++) {
                int idxWorkout = m[i].layWorkoutTai(j);
                if (idxWorkout >= 0 && idxWorkout < nw) {
                    cout << "[" << idxWorkout << "] ";
                }
            }
        }
        cout << endl;
    }
}

void GymSystem::timMember() {
    if (nm == 0) {
        cout << "Chua co member nao.\n";
        return;
    }

    int id;
    cout << "Nhap ID can tim: ";
    cin >> id;

    for (int i = 0; i < nm; i++) {
        if (m[i].getID() == id) {
            cout << "Tim thay member:\n";
            m[i].xuat();
            return;
        }
    }

    cout << "Khong tim thay member.\n";
}

void GymSystem::xoaMember() {
    if (nm == 0) {
        cout << "Chua co member nao de xoa.\n";
        return;
    }

    int id;
    cout << "Nhap ID can xoa: ";
    cin >> id;

    for (int i = 0; i < nm; i++) {
        if (m[i].getID() == id) {
            for (int j = i; j < nm - 1; j++) {
                m[j] = m[j + 1];
            }
            nm--;
            cout << "Da xoa member.\n";
            return;
        }
    }

    cout << "Khong tim thay member.\n";
}
void GymSystem::suaMember() {
    if (nm == 0) {
        cout << "Chua co member nao de sua.\n";
        return;
    }
    int id;
    cout << "Nhap ID can sua: ";
    cin >> id;
    for (int i = 0; i < nm; i++) {
        if (m[i].getID() == id) {
            cout << "Nhap lai thong tin member:\n";
            m[i].nhap();
            cout << "Da sua member.\n";
            return;
        }
    }

    cout << "Khong tim thay member.\n";
}
void GymSystem::nhapTrainer() {
    cout << "Nhap so luong trainer: ";
    while (!(cin >> nt) || nt <= 0 || nt > 50) {
        cin.ignore();
        cout << "Nhap lai so luong trainer: ";
    }

    for (int i = 0; i < nt; i++) {
        cout << "\n--- Nhap trainer thu " << i + 1 << " ---\n";
        t[i].nhap();
    }
}

void GymSystem::xuatTrainer() {
    if (nt == 0) {
        cout << "Danh sach trainer rong.\n";
        return;
    }

    cout << "\n================ DANH SACH TRAINER ================\n";
    cout << left
        << setw(15) << "ID"
        << setw(20) << "Ten"
        << setw(10) << "Tuoi"
        << setw(20) << "Chuyen mon"
        << endl;

    for (int i = 0; i < nt; i++) {
        t[i].xuat();
    }
}

void GymSystem::nhapPackage() {
    cout << "Nhap so luong package: ";
    while (!(cin >> np) || np <= 0 || np > 50) {
        cin.ignore();
        cout << "Nhap lai so luong package: ";
    }

    for (int i = 0; i < np; i++) {
        cout << "\n--- Nhap package thu " << i + 1 << " ---\n";
        p[i].nhap();
    }
}

void GymSystem::xuatPackage() {
    if (np == 0) {
        cout << "Danh sach package rong.\n";
        return;
    }

    cout << "\n================ DANH SACH PACKAGE ================\n";
    cout << left
        << setw(15) << "ID goi"
        << setw(20) << "Ten goi"
        << setw(12) << "Gia"
        << setw(10) << "Thang"
        << endl;
    for (int i = 0; i < np; i++) {
        p[i].xuat();
    }
}

void GymSystem::nhapWorkout() {
    cout << "Nhap so luong workout: ";
    while (!(cin >> nw) || nw <= 0 || nw > 100) {
        cin.ignore();
        cout << "Nhap lai so luong workout: ";
    }

    for (int i = 0; i < nw; i++) {
        cout << "\n--- Nhap workout thu " << i + 1 << " ---\n";
        w[i].nhap();
    }
}

void GymSystem::xuatWorkout() {
    if (nw == 0) {
        cout << "Danh sach workout rong.\n";
        return;
    }

    cout << "\n===== DANH SACH =====\n";
    cout << left
        << setw(30) << "Ten"
        << setw(15) << "Loai"
        << setw(10) << "Phut"
        << setw(15) << "Calo/phut"
        << setw(10) << "Tong"
        << endl;

    for (int i = 0; i < nw; i++) {
        w[i].hienThi();
    }
}

void GymSystem::menu() {
    int ch;
    do {
        cout << "\n===== GYM SYSTEM =====";
        cout << "\n1. Member";
        cout << "\n2. Trainer";
        cout << "\n3. Package";
        cout << "\n4. Workout";
        cout << "\n0. Exit";
        cout << "\nChon: ";

        while (!(cin >> ch)) {
            cin.ignore();
            cout << "Nhap lai lua chon: ";
        }

        switch (ch) {
            case 1:
                menuMember();
                break;
            case 2:
                menuTrainer();
                break;
            case 3:
                menuPackage();
                break;
            case 4:
                menuWorkout();
                break;
            case 0:
                cout << "Thoat chuong trinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le.\n";
        }
    } while (ch != 0);
}

void GymSystem::menuMember() {
    int ch;
    do {
        cout << "\n--- MEMBER MENU ---";
        cout << "\n1. Nhap danh sach";
        cout << "\n2. Xuat danh sach";
        cout << "\n3. Tim member";
        cout << "\n4. Xoa member";
        cout << "\n5. Sua member";
        cout << "\n0. Quay lai";
        cout << "\nChon: ";

        while (!(cin >> ch)) {
            cin.ignore();
            cout << "Nhap lai lua chon: ";
        }

        switch (ch) {
            case 1:
                nhapMember();
                break;
            case 2:
                xuatMember();
                break;
            case 3:
                timMember();
                break;
            case 4:
                xoaMember();
                break;
            case 5:
                suaMember();
                break;
            case 0:
                break;
            default:
                cout << "Lua chon khong hop le.\n";
        }
    } while (ch != 0);
}

void GymSystem::menuTrainer() {
    int ch;
    do {
        cout << "\n--- TRAINER MENU ---";
        cout << "\n1. Nhap danh sach";
        cout << "\n2. Xuat danh sach";
        cout << "\n0. Quay lai";
        cout << "\nChon: ";

        while (!(cin >> ch)) {
            cin.ignore();
            cout << "Nhap lai lua chon: ";
        }

        switch (ch) {
            case 1:
                nhapTrainer();
                break;
            case 2:
                xuatTrainer();
                break;
            case 0:
                break;
            default:
                cout << "Lua chon khong hop le.\n";
        }
    } while (ch != 0);
}

void GymSystem::menuPackage() {
    int ch;
    do {
        cout << "\n--- PACKAGE MENU ---";
        cout << "\n1. Nhap danh sach";
        cout << "\n2. Xuat danh sach";
        cout << "\n0. Quay lai";
        cout << "\nChon: ";

        while (!(cin >> ch)) {
            cin.ignore();
            cout << "Nhap lai lua chon: ";
        }

        switch (ch) {
            case 1:
                nhapPackage();
                break;
            case 2:
                xuatPackage();
                break;
            case 0:
                break;
            default:
                cout << "Lua chon khong hop le.\n";
        }
    } while (ch != 0);
}

void GymSystem::menuWorkout() {
    int ch;
    do {
        cout << "\n--- WORKOUT MENU ---";
        cout << "\n1. Nhap danh sach";
        cout << "\n2. Xuat danh sach";
        cout << "\n0. Quay lai";
        cout << "\nChon: ";

        while (!(cin >> ch)) {
            cin.ignore();
            cout << "Nhap lai lua chon: ";
        }

        switch (ch) {
            case 1:
                nhapWorkout();
                break;
            case 2:
                xuatWorkout();
                break;
            case 0:
                break;
            default:
                cout << "Lua chon khong hop le.\n";
        }
    } while (ch != 0);
}
