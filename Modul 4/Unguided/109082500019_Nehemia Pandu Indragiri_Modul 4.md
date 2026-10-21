# <h1 align="center">Laporan Praktikum Modul 4 - SINGLY LINKED LIST (BAGIAN PERTAMA)</h1>
<p align="center">Nehemia Pandu Indragiri - 109082500019</p>

## Dasar Teori
Linked list adalah salah satu bentuk struktur data berupa serangkaian elemen data yang saling berkait (berhubungan) dan bersifat fleksibel karena dapat tumbuh dan mengerut sesuai kebutuhan. Linked list dapat diimplementasikan menggunakan array dan pointer, namun pointer lebih dipilih karena bersifat dinamis, sedangkan array bersifat statis. Singly linked list merupakan model ADT linked list yang hanya memiliki satu arah pointer, di mana setiap elemen terdiri dari data dan successor yang berfungsi sebagai penghubung ke elemen berikutnya. Node akhir menunjuk ke Nil, dan list hanya dapat dibaca maju. Istilah penting dalam singly linked list antara lain first/head yang menunjuk elemen pertama, next yang menunjuk elemen berikutnya, serta Nil/NULL yang berarti tidak mengacu ke mana pun. Dalam bahasa C/C++, TYPE diterjemahkan menjadi struct, sedangkan PRIMITIF diterjemahkan menjadi fungsi atau prosedur. Operasi dasar pada singly linked list meliputi pembentukan list (createList), pengalokasian memori (alokasi) menggunakan syntax new, dealokasi menggunakan syntax delete, pengecekan list kosong (isEmpty), penyisipan elemen (insert first, insert last, dan insert after), penghapusan elemen (delete first, delete last, dan delete after), penelusuran list untuk menampilkan isi node (printInfo), penghitungan jumlah elemen (nbList), serta penghapusan seluruh elemen list (deleteList). ADT biasanya diimplementasikan menjadi dua modul utama dan satu modul driver, yaitu file .h yang berisi spesifikasi type dan primitif, file .cpp yang berisi realisasi primitif, dan main.cpp yang memanggil ADT tersebut. Agar file header tidak terbaca dua kali, digunakan #ifndef, #define, dan #endif. [3]

## Guided 

### 1. Mahasiswa

```C++
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node *address; //mendefinisikan alias address sebagai pointer ke struct node

struct node { //node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct LinkedList { //ini linked listnya
    address first;
};

//semua function & prosedure yang akan dipakai
bool isEmpty(LinkedList List);
void createList(LinkedList &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(LinkedList List);
void insertFirst(LinkedList &List, address nodeBaru);
void insertAfter(LinkedList &List, address nodeBaru, address Prev);
void insertLast(LinkedList &List, address nodeBaru);

void delFirst(LinkedList &List);
void delLast(LinkedList &List);
void delAfter(LinkedList &List, address nodeHapus, address nodePrev);
int nbList(LinkedList List);
void deleteList(LinkedList &List);

#endif
```

```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(LinkedList List) {
    if(List.first == Nil){
        return true;
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(LinkedList &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) {
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(LinkedList &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(LinkedList &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(LinkedList &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(LinkedList &List){
    /* I.S. list tidak kosong
       F.S. node pertama di list terhapus*/
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(LinkedList &List){
    /* I.S. list tidak kosong
       F.S. node terakhir di list terhapus */
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else {
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(LinkedList &List, address nodeHapus, address nodePrev){
    /* I.S. list tidak kosong, Prev alamat salah satu elemen list
       F.S. nodeBantu adalah alamat dari Prev->next, menghapus Prev->next dari list */
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(LinkedList List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) {
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(LinkedList List) {
    /* I.S. list sudah ada
       F.S. Menampilkan jumlah node didalam list*/
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(LinkedList &List){
    /* I.S. list sudah ada
       F.S. menghapus semua node didalam list*/
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    List.first = Nil;
    cout << "List sudah terhapus!" << endl;
}
```

