# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Nehemia Pandu Indragiri - 109082500019</p>

## Dasar Teori
isi dengan penjelasan dasar teori disertai referensi jurnal (gunakan kurung siku [] untuk pernyataan yang mengambil refernsi dari jurnal).
contoh :
Linked list atau yang disebut juga senarai berantai adalah Salah satu bentuk struktur data yang berisi kumpulan data yang tersusun secara sekuensial, saling bersambungan, dinamis, dan terbatas[1]. Linked list terdiri dari sejumlah node atau simpul yang dihubungkan secara linier dengan bantuan pointer.

## Unguided 

### 1. (isi dengan soal unguided 1)

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
![Screenshot Output Unguided 1_1]![(https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).pn](https://github.com/NehemiaPandu/Struktur-Data-Laporan-Praktikum/blob/main/Modul%201/Screenshot%20Output/Output%20Soal%201/Screenshot%202026-09-30%20044609.png?raw=true)


##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

Program di atas merupakan program yang saya buat untuk menghitung dan menampilkan hasil penjumlahan, pengurangan, perkalian, dan pembagian dari 2 buah bilangan a dan b.

### 2. (isi dengan soal unguided 2)

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
![Screenshot Output Unguided 2_1]![(https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)](https://github.com/NehemiaPandu/Struktur-Data-Laporan-Praktikum/blob/main/Modul%201/Screenshot%20Output/Output%20Soal%202/Screenshot%202026-09-30%20045037.png?raw=true)

contoh :
![Screenshot Output Unguided 2_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided2-1.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 2

### 3. (isi dengan soal unguided 3)

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
![Screenshot Output Unguided 3_1]![(https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)](https://github.com/NehemiaPandu/Struktur-Data-Laporan-Praktikum/blob/main/Modul%201/Screenshot%20Output/Output%20Soal%203/Screenshot%202026-09-30%20045139.png?raw=true)

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
<br>...
