#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

class Workout{
private:
    string tenBaiTap;
    string loaiBaiTap;
    int thoiGian; // phút

public:
    string chonLoaiBaiTap(){
        string loai;
        do{
            cout << "Nhap loai bai tap (Cardio / Strength / Yoga / HIIT / Functional): ";
            getline(cin, loai);

            if (loai != "Cardio" && loai != "Strength" &&
                loai != "Yoga" && loai != "HIIT" &&
                loai != "Functional"){
                cout << "Ten loai bai tap khong hop le! Vui long nhap loai bai tap dung voi nhung goi y!.\n";
            }
        } while (loai != "Cardio" && loai != "Strength" &&
                 loai != "Yoga" && loai != "HIIT" &&
                 loai != "Functional");

        return loai;
    }

    string chonTenBaiTapTheoLoai(const string& loai){
        string ten;

        if (loai == "Cardio"){
            do {
                cout << "Chon bai tap Cardio:\n";
                cout << "- Chay bo\n";
                cout << "- Dap xe\n";
                cout << "- Nhay day\n";
                cout << "Nhap ten bai tap: ";
                getline(cin, ten);

                if (ten != "Chay bo" && ten != "Dap xe" && ten != "Nhay day"){
                    cout << "Ten bai tap khong hop le! Vui long nhap ten bai tap dung voi nhung goi y.\n";
                }
            } while (ten != "Chay bo" && ten != "Dap xe" && ten != "Nhay day");
        }
        else if (loai == "Strength"){
            do {
                cout << "Chon bai tap Strength:\n";
                cout << "- Bench press\n";
                cout << "- Squat\n";
                cout << "- Deadlift\n";
                cout << "Nhap ten bai tap: ";
                getline(cin, ten);

                if (ten != "Bench press" && ten != "Squat" && ten != "Deadlift"){
                    cout << "Ten bai tap khong hop le! Vui long nhap lai dung goi y.\n";
                }
            } while (ten != "Bench press" && ten != "Squat" && ten != "Deadlift");
        }
        else if (loai == "Yoga"){
            do {
                cout << "Chon bai tap Yoga:\n";
                cout << "- Yoga co ban\n";
                cout << "- Yoga deo dai\n";
                cout << "- Pilates\n";
                cout << "Nhap ten bai tap: ";
                getline(cin, ten);

                if (ten != "Yoga co ban" && ten != "Yoga deo dai" && ten != "Pilates"){
                    cout << "Ten bai tap khong hop le! Vui long nhap lai dung goi y.\n";
                }
            } while (ten != "Yoga co ban" && ten != "Yoga deo dai" && ten != "Pilates");
        }
        else if (loai == "HIIT"){
            do {
                cout << "Chon bai tap HIIT:\n";
                cout << "- Burpees\n";
                cout << "- Jump squat\n";
                cout << "- Mountain climber\n";
                cout << "Nhap ten bai tap: ";
                getline(cin, ten);

                if (ten != "Burpees" && ten != "Jump squat" && ten != "Mountain climber"){
                    cout << "Ten bai tap khong hop le! Vui long nhap lai dung goi y.\n";
                }
            } while (ten != "Burpees" && ten != "Jump squat" && ten != "Mountain climber");
        }
        else if (loai == "Functional"){
            do {
                cout << "Chon bai tap Functional:\n";
                cout << "- Kettlebell swing\n";
                cout << "- Battle rope\n";
                cout << "- Medicine ball\n";
                cout << "Nhap ten bai tap: ";
                getline(cin, ten);

                if (ten != "Kettlebell swing" && ten != "Battle rope" && ten != "Medicine ball"){
                    cout << "Ten bai tap khong hop le! Vui long nhap lai dung goi y.\n";
                }
            } while (ten != "Kettlebell swing" && ten != "Battle rope" && ten != "Medicine ball");
        }

        return ten;
    }

    int nhapSoNguyenDuong(){
        int x;
        while (true) {
            cout << "Nhap thoi gian tap: ";
            cin >> x;

            if (cin.fail()){
                cout << "Gia tri khong hop le. Vui long nhap lai!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            if (x <= 0){
                cout << "Gia tri khong hop le. Vui long nhap lai!\n";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return x;
        }
    }

    void nhap(){
        loaiBaiTap = chonLoaiBaiTap();
        tenBaiTap = chonTenBaiTapTheoLoai(loaiBaiTap);
        thoiGian = nhapSoNguyenDuong();
    }

    double layCaloMoiPhut() const{
        if (tenBaiTap == "Chay bo") return 10.0;
        if (tenBaiTap == "Dap xe") return 8.0;
        if (tenBaiTap == "Nhay day") return 12.0;

        if (tenBaiTap == "Bench press") return 7.0;
        if (tenBaiTap == "Squat") return 8.0;
        if (tenBaiTap == "Deadlift") return 8.0;

        if (tenBaiTap == "Yoga co ban") return 5.0;
        if (tenBaiTap == "Yoga deo dai") return 6.0;
        if (tenBaiTap == "Pilates") return 6.0;

        if (tenBaiTap == "Burpees") return 14.0;
        if (tenBaiTap == "Jump squat") return 13.0;
        if (tenBaiTap == "Mountain climber") return 12.0;

        if (tenBaiTap == "Kettlebell swing") return 10.0;
        if (tenBaiTap == "Battle rope") return 11.0;
        if (tenBaiTap == "Medicine ball") return 9.0;

        return 0.0;
    }

    double tinhCalo() const{
        return thoiGian * layCaloMoiPhut();
    }

    void hienThi() const{
        cout << left
             << setw(20) << tenBaiTap
             << setw(15) << loaiBaiTap
             << setw(12) << thoiGian
             << setw(15) << layCaloMoiPhut()
             << setw(15) << tinhCalo()
             << endl;
    }
};

int nhapSoLuongBaiTap(){
    int n;
    while (true){
        cout << "Nhap so luong bai tap: ";
        cin >> n;

        if (cin.fail()){
            cout << "Gia tri khong hop le. Vui long nhap lai!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (n <= 0){
            cout << "Gia tri khong hop le. Vui long nhap lai!.\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return n;
    }
}

int main(){
    vector<Workout> ds;
    int n = nhapSoLuongBaiTap();

    for (int i = 0; i < n; i++){
        cout << "\nNhap thong tin bai tap thu " << i + 1 << ":\n";
        Workout w;
        w.nhap();
        ds.push_back(w);
    }

    cout << "\n================ DANH SACH BAI TAP ================\n";
    cout << left
         << setw(20) << "Ten bai tap"
         << setw(15) << "Loai"
         << setw(12) << "So phut"
         << setw(15) << "Calo/phut"
         << setw(15) << "Tong calo"
         << endl;

    double tongCalo = 0;
    for (const auto& w : ds){
        w.hienThi();
        tongCalo += w.tinhCalo();
    }

    cout << "\nTong luong calo tieu hao cua tat ca bai tap: " << tongCalo << " calo\n";

    return 0;
}
