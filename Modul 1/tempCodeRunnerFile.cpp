#include <iostream>
using namespace std;

int main(){
    float a, b;

    cout << "Masukkan bilangan a: ";
    cin >> a;
    cout << "Masukkan bilangan b: "; 
    cin >> b;

    cout << "\n----- OUTPUT -----" << endl;
    cout << "Hasil Penjumlahan: " << a + b << endl;
    cout << "Hasil Pengurangan: " << a - b << endl;
    cout << "Hasil Perkalian: " << a * b << endl;
    cout << "Hasil Pembagian: " << a / b << endl;
}