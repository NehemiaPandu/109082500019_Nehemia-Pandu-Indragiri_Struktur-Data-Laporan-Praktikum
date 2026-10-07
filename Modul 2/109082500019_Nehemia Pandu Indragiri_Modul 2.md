# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahas C++ (Bagian Kedua)</h1>
<p align="center">Nehemia Pandu Indragiri - 109082500019</p>

## Dasar Teori
Array adalah kumpulan data dengan nama yang sama dan tipe data yang sama, yang elemennya diakses melalui indeks mulai dari 0, dan dapat berbentuk satu dimensi, dua dimensi (seperti tabel), maupun berdimensi banyak. Setiap data program disimpan di memori yang memiliki alamat (address), dan alamat suatu variabel dapat diketahui dengan operator &. Pointer adalah variabel yang menyimpan alamat memori variabel lain, dideklarasikan dengan tipe *nama_variabel, dan nilai yang ditunjuknya dapat diakses dengan operator *. Pointer memiliki hubungan erat dengan array, karena pa = &a[0] membuat pa menunjuk ke elemen pertama array, sehingga *(pa + i) sama dengan a[i]. String pada C++ pada dasarnya adalah array dari karakter yang diakhiri karakter '\0', dan dapat diakses melalui indeks maupun pointer karakter. Fungsi adalah blok kode yang dirancang untuk tugas tertentu agar program lebih terstruktur dan mengurangi duplikasi kode, dengan bentuk umum tipe_keluaran nama_fungsi(daftar_parameter). Prosedur adalah fungsi bertipe void yang tidak mengembalikan nilai. Parameter formal adalah variabel pada definisi fungsi, sedangkan parameter aktual adalah nilai atau variabel yang dipakai saat fungsi dipanggil. Parameter dapat dilewatkan dengan tiga cara: call by value yang hanya menyalin nilai sehingga variabel asli tidak berubah, serta call by pointer (parameter *x, dipanggil dengan &a) dan call by reference (parameter &x) yang melewatkan alamat sehingga variabel asli dapat berubah. [3]

## Guided 

### 1. Array

```C++
#include <iostream>
using namespace std;

int main(){
    int nilai[5];

    nilai[0] = 80;
    nilai[1] = 75;
    nilai[2] = 90;
    nilai[3] = 85;
    nilai[4] = 95;

    for (int i = 0; i < 5; i++) {
        cout << "Nilai ke-" << i + 1 << " = " << nilai[i] << endl;
    }

    return 0;
}
```
Program di atas merupakan program sederhana yang berfungsi untuk menyimpan lima buah nilai ke dalam sebuah array, lalu menampilkannya satu per satu ke layar dengan menggunakan perulangan for. Array nilai dideklarasikan dengan tipe int dan berukuran 5, sehingga bisa menampung lima data bilangan bulat.

### 2. Array 2D

```C++
#include <iostream>
using namespace std;

int main() {
    int nilai[3][3] = {
        {80, 75, 90},
        {85, 90, 88},
        {70, 80, 85}
    };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << nilai [i][j] << " ";
        }

        cout << endl;
    }
    cout << endl;
    cout << nilai[1][2] << endl;

    return 0;
}
```
Program di atas merupakan array dua dimensi yang berfungsi untuk menyimpan sembilan nilai dalam bentuk tabel 3 baris dan 3 kolom, lalu menampilkannya menggunakan perulangan for bersarang.
Cara kerjanya perulangan luar (i) mengatur baris dan perulangan dalam (j) mengatur kolom, sehingga setiap nilai dicetak dengan pemisah spasi dan endl pindah baris setiap satu baris selesai. Setelah itu program mencetak nilai[1][2], yaitu data pada baris indeks 1 dan kolom indeks 2.

### 3. Array 3D

