# <h1 align="center">Laporan Praktikum Modul 3 - Abstract Data Type (ADT)</h1>
<p align="center">Nehemia Pandu Indragiri - 109082500019</p>

## Dasar Teori
Abstract Data Type (ADT) adalah sebuah TYPE beserta sekumpulan PRIMITIF (operasi dasar) yang berlaku pada TYPE tersebut. Dalam ADT yang lengkap, biasanya disertakan juga definisi invarian dari TYPE dan aksioma yang berlaku. ADT bersifat STATIK. Definisi type dari sebuah ADT dapat mengandung ADT lain, misalnya ADT waktu yang terdiri dari ADT JAM dan ADT DATE, atau garis yang terdiri dari dua buah ADT POINT. Dalam bahasa C/C++, TYPE diterjemahkan menjadi struct, sedangkan PRIMITIF diterjemahkan menjadi fungsi atau prosedur. Primitif dikelompokkan menjadi konstruktor/kreator (membentuk nilai type, biasanya diawali Make), selector (mengakses komponen, biasanya diawali Get), prosedur pengubah nilai komponen, validator komponen, destruktor/dealokator (menghapus nilai objek sekaligus memorinya), baca/tulis untuk interface dengan input/output device, operator relasional, aritmatika, dan konversi dari tipe tersebut ke tipe dasar dan sebaliknya. ADT biasanya diimplementasikan menjadi dua modul utama dan satu modul driver. Modul pertama adalah definisi/spesifikasi type dan header primitif (file .h) yang berisi spesifikasi type serta primitif berupa fungsi (nama, domain, range, prekondisi) dan prosedur (initial state, final state, proses yang dilakukan). Modul kedua adalah body/realisasi dari primitif (file .cpp), yang sebaiknya memanfaatkan selector dan konstruktor. Modul ketiga adalah driver (main.cpp) yang memanggil ADT tersebut. Untuk menerapkan ADT, deklarasi type, variabel, dan fungsi dipisah ke file .h, sedangkan definisi fungsinya dipisah ke file .cpp. Agar file header tidak terbaca dua kali, digunakan #ifndef, #define, dan #endif. [3]
## Guided 

### 1. Mahasiswa

```C++
#ifndef Mahasiswa_H_Included
#define Mahasiswa_H_Included

struct mahasiswa {
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs (mahasiswa &m);
float rata2 (mahasiswa m);
#endif
```
```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

void inputMhs(mahasiswa &m) {
    cout << "Input NIM = ";
    cin >> (m).nim;
    cout << "Input Nilai 1 = ";
    cin >> (m).nilai1;
    cout << "Input Nilai 2 = ";
    cin >> (m).nilai2;
}

float rata2(mahasiswa m) {
    return float(m.nilai1 + m.nilai2) / 2;
    
}
```
```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

int main(){
    mahasiswa mhs;
    inputMhs (mhs);
    cout << "Rata-rata: " << rata2 (mhs);
    
    return 0;
}
```

