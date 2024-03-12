# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>

<h2 align="center">Hamid Sabirin</h2>

## Dasar Teori

Tipe data adalah cara untuk mengelompokkan dan membedakan berbagai jenis nilai yang dapat direpresentasikan dan dimanipulasi oleh sebuah program komputer. Tipe data memungkinkan komputer untuk memahami bagaimana nilai-nilai tersebut harus diinterpretasikan dan bagaimana operasi-operasi tertentu dapat dilakukan terhadap nilai-nilai tersebut.

pada tipe data terdapat 3 jenis yaitu :

1. Primitif
   Tipe data bawaan bahasa pemrograman dan bisa langsung digunakan programmer untuk mendeklarasikan variabel contohnya adalah

   - Int = bilangan bulat
   - Float = bilangan koma atau desimal
   - Bool = true or false
   - Char = angka, huruf, simbol dan operator logika

2. Abstrak
   Tipe untuk objek yang perilakunya ditentukan oleh satu set nilai dan satu set operasi contoh darit ipe data abstrak adalah :

   - Struct = digunakan untuk mengelompokkan data dan fungsi
   - Class = konsep struktur data yang diperluas

3. Koleksi
   Tipe data Koleksi adalah tipe data yang terdiri dari beberapa elemen dengan tipe data yang sama, dan tiap elemen memiliki index unik yang dapat diakses secara langsung.

   - Array = tipe data yang terdiri dari elemen-elemen yang memiliki tipe data yang sama dan diberi nama tertentu
   - Vector = berisi sebuah koleksi elemen dengan tipe data yang sama, tiap elemen memiliki index yang unique dan dapat diakses secara langsung, sering digunakan untuk menyimpan data-data yang memiliki urutan dan dapat dibuka secara acak.
   - Map = berisi pasangan key-value

## Guided

### 1. [Tipe Data Primitif]

```C++
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    char op;
    float num1, num2;
    // It allows user to enter operator i.e. +, -, *, /
    cout << "Enter operator (+, -, *, /): ";
    cin >> op;
    // It allows user to enter the operands
    cout << "Enter two operands: ";
    cin >> num1 >> num2;
    // Switch statement begins
    switch (op)
    {
    // If user enters +
    case '+':
        cout << "Result: " << num1 + num2;
        break;
    // If user enters -
    case '-':
        cout << "Result: " << num1 - num2;
        break;
    // If user enters *
    case '*':
        cout << "Result: " << num1 * num2;
        break;
    // If user enters /
    case '/':
        if (num2 != 0)
        {
            cout << "Result: " << fixed << setprecision(2) << num1 / num2;
        }
        else
        {
            cout << "Error! Division by zero is not allowed.";
        }
        break;
    // If the operator is other than +, -, * or /,
    // error message will display
    default:
        cout << "Error! Operator is not correct";
    } // switch statement ends
    return 0;
}
```

=> Kode di atas adalah kode untuk melakukan operasi operator bilangan dengan menggunakan inputan berupa tipe data primitif yang terdiri dari integer, float, boolean, dan char pada kode di atas kita hanya menggunakan tipe data char untuk menginputkan operator dan float untuk inputan angka maupun hasil outputnya. pada program di atas akan mengeksekusi sesuai simbol operator dengan menjumlahkan mengurangkan mengalikan dan membagi nilai angka pertama dengan angka ke dua kecuali pada pembagian dimana nilainya tidak boleh ada yang bernilai nol

### 2. [Tipe data Abstrak]

```C++
#include <stdio.h>
#include <string.h>
// Struct
struct Mahasiswa
{
    //tipe data mahasisawa yang di tampung oleh struc
    char name[50];
    char address[100];
    int age;
};
int main()
{
    // menggunakan struct
    struct Mahasiswa mhs1, mhs2;
    // mengisikan data struct mahasiswa 1
    strcpy(mhs1.name, "Dian");
    strcpy(mhs1.address, "Mataram");
    mhs1.age = 22;
    // mengisikan data struct mahasiswa 2
    strcpy(mhs2.name, "Bambang");
    strcpy(mhs2.address, "Surabaya");
    mhs2.age = 23;
    // mencetak isi struct mahasiswa 1
    printf("## Mahasiswa 1 ##\n");
    printf("Nama: %s\n", mhs1.name);
    printf("Alamat: %s\n", mhs1.address);
    printf("Umur: %d\n", mhs1.age);
    // mencetak isi struct mahasiswa 2
    printf("\n");
    printf("## Mahasiswa 2 ##\n");
    printf("Nama: %s\n", mhs2.name);
    printf("Alamat: %s\n", mhs2.address);
    printf("Umur: %d\n", mhs2.age);
    return 0;
}

```

