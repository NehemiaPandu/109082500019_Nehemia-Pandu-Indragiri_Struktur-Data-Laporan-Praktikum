#ifndef Mahasiswa_H_Included
#define Mahasiswa_H_Included

struct mahasiswa {
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs (mahasiswa &m);
float rata2 (mahasiswa m);
#endif