Pada guided 1, saya belajar untuk membuat program yang menerapkan konsep ADT dengan memisahkan kode menjadi tiga file, yaitu mahasiswa.h, mahasiswa.cpp, dan main.cpp. File mahasiswa.h berisi deklarasi struct mahasiswa dengan field nim, nilai1, dan nilai2, serta deklarasi prosedur inputMhs dan fungsi rata2, yang dilindungi include guard (#ifndef, #define, #endif) agar tidak terbaca dua kali. File mahasiswa.cpp berisi isi dari kedua primitif tersebut. Prosedur inputMhs menerima parameter mahasiswa &m (call by reference) sehingga data yang diinput lewat cin langsung tersimpan di variabel aslinya. Fungsi rata2 menjumlahkan nilai1 dan nilai2, lalu membaginya dengan 2 dan mengembalikan hasilnya bertipe float. Pada main.cpp, program membuat variabel mhs bertipe mahasiswa, memanggil inputMhs untuk mengisi datanya, lalu menampilkan hasil rata-rata dari fungsi rata2 menggunakan cout.

## Unguided 

### 1. Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3*uts+0.4*uas+0.3*tugas.

```C++
#ifndef Mahasiswa_H_Included
#define Mahasiswa_H_Included

using namespace std;

struct mahasiswa {
    string nama;
    char nim[10];
    int nilaiUTS, nilaiUAS, nilaiTugas;
    float nilaiAkhir;
};

void inputMhs (mahasiswa &m);
float nilaiAkhir (mahasiswa m);
#endif

```

```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

void inputMhs(mahasiswa &m) {
    cout << "Input Nama = ";
    cin >> (m).nama;
    cout << "Input NIM = ";
    cin >> (m).nim;
    cout << "Input Nilai UTS = ";
    cin >> (m).nilaiUTS;
    cout << "Input Nilai UAS = ";
    cin >> (m).nilaiUAS;
    cout << "Input Nilai Tugas = ";
    cin >> (m).nilaiTugas;
}

float nilaiAkhir(mahasiswa m) {
    return float(0.3 * m.nilaiUTS + 0.4 * m.nilaiUAS + 0.3 * m.nilaiTugas);
}

void hasil(mahasiswa m) {
    cout << "Nama        :" << m.nama << endl;
    cout << "NIM         :" << m.nama << endl;
    cout << "Nilai UTS   :" << m.nama << endl;
    cout << "Nilai UAS   :" << m.nama << endl;
    cout << "Nilai Tugas :" << m.nama << endl;
    m.nilaiAkhir = nilaiAkhir(m);
}
```

```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

int main(){
    mahasiswa mhs[13];
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
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/NehemiaPandu/109082500019_Nehemia-Pandu-Indragiri_Struktur-Data-Laporan-Praktikum/blob/main/Modul%203/Unguided/Screenshot%20Output/Output%20Soal%201/Screenshot%202026-10-14%20123554.png?raw=true)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/NehemiaPandu/109082500019_Nehemia-Pandu-Indragiri_Struktur-Data-Laporan-Praktikum/blob/main/Modul%203/Unguided/Screenshot%20Output/Output%20Soal%201/Screenshot%202026-10-14%20123618.png?raw=true)

Program di atas merupakan program yang saya buat untuk menyimpan data mahasiswa (maksimal 10) ke dalam sebuah array bertipe struct mahasiswa, dengan field nama, nim, nilai UTS, nilai UAS, nilai tugas, dan nilai akhir. Program dibagi menjadi tiga file, yaitu mahasiswa.h untuk deklarasi struct dan fungsi, mahasiswa.cpp untuk isi fungsi, dan main.cpp sebagai program utama. Pertama, user memasukkan jumlah mahasiswa (1 sampai 10) menggunakan cin, dan jika jumlahnya di luar batas maka program menampilkan pesan kesalahan. Setelah itu program memanggil prosedur inputMhs dengan perulangan for untuk mengisi data setiap mahasiswa. Di akhir prosedur tersebut, fungsi hitungNilaiAkhir dipanggil untuk menghitung nilai akhir dengan rumus 0.3uts + 0.4uas + 0.3*tugas, lalu hasilnya disimpan ke field nilaiAkhir. Terakhir, semua data mahasiswa beserta nilai akhirnya ditampilkan menggunakan perulangan for dan cout.

### 2. Buatlah ADT pelajaran sebagai berikut di dalam file “pelajaran.h”:
Type pelajaran <
namaMapel : string
kodeMapel : string
>
function create_pelajaran( namapel : string,
 kodepel : string ) → pelajaran
procedure tampil_pelajaran( input pel : pelajaran )

Buatlah implementasi ADT pelajaran pada file “pelajaran.cpp”
Cobalah hasil implementasi ADT pada file “main.

using namespace std;
int main(){
string namapel = "Struktur Data";
string kodepel = "STD";
pelajaran pel = create_pelajaran(namapel,kodepel);
tampil_pelajaran(pel);
return 0;
}


```C++
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
```

```C++
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
```

```C++
    #include <iostream>
    #include "pelajaran.h"
    using namespace std;

    int main(){
        string namapel = "Struktur Data";
        string kodepel = "STD";
        pelajaran pel = create_pelajaran(namapel, kodepel);
        tampil_pelajaran(pel);

        return 0;
    }
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/NehemiaPandu/109082500019_Nehemia-Pandu-Indragiri_Struktur-Data-Laporan-Praktikum/blob/main/Modul%203/Unguided/Screenshot%20Output/Output%20Soal%202/Screenshot%202026-10-14%20122508.png?raw=true)


Program di atas merupakan program yang saya buat untuk menerapkan konsep ADT pada data pelajaran, dengan struct pelajaran yang memiliki field namaMapel dan kodeMapel bertipe string. Program dibagi menjadi tiga file, yaitu pelajaran.h untuk deklarasi type dan fungsi, pelajaran.cpp untuk isi fungsi, dan main.cpp untuk mencobanya. Pada main.cpp, variabel namapel dan kodepel diisi dengan “Struktur Data” dan “STD”, lalu keduanya dikirim ke fungsi create_pelajaran. Fungsi ini membuat variabel bertipe pelajaran, mengisi kedua field-nya dengan nilai yang diterima, lalu mengembalikannya ke main. Hasilnya disimpan di variabel pel, kemudian prosedur tampil_pelajaran dipanggil untuk menampilkan nama pelajaran dan kode pelajaran menggunakan cout.

### 3. Buatlah program dengan ketentuan :
- 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer
- fungsi/prosedur yang menampilkan isi sebuah array integer 2D
- fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu
STRUKTUR DATA 35
- fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah
pointer

