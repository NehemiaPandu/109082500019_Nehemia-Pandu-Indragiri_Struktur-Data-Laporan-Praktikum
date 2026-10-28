# <h1 align="center">Laporan Praktikum Modul 5 - Singly Linked List (Bagian Kedua)</h1>
<p align="center">Nehemia Pandu Indragiri - 109082500019</p>

## Dasar Teori
Singly linked list merupakan struktur data dinamis yang tersusun dari serangkaian elemen (node) yang saling terhubung satu arah melalui pointer, di mana setiap node terdiri dari info yang menyimpan data dan next yang menyimpan alamat node berikutnya. Node terakhir menunjuk ke Nil dan list dinyatakan kosong apabila first bernilai Nil. Elemen yang ditunjuk oleh pointer P dapat diakses menggunakan operator panah, yaitu P->info untuk mengambil data dan P->next untuk mengambil alamat elemen selanjutnya. Seluruh operasi pada singly linked list disusun dalam bentuk ADT yang terbagi menjadi dua file, yaitu file .h yang berisi deklarasi type (infotype, address, elmlist, dan list) beserta prototype primitif, serta file .cpp yang berisi realisasi dari primitif tersebut, kemudian dipanggil melalui main.cpp. Agar file header tidak terbaca dua kali, digunakan #ifndef, #define, dan #endif. Operasi dasar pada singly linked list meliputi pembentukan list kosong (createList), pengecekan list kosong (ListEmpty), pengalokasian memori (alokasi) dan pengembalian memori ke sistem (dealokasi), penambahan elemen (insertFirst, insertAfter, dan insertLast), penghapusan elemen (delFirst, delLast, delAfter, dan delP), penampilan seluruh isi list (printInfo), penghitungan jumlah elemen (nbList), serta operasi terhadap seluruh list seperti penghapusan semua elemen (delAll), pembalikan urutan elemen (invertList), dan penyalinan list (copyList dan fCopyList). Salah satu operasi dasar yang menjadi pokok pembahasan pada modul ini adalah searching, yaitu pencarian terhadap node tertentu dengan cara mengunjungi setiap node dari elemen pertama dan berhenti setelah node yang dicari ditemukan. Fungsi findElm mengembalikan alamat elemen yang memiliki info sesuai dengan nilai yang dicari, dan mengembalikan Nil apabila tidak ditemukan, sedangkan fFindElm memeriksa apakah suatu alamat elemen terdapat di dalam list dengan nilai kembalian true atau false, dan findBefore mengembalikan alamat elemen sebelum P. Dengan adanya operasi searching, operasi lain seperti insert after, delete after, dan update menjadi lebih mudah dilakukan karena alamat elemen acuan dapat diketahui terlebih dahulu. Proses penelusuran (traversal) dari first hingga Nil dengan memanfaatkan pointer next juga digunakan untuk menampilkan isi list dan menghitung jumlah total info seluruh elemen. Pada operasi insertFirst, elemen baru selalu ditempatkan di awal list sehingga elemen yang dimasukkan paling akhir akan menjadi elemen pertama, misalnya data yang dimasukkan berurutan 2, 0, 8, 12, dan 9 akan menghasilkan list dengan urutan 9, 12, 8, 0, dan 2. [3]

## Guided 

### 1. Buah

```C++
//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include<iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah; 
    float harga;
};

typedef buah dataBuah; //Memberikan nama alias databuah untuk struct buah.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataBuah isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
//Materi modul 4
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

//materi modul 5 (update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

//materi modul 5 (searching)
void FindNodeByData(linkedlist list, string data);
void FindNodeByAddress(linkedlist list, address node);
void FindNodeByRange(linkedlist list, float hargaAwal, float HargaAkhir);

#endif
```

```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;   
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
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
void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
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
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - UPDATE -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - SEARCHING -----*/
//prosedur-prosedur untuk searching data
//prosedur untuk mencari node berdasarkan data
void FindNodeByData(linkedlist list, string data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->isidata.nama == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan alamat node
void FindNodeByAddress(linkedlist list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan range data (range harga)
void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if(harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}
```

