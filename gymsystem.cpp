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
        cin.ignore();
        cout << "Nhap lai so luong member: ";
    }
    for (int i = 0; i < sl; i++) {
        cout << "\n--- Them member thu " << nm + 1 << " ---\n";
        m[nm].nhap();

        cout << "\n=== DANH SACH GOI ===\n";
        for (int j = 0; j < np; j++) {
            cout << "Goi so " << j + 1 << ":\n";
            p[j].xuat();
            cout << "------------------\n";
        }
        int chonGoi;
        do {
            cout << "Chon goi (1 -> " << np << "): ";
            cin >> chonGoi;
        } while (chonGoi < 1 || chonGoi > np);
        chonGoi--;
        m[nm].chongoi(chonGoi);

        cout << "\n=== DANH SACH TRAINER ===\n";
        for (int j = 0; j < nt; j++) {
            cout << "Trainer so " << j + 1 << ":\n";
            t[j].xuat();
            cout << "------------------\n";
        }
        int chonTrainer;
        do {
            cout << "Chon trainer (1 -> " << nt << "): ";
            cin >> chonTrainer;
        } while (chonTrainer < 1 || chonTrainer > nt);
        chonTrainer--;
        m[nm].chonTrainer(chonTrainer);

        cout << "\n=== DANH SACH WORKOUT ===\n";
        for (int j = 0; j < nw; j++) {
            cout << j + 1<< ". ";
            w[j].hienThi();
        }
        int soLuongWorkoutChon;
        cout << "Nhap so workout muon chon: ";
        while (!(cin >> soLuongWorkoutChon) || soLuongWorkoutChon <= 0 || soLuongWorkoutChon > nw) {
            cin.ignore();
            cout << "Nhap lai so workout muon chon: ";
        }
        for (int k = 0; k < soLuongWorkoutChon; k++) {
            int chonWorkout;
            do {
                cout << "Chon workout thu " << k + 1 << " (1 -> " << nw << "): ";
                cin >> chonWorkout;
            } while (chonWorkout < 1 || chonWorkout > nw);

            chonWorkout--;
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
        << setw(25) << "Goi"
        << setw(15) << "Trainer"
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
            cout << setw(25) << goi;
        }
        else {
            cout << setw(15) << "Chua chon";
        }
        int idxTrainer = m[i].layTrainer();
        if (idxTrainer >= 0 && idxTrainer < nt)
            cout << setw(15) << t[idxTrainer].getName();
        else
            cout << setw(15) << "Chua chon";
        cout << endl;
        cout << "   Workout: ";
        int sw = m[i].laySoWorkout();
        if (sw == 0) {
            cout << "Chua chon workout nao.";
        }
        else {
            bool first = true;

            for (int j = 0; j < sw; j++) {
                int idxWorkout = m[i].layWorkoutTai(j);
                if (idxWorkout >= 0 && idxWorkout < nw) {

                    if (!first) {
                        cout << ", ";
                    }

                    cout << w[idxWorkout].gettenBaiTap();
                    first = false;
                }
            }
            cout << endl;
        }
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
    xuatMember();
    int stt;
    cout << "Nhap STT member can sua: ";
    while (!(cin >> stt) || stt < 1 || stt > nm) {
        cin.ignore();
        cout << "Nhap lai STT member can sua: ";
    }
    stt--;
    cout << "Nhap lai thong tin member:\n";
    m[stt].nhap();
    cout << "Da sua member.\n";
}

void GymSystem::nhapTrainer() {
    int sl;
    cout << "Nhap so luong trainer muon them: ";
    while (!(cin >> sl) || sl <= 0 || nt + sl > 50) {
        cin.ignore();
        cout << "Nhap lai so luong trainer muon them: ";
    }

    for (int i = 0; i < sl; i++) {
        cout << "\n--- Nhap trainer thu " << nt + 1 << " ---\n";
        t[nt].nhap();
        nt++;
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

void GymSystem::suaTrainer() {
    if (nt == 0) {
        cout << "Chua co trainer nao de sua.\n";
        return;
    }
    xuatTrainer();
    int stt;
    cout << "Nhap STT trainer can sua: ";
    while (!(cin >> stt) || stt < 1 || stt > nt) {
        cin.ignore();
        cout << "Nhap lai STT trainer can sua: ";
    }
    stt--;
    cout << "Nhap lai thong tin trainer:\n";
    t[stt].nhap();
    cout << "Da sua trainer.\n";
}

void GymSystem::nhapPackage() {
    int sl;
    cout << "Nhap so luong package muon them: ";
    while (!(cin >> sl) || sl <= 0 || np + sl > 50) {
        cin.ignore();
        cout << "Nhap lai so luong package muon them: ";
    }
    cin.ignore();
    for (int i = 0; i < sl; i++) {
        cout << "\n--- Nhap package thu " << np + 1 << " ---\n";
        p[np].nhap();
        np++;
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

void GymSystem::suaPackage() {
    if (np == 0) {
        cout << "Chua co package nao de sua.\n";
        return;
    }
    xuatPackage();
    int stt;
    cout << "Nhap STT package can sua: ";
    while (!(cin >> stt) || stt < 1 || stt > np) {
        cin.ignore();
        cout << "Nhap lai STT package can sua: ";
    }
    stt--;
    cin.ignore(1000, '\n');
    cout << "Nhap lai thong tin package:\n";
    p[stt].nhap();
    cout << "Da sua package.\n";
}

void GymSystem::nhapWorkout() {
    int sl;
    cout << "Nhap so luong workout muon them: ";
    while (!(cin >> sl) || sl <= 0 || nw + sl > 100) {
        cin.ignore();
        cout << "Nhap lai so luong workout muon them: ";
    }

    for (int i = 0; i < sl; i++) {
        cout << "\n--- Nhap workout thu " << nw + 1 << " ---\n";
        w[nw].nhap();
        nw++;
    }
}

void GymSystem::xuatWorkout() {
    if (nw == 0) {
        cout << "Danh sach workout rong.\n";
        return;
    }

    cout << "\n===== DANH SACH WORKOUT =====\n";
    cout << left
        << setw(5) << "STT"
        << setw(30) << "Ten"
        << setw(15) << "Loai"
        << setw(10) << "Phut"
        << setw(15) << "Calo/phut"
        << setw(10) << "Tong"
        << endl;

    for (int i = 0; i < nw; i++) {
        cout << setw(5) << i + 1;
        w[i].hienThi();
    }
}

void GymSystem::suaWorkout() {
    if (nw == 0) {
        cout << "Chua co workout nao de sua.\n";
        return;
    }

    xuatWorkout();

    int stt;
    cout << "Nhap STT workout can sua: ";
    while (!(cin >> stt) || stt < 1 || stt > nw) {
        cin.ignore();
        cout << "Nhap lai STT workout can sua: ";
    }
    stt--;
    cout << "Nhap lai thong tin workout:\n";
    w[stt].nhap();
    cout << "Da sua workout.\n";
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
        cout << "\n1. Them member";
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
        cout << "\n1. Them trainer";
        cout << "\n2. Xuat danh sach";
        cout << "\n3. Sua trainer";
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
        case 3:
            suaTrainer();
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
        cout << "\n1. Them package";
        cout << "\n2. Xuat danh sach";
        cout << "\n3. Sua package";
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
        case 3:
            suaPackage();
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
        cout << "\n1. Them workout";
        cout << "\n2. Xuat danh sach";
        cout << "\n3. Sua workout";
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
        case 3:
            suaWorkout();
            break;
        case 0:
            break;
        default:
            cout << "Lua chon khong hop le.\n";
        }
    } while (ch != 0);
}