=> Kode di atas merupakan tipe data abstrak yaitu struct, struct di gunakan untuk menampung tipe data yang berbeda beda menjadi satu di dalam struct. pada kode di atas kita memiliki dua data mahasiswa dan kita memanggil nama struct tersebut untuk menambahkan data mahasiswa kedalam struct dan kita melakukan perintah printf untuk mencetak data mahasiswa dengan cara nama variable diikuti nama tipe data dari mahasiswanya.

### 2. [Tipe Data Koleksi]

```C++
#include <iostream>
#include <array>
using namespace std;
int main()
{
    // Deklarasi dan inisialisasi array satu per satu
    int nilai[5];
    nilai[0] = 23;
    nilai[1] = 50;
    nilai[2] = 34;
    nilai[3] = 78;
    nilai[4] = 90;

    // Mencetak array sesuai urutan index
    cout << "Isi array pertama : " << nilai[0] << endl;
    cout << "Isi array kedua : " << nilai[1] << endl;
    cout << "Isi array ketiga : " << nilai[2] << endl;
    cout << "Isi array keempat : " << nilai[3] << endl;
    cout << "Isi array kelima : " << nilai[4] << endl;
    return 0;
}
```

=> Kode di atas adalah sebuah tipe data koleksi yaitu array pada kode tersebut kita membuat sebuah array yang berisikan lima data yang berisikan sebuah angka, dan kita akan mencetak array tersebut berdasarkan index menggunakan cout dan kita melakukan dengan cara memanggil nama array nya dan urutan index pada array tersebut.

## Unguided

### 1. [Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!]

```C++
#include <iostream>
#include <iomanip>
using namespace std;

// fungsi tambah
void tambah(int nilaiA_129, int nilaiB_129)
{
    int tambah = nilaiA_129 + nilaiB_129;
    cout << "Hasil Penjumlahan : " << tambah << endl;
}

// fungsi kurang
void kurang(int nilaiA_129, int nilaiB_129)
{
    int kurang = nilaiA_129 - nilaiB_129;
    cout << "Hasil Pengurangan : " << kurang << endl;
}

// fungsi kali
void kali(int nilaiA_129, int nilaiB_129)
{
    int kali = nilaiA_129 * nilaiB_129;
    cout << "Hasil Perkalian : " << kali << endl;
}

// fungsi bagi
float bagi(int nilaiA_129, int nilaiB_129)
{
    float hasil = static_cast<float>(nilaiA_129) / nilaiB_129;
    cout << "Hasil Pembagian : " << hasil << endl;
    return hasil;
}

int main()
{
    char pilihan_129;
    do
    {
        // memasukan nilai a dan b
        int nilaiA_129, nilaiB_129;
        cout << "Masukkan Nilai A : ";
        cin >> nilaiA_129;
        cout << "Masukkan Nilai B : ";
        cin >> nilaiB_129;

        // menampilkan menu
        cout << "Pilih operator logika:" << endl;
        cout << "a. Penjumlahan (+)" << endl;
        cout << "b. Pengurangan (-)" << endl;
        cout << "c. Perkalian (*)" << endl;
        cout << "d. Pembagian (/)" << endl;

        // memilih operator logika
        char nomor_129;
        cout << "Masukkan pilihan Anda (a/b/c/d): ";
        cin >> nomor_129;

        // melakukan operasi berdasarkan pilihan
        switch (nomor_129)
        {
        case 'a':
            tambah(nilaiA_129, nilaiB_129);
            break;
        case 'b':
            kurang(nilaiA_129, nilaiB_129);
            break;
        case 'c':
            kali(nilaiA_129, nilaiB_129);
            break;
        case 'd':
            bagi(nilaiA_129, nilaiB_129);
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
        }

        cout << "Apakah Anda ingin melanjutkan (y/n) ? ";
        cin >> pilihan_129;
    } while (pilihan_129 == 'y' || pilihan_129 == 'Y');

    return 0;
}
```

### Output :

![unguided_output 1](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/cffb907635b78b07e7463ffcb95ff63b7131cff6/Pertemuan1/assets/output1.png)

=> Penjelasan Program

