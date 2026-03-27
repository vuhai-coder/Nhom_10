#include<iostream>
#include<string>
using namespace std;
class membership{
private:
    string tengoi;
    int giatien;
    int thoihan;
public:
    membership(){
        tengoi = "";
        giatien = 0;
        thoihan = 0;
    }
    string gettengoi(){
        return tengoi;
    }
    void nhap(){
        cout << "Nhap ten goi:";
        getline(cin,tengoi);
        cout << "Nhap gia tien:";
        cin >> giatien;
        while(giatien <= 0){
            cout << "Nhap lai:";
            cin >> giatien;
        }
        cout << "Nhap thoi han:";
        cin >> thoihan;
        cin.ignore();
        while(thoihan <= 0){
            cout << "Nhap lai:";
            cin >> thoihan;
        }
    }
    void xuat(){
        cout << "Ten goi: " << tengoi << endl;
        cout << "Gia tien: " << giatien << endl;
        cout << "Thoi han: " << thoihan << " thang" << endl;
    }
    static void nhapdsgoi(membership ds[], int &n){
        cout << "Nhap so luong goi:";
        cin >> n;
        while(n < 0 || n > 50){
        	cout << "Vui long nhap lai so luong goi tap(0 < n <= 50):";
        	cin >> n;
		}
		cin.ignore();
        for(int i = 0; i < n; i++){
            cout << "\nGoi " << i+1 << ":\n";
            ds[i].nhap();
        }
    }
    static void xuatdsgoi(membership ds[], int n){
        for(int i = 0; i < n; i++){
            cout << "\nGoi " << i+1 << ":\n";
            ds[i].xuat();
        }
    }
    static void themgoi(membership ds[], int &n){
        cout << "\nNhap goi moi:\n";
        cin.ignore();
        ds[n].nhap();
        n++;
    }
    static void capnhat(membership ds[], int n, string ten){
        for(int i = 0; i < n; i++){
            if(ds[i].gettengoi() == ten){
                cout << "Nhap lai thong tin:\n";
                ds[i].nhap();
                return;
            }
        }
        cout << "Khong tim thay!\n";
    }
};

int main(){
    membership dsGoi[50];
    int nGoi = 0;
    int luachon;
    string ten;

    do{
        cout << "\n===== MENU QUAN LY GOI TAP =====\n";
        cout << "1. Quan ly goi tap\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";
        cin >> luachon;

        switch(luachon){

        case 1:{
            int lc;
            do{
                cout << "\n--- GOI TAP ---\n";
                cout << "1. Nhap DS\n2. Xuat DS\n3. Them\n4. Cap nhat\n0. Back\nChon:";
                cin >> lc;

                switch(lc){
                    case 1: membership::nhapdsgoi(dsGoi,nGoi); break;
                    case 2: membership::xuatdsgoi(dsGoi,nGoi); break;
                    case 3: membership::themgoi(dsGoi,nGoi); break;
                    case 4:
                        cin.ignore();
                        cout << "Nhap ten:";
                        getline(cin,ten);
                        membership::capnhat(dsGoi,nGoi,ten);
                        break;
                	}
            	}while(lc != 0);
            	break;
        	}

   	 	}

    }while(luachon != 0);
    return 0;
}
