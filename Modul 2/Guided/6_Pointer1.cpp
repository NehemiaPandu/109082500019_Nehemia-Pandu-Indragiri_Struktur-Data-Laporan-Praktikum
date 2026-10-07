#include <iostream>
using namespace std;

int main(){
    int angka = 100;

    int *pointer;

    pointer = &angka;

    cout << "Nilai angka: " << angka << endl;
    cout << "Alamat angka: " << &angka << endl;
    cout << "Isi angka: " << pointer << endl;
    cout << "Nilai dari angka: " << *pointer << endl;

    return 0;
}