```C++
#ifndef OPERASI_H_INCLUDED
#define OPERASI_H_INCLUDED

void tampilArray(int arr[3][3]);

void tukarIsiArray(int arr1[3][3], int arr2[3][3], int baris, int kolom);

void tukarPointer(int *ptr1, int *ptr2);

#endif 
```

```C++
#include <iostream>
#include "array.h"

using namespace std;

void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarIsiArray(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    if (baris >= 0 && baris < 3 && kolom >= 0 && kolom < 3) {
        int temp = arr1[baris][kolom];
        arr1[baris][kolom] = arr2[baris][kolom];
        arr2[baris][kolom] = temp;
    } else {
        cout << "Posisi di luar batas array!" << endl;
    }
}

void tukarPointer(int *ptr1, int *ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}
```

```C++
#include <iostream>
#include "array.h"

using namespace std;

int main() {
   
    int arrayA[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int arrayB[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    cout << "=== ARRAY AWAL ===" << endl;
    cout << "Array A:" << endl;
    tampilArray(arrayA);
    cout << "\nArray B:" << endl;
    tampilArray(arrayB);

    cout << "\n=== TUKAR ARRAY ===" << endl;
    cout << "Menukar posisi [1][1]" << endl;
    tukarIsiArray(arrayA, arrayB, 1, 1);
    
    cout << "\nArray A (Setelah ditukar):" << endl;
    tampilArray(arrayA);
    cout << "\nArray B (Setelah ditukar):" << endl;
    tampilArray(arrayB);

    cout << "\n=== TUKAR POINTER ===" << endl;
    int var1 = 100, var2 = 500;
    int *p1 = &var1;
    int *p2 = &var2;

    cout << "Sebelum ditukar -> var1: " << *p1 << ", var2: " << *p2 << endl;
    tukarPointer(p1, p2);
    cout << "Setelah ditukar -> var1: " << *p1 << ", var2: " << *p2 << endl;

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/NehemiaPandu/109082500019_Nehemia-Pandu-Indragiri_Struktur-Data-Laporan-Praktikum/blob/main/Modul%203/Unguided/Screenshot%20Output/Output%20Soal%203/Screenshot%202026-10-14%20122346.png?raw=true)


Program di atas merupakan program yang saya buat untuk melakukan operasi pada array 2D dan pointer. Program menggunakan dua array integer 2D berukuran 3x3 (arrayA dan arrayB) serta dua pointer integer (p1 dan p2) yang menunjuk ke variabel var1 dan var2. Program dibagi menjadi tiga file, yaitu array.h untuk deklarasi fungsi, array.cpp untuk isi fungsi, dan main.cpp sebagai program utama. Pertama, kedua array ditampilkan menggunakan fungsi tampilArray yang memakai perulangan for bersarang. Kemudian fungsi tukarIsiArray menukar elemen arrayA dan arrayB pada posisi tertentu, yaitu baris 1 dan kolom 1, dengan bantuan variabel temp, dan jika posisinya di luar batas array maka program menampilkan pesan kesalahan. Setelah itu kedua array ditampilkan kembali untuk melihat hasil penukaran. Pada bagian pointer, fungsi tukarPointer menerima alamat dari var1 dan var2 lalu menukar isi variabel yang ditunjuk oleh kedua pointer tersebut menggunakan operator *. Hasilnya, nilai var1 dan var2 saling bertukar dan ditampilkan menggunakan cout.

## Kesimpulan
Pada praktikum modul 3 saya belajar terkait konsep Abstract Data Type (ADT), yaitu sebuah type beserta sekumpulan primitif (operasi dasar) yang berlaku pada type tersebut, serta penerapannya dengan memisahkan program menjadi tiga bagian, yaitu file header (.h) untuk deklarasi type dan fungsi, file body (.cpp) untuk isi fungsi, dan file driver (main.cpp) sebagai program utama. Saya juga belajar menggunakan struct untuk menyimpan beberapa data dengan tipe berbeda dalam satu type, membuat konstruktor seperti create_pelajaran untuk membentuk nilai type, serta menggunakan include guard (#ifndef, #define, #endif) agar file header tidak terbaca dua kali. Semua materi tersebut saya terapkan dalam tiga latihan soal yang sudah diberikan, yaitu membuat program penyimpanan data mahasiswa (maksimal 10) dalam array dengan nilai akhir yang dihitung menggunakan fungsi, membuat ADT pelajaran beserta fungsi create_pelajaran dan prosedur tampil_pelajaran, serta membuat program dengan array 2D 3x3 dan pointer untuk menampilkan isi array, menukar isi dua array pada posisi tertentu, dan menukar isi variabel yang ditunjuk oleh dua pointer.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>[3] Laboratorium Informatika. Modul 3: Abstract Data Type (ADT). Praktikum Struktur Data, Fakultas Informatika, Telkom University.