#include <iostream>
#include "mahasiswa.h"

using namespace std;

int main(){
    mahasiswa mhs[10];
    int n;
    
    cout << "Masukan Jumlah Mahasiswa (1-10): ";
    cin >> n;
  
    if (n < 1 || n > 10) {
        cout << "Masukan harus antara 1-10." << endl;
    } else {

    for (int i = 0; i < n; i++) {
        cout << "\nData Mahasiswa " << i + 1 << endl;
    
        inputMhs(mhs[i]);
    }
    
    cout << "\n-----Data Semua Mahasiswa-----" << endl;
    
    for (int i =  0; i < n; i++){
        cout << "Nama        :" << mhs[i].nama << endl;
        cout << "NIM         :" << mhs[i].nim << endl;
        cout << "Nilai UTS   :" << mhs[i].nilaiUTS << endl;
        cout << "Nilai UAS   :" << mhs[i].nilaiUAS << endl;
        cout << "Nilai Tugas :" << mhs[i].nilaiTugas << endl;
        cout << "Nilai Akhir : " << nilaiAkhir (mhs[i]) << endl;
        
        cout <<"========================" << endl;
    }
    
}
    return 0;

}