```C++
#include <iostream>
using namespace std;

int main() {
    int data [2][2][3] = {
        {
            {10, 20, 30},
            {40, 50, 60}
        },
        {
            {70, 80, 90},
            {100, 110, 120}
        }
    };

    cout << data[0][1][2] << endl;

    return 0;
}
```
Program di atas merupakan array tiga dimensi yang berfungsi untuk menyimpan 12 nilai dalam 2 tabel, dengan setiap tabel terdiri dari 2 baris dan 3 kolom, lalu menampilkan salah satu elemennya.
Cara kerjanya indeks pertama memilih tabel, indeks kedua memilih baris, dan indeks ketiga memilih kolom. Program mencetak data[0][1][2], yaitu tabel pertama, baris kedua, kolom ketiga.

### 4. Function

```C++
#include <iostream>
using namespace std;

int maks3(int a, int b, int c) {
    int temp_max = a;

    if (b > temp_max) 
        temp_max = b;
        
    if (c > temp_max) 
        temp_max = c;

    return temp_max;
}

int main() {
    int x, y, z;

    cout << "Masukkan nilai 1: ";
    cin >> x;

    cout << "Masukkan nilai 2: ";
    cin >> y;

    cout << "Masukkan nilai 3: ";
    cin >> z;

    cout << "Nilai maksimum = " << maks3(x,y,z);

    return 0;
    
}
```
Program di atas merupakan fungsi bernama maks3 yang berfungsi untuk mencari nilai terbesar dari tiga bilangan yang diinputkan user.
Cara kerjanya user memasukkan tiga bilangan ke x, y, dan z, lalu ketiganya dikirim ke fungsi maks3. Di dalam fungsi, temp_max diisi a, kemudian diganti b jika b lebih besar, dan diganti c jika c lebih besar. Nilai temp_max dikembalikan dengan return dan ditampilkan di main().

### 5. Procedure

```C++
#include <iostream>
using namespace std;

void sapa() {
    cout << "Selamat datang di Praktikum Struktur Data" << endl;
}

int main() {
    sapa();
    return 0;
}
```
Program di atas merupakan prosedur bernama sapa yang berfungsi untuk menampilkan pesan sambutan. Prosedur bertipe void, sehingga hanya menjalankan tugas tanpa mengembalikan nilai.
Cara kerjanya program berjalan dari main(), lalu memanggil sapa(). Saat dipanggil, isi prosedur dijalankan dan teks tampil di layar.

### 6. Pointer 1

```C++
#include <iostream>
using namespace std;

int main(){
    int angka = 100;

    int *pointer;

    pointer = &angka;

    cout << "Nilai angka: " << angka << endl;
    cout << "Alamat angka: " << &angka << endl;
    cout << "Isi angka: " << pointer << endl;
    cout << "Nilai dari angka: " << *pointer << endl;

    return 0;
}
```
penjelasan singkat guided 6

### 7. Pointer 2

```C++
#include <iostream>
using namespace std;

int main() {
    char arr[6];

    arr[0] = 'a';
    arr[1] = 'b';
    arr[2] = 'c';
    arr[3] = 'b';
    arr[4] = 'd';
    arr[5] = 'e';

    cout << arr[3] << endl;
    cout << &(arr[4]) << endl;

    return 0;

    
}
```
penjelasan singkat guided 7

### 8. Address

```C++
#include <iostream>
using namespace std;

int main(){
    int angka = 100;

    cout << "Nilai angka: " << angka << endl;
    cout << "Alamat angka: " << &angka << endl;

    return 0;
}
```
Program di atas merupakan penggunaan operator alamat (&) yang berfungsi untuk menampilkan nilai sebuah variabel beserta alamat memorinya.
Cara kerjanya variabel angka diisi 100, lalu angka mencetak nilainya dan &angka mencetak alamat memori tempat angka disimpan dalam format heksadesimal.

### 9. callByPointerReferenceValue

