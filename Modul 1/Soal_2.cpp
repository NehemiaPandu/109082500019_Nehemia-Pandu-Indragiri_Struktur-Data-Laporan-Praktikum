#include <iostream>
using namespace std;

int main(){
    int a;

    cout << "Masukkan bilangan bulat (0-100): ";
    cin >> a;

    if (a < 0 || a > 100) {
        cout << "Masukan bilangan harus antara 0-100." << endl;
        return 0;
    }

    string satuan[] = {"nol", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};

    string hasil;
 
    if (a < 10) {
        hasil = satuan[a];
    } else if (a == 10) {
        hasil = "sepuluh";
    } else if (a == 11) {
        hasil = "sebelas";
    } else if (a < 20) {
        hasil = satuan[a - 10] + " belas";
    } else if (a < 100) {
        hasil = satuan[a / 10] + " puluh";
        if (a % 10 != 0) {
            hasil = hasil + " " + satuan[a % 10];
        }
    } else {
        hasil = "seratus";
    }
 
    cout << a << " : " << hasil << endl;
    return 0;

}