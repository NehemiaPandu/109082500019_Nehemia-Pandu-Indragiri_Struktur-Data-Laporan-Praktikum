#ifndef Mahasiswa_H_Included
#define Mahasiswa_H_Included

using namespace std;

struct mahasiswa {
    string nama;
    char nim[10];
    int nilaiUTS, nilaiUAS, nilaiTugas;
};

void inputMhs (mahasiswa &m);
float nilaiAkhir (mahasiswa m);
#endif