```C++
#include "list.h"

#include <iostream>
using namespace std;

int main(){
    LinkedList List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
Pada guided 1, saya belajar untuk membuat program singly linked list yang menerapkan konsep ADT dengan memisahkan kode menjadi tiga file, yaitu list.h, list.cpp, dan main.cpp. File list.h berisi deklarasi struct mahasiswa dengan field nama, nim, dan umur, alias dataMahasiswa, alias address sebagai pointer ke struct node, struct node yang berisi isidata dan next, serta struct LinkedList dengan field first sebagai penunjuk node pertama. File ini juga berisi prototipe semua fungsi dan prosedur yang dipakai, serta dilindungi include guard (#ifndef, #define, #endif) agar tidak terbaca dua kali. File list.cpp berisi isi dari primitif-primitif tersebut. Fungsi isEmpty mengecek apakah first bernilai Nil, sedangkan prosedur createList mengatur first menjadi Nil untuk membentuk list kosong. Fungsi alokasi membuat node baru menggunakan new, mengisi isidata sesuai parameter, dan mengatur next menjadi Nil, sedangkan dealokasi mengembalikan memori node ke sistem menggunakan delete. Untuk penyisipan, insertFirst menempatkan node di awal list, insertAfter menyisipkan node setelah node Prev, dan insertLast menelusuri list sampai node terakhir lalu menyambungkan node baru di sana. Untuk penghapusan, delFirst, delLast, dan delAfter masing-masing menghapus node pertama, node terakhir, dan node setelah nodePrev, lalu memanggil dealokasi agar memorinya dibebaskan. Prosedur printList menelusuri list dan menampilkan nama, NIM, dan usia setiap node, fungsi nbList menghitung jumlah node dan mengembalikannya bertipe int, dan prosedur deleteList menghapus seluruh node lalu mengatur first kembali ke Nil. Semua prosedur yang mengubah list menerima parameter LinkedList &List (call by reference) agar perubahan langsung tersimpan di list aslinya. Pada main.cpp, program membuat variabel List bertipe LinkedList, memanggil createList, lalu mengalokasikan lima node untuk Dhimas, Arvin, Rizal, Satrio, dan Joshua. Kelima node disisipkan menggunakan insertFirst, insertLast, dan insertAfter sehingga urutan list menjadi Dhimas, Rizal, Satrio, Arvin, Joshua dengan jumlah 5 node. Setelah itu delFirst menghapus Dhimas, delLast menghapus Joshua, dan delAfter menghapus Satrio sehingga tersisa Rizal dan Arvin dengan jumlah 2 node. Terakhir, deleteList menghapus seluruh node sehingga printList menampilkan list kosong dan nbList menampilkan jumlah 0.


## Unguided 

### 1. Buatlah ADT Singly Linked list sebagai berikut di dalam file “Singlylist.h” Kemudian buatlah implementasi dari procedure-procedure yang digunakan didalam file “Singlylist.cpp” Kemudian buat program utama didalam file “main.cpp” dengan implementasi sebagai berikut :

```C++
#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED

#include <iostream>
using namespace std;

#define Nil NULL

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

#endif
```

```C++
#include "Singlylist.h"

void createList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.First;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}
```

```C++
#include "Singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1]![](https://github.com/NehemiaPandu/109082500019_Nehemia-Pandu-Indragiri_Struktur-Data-Laporan-Praktikum/blob/main/Modul%204/Unguided/Screenshot%20Output/Output%20Soal%201/Screenshot%202026-10-21%20165502.png?raw=true)

