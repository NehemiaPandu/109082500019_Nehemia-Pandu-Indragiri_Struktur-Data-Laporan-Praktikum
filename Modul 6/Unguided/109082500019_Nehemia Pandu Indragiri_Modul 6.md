# <h1 align="center">Laporan Praktikum Modul 6 - DOUBLY LINKED LIST (BAGIAN PERTAMA)</h1>
<p align="center">Nehemia Pandu Indragiri - 109082500019</p>

## Dasar Teori
Doubly linked list adalah linked list yang masing-masing elemennya memiliki dua successor, yaitu successor yang menunjuk pada elemen sebelumnya (prev) dan successor yang menunjuk pada elemen sesudahnya (next). Selain itu, doubly linked list menggunakan dua pointer utama pada list, yaitu first yang menunjuk elemen pertama dan last yang menunjuk elemen terakhir. Pada list kosong, first dan last bernilai Nil. Dalam bahasa C/C++, TYPE diterjemahkan menjadi struct, yaitu struct elmlist yang berisi info, next, dan prev, serta struct list yang berisi first dan last. Data pada info dapat berupa data tunggal seperti integer atau data majemuk berupa record, misalnya data kendaraan yang terdiri dari nomor polisi, warna, dan tahun pembuatan.

Operasi dasar pada doubly linked list meliputi penyisipan dan penghapusan elemen. Penyisipan terdiri dari insert first yang menempatkan elemen di awal list, insert last yang menempatkan elemen di akhir list, dan insert after yang menempatkan elemen setelah elemen tertentu, sedangkan insert before merupakan kebalikan dari insert after dan hanya berbeda pada pencarian elemennya. Penghapusan terdiri dari delete first, delete last, dan delete after, yaitu menghapus elemen pertama, elemen terakhir, dan elemen setelah elemen tertentu, sedangkan delete before merupakan kebalikan dari delete after. Pada setiap operasi tersebut, pointer next dan prev dari elemen yang terkait harus diperbarui agar hubungan antar elemen tetap benar, dan elemen yang dihapus dikembalikan nilainya atau dibebaskan memorinya dengan dealokasi. Proses pencarian (searching), pengubahan data (update), dan penampilan data (view) pada dasarnya sama dengan singly linked list, hanya saja doubly linked list lebih mudah dalam mengakses elemen karena dapat melakukan iterasi maju dan mundur. ADT doubly linked list juga pada dasarnya sama dengan singly linked list, yaitu createList, alokasi, dealokasi, dan printInfo, dan diimplementasikan menjadi tiga modul, yaitu file .h untuk spesifikasi type dan prototipe primitif, file .cpp untuk realisasi primitif, dan main.cpp sebagai driver. Agar file header tidak terbaca dua kali, digunakan #ifndef, #define, dan #endif. [3]

## Guided

### 1. 

```C++
#ifndef DOUBLELIST_H
#define DOUBLELIST_H
#include <string>
using namespace std;

struct barang{
    string kode;
    string nama;
    int tahun;
};

using infotype = barang;
struct elmlist;
using address = elmlist*;
struct elmlist {infotype info; address prev; address next;};
struct list {address first; address last;};

void CreateList(list &L);
address alokasi(const infotype &x);
void dealokasi(address &P);
void insertFirst(list &L, address P);
void insertLast(list &L, address P);
void insertAfter(list &L, address R, address P);
void insertBefore(list &L, address R, address P);
void printInfo(const list &L);
address findElm(const list &L, const string &kode);
void deleteFirst(list  &L, address &P);
void deleteLast(list  &L, address &P);
void deleteAfter(list &L, address prec, address &P);
void deleteBefore(list &L, address succ, address &P);
#endif
```

