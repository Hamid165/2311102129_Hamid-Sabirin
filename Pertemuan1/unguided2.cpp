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

// penjelasan struct
/*
struct adalah tipe data compound yang digunakan untuk mengelompokkan beberapa variabel dalam sebuah variabel 
yang lebih besar struct adalah tipe data yang bisa didefinisikan oleh pengguna sendiri, sedangkan class adalah 
tipe data yang sudah ada di bahasa pemrograman C++ dan tidak dapat didefinisikan ulang dalam struct, kita dapat 
mendefinisikan beberapa variabel dengan tipe data apapun yang kita inginkan struct sendiri tidak memiliki fungsi 
dan hanya digunakan untuk mengelompokkan variabel-variabel dalam sebuah variabel yang lebih besar contoh penggunaan 
struct adalah ketika kita ingin mengelompokkan beberapa data-data yang terkait dalam satu variabel yang lebih besar
*/

// penjelasan class

// class
/*
class adalah tipe data yang dapat digunakan untuk mengelompokkan beberapa variabel dalam sebuah tipe data yang lebih besar
class dapat memiliki fungsi yang dapat digunakan untuk mengelola data yang dideklarasikan dalam class, class juga dapat didefinisikan 
untuk mengelompokkan fungsi-fungsi yang dapat digunakan untuk mengelola data yang dideklarasikan dalam class, class mempunyai sifat OOP 
(Object Oriented Programming) yang artinya class dapat diinstansiasi (dibuat objek) dan dapat memiliki fungsi yang dapat digunakan untuk 
mengelola data yang dideklarasikan dalam class class juga dapat menggunakan inheritance (penggunaan sifat dari suatu class lain) dan polymorphism 
(penggunaan fungsi yang sama dengan nama yang sama dari class lain) class digunakan untuk membuat data-data yang terkait dalam satu variabel yang 
lebih besar dan dapat digunakan untuk mengelola data-data tersebut secara lebih baik dan efektif
*/