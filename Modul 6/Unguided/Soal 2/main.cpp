#include "Doublylist.h"

int main() {
    List L;
    infotype x;
    address P;
    CreateList(L);

    for (int i = 0; i < 4; i++) {
        cout << "masukkan nomor polisi: ";
        cin >> x.nopol;
        cout << "masukkan warna kendaraan: ";
        cin >> x.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> x.thnBuat;

        if (findElm(L, x) != Nil) {
            cout << "nomor polisi sudah terdaftar" << endl;
        } else {
            P = alokasi(x);
            insertLast(L, P);
        }
        cout << endl;
    }

    infotype cari;
    cout << "Masukkan Nomor Polisi yang dicari : ";
    cin >> cari.nopol;
    cout << endl;

    address hasil = findElm(L, cari);
    if (hasil != Nil) {
        cout << "Nomor Polisi : " << hasil->info.nopol << endl;
        cout << "Warna        : " << hasil->info.warna << endl;
        cout << "Tahun        : " << hasil->info.thnBuat << endl;
    } else {
        cout << "Data dengan nomor polisi " << cari.nopol << " tidak ditemukan." << endl;
    }

    return 0;
}