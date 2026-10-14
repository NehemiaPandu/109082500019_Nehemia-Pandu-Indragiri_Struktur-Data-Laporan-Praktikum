#ifndef Pelajaran_H_Included
#define Pelajaran_H_Included
#include <iostream>

using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(pelajaran pel);

#endif