```C++
#include <iostream>
using namespace std;

//BY POINTER
void tukar(int *x, int *y) {
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a = 4;
    int b = 6;

    cout << "Sebelum ditukar: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    tukar(&a, &b);

    cout << "\nSetelah ditukar: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}


// BY REFERENCE
// #include <iostream>
// using namespace std;

// void tukar(int &x, int &y) {
//     int temp;
//     temp = x;
//     x = y;
//     y = temp;
// }

// int main() {
//     int a = 4;
//     int b = 6;

//     cout << "Sebelum ditukar: " << endl;
//     cout << "a = " << a << endl;
//     cout << "b = " << b << endl;

//     tukar(a, b); 

//     cout << "\nSetelah ditukar: " << endl;
//     cout << "a = " << a << endl;
//     cout << "b = " << b << endl;
    
//     return 0;
// }

//BY VALUE
// #include <iostream>
// using namespace std;

// void tukar(int x, int y) {
//     int temp;
//     temp = x;
//     x = y;
//     y = temp;
// }

// int main() {
//     int a = 4;
//     int b = 6;

//     cout << "Sebelum ditukar: " << endl;
//     cout << "a = " << a << endl;
//     cout << "b = " << b << endl;

//     // Memanggil fungsi dengan mengirimkan nilainya saja
//     tukar(a, b);

//     // Hasil print di bawah ini angkanya akan tetap a = 4 dan b = 6
//     cout << "\nSetelah ditukar: " << endl;
//     cout << "a = " << a << endl;
//     cout << "b = " << b << endl;
    
//     return 0;
// }
```
Perbedaan ketiganya terletak pada cara fungsi menerima data dan dampaknya ke variabel asli. Call by value hanya menyalin nilai (int x, int y) sehingga variabel asli tidak berubah, sedangkan call by pointer (int *x, int *y, dipanggil dengan tukar(&a, &b)) dan call by reference (int &x, int &y, dipanggil dengan tukar(a, b)) sama-sama mengubah variabel asli karena yang diterima adalah alamatnya. Bedanya, call by pointer harus menulis & saat memanggil dan * saat mengakses nilai, sedangkan call by reference cukup menulis & pada parameter sehingga penulisannya lebih sederhana.

## Unguided 

### 1. Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3 

```C++
#include <iostream>
using namespace std;

void cetakMatriks(int matriks[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int matriks[10][3][3];
    int n;

    cout << "Banyak Matriks (2 - 10): ";
    cin >> n;

    if (n < 2 || n > 10) {
        cout << "Banyak matriks harus antara 2 sampai 10." << endl;
        return 0;
    }

    for (int m = 0; m < n; m++) {
        cout << "\nMasukkan nilai Matriks ke-" << m + 1 << " (3x3)" << endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << "Input baris " << i << ", kolom " << j << " : ";
                cin >> matriks[m][i][j];
            }
        }
        cout << "\n==========================" << endl;
    }

    for (int m = 0; m < n; m++) {
        cout << "\n--------Matriks " << m + 1 << endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << matriks[m][i][j] << " ";
            }
            cout << endl;
        }
    }
    cout << endl;

    cout << "Hasil Penjumlahan Matriks" << endl;
    int hasilTambah[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            hasilTambah[i][j] = matriks[0][i][j];
        }
    }
    for (int m = 1; m < n; m++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                hasilTambah[i][j] += matriks[m][i][j];
            }
        }
    }
    cetakMatriks(hasilTambah);

    cout << "Hasil Pengurangan Matriks" << endl;
    int hasilKurang[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            hasilKurang[i][j] = matriks[0][i][j];
        }
    }
    for (int m = 1; m < n; m++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                hasilKurang[i][j] -= matriks[m][i][j];
            }
        }
    }
    cetakMatriks(hasilKurang);

    cout << "Hasil Perkalian Matriks" << endl;
    int hasilKali[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            hasilKali[i][j] = matriks[0][i][j];
        }
    }
    for (int m = 1; m < n; m++) {
        int tempKali[3][3] = {0};

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    tempKali[i][j] += hasilKali[i][k] * matriks[m][k][j];
                }
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                hasilKali[i][j] = tempKali[i][j];
            }
        }
    }
    cetakMatriks(hasilKali);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/NehemiaPandu/109082500019_Nehemia-Pandu-Indragiri_Struktur-Data-Laporan-Praktikum/blob/main/Modul%202/Unguided/Screenshot%20Output/Output%20Soal%201/Screenshot%202026-10-07%20162554.png?raw=true)


##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/NehemiaPandu/109082500019_Nehemia-Pandu-Indragiri_Struktur-Data-Laporan-Praktikum/blob/main/Modul%202/Unguided/Screenshot%20Output/Output%20Soal%201/Screenshot%202026-10-07%20162634.png?raw=true)

Program di atas merupakan program yang saya buat untuk melakukan operasi penjumlahan, pengurangan, dan perkalian pada matriks berukuran 3x3 dengan tipe data int, lalu jumlah matriks (2 sampai 10) dan nilai setiap elemennya diinputkan oleh user menggunakan cin. Setelah itu program menyimpan semua matriks dalam array tiga dimensi matriks[10][3][3] dan menampilkannya menggunakan perulangan for bersarang. Penjumlahan dan pengurangan dihitung dengan cara menyalin matriks pertama ke hasilTambah dan hasilKurang, lalu menambah atau mengurangkannya dengan matriks berikutnya pada setiap elemen yang posisinya sama. Perkalian dihitung dengan cara mengalikan baris dan kolom (hasilKali[i][k] * matriks[m][k][j]) yang disimpan sementara pada tempKali, lalu dipindahkan kembali ke hasilKali. Semua hasilnya ditampilkan menggunakan fungsi cetakMatriks() dan cout.

### 2. Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel

```C++
#include <iostream>
using namespace std;