Pada kode di atas kita menggunakan fungsi tambah, kurang, kali, dan bagi untuk melakukan operasi matematika dengan menggunakan tipe data primitif kita menginputkan nilai a dan b kemudian memilih operator dengan tipe data char yaitu ankga, ketika kita memilih logika yang ingin dijalankan dengan menggunakan tipe data primitif char untuk nilainya kita menggunakan fungsi switch untuk memilih operator logika yang ingin dijalankan ketika kita memilih penjumlahan maka code akan mengeksekusi fungsi tambah dan mencetak hasil dari penjumlahan tersebut dan begitu juga dengan operator logika lainya.

#### Full code Screenshot:

![Full ss code unguided 1](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan1/assets/fullcode_unguided1.png)

=> Kesimpulan dari tipe data primitif

tipe data primitif dapat digunakan untuk mengelompokkan beberapa data dalam sebuah variabel yang lebih besar
tipe data primitif dapat digunakan untuk mengelola data dengan cara membuat parameter untuk setiap data yang ingin diolah
tipe data primitif dapat digunakan untuk mengerjakan soal-soal yang membutuhkan operasi matematika dengan cara menggunakan fungsi
tipe data primitif hanya dapat digunakan untuk mengelompokkan data yang memiliki tipe data yang sama atau yang dapat diubah menjadi tipe data yang sama

### 2. [Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya]

```C++
#include <iostream>
using namespace std;

// struct mahasiswa
struct Mahasiswa
{
    char nama_mahasiswa_129[50];
    char alamat_mhsw_129[100];
    int umur_mahasiswa_129;
};
// class karyawan
class Karyawan
{
public:
    char nama_krywn_129[50];
    char alamat_kryw_129[100];
    int umur_karyawan_129;
};

int main()
{
    // Input data mahasiswa ke struct
    struct Mahasiswa mhs_129;
    cout << "Masukkan Nama Mahasiswa : ";
    cin.getline(mhs_129.nama_mahasiswa_129, 50);
    cout << "Masukkan Alamat Mahasiswa : ";
    cin.getline(mhs_129.alamat_mhsw_129, 100);
    cout << "Masukkan Umur Mahasiswa : ";
    cin >> mhs_129.umur_mahasiswa_129;
    cout << endl;

    // menampilkan data mahasiswa
    cout << "Data mahasiswa 1 " << endl;
    cout << "Nama: " << mhs_129.nama_mahasiswa_129 << endl;
    cout << "Alamat: " << mhs_129.alamat_mhsw_129 << endl;
    cout << "Umur: " << mhs_129.umur_mahasiswa_129 << endl;
    cout << endl;


    // input data class karyawan
    class Karyawan krywn_129;
    cin.ignore();
    cout << "Masukkan Nama Karyawan: ";
    cin.getline(krywn_129.nama_krywn_129, 50);
    cout << "Masukkan Alamat Karyawan : ";
    cin.getline(krywn_129.alamat_kryw_129, 100);
    cout << "Masukkan Umur Karyawan : ";
    cin >> krywn_129.umur_karyawan_129;
    cout << endl;
    // menampilkan data inputan karyawan
    cout << "Nama Karyawan :" << krywn_129.nama_krywn_129 << endl;
    cout << "Alamat Karyawan :" << krywn_129.alamat_kryw_129 << endl;
    cout << "Umur Karyawan :" << krywn_129.umur_karyawan_129 << endl;

    return 0;
}
```

### Output :

![unguided_output_2](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/cffb907635b78b07e7463ffcb95ff63b7131cff6/Pertemuan1/assets/output2.png)

=> Penjelasan program

pada program di atas kita menggunakan sebuah tipe data abstrak yaitu struct dan class yang dimana struct dan kelas itu untuk menampung sebuah tipe data yang berbeda beda dan di tampung oleh kelas maupun struct. setelah di tampung oleh struct dan class kita bisa mencetak data yang sudah ada ataupun yang di inputkan dan di tampung pada struct dan class dengan cara memanggil nama struct atau nama class terlebuh dahulu.

#### Full code Screenshot:

![Full ss code unguided 1](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan1/assets/fullcode_unguided2.png)
=> Penjelasan Struct

Struct adalah tipe data compound yang digunakan untuk mengelompokkan beberapa variabel dalam sebuah variabel
yang lebih besar struct adalah tipe data yang bisa didefinisikan oleh pengguna sendiri, sedangkan class adalah
tipe data yang sudah ada di bahasa pemrograman C++ dan tidak dapat didefinisikan ulang dalam struct, kita dapat
mendefinisikan beberapa variabel dengan tipe data apapun yang kita inginkan struct sendiri tidak memiliki fungsi
dan hanya digunakan untuk mengelompokkan variabel-variabel dalam sebuah variabel yang lebih besar contoh penggunaan
struct adalah ketika kita ingin mengelompokkan beberapa data-data yang terkait dalam satu variabel yang lebih besar

