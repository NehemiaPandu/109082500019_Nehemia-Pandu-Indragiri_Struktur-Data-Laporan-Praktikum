#include <iostream>
#include "pelajaran.h"
using namespace std;

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran pel;
    pel.namaMapel = namapel;
    pel.kodeMapel = kodepel;
    
    return pel;
}

void tampil_pelajaran(pelajaran pel){
    cout << "Nama Mapel: " << pel.namaMapel << endl;
    cout << "Kode Mapel: " << pel.kodeMapel << endl;
}
