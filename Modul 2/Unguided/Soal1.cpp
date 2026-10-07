#include <iostream>
using namespace std;

void cetakMatriks(int matriks[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int matriks[10][3][3];
    int n;

    cout << "Banyak Matriks (2 - 10): ";
    cin >> n;

    if (n < 2 || n > 10) {
        cout << "Banyak matriks harus antara 2 sampai 10." << endl;
        return 0;
    }

    for (int m = 0; m < n; m++) {
        cout << "\nMasukkan nilai Matriks ke-" << m + 1 << " (3x3)" << endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << "Input baris " << i << ", kolom " << j << " : ";
                cin >> matriks[m][i][j];
            }
        }
        cout << "\n==========================" << endl;
    }

    for (int m = 0; m < n; m++) {
        cout << "\n--------Matriks " << m + 1 << endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << matriks[m][i][j] << " ";
            }
            cout << endl;
        }
    }
    cout << endl;

    cout << "Hasil Penjumlahan Matriks" << endl;
    int hasilTambah[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            hasilTambah[i][j] = matriks[0][i][j];
        }
    }
    for (int m = 1; m < n; m++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                hasilTambah[i][j] += matriks[m][i][j];
            }
        }
    }
    cetakMatriks(hasilTambah);

    cout << "Hasil Pengurangan Matriks" << endl;
    int hasilKurang[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            hasilKurang[i][j] = matriks[0][i][j];
        }
    }
    for (int m = 1; m < n; m++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                hasilKurang[i][j] -= matriks[m][i][j];
            }
        }
    }
    cetakMatriks(hasilKurang);

    cout << "Hasil Perkalian Matriks" << endl;
    int hasilKali[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            hasilKali[i][j] = matriks[0][i][j];
        }
    }
    for (int m = 1; m < n; m++) {
        int tempKali[3][3] = {0};

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    tempKali[i][j] += hasilKali[i][k] * matriks[m][k][j];
                }
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                hasilKali[i][j] = tempKali[i][j];
            }
        }
    }
    cetakMatriks(hasilKali);

    return 0;
}