```C++
#include <iostream>
#include <iomanip>
#include "Doublylist.h"
using namespace std;

void CreateList(list &L) { L.first = nullptr; L.last = nullptr; }

address alokasi(const infotype &x) {
    address P = new elmlist;
    P->info = x;
    P->prev = nullptr; P->next = nullptr;
    return P;
}
void dealokasi(address &P) {
    if (P != nullptr) { delete P; P = nullptr; }
}
void insertFirst(list &L, address P) {
    if (!P) return;
    P->prev = nullptr; P->next = L.first;
    if (L.first) L.first->prev = P;
    else L.last = P;
    L.first = P;
}
void insertLast(list &L, address P) {
    if (!P) return;
    P->next = nullptr; P->prev = L.last;
    if (L.last) L.last->next = P;
    else L.first = P;
    L.last = P;
}

// Menyisipkan P tepat setelah R.
void insertAfter(list &L, address R, address P) {
    if (!R || !P) return;
    P->prev = R;
    P->next = R->next;
    if (R->next) R->next->prev = P;
    else L.last = P;
    R->next = P;
}

// Menyisipkan P tepat sebelum R.
void insertBefore(list &L, address R, address P) {
    if (!R || !P) return;
    P->next = R;
    P->prev = R->prev;
    if (R->prev) R->prev->next = P;
    else L.first = P;
    R->prev = P;
}
void printInfo(const list &L) {
    address P = L.first;
    if (!P) {
        cout << "List kosong.\n";
        return;
    }

    cout << "+--------+------------+-------+\n";
    cout << "| Kode   | Nama       | Tahun |\n";
    cout << "+--------+------------+-------+\n";
    while (P) {
        cout << "| " << left << setw(6) << P->info.kode
             << " | " << setw(10) << P->info.nama
             << " | " << setw(5) << P->info.tahun << " |\n";
        P = P->next;
    }
    cout << "+--------+------------+-------+\n";
}
address findElm(const list &L, const string &kode) {
    address P = L.first;
    while (P) {
        if (P->info.kode == kode) return P;
        P = P->next;
    }
    return nullptr;
}
void deleteFirst(list &L, address &P) {
    if (!L.first) { P = nullptr; return; }
    P = L.first; L.first = P->next;
    if (L.first) L.first->prev = nullptr;
    else L.last = nullptr;
    P->prev = P->next = nullptr;
}
void deleteLast(list &L, address &P) {
    if (!L.last) { P = nullptr; return; }
    P = L.last; L.last = P->prev;
    if (L.last) L.last->next = nullptr;
    else L.first = nullptr;
    P->prev = P->next = nullptr;
}
// Menghapus node tepat setelah prec.
void deleteAfter(list &L, address prec, address &P) {
    P = nullptr;
    if (!prec || !prec->next) return;
    P = prec->next; prec->next = P->next;
    if (P->next) P->next->prev = prec;
    else L.last = prec;
    P->prev = P->next = nullptr;
}
// Menghapus node tepat sebelum succ.
void deleteBefore(list &L, address succ, address &P) {
    P = nullptr;
    if (!succ || !succ->prev) return;
    P = succ->prev; succ->prev = P->prev;
    if (P->prev) P->prev->next = succ;
    else L.first = succ;
    P->prev = P->next = nullptr;
}
```

```C++
#include <iostream>
#include "Doublylist.h"
using namespace std;

void tampilkanJudul(const string &judul) {
    cout << "\n========================================\n";
    cout << judul << '\n';
    cout << "========================================\n";
}

int main() {
    list L;
    CreateList(L);

    infotype barang1 = {"B001", "Laptop", 2020};
    infotype barang2 = {"B002", "Monitor", 2022};
    infotype barang3 = {"B003", "Keyboard", 2023};
    infotype barang4 = {"B004", "Mouse", 2024};

    address P = nullptr;
    address posisi = nullptr;

    cout << "DEMONSTRASI OPERASI DOUBLY LINKED LIST\n";
    cout << "Data yang digunakan: B001, B002, B003, dan B004\n";

    tampilkanJudul("[1] INSERT FIRST");
    cout << "Menambahkan B002 di awal list.\n";
    insertFirst(L, alokasi(barang2));
    printInfo(L);

    tampilkanJudul("[2] INSERT LAST");
    cout << "Menambahkan B004 di akhir list.\n";
    insertLast(L, alokasi(barang4));
    printInfo(L);

    tampilkanJudul("[3] INSERT AFTER");
    cout << "Menambahkan B003 setelah B002.\n";
    posisi = findElm(L, "B002");
    if (posisi != nullptr) {
        insertAfter(L, posisi, alokasi(barang3));
    }
    printInfo(L);

    tampilkanJudul("[4] INSERT BEFORE");
    cout << "Menambahkan B001 sebelum B002.\n";
    posisi = findElm(L, "B002");
    if (posisi != nullptr) {
        insertBefore(L, posisi, alokasi(barang1));
    }
    printInfo(L);

    tampilkanJudul("[5] FIND ELEMENT");
    cout << "Mencari barang dengan kode B003.\n";
    posisi = findElm(L, "B003");
    if (posisi != nullptr) {
        cout << "Data ditemukan:\n";
        cout << "  Kode  : " << posisi->info.kode << '\n';
        cout << "  Nama  : " << posisi->info.nama << '\n';
        cout << "  Tahun : " << posisi->info.tahun << '\n';
    } else {
        cout << "Data tidak ditemukan.\n";
    }

    tampilkanJudul("[6] DELETE AFTER");
    cout << "Menghapus node setelah B002 (B003).\n";
    posisi = findElm(L, "B002");
    deleteAfter(L, posisi, P);
    if (P != nullptr) {
        cout << "Node yang dihapus: " << P->info.kode << '\n';
        dealokasi(P);
    } else {
        cout << "Tidak ada node yang dapat dihapus.\n";
    }
    printInfo(L);

    tampilkanJudul("[7] DELETE BEFORE");
    cout << "Menghapus node sebelum B004 (B002).\n";
    posisi = findElm(L, "B004");
    deleteBefore(L, posisi, P);
    if (P != nullptr) {
        cout << "Node yang dihapus: " << P->info.kode << '\n';
        dealokasi(P);
    } else {
        cout << "Tidak ada node yang dapat dihapus.\n";
    }
    printInfo(L);

    tampilkanJudul("[8] DELETE FIRST");
    cout << "Menghapus node pertama.\n";
    deleteFirst(L, P);
    if (P != nullptr) {
        cout << "Node yang dihapus: " << P->info.kode << '\n';
        dealokasi(P);
    } else {
        cout << "List kosong, tidak ada node yang dapat dihapus.\n";
    }
    printInfo(L);

    tampilkanJudul("[9] DELETE LAST");
    cout << "Menghapus node terakhir.\n";
    deleteLast(L, P);
    if (P != nullptr) {
        cout << "Node yang dihapus: " << P->info.kode << '\n';
        dealokasi(P);
    } else {
        cout << "List kosong, tidak ada node yang dapat dihapus.\n";
    }
    printInfo(L);

    tampilkanJudul("SELESAI");
    cout << "Kondisi list: "
         << (L.first == nullptr && L.last == nullptr ? "kosong.\n" : "masih berisi data.\n");

    return 0;
}
```

