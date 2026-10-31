#include "Doublylist.h"

// Membuat list kosong
void CreateList(List &L) {
    L.First = Nil;
    L.Last = Nil;
}

// Membuat elemen baru (alokasi memori)
address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

// Menghapus elemen dari memori
void dealokasi(address &P) {
    delete P;
    P = Nil;
}

// Menambah elemen di akhir list
void insertLast(List &L, address P) {
    if (L.First == Nil) {
        // list masih kosong
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last;
        L.Last->next = P;
        L.Last = P;
    }
}

// Menampilkan isi list dari elemen terakhir ke elemen pertama (menggunakan prev)
void printInfo(List L) {
    address P = L.Last;
    while (P != Nil) {
        cout << "no polisi : " << P->info.nopol << endl;
        cout << "warna     : " << P->info.warna << endl;
        cout << "tahun     : " << P->info.thnBuat << endl;
        P = P->prev;
    }
}