Program di atas merupakan program yang saya buat untuk membuat singly linked list dengan menerapkan konsep ADT yang dibagi menjadi tiga file, yaitu Singlylist.h untuk deklarasi, Singlylist.cpp untuk isi prosedur, dan main.cpp sebagai program utama. File Singlylist.h berisi definisi Nil sebagai NULL, alias infotype bertipe int, alias address sebagai pointer ke struct ElmList, struct ElmList dengan field info dan next, serta struct List dengan field First sebagai penunjuk elemen pertama. File ini juga berisi prototipe prosedur dan dilindungi include guard (#ifndef, #define, #endif). Pada Singlylist.cpp, prosedur createList menerima parameter List &L (call by reference) lalu mengatur First menjadi Nil untuk membentuk list kosong. Fungsi alokasi membuat elemen baru dengan new, mengisi info sesuai parameter x, dan mengatur next menjadi Nil, sedangkan dealokasi mengembalikan memori elemen ke sistem dengan delete. Prosedur insertFirst menyisipkan elemen di awal list dengan mengarahkan next dari P ke First, lalu menjadikan P sebagai First yang baru. Prosedur printInfo menelusuri list dari First sampai Nil sambil menampilkan info setiap elemen yang dipisahkan spasi. Pada main.cpp, program membuat variabel L bertipe List, memanggil createList, lalu mengalokasikan lima elemen bernilai 2, 0, 8, 12, dan 9 yang disisipkan satu per satu dengan insertFirst. Karena setiap elemen disisipkan di awal, urutan list menjadi 9, 12, 8, 0, 2 dan itulah yang ditampilkan oleh printInfo.

### 2.  Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst(), node 2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tampilkan jumlah node yang tersimpan menggunakan nbList() dan lakukan penghapusan seluruh node menggunakan deleteList().

```C++
#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED

#include <iostream>
using namespace std;

#define Nil NULL

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);
int nbList(List L);
void deleteList(List &L);

#endif
```

```C++
#include "Singlylist.h"

void createList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.First;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}

void deleteFirst(List &L, address &P) {
    if (L.First != Nil) {
        P = L.First;
        L.First = P->next;
        P->next = Nil;
    } else {
        P = Nil;
    }
}

void deleteLast(List &L, address &P) {
    if (L.First == Nil) {
        P = Nil;
    } else if (L.First->next == Nil) {
        P = L.First;
        L.First = Nil;
    } else {
        address Q = L.First;
        while (Q->next->next != Nil) {
            Q = Q->next;
        }
        P = Q->next;
        Q->next = Nil;
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = Nil;
    } else {
        P = Nil;
    }
}

int nbList(List L) {
    int jumlah = 0;
    address P = L.First;
    while (P != Nil) {
        jumlah++;
        P = P->next;
    }
    return jumlah;
}

void deleteList(List &L) {
    address P;
    while (L.First != Nil) {
        deleteFirst(L, P);
        dealokasi(P);
    }
}
```

```C++
#include "Singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    address P;

    deleteFirst(L, P);
    dealokasi(P);

    deleteLast(L, P);
    dealokasi(P);

    deleteAfter(L, L.First, P);
    dealokasi(P);

    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << endl;
    cout << endl;

    deleteList(L);
    cout << "- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/NehemiaPandu/109082500019_Nehemia-Pandu-Indragiri_Struktur-Data-Laporan-Praktikum/blob/main/Modul%204/Unguided/Screenshot%20Output/Output%20Soal%202/Screenshot%202026-10-21%20165641.png?raw=true)

Program di atas merupakan lanjutan dari soal 1 yang saya buat untuk melakukan penghapusan elemen pada singly linked list. Pada Singlylist.h dan Singlylist.cpp ditambahkan lima primitif baru, yaitu deleteFirst, deleteLast, deleteAfter, nbList, dan deleteList. Prosedur deleteFirst mengambil elemen pertama ke variabel P lalu memindahkan First ke elemen berikutnya. Prosedur deleteLast menelusuri list sampai elemen kedua dari terakhir, lalu memutus hubungannya dengan elemen terakhir, dan jika list hanya berisi satu elemen maka First diatur menjadi Nil. Prosedur deleteAfter menghapus elemen yang berada tepat setelah elemen Prec dengan menghubungkan next dari Prec ke elemen sesudahnya. Pada ketiga prosedur tersebut, elemen yang dihapus disimpan di parameter P (call by reference) agar bisa dibebaskan memorinya dengan dealokasi. Fungsi nbList menelusuri list sambil menghitung jumlah elemen dan mengembalikannya bertipe int, sedangkan prosedur deleteList menghapus semua elemen satu per satu dengan deleteFirst dan dealokasi sampai First bernilai Nil. Pada main.cpp, list dari soal 1 dibuat terlebih dahulu dengan urutan 9, 12, 8, 0, 2. Kemudian deleteFirst menghapus node 9, deleteLast menghapus node 2, dan deleteAfter dengan Prec berupa L.First (node 12) menghapus node 8 yang berada tepat setelahnya, dan setiap node yang dihapus langsung dibebaskan memorinya dengan dealokasi. Setelah itu printInfo menampilkan sisa list yaitu 12 dan 0, dan nbList menampilkan jumlah node 2. Terakhir, deleteList menghapus seluruh node sehingga ditampilkan pesan list berhasil terhapus dan jumlah node menjadi 0.

## Kesimpulan
Pada praktikum modul 4 saya belajar terkait konsep singly linked list, yaitu salah satu bentuk struktur data berupa serangkaian elemen yang saling berkait dan hanya memiliki satu arah pointer, serta penerapannya dengan memisahkan program menjadi tiga bagian, yaitu file header (.h) untuk deklarasi type dan prosedur, file body (.cpp) untuk isi prosedur, dan file driver (main.cpp) sebagai program utama. Saya juga belajar menggunakan pointer untuk membentuk list yang dinamis, di mana setiap elemen terdiri dari data dan pointer next, sedangkan first digunakan untuk menunjuk elemen pertama. Selain itu, saya mempelajari operasi-operasi dasar pada list, seperti membentuk list kosong dengan createList, mengalokasikan dan membebaskan memori dengan alokasi (new) dan dealokasi (delete), menyisipkan elemen dengan insertFirst, insertAfter, dan insertLast, menghapus elemen dengan deleteFirst, deleteLast, dan deleteAfter, menampilkan isi list dengan printInfo, menghitung jumlah elemen dengan nbList, serta menghapus seluruh elemen dengan deleteList. Semua materi tersebut saya terapkan dalam guided dan dua latihan soal yang sudah diberikan, yaitu membuat program penyimpanan data mahasiswa (nama, NIM, dan umur) dalam linked list lengkap dengan proses insert dan delete, membuat ADT singly linked list yang berisi lima elemen dengan insertFirst sehingga menghasilkan list 9, 12, 8, 0, 2, serta melakukan penghapusan node 9, 2, dan 8 menggunakan deleteFirst, deleteLast, dan deleteAfter, menampilkan jumlah node, lalu menghapus seluruh isi list.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>[3] Laboratorium Informatika. MModul 4 - SINGLY LINKED LIST (BAGIAN PERTAMA). Praktikum Struktur Data, Fakultas Informatika, Telkom University.
