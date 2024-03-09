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

/*
penjelasan map
map adalah tipe data compound yang digunakan untuk mengelompokkan beberapa variabel dalam sebuah variabel yang lebih besar
map sendiri tidak memiliki fungsi dan hanya digunakan untuk mengelompokkan variabel-variabel dalam sebuah variabel yang lebih besar.

//perbedaan map dan array
map tidak beda jauh dengan array bedanya hanya pada key dan value yang dimana ketika kita menggunakan map
kita membutuhkan sebuah key untuk menampilkan value pada data map tersebut sedangkan array itu tidak menggunakan
key untuk menampilkan data tetapi menggunakan index urutan array yang di mulai index 0 pada data awal sampai index akhir.

*/