```C++
#include "listBuah.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    printList(List);
    updateLast(List);
    printList(List);
    updateAfter(List, nodeD);
    printList(List);
    
    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;
    
    FindNodeByData(List, "kelapa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 5000, 10000);
    
    delFirst(List);
    printList(List);
    delLast(List);
    printList(List);
    delAfter(List, nodeD, nodeC);
    printList(List);

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
Pada guided ini, saya belajar untuk membuat program singly linked list yang menerapkan konsep ADT dengan memisahkan kode menjadi tiga file, yaitu listBuah.h, listBuah.cpp, dan main.cpp. File listBuah.h berisi definisi Nil sebagai NULL, deklarasi struct buah dengan field nama, jumlah, dan harga, alias dataBuah, alias address sebagai pointer ke struct node, struct node yang berisi isidata dan next, serta struct linkedlist dengan field first sebagai penunjuk node pertama. File ini juga berisi prototipe semua fungsi dan prosedur yang dipakai, serta dilindungi include guard (#ifndef, #define, #endif) agar tidak terbaca dua kali. File listBuah.cpp berisi isi dari primitif-primitif tersebut. Fungsi isEmpty mengecek apakah first bernilai Nil, sedangkan prosedur createList mengatur first menjadi Nil untuk membentuk list kosong. Fungsi alokasi membuat node baru menggunakan new, mengisi isidata sesuai parameter nama, jumlah, dan harga, dan mengatur next menjadi Nil, sedangkan dealokasi mengembalikan memori node ke sistem menggunakan delete. Untuk penyisipan, insertFirst menempatkan node di awal list, insertAfter menyisipkan node setelah node Prev, dan insertLast menelusuri list sampai node terakhir lalu menyambungkan node baru di sana. Untuk penghapusan, delFirst, delLast, dan delAfter masing-masing menghapus node pertama, node terakhir, dan node setelah nodePrev, lalu memanggil dealokasi agar memorinya dibebaskan. Prosedur updateFirst, updateLast, dan updateAfter digunakan untuk mengubah isidata pada node pertama, node terakhir, dan node setelah nodePrev dengan data baru yang diinputkan pengguna. Untuk pencarian, FindNodeByData mencari node berdasarkan nama buah, FindNodeByAddress mencari node berdasarkan alamatnya, dan FindNodeByRange menampilkan seluruh node yang harganya berada dalam rentang tertentu, dengan masing-masing menampilkan posisi node yang ditemukan atau pesan jika tidak ditemukan. Prosedur printList menelusuri list dan menampilkan nama buah, jumlah, dan harga setiap node, fungsi nbList menghitung jumlah node dan mengembalikannya bertipe int, dan prosedur deleteList menghapus seluruh node lalu mengatur first kembali ke Nil. Semua prosedur yang mengubah susunan list menerima parameter linkedlist &List (call by reference) agar perubahan langsung tersimpan di list aslinya. Pada main.cpp, program membuat variabel List bertipe linkedlist, memanggil createList, lalu mengalokasikan lima node untuk Jeruk, Apel, Pir, Semangka, dan Durian. Kelima node disisipkan menggunakan insertFirst, insertLast, dan insertAfter sehingga urutan list menjadi Jeruk, Pir, Semangka, Apel, Durian dengan jumlah 5 node. Setelah itu updateFirst, updateLast, dan updateAfter mengubah data node pertama, node terakhir, dan node setelah Semangka (yaitu Apel), kemudian FindNodeByData, FindNodeByAddress, dan FindNodeByRange digunakan untuk mencari node berdasarkan nama, alamat nodeC, dan rentang harga 5000 sampai 10000. Berikutnya delFirst menghapus node pertama, delLast menghapus node terakhir, dan delAfter menghapus Semangka yang berada setelah Pir sehingga tersisa Pir dan Apel dengan jumlah 2 node. Terakhir, deleteList menghapus seluruh node sehingga printList menampilkan list kosong dan nbList menampilkan jumlah 0.

## Unguided 

### 2.  Buatlah ADT Singly Linked list sebagai berikut di dalam file “Singlylist.h”:
Type infotype : int
Type address : pointer to ElmList
Type ElmList <
info : infotype
next : address
>
Type List : < First : address >
procedure CreateList( input/output L : List )
function alokasi( x : infotype ) → address
procedure dealokasi(input/output P : address )
procedure printInfo( input L : List )
procedure insertFirst(input/output L : List, input P :address)

Kemudian buat implementasi ADT Singly Linked list pada file “Singlylist.cpp”.
Adapun isi data
Gambar 5-1 Ilustrasi elemen

Cobalah hasil implementasi ADT pada file “main.cpp”

int main()
{
List L;
address P1, P2, P3, P4, P5 = Nil;
createList(L);
P1 = alokasi(2);
insertFirst(L,P1);
P2 = alokasi(0);
insertFirst(L,P2);
P3 = alokasi(8);
insertFirst(L,P3);
P4 = alokasi(12);
insertFirst(L,P4);
P5 = alokasi(9);
insertFirst(L,P5);
printInfo(L)
return 0;
}

```C++
#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED

#include <iostream>
using namespace std;

