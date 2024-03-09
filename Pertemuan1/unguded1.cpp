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

// penjelasan
/*
Pada kode di atas kita menggunakan fungsi tambah, kurang, kali, dan bagi untuk melakukan operasi matematika dengan menggunakan tipe data primitif
kita menginputkan nilai a dan b kemudian memilih operator dengan tipe data char yaitu ankga, ketika kita memilih logika yang ingin dijalankan dengan menggunakan tipe data primitif char untuk nilainya
kita menggunakan fungsi switch untuk memilih operator logika yang ingin dijalankan ketika kita memilih penjumlahan maka code akan mengeksekusi
fungsi tambah dan mencetak hasil dari penjumlahan tersebut dan begitu juga dengan operator logika lainya.

//Kesimpulan dari tipe data primitif
  tipe data primitif dapat digunakan untuk mengelompokkan beberapa data dalam sebuah variabel yang lebih besar
  tipe data primitif dapat digunakan untuk mengelola data dengan cara membuat parameter untuk setiap data yang ingin diolah
  tipe data primitif dapat digunakan untuk mengerjakan soal-soal yang membutuhkan operasi matematika dengan cara menggunakan fungsi
  tipe data primitif hanya dapat digunakan untuk mengelompokkan data yang memiliki tipe data yang sama atau yang dapat diubah menjadi tipe data yang sama
*/