// BY POINTER
void tukarPointer(int *x, int *y, int *z) {
    int temp;

    temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
}

void tukarReference(int &x, int &y, int &z) {
    int temp;

    temp = x;
    x = y;
    y = z;
    z = temp;
}

int main() {
    int a, b, c;

    cout << "Masukkan nilai a: ";
    cin >> a;
    cout << "Masukkan nilai b: ";
    cin >> b;
    cout << "Masukkan nilai c: ";
    cin >> c;

    int a2 = a;
    int b2 = b;
    int c2 = c;

    cout << "\n=== By Pointer ===" << endl;
    cout << "Sebelum ditukar: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    tukarPointer(&a, &b, &c);

    cout << "\nSetelah ditukar: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    cout << "\n=== By Reference ===" << endl;
    cout << "Sebelum ditukar: " << endl;
    cout << "a = " << a2 << endl;
    cout << "b = " << b2 << endl;
    cout << "c = " << c2 << endl;

    tukarReference(a2, b2, c2);

    cout << "\nSetelah ditukar: " << endl;
    cout << "a = " << a2 << endl;
    cout << "b = " << b2 << endl;
    cout << "c = " << c2 << endl;

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/NehemiaPandu/109082500019_Nehemia-Pandu-Indragiri_Struktur-Data-Laporan-Praktikum/blob/main/Modul%202/Unguided/Screenshot%20Output/Output%20Soal%202/Screenshot%202026-10-07%20162840.png?raw=true)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/NehemiaPandu/109082500019_Nehemia-Pandu-Indragiri_Struktur-Data-Laporan-Praktikum/blob/main/Modul%202/Unguided/Screenshot%20Output/Output%20Soal%202/Screenshot%202026-10-07%20162911.png?raw=true)

Program di atas merupakan program yang saya buat untuk menukar nilai dari 3 buah variabel a, b, dan c dengan tipe data int menggunakan dua cara, yaitu call by pointer dan call by reference, lalu nilainya diinputkan oleh user menggunakan cin. Setelah itu program memanggil fungsi tukarPointer(&a, &b, &c) dan tukarReference(a2, b2, c2), yang di dalamnya nilai a diisi nilai b, nilai b diisi nilai c, dan nilai c diisi nilai a yang disimpan sementara pada variabel temp, kemudian menampilkan nilai sebelum dan sesudah ditukar menggunakan cout.

