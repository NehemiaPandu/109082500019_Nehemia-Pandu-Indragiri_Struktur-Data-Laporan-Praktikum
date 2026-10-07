#include <iostream>
using namespace std;

// BY POINTER
void tukarPointer(int *x, int *y, int *z) {
    int temp;

    temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
}

void tukarReference(int &x, int &y, int &z) {
    int temp;

    temp = x;
    x = y;
    y = z;
    z = temp;
}

int main() {
    int a, b, c;

    cout << "Masukkan nilai a: ";
    cin >> a;
    cout << "Masukkan nilai b: ";
    cin >> b;
    cout << "Masukkan nilai c: ";
    cin >> c;

    int a2 = a;
    int b2 = b;
    int c2 = c;

    cout << "\n=== By Pointer ===" << endl;
    cout << "Sebelum ditukar: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    tukarPointer(&a, &b, &c);

    cout << "\nSetelah ditukar: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    cout << "\n=== By Reference ===" << endl;
    cout << "Sebelum ditukar: " << endl;
    cout << "a = " << a2 << endl;
    cout << "b = " << b2 << endl;
    cout << "c = " << c2 << endl;

    tukarReference(a2, b2, c2);

    cout << "\nSetelah ditukar: " << endl;
    cout << "a = " << a2 << endl;
    cout << "b = " << b2 << endl;
    cout << "c = " << c2 << endl;

    return 0;
}