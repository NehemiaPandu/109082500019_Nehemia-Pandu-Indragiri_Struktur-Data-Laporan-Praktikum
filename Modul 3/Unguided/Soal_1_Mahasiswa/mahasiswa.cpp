#include <iostream>
#include "mahasiswa.h"

using namespace std;

void inputMhs(mahasiswa &m) {
    cout << "Input Nama = ";
    cin >> (m).nama;
    cout << "Input NIM = ";
    cin >> (m).nim;
    cout << "Input Nilai UTS = ";
    cin >> (m).nilaiUTS;
    cout << "Input Nilai UAS = ";
    cin >> (m).nilaiUAS;
    cout << "Input Nilai Tugas = ";
    cin >> (m).nilaiTugas;
}

float nilaiAkhir(mahasiswa m) {
    return float(0.3 * m.nilaiUTS + 0.4 * m.nilaiUAS + 0.3 * m.nilaiTugas);
}

void hasil(mahasiswa m) {
    cout << "Nama        :" << m.nama << endl;
    cout << "NIM         :" << m.nama << endl;
    cout << "Nilai UTS   :" << m.nama << endl;
    cout << "Nilai UAS   :" << m.nama << endl;
    cout << "Nilai Tugas :" << m.nama << endl;
}