Pada guided 1, saya belajar untuk membuat program doubly linked list yang menerapkan konsep ADT dengan memisahkan kode menjadi tiga file, yaitu Doublylist.h, Doublylist.cpp, dan main.cpp. File Doublylist.h berisi deklarasi struct barang dengan field kode, nama, dan tahun, alias infotype untuk struct barang, alias address sebagai pointer ke struct elmlist, struct elmlist yang berisi info, prev, dan next, serta struct list dengan field first dan last sebagai penunjuk elemen pertama dan terakhir. File ini juga berisi prototipe semua prosedur dan fungsi yang dipakai, serta dilindungi include guard (#ifndef, #define, #endif) agar tidak terbaca dua kali. File Doublylist.cpp berisi isi dari primitif-primitif tersebut. Prosedur CreateList mengatur first dan last menjadi nullptr untuk membentuk list kosong. Fungsi alokasi membuat elemen baru dengan new, mengisi info sesuai parameter, dan mengatur prev dan next menjadi nullptr, sedangkan dealokasi mengembalikan memori elemen ke sistem dengan delete. Untuk penyisipan, insertFirst menempatkan elemen di awal list dan insertLast di akhir list, dan keduanya mengecek apakah list masih kosong agar first dan last ikut diperbarui. Prosedur insertAfter menyisipkan elemen P tepat setelah R, sedangkan insertBefore menyisipkan P tepat sebelum R, dan keduanya memperbarui pointer next dan prev dari elemen di sekitarnya. Untuk penghapusan, deleteFirst dan deleteLast mengambil elemen pertama dan terakhir ke P lalu memindahkan first dan last, deleteAfter menghapus elemen tepat setelah prec, dan deleteBefore menghapus elemen tepat sebelum succ. Pada keempat prosedur tersebut, elemen yang dihapus disimpan di parameter P (call by reference) agar bisa dibebaskan memorinya dengan dealokasi. Fungsi findElm menelusuri list dari first untuk mencari elemen dengan kode tertentu dan mengembalikan alamatnya, atau nullptr jika tidak ditemukan, sedangkan prosedur printInfo menampilkan seluruh isi list dalam bentuk tabel menggunakan setw dari iomanip. Pada main.cpp, program membuat variabel list L, memanggil CreateList, lalu menyiapkan empat data barang, yaitu B001 (Laptop), B002 (Monitor), B003 (Keyboard), dan B004 (Mouse). Data tersebut disisipkan secara bertahap, yaitu B002 dengan insertFirst, B004 dengan insertLast, B003 dengan insertAfter setelah B002, dan B001 dengan insertBefore sebelum B002, sehingga urutan list menjadi B001, B002, B003, B004. Kemudian findElm dipakai untuk mencari B003 dan menampilkan datanya. Setelah itu deleteAfter menghapus B003 yang berada setelah B002, deleteBefore menghapus B002 yang berada sebelum B004, deleteFirst menghapus B001, dan deleteLast menghapus B004, dan setiap elemen yang dihapus langsung dibebaskan memorinya dengan dealokasi. Pada akhir program, first dan last bernilai nullptr sehingga list ditampilkan dalam kondisi kosong.



## Unguided 

### 1. (isi dengan soal unguided 1)

```C++
source code unguided 1
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 1_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided1-1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 1 

### 2. (isi dengan soal unguided 2)

```C++
source code unguided 2
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 2_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided2-1.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 2

### 3. (isi dengan soal unguided 3)

```C++
source code unguided 3
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 3_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided3-1.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 3

## Kesimpulan
...

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>