=> Penjelasan class

Class adalah tipe data yang dapat digunakan untuk mengelompokkan beberapa variabel dalam sebuah tipe data yang lebih besar
class dapat memiliki fungsi yang dapat digunakan untuk mengelola data yang dideklarasikan dalam class, class juga dapat didefinisikan
untuk mengelompokkan fungsi-fungsi yang dapat digunakan untuk mengelola data yang dideklarasikan dalam class, class mempunyai sifat OOP
(Object Oriented Programming) yang artinya class dapat diinstansiasi (dibuat objek) dan dapat memiliki fungsi yang dapat digunakan untuk
mengelola data yang dideklarasikan dalam class. class digunakan untuk membuat data-data yang terkait dalam satu variabel yang
lebih besar dan dapat digunakan untuk mengelola data-data tersebut secara lebih baik dan efektif.

### 3. [ Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map.]

```C++
#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{
    // array untuk menyimpan data index dan nama
    cout << "menampilkan  data marray" << endl;
    string nama[5] = {"Qonita", "Rahayu", "Atmi", "Hamid", "Sabirin"};

    // menampilkan isi array satu per satu sesuai index
    cout << "array index 0 : " << nama[0] << endl;
    cout << "array index 1 : " << nama[1] << endl;
    cout << "array index 2 : " << nama[2] << endl;
    cout << "array index 3 : " << nama[3] << endl;
    cout << "array index 4 : " << nama[4] << endl;

    // menggunakan map untuk menyimpan data index dan nama dalam satu variabel
    cout << "\n";
    cout << "menampilkan  data map" << endl;
    map<int, string> Kota;
    Kota[1] = "Magelang";
    Kota[2] = "Sleman";
    Kota[3] = "Tulungagung";
    Kota[4] = "Karawang";
    // menampilkan isi dari data map
    cout << "kota[1] :" << Kota[1] << endl;
    cout << "kota[2] :" << Kota[2] << endl;
    cout << "kota[3] :" << Kota[3] << endl;
    cout << "kota[4] :" << Kota[4] << endl;
    return 0;
}
```

### Output :

![unguided_output 3](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/cffb907635b78b07e7463ffcb95ff63b7131cff6/Pertemuan1/assets/output3.png)

=> Penjelasan program
Pada kode di atas kita membuat sebuah array dan map pada array kita memiliki 5 data berupa bilangan nama orang dan kita bisa mencetaknya dengan cara memanggil urutan index array yang kita ingginkan dan pada map kita memiliki data nama tempat yang dimana terdapat sebuah key yaitu berupa angka integer dan value berupa string nama tempatnya dan kita bisa mencetaknya dengan cara memanggil key dari value.

#### Full code Screenshot:

![Full ss code unguided 1](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan1/assets/fullcode_unguided3.png)
=> Penjelasan map

Map adalah tipe data compound yang digunakan untuk mengelompokkan beberapa variabel dalam sebuah variabel yang lebih besar
map sendiri tidak memiliki fungsi dan hanya digunakan untuk mengelompokkan variabel-variabel dalam sebuah variabel yang lebih besar.

=> Perbedaan map dan array

Map tidak beda jauh dengan array bedanya hanya pada key dan value yang dimana ketika kita menggunakan map
kita membutuhkan sebuah key untuk menampilkan value pada data map tersebut sedangkan array itu tidak menggunakan
key untuk menampilkan data tetapi menggunakan index urutan array yang di mulai index 0 pada data awal sampai index akhir.

## Kesimpulan

Dari materi tipe data di atas yang sudah dipraktekan saya menyimpulkan bahwa tipe data pada c++ terbagi menjadi 3 yaitu tipe data primitif yang berisikan int, char, bool, dan float, dan tipe data selanjutnya yaitu tipe data abstrak yang dimana berisikan sebuah struct dan class yang dimana keduanya bisa menampung sebuah banyak tipe data tetapi pada class kita bisa mengubahnya menjadi public ataupun pirvate dan tipe data terakhir adalah tipe data koleksi yang berisikan array dan map dari keduanya tersebut tidak beda jauh yang dimana menampung data, pada array menampung data pad aumumnya tetapi indexnya dimulai dari 0 sedangkan map juga sama menampungdata tetapi kita memerlukan sebuah key dan value yang dimana key tersebut digunakan untuk menampilkan sebuah value.

## Referensi

[1] Afrizal Zein, Emi Sita Eriana , Algoritma dan Struktur Data Pamulang: Universitas Pamulang, 2022.
