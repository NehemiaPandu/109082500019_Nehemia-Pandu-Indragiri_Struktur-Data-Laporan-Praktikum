#include <iostream>
#include "array.h"

using namespace std;

int main() {
   
    int arrayA[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int arrayB[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    cout << "=== ARRAY AWAL ===" << endl;
    cout << "Array A:" << endl;
    tampilArray(arrayA);
    cout << "\nArray B:" << endl;
    tampilArray(arrayB);

    cout << "\n=== TUKAR ARRAY ===" << endl;
    cout << "Menukar posisi [1][1]" << endl;
    tukarIsiArray(arrayA, arrayB, 1, 1);
    
    cout << "\nArray A (Setelah ditukar):" << endl;
    tampilArray(arrayA);
    cout << "\nArray B (Setelah ditukar):" << endl;
    tampilArray(arrayB);

    cout << "\n=== TUKAR POINTER ===" << endl;
    int var1 = 100, var2 = 500;
    int *p1 = &var1;
    int *p2 = &var2;

    cout << "Sebelum ditukar -> var1: " << *p1 << ", var2: " << *p2 << endl;
    tukarPointer(p1, p2);
    cout << "Setelah ditukar -> var1: " << *p1 << ", var2: " << *p2 << endl;

    return 0;
}