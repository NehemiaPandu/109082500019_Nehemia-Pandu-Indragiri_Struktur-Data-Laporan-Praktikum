# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Nehemia Pandu Indragiri - 109082500019</p>

## Dasar Teori

C++ adalah bahasa pemrograman yang diciptakan oleh Bjarne Stroustrup di AT&T Bell Laboratories pada awal tahun 1980-an sebagai pengembangan dari bahasa C dengan tambahan fasilitas kelas, dan pada praktikum ini digunakan Code::Blocks sebagai IDE yang bersifat free, open-source, dan cross-platform. Program C++ terdiri dari fungsi-fungsi dengan main() sebagai program utama, di mana setiap pernyataan diakhiri titik koma (;) dan setiap variabel harus dideklarasikan terlebih dahulu sebelum digunakan. Data disimpan dalam variabel atau konstanta dengan tipe dasar seperti char, int, long, float, dan double, sedangkan masukan dan keluaran dilakukan dengan cin >> dan cout <<. Operasi pada data dilakukan menggunakan operator aritmatika, assignment, relasional, logika, dan unary seperti increment (++) dan decrement (--). Untuk pengambilan keputusan digunakan struktur kondisional if, if-else, dan switch, sedangkan pengulangan proses dilakukan dengan for, while, dan do...while yang semuanya memerlukan kondisi berhenti. Selain itu, struct dan array dipakai untuk mengelompokkan data, dan fungsi dipakai agar program lebih terstruktur serta dapat digunakan kembali. [3]

## Unguided 

### 1. Buatlah program yang menerima input-an dua buah bilangan betipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut. 

```C++
#include <iostream>
using namespace std;

int main(){
    float a, b;

    cout << "Masukkan bilangan a: ";
    cin >> a;
    cout << "Masukkan bilangan b: "; 
    cin >> b;

    cout << "\n----- OUTPUT -----" << endl;
    cout << "Hasil Penjumlahan: " << a + b << endl;
    cout << "Hasil Pengurangan: " << a - b << endl;
    cout << "Hasil Perkalian: " << a * b << endl;
    cout << "Hasil Pembagian: " << a / b << endl;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/NehemiaPandu/Struktur-Data-Laporan-Praktikum/blob/main/Modul%201/Screenshot%20Output/Output%20Soal%201/Screenshot%202026-09-30%20044609.png?raw=true)


##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/NehemiaPandu/Struktur-Data-Laporan-Praktikum/blob/main/Modul%201/Screenshot%20Output/Output%20Soal%201/Screenshot%202026-09-30%20051216.png?raw=true)

Program di atas merupakan program yang saya buat untuk menghitung dan menampilkan hasil penjumlahan, pengurangan, perkalian, dan pembagian dari 2 buah bilangan a dan b dengan tipe data float, lalu nilainya diinputkan oleh user menggunakan cin. Setelah itu program menghitung a + b, a - b, a * b, dan a / b, kemudian menampilkan semua hasilnya menggunakan cout.

### 2. Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di- input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100 contoh:   Gambar 1. 24 

```C++
#include <iostream>
using namespace std;

int main(){
    int a;

    cout << "Masukkan bilangan bulat (0-100): ";
    cin >> a;

    if (a < 0 || a > 100) {
        cout << "Masukan bilangan harus antara 0-100." << endl;
        return 0;
    }

    string satuan[] = {"nol", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};

    string hasil;
 
    if (a < 10) {
        hasil = satuan[a];
    } else if (a == 10) {
        hasil = "sepuluh";
    } else if (a == 11) {
        hasil = "sebelas";
    } else if (a < 20) {
        hasil = satuan[a - 10] + " belas";
    } else if (a < 100) {
        hasil = satuan[a / 10] + " puluh";
        if (a % 10 != 0) {
            hasil = hasil + " " + satuan[a % 10];
        }
    } else {
        hasil = "seratus";
    }
 
    cout << a << " : " << hasil << endl;
    return 0;

}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/NehemiaPandu/Struktur-Data-Laporan-Praktikum/blob/main/Modul%201/Screenshot%20Output/Output%20Soal%202/Screenshot%202026-09-30%20051457.png?raw=true)


##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/NehemiaPandu/Struktur-Data-Laporan-Praktikum/blob/main/Modul%201/Screenshot%20Output/Output%20Soal%202/Screenshot%202026-09-30%20051608.png?raw=true)

Program di atas merupakan program yang saya buat untuk mengubah bilangan bulat 0-100 yang diinputkan user menjadi bentuk tulisan. contoh: 79 menjadi "tujuh puluh sembilan". Angka satuan 0-9 disimpan dalam sebuah array satuan, sehingga dapat dipanggil langsung berdasarkan indeksnya. Pengubahan dilakukan dengan struktur kondisional if-else yang menyesuaikan pola penulisan tiap rentang angka. Jika angka di luar 0-100, program akan menampilkan pesan peringatan.

### 3. Buatlah program yang dapat memberikan input dan output sbb. Gambar 1. 25 Mirror 

```C++
#include <iostream>
using namespace std;

int main () {
    int x;

    cout << "Input: ";
    cin >> x;
    
    cout << "\nOutput: " << endl;

    int spasi = 3;

    for (int i = x; i >= 0; i--) {
        for (int s = 0; s < spasi + 2 * (x - i); s++) {
            cout << " ";
        }
      
    for (int j = i; j >= 1; j--) {
        cout << j << " ";
    }
    
    cout << "*";
       
    for (int j = 1; j <= i; j++) {
        cout << " " << j;
    }
    
        cout << endl;

    }

    return 0;

}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/NehemiaPandu/Struktur-Data-Laporan-Praktikum/blob/main/Modul%201/Screenshot%20Output/Output%20Soal%203/Screenshot%202026-09-30%20051346.png?raw=true)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/NehemiaPandu/Struktur-Data-Laporan-Praktikum/blob/main/Modul%201/Screenshot%20Output/Output%20Soal%203/Screenshot%202026-09-30%20051402.png?raw=true)

Program di atas merupakan program yang saya buat untuk menampilkan pola mirror berdasarkan angka yang diinputkan user. Pola dibentuk dari angka menurun di sisi kiri, tanda * di tengah, dan angka menaik di sisi kanan, dengan jumlah angka yang berkurang di setiap baris. Program ini menggunakan nested loop, perulangan luar mengatur baris, dan perulangan dalam mengatur spasi serta angka di setiap baris.

## Kesimpulan
Pada praktikum modul 1 saya belajar terkait struktur dasar program C++, yaitu penggunaan #include < iostream>, fungsi main(), deklarasi variabel dengan tipe data yang sesuai, serta input dan output menggunakan cin dan cout. Saya juga belajar menggunakan operator aritmatika untuk mengolah data, struktur kondisional if-else untuk mengambil keputusan, dan perulangan for termasuk nested loop untuk membentuk pola keluaran. Semua materi tersebut saya terapkan dalam tiga latihan soal yang sudah diberikan yaitu menghitung operasi aritmatika dua bilangan, mengubah angka 0 sampai 100 menjadi tulisan, dan membuat pola mirror.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>[3] Laboratorium Informatika. Modul 1: Code Blocks IDE dan Pengenalan Bahasa C++ (Bagian Pertama). Praktikum Struktur Data, Fakultas Informatika, Telkom University.
