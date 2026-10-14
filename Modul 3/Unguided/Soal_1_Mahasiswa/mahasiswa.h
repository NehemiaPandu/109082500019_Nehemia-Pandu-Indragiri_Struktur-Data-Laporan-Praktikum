#ifndef Mahasiswa_H_Included
#define Mahasiswa_H_Included

using namespace std;

struct mahasiswa {
    string nama;
    char nim[13];
    int nilaiUTS, nilaiUAS, nilaiTugas;
     float nilaiAkhir;
};

void inputMhs (mahasiswa &m);
float nilaiAkhir (mahasiswa m);
#endif
