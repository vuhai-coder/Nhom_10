#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Person {
protected:
    string ten;
    int tuoi;
public:
    void nhap() {
        cout << "Nhap ten: ";
        getline(cin, ten);
        cout << "Nhap tuoi: ";
        cin >> tuoi;
        cin.ignore();
    }
    void hienThi() {
        cout << "Ten: " << ten << ", Tuoi: " << tuoi;
    }
};
class Trainer : public Person {
private:
    string chuyenMon;
public:
    void nhap() {
        Person::nhap();
        cout << "Nhap chuyen mon: ";
        getline(cin, chuyenMon);
    }
    void hienThi() {
        Person::hienThi();
        cout << ", Chuyen mon: " << chuyenMon << endl;
    }
    string layChuyenMon() {
        return chuyenMon;
    }
};
void nhapDanhSach(vector<Trainer> &ds) {
    int n;
    cout << "Nhap so luong huan luyen vien: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        cout << "\nHuan luyen vien thu " << i + 1 << ":\n";
        Trainer t;
        t.nhap();
        ds.push_back(t);
    }
}
void hienThiDanhSach(vector<Trainer> ds) {
    cout << "\nDanh sach huan luyen vien:\n";
    for (int i = 0; i < ds.size(); i++) {
        ds[i].hienThi();
    }
}
void timTheoChuyenMon(vector<Trainer> ds) {
    string key;
    cout << "\nNhap chuyen mon can tim: ";
    getline(cin, key);
    cout << "\nKet qua:\n";
    for (int i = 0; i < ds.size(); i++) {
        if (ds[i].layChuyenMon() == key) {
            ds[i].hienThi();
        }
    }
}
int main() {
    vector<Trainer> ds;
    nhapDanhSach(ds);
    hienThiDanhSach(ds);
    timTheoChuyenMon(ds);
    return 0;
}