#define Nil NULL
#define info(P) (P)->info
#define next(P) (P)->next
#define first(L) ((L).first)

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address first;
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
    first(L) = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    info(P) = x;
    next(P) = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = first(L);
    while (P != Nil) {
        cout << info(P) << " ";
        P = next(P);
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    next(P) = first(L);
    first(L) = P;
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
### Output Unguided 2 :

##### Output 1

![Screenshot Output Unguided 2_1](https://github.com/NehemiaPandu/109082500019_Nehemia-Pandu-Indragiri_Struktur-Data-Laporan-Praktikum/blob/main/Modul%205/Unguided/Screenshot%20Output/Output%20Soal%202/image.png?raw=true)


Program di atas merupakan program yang saya buat untuk membuat singly linked list dengan menerapkan konsep ADT yang dibagi menjadi tiga file, yaitu Singlylist.h untuk deklarasi, Singlylist.cpp untuk isi prosedur, dan main.cpp sebagai program utama. File Singlylist.h berisi definisi Nil sebagai NULL, alias infotype bertipe int, alias address sebagai pointer ke struct ElmList, struct ElmList dengan field info dan next, serta struct List dengan field first sebagai penunjuk elemen pertama. File ini juga berisi prototipe prosedur dan dilindungi include guard (#ifndef, #define, #endif). Pada Singlylist.cpp, prosedur createList menerima parameter List &L (call by reference) lalu mengatur first menjadi Nil untuk membentuk list kosong. Fungsi alokasi membuat elemen baru dengan new, mengisi info sesuai parameter x, dan mengatur next menjadi Nil, sedangkan dealokasi mengembalikan memori elemen ke sistem dengan delete. Prosedur insertFirst menyisipkan elemen di awal list dengan mengarahkan next dari P ke first, lalu menjadikan P sebagai first yang baru. Prosedur printInfo menelusuri list dari first sampai Nil sambil menampilkan info setiap elemen yang dipisahkan spasi. Pada main.cpp, program membuat variabel L bertipe List, memanggil createList, lalu mengalokasikan lima elemen bernilai 2, 0, 8, 12, dan 9 yang disisipkan satu per satu dengan insertFirst. Karena setiap elemen disisipkan di awal, urutan list menjadi 9, 12, 8, 0, 2 dan itulah yang ditampilkan oleh printInfo.

### 3.  Carilah elemen dengan info 8 dengan membuat fungsi baru.
fungsi findElm( L : List, x : infotype ) : address

```C++
#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED

#include <iostream>
using namespace std;

#define Nil NULL
#define info(P) (P)->info
#define next(P) (P)->next
#define first(L) ((L).first)

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

address findElm(List L, infotype x);

#endif
```
```C++
#include "Singlylist.h"

void createList(List &L) {
    first(L) = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    info(P) = x;
    next(P) = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = first(L);
    while (P != Nil) {
        cout << info(P) << " ";
        P = next(P);
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    next(P) = first(L);
    first(L) = P;
}

address findElm(List L, infotype x) {
    address P = first(L);
    while (P != Nil) {
        if (info(P) == x) {
            return P;
        }
        P = next(P);
    }
    return Nil;
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

    address P = findElm(L, 8);
    if (P != Nil) {
        cout << "8 ditemukan dalam list" << endl;
    } else {
        cout << "8 tidak ditemukan dalam list" << endl;
    }

    return 0;
}
```

### Output Unguided 3 :

##### Output 1

![Screenshot Output Unguided 3_1](https://github.com/NehemiaPandu/109082500019_Nehemia-Pandu-Indragiri_Struktur-Data-Laporan-Praktikum/blob/main/Modul%205/Unguided/Screenshot%20Output/Output%20Soal%203/image.png?raw=true)


Pada soal ini, program dikembangkan dengan menambahkan fungsi findElm untuk mencari elemen yang memiliki info bernilai 8 di dalam list. Fungsi findElm dideklarasikan pada Singlylist.h dengan parameter List L dan infotype x, serta mengembalikan address. Pada Singlylist.cpp, fungsi ini membuat pointer P yang dimulai dari first, lalu menelusuri list selama P tidak sama dengan Nil. Setiap elemen yang dikunjungi akan dibandingkan nilai info-nya dengan x, jika sama maka fungsi langsung mengembalikan alamat elemen tersebut, jika tidak maka P berpindah ke elemen berikutnya melalui next. Apabila penelusuran selesai dan tidak ada elemen yang cocok, fungsi mengembalikan Nil. Pada main.cpp, hasil pemanggilan findElm(L, 8) disimpan dalam variabel P, lalu diperiksa dengan percabangan if. Karena elemen bernilai 8 ada di dalam list, hasilnya bukan Nil sehingga program menampilkan tulisan “8 ditemukan dalam list”.

### 4. Hitunglah jumlah total info seluruh elemen (9+12+8+0+2=31).

```C++
#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED

#include <iostream>
using namespace std;

#define Nil NULL
#define info(P) (P)->info
#define next(P) (P)->next
#define first(L) ((L).first)

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

address findElm(List L, infotype x);

int totalInfo(List L);

#endif
```

```C++
#include "Singlylist.h"

void createList(List &L) {
    first(L) = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    info(P) = x;
    next(P) = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = first(L);
    while (P != Nil) {
        cout << info(P) << " ";
        P = next(P);
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    next(P) = first(L);
    first(L) = P;
}

address findElm(List L, infotype x) {
    address P = first(L);
    while (P != Nil) {
        if (info(P) == x) {
            return P;
        }
        P = next(P);
    }
    return Nil;
}

int totalInfo(List L) {
    int total = 0;
    address P = first(L);
    while (P != Nil) {
        total += info(P);
        P = next(P);
    }
    return total;
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

    address P = findElm(L, 8);
    if (P != Nil) {
        cout << "8 ditemukan dalam list" << endl;
    } else {
        cout << "8 tidak ditemukan dalam list" << endl;
    }

    cout << "Total info dari kelima elemen adalah " << totalInfo(L) << endl;

    return 0;
}
```
### Output Unguided 4 :

##### Output 1

![Screenshot Output Unguided 4_1](https://github.com/NehemiaPandu/109082500019_Nehemia-Pandu-Indragiri_Struktur-Data-Laporan-Praktikum/blob/main/Modul%205/Unguided/Screenshot%20Output/Output%20Soal%204/image.png?raw=true)

Pada soal ini, program ditambahkan fungsi totalInfo untuk menghitung jumlah info dari seluruh elemen di dalam list. Fungsi totalInfo dideklarasikan pada Singlylist.h dengan parameter List L dan mengembalikan nilai bertipe int. Pada Singlylist.cpp, fungsi ini menyiapkan variabel total yang diawali dengan nilai 0 dan pointer P yang dimulai dari first. Selama P tidak sama dengan Nil, info dari elemen yang sedang ditunjuk ditambahkan ke total, kemudian P berpindah ke elemen berikutnya melalui next. Setelah penelusuran selesai, nilai total dikembalikan sebagai hasil fungsi. Pada main.cpp, hasil pemanggilan totalInfo(L) ditampilkan bersama teks keterangan. Karena list berisi elemen 9, 12, 8, 0, dan 2, maka hasil penjumlahannya adalah 31 dan itulah yang ditampilkan oleh program.

## Kesimpulan
Pada praktikum modul 5 saya belajar terkait lanjutan dari konsep singly linked list, yaitu struktur data dinamis berupa serangkaian elemen yang saling berkait dan hanya memiliki satu arah pointer, dengan penekanan pada operasi update dan searching. Penerapannya tetap memisahkan program menjadi tiga bagian, yaitu file header (.h) untuk deklarasi type dan prosedur, file body (.cpp) untuk isi prosedur, dan file driver (main.cpp) sebagai program utama. Saya juga mengulang penggunaan pointer untuk membentuk list yang dinamis, di mana setiap elemen terdiri dari data dan pointer next, sedangkan first digunakan untuk menunjuk elemen pertama. Selain itu, saya mempelajari operasi update, yaitu mengubah isi data pada node tertentu dengan updateFirst, updateLast, dan updateAfter, serta operasi searching, yaitu mencari node dengan menelusuri list dari elemen pertama sampai node yang dicari ditemukan atau sampai Nil. Pada guided, searching dilakukan dengan tiga cara, yaitu FindNodeByData untuk mencari berdasarkan nama buah, FindNodeByAddress untuk mencari berdasarkan alamat node, dan FindNodeByRange untuk mencari semua node yang harganya berada dalam rentang tertentu. Pada latihan, searching diterapkan dengan fungsi findElm yang mengembalikan alamat elemen yang memiliki info sesuai nilai yang dicari dan mengembalikan Nil apabila tidak ditemukan. Saya juga belajar bahwa proses penelusuran (traversal) dari first hingga Nil dengan memanfaatkan pointer next dapat dipakai untuk menghitung total info seluruh elemen melalui fungsi totalInfo. Semua materi tersebut saya terapkan dalam guided dan latihan soal yang sudah diberikan, yaitu membuat program penyimpanan data buah (nama, jumlah, dan harga) dalam linked list lengkap dengan proses insert, update, searching, dan delete, kemudian membuat ADT singly linked list yang berisi lima elemen dengan insertFirst sehingga menghasilkan list 9, 12, 8, 0, 2, mencari elemen dengan info 8 menggunakan findElm, serta menghitung total info seluruh elemen menggunakan totalInfo sehingga menghasilkan nilai 31.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>[3] Laboratorium Informatika. Modul 5 - SINGLY LINKED LIST (BAGIAN KEDUA). Praktikum Struktur Data, Fakultas Informatika, Telkom University.