### 3. Diketahui sebuah array 1 dimensi sebagai berikut : arrA = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55} Buatlah program yang dapat mencari nilai minimum, maksimum, dan rata – rata dari array tersebut! Gunakan function cariMinimum() untuk mencari nilai minimum dan function cariMaksimum() untuk mencari nilai maksimum, serta gunakan prosedur hitungRataRata() untuk menghitung nilai rata – rata! Buat program menggunakan menu switch-case seperti berikut ini : <br>--- Menu Program Array --- <br>• Tampilkan isi array <br>• cari nilai maksimum <br>• cari nilai minimum <br>• Hitung nilai rata - rata

```C++
#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

const int N = 10;

int cariMinimum(int arr[], int n) {
    int min = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int cariMaksimum(int arr[], int n) {
    int maks = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > maks) {
            maks = arr[i];
        }
    }
    return maks;
}

void hitungRataRata(int arr[], int n) {
    int total = 0;

    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    float rata = (float)total / n;

    cout << "Nilai rata-rata = " << rata << endl;
}

int main() {
    int arrA[N] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int pilihan;

    do {
        cout << "\n--- Menu Program Array ---" << endl;
        cout << "1. Tampilkan isi array" << endl;
        cout << "2. Cari nilai maksimum" << endl;
        cout << "3. Cari nilai minimum" << endl;
        cout << "4. Hitung nilai rata-rata" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Isi array: ";
                for (int i = 0; i < N; i++) {
                    cout << arrA[i] << " ";
                }
                cout << endl;
                break;
            case 2:
                cout << "Nilai maksimum = " << cariMaksimum(arrA, N) << endl;
                break;
            case 3:
                cout << "Nilai minimum = " << cariMinimum(arrA, N) << endl;
                break;
            case 4:
                hitungRataRata(arrA, N);
                break;
            case 0:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/NehemiaPandu/109082500019_Nehemia-Pandu-Indragiri_Struktur-Data-Laporan-Praktikum/blob/main/Modul%202/Unguided/Screenshot%20Output/Output%20Soal%203/Screenshot%202026-10-07%20163014.png?raw=true)


##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/NehemiaPandu/109082500019_Nehemia-Pandu-Indragiri_Struktur-Data-Laporan-Praktikum/blob/main/Modul%202/Unguided/Screenshot%20Output/Output%20Soal%203/Screenshot%202026-10-07%20163032.png?raw=true)

Program di atas merupakan program yang saya buat untuk mengolah sebuah array satu dimensi arrA yang berisi 10 bilangan dengan tipe data int, lalu menampilkan menu pilihan menggunakan switch-case yang berulang dengan do-while. Setelah user memilih menu, program menampilkan isi array menggunakan perulangan for, mencari nilai maksimum dan minimum menggunakan function cariMaksimum() dan cariMinimum() dengan cara membandingkan setiap elemen array, serta menghitung nilai rata-rata menggunakan prosedur hitungRataRata() dengan cara menjumlahkan semua elemen lalu membaginya dengan jumlah elemen, kemudian menampilkan semua hasilnya menggunakan cout.

## Kesimpulan
Pada praktikum modul 2 saya belajar terkait penggunaan array satu dimensi, dua dimensi, dan tiga dimensi untuk menyimpan sekumpulan data dengan tipe data yang sama, serta penggunaan pointer dan operator alamat (&) untuk menyimpan dan mengakses alamat memori suatu variabel. Saya juga belajar membuat function yang mengembalikan nilai dan prosedur (void) yang hanya menjalankan tugas, serta tiga cara melewatkan parameter, yaitu call by value, call by pointer, dan call by reference. Semua materi tersebut saya terapkan dalam tiga latihan soal yang sudah diberikan, yaitu menukar nilai tiga variabel menggunakan pointer dan reference, membuat menu program array untuk mencari nilai maksimum, minimum, dan rata-rata menggunakan function dan prosedur, serta melakukan operasi penjumlahan, pengurangan, dan perkalian pada matriks 3x3.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>[3] Laboratorium Informatika. Modul 2: Pengenalan Bahasa C++ (Bagian Kedua). Praktikum Struktur Data, Fakultas Informatika, Telkom University.
