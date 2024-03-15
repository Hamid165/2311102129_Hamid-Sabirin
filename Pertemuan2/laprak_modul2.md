# <h1 align="center">Laporan Praktikum Modul Array</h1>

<h2 align="center">Hamid Sabirin-2311102129</h2>

## Dasar Teori

Array merupakan sebuah tipe data terstruktur yang dapat diterapkan pada suatu variabel yangdapat menyimpan banyak data dengan tipe sejenis atau homogen.
Jenis Array sebagai berikut:
A. Array 1 dimensi
- Array 1 dimensi atau yang sering disebut dengan vektor adalah suatu array yang valueatau nilainya hanya ditunjukkan oleh satu indeks.

B. Array 2 dimensi
- Array 2 dimensi atau yang lebih sering digambarkan dengan sebuah matriks digunakan untuk menggambarkan arrayyang lebih rumit.

C. Array multidimensi
- Array multidimensi adalah array yang mempunyai lebih dari satu dimensi. Ini adalah kumpulan item yang homogen di mana setiap elemen diakses menggunakan beberapa indeks.

## Guided

### 1. [Input Array Tiga Dimensi]

```C++
#include <iostream>
using namespace std;
// PROGRAM INPUT ARRAY 3 DIMENSI
int main()
{
    // Deklarasi array
    int arr[2][3][3];
    // Input elemen
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }
    // Output Array
        for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Data Array[" << x << "][" << y << "][" << z
                     << "] = " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;
    // Tampilan array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << arr[x][y][z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
}
```

=> Penjelasan program

- Pada code di atas merupakan code untuk membuat array 3 dimensi dengan 3 colom, 3 baris dan 1 halaman, pada perulangan pertama kita diminta untuk menginputkan isi array, selanjutnya pada perulangan kedua kita mencetak perulangan yang telah inputkan pada perulangan pertama dan perulangan terakhir yaitu perulangan untuk menampilkan output array 3 dimensi secara lebih ringkas secara tampilan.

### 2. [Mencari Nilai Maksimal pada Array]

```C++
#include <iostream>
using namespace std;
int main()
{
    int maks, a, i = 1, lokasi;
    cout << "Masukkan panjang array: ";
    cin >> a;
    int array[a];
    cout << "Masukkan " << a << " angka\n";
    for (i = 0; i < a; i++)
    {
        cout << "Array ke-" << (i) << ": ";
        cin >> array[i];
    }
    maks = array[0];
    for (i = 0; i < a; i++)
    {
        if (array[i] > maks)
        {
            maks = array[i];
            lokasi = i;
        }
    }
    cout << "Nilai maksimum adalah " << maks << " berada di Array ke " << lokasi << endl;
}
```

=> Penjelasan program

- Program di atasmerupakan untuk mencari nilai maks pada indeks keberapa, pertama masukan panjang dari array dan jumlahnya. selanjutnya setelah mengisi inputan array tersebut, terdapat sebuah perulangan untuk mencari nilai maksimum yang dimana perulangan tersebut memeriksa data array satu persatu dengan urut indeks dan jika ketemu nilai maksimum terbesar maka akan di tampilkan dan juga menampilkan indeks keberapa.

## Unguided

### 1. [Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user!]
![contoh_output_unguided](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan2/assets/contoh_output.png)

```C++
#include <iostream>
using namespace std;

int main()
{
    // variable untuk data array, bilangan ganjil dan genap
    int jmlh_data_arr_129, data_arr_129, bil_genap_129 = 0, bil_ganjil_129 = 0;
    // input panjang array
    cout << "Masukkan jumlah data yang akan diinputkan : ";
    cin >> jmlh_data_arr_129;
    int array[jmlh_data_arr_129];

    // input data array
    for (int i = 0; i < jmlh_data_arr_129; i++)
    {
        cout << "Masukkan data ke " << i + 1 << " : ";
        cin >> data_arr_129;
        array[i] = data_arr_129;
    }
    // menampilkan isi
    cout << "Data Array : ";
    for (int i = 0; i < jmlh_data_arr_129; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    // tampilkan data array yang genap
    cout << "Nomor genap adalah : ";
    for (int i = 0; i < jmlh_data_arr_129; i++)
    {
        if (array[i] % 2 == 0)
        {
            cout << array[i] << ", ";
            bil_genap_129++;
        }
    }
    cout << endl;

    // tampilkan data array yang ganjil
    cout << "Nomor ganjil adalah : ";
    for (int i = 0; i < jmlh_data_arr_129; i++)
    {
        if (array[i] % 2 != 0)
        {
            cout << array[i] << ", ";
            bil_ganjil_129++;
        }
    }
    return 0;
}
```
### Output :
![unguided_output 1](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan2/assets/output_unguided1.png)

=> Penjelasan Program
- Program ini menggunakan bahasa C++ untuk mencari nomor genap dan ganjil dari sebuah data array. pada code di atas terdapat variable yang akan menampung panjang array, isi array, nomor genap dan nomor ganjil. program meminta untuk menginputkan panjang array dan menginputkan isi array sesuai panjang yang di inputkan. selanjutna data tersebut akan di cetak dan di tampilkan, dan pada code dibawahnya yaitu code untuk mengecek apakah bilangan tersebut bilangan yang habis dibagi 2 maka itu nomor genap sedangkan code menampilkan array ganjil jika angka tidak habis dibagi 2 maka akan masuk pada nomor ganjil.

#### Full code Screenshot:
![Full ss code unguided 1](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan2/assets/full_ss_code_unguided1.png)

### 2. [Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!]

```C++
#include <iostream>
using namespace std;
int main()
{
    int jumlah_element_129;
    cout <<"masukan jumlah element array : ";
    cin >> jumlah_element_129;

    // Deklarasi array jumlah_element_129 dimensi
    int arr_129[jumlah_element_129][jumlah_element_129][jumlah_element_129];
    // Input elemen
    for (int x = 0; x < jumlah_element_129; x++)
    {
        for (int y = 0; y < jumlah_element_129; y++)
        {
            for (int z = 0; z < jumlah_element_129; z++)
            {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr_129[x][y][z];
            }
        }
        cout << endl;
    }
    // Output Array
    for (int x = 0; x < jumlah_element_129; x++)
    {
        for (int y = 0; y < jumlah_element_129; y++)
        {
            for (int z = 0; z < jumlah_element_129; z++)
            {
                cout << "Data Array[" << x << "][" << y << "][" << z<< "] = " << arr_129[x][y][z] << endl;
            }
        }
    }
    cout << endl;
    // Menampilkan array
    for (int x = 0; x < jumlah_element_129; x++)
    {
        for (int y = 0; y < jumlah_element_129; y++)
        {
            for (int z = 0; z < jumlah_element_129; z++)
            {
                cout << arr_129[x][y][z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
}
```
### Output :
![unguided_output_2](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan2/assets/output_unguided2.png)

=> Penjelasan program
- Pada code di atas kita akan membuat array 3 dimensi dengan inputan element dari user. code di atas kita membuat variable array yang berisi 3 baris, 3 colom dan 3 halaman. setelah itu kita melakukan perulangan untuk menginputkan data ke dalam array setelah menginputkan dilakukan perulangan untuk mencetak array yang sudah di inputkan oleh user setelah itu mencetak kembali array tersebut lebih ringkas

#### Full code Screenshot:
![Full ss code unguided 2](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan2/assets/full_ss_code_unguided2.png)

### 3. [Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user!]

```C++
#include <iostream>
using namespace std;

int main()
{
    //variable untuk data maksimum minimum, rata rata, i , panjang_array_129, pilihan dan Rata
    int panjang_array_129, pilih_menu_129, maks, min, total;
    double rata;
    // input panjang array oleh user
    cout << "Masukkan panjang array: ";
    cin >> panjang_array_129;
    // perulangan untuk input data array
    int array[panjang_array_129];
    cout << "Masukkan " << panjang_array_129 << " angka"<< endl;
    for (int i = 0; i < panjang_array_129; i++)
    {
        cout << "Array ke-" << (i+1) << ": ";
        cin >> array[i];
    }
    // perulangan do untuk menu
    do
    {
        // menu pilihan
        cout << "Pilih menu :" << endl;
        cout << "1. Mencari Maksimum" << endl;
        cout << "2. Mencari Minimum" << endl;
        cout << "3. Mencari Rata-rata" << endl;
        cout << "4. Exit" << endl;
        cout << "Pilihan: ";
        // input pilihan menu
        cin >> pilih_menu_129;
        // switch case menu
        switch (pilih_menu_129)
        {
            case 1:
            // mencari maksimum
                maks = array[0];
                for (int i = 0; i < panjang_array_129; i++)
                {
                    if (array[i] > maks)
                        maks = array[i];
                }
                cout << "Maksimum dari array adalah: " << maks << endl;
                break;
            case 2:
            // mencari minimum
                min = array[0];
                for (int i = 0; i < panjang_array_129; i++)
                {
                    if (array[i] < min)
                        min = array[i];
                }
                cout << "Minimum dari array adalah: " << min << endl;
                break;
            case 3:
            // mencari rata-rata
                total = 0;
                for (int i = 0; i < panjang_array_129; i++)
                    total += array[i];
                rata = static_cast<double>(total) / panjang_array_129;
                cout << "Rata-rata dari array adalah: " << rata << endl;
                break;
            case 4:
                break;
            default:
                cout << "Pilihan tidak tersedia" << endl;
        }
    } while (pilih_menu_129 != 4);
    return 0;
}

```
### Output :
![unguided_output 3](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan2/assets/output_unguided3.png)

=> Penjelasan program
- Pada code kita akan mencari sebuah nilai maksimum, minimum dan rata rata nilai pada array. pada awal code kita membuat sebuah variable untuk menampung berbagai data, setelah itu kita akan menginputkan panjang array dan menginputkan data array sesuai panjang array yang diinputkan menggunakan perulangan. setelah itu kita membuat perulangan do while untuk menampilkan menu yang dimana nanti kita akan memilih menampilkan maksimum, minimum atau rata rata nilai. jika kita memilih case 1 maka code akan mengecek isi data aray satu per satu menggunakan for untuk mencari nilai terbesar, jika memilih case 2 maka code akan mencari data pada array yang terkecil dan jika memilih case 3 maka code akan menjalankan perintah perulangan menjumlahkan semua isi data array dan di bagi panjang data array untuk menemukan rata rata nilai

#### Full code Screenshot:
![Full ss code unguided 3](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan2/assets/full_ss_code_unguided3.png)

## Kesimpulan

 Dari materi array yang telah dipelajari, Array merupakan sebuah tipe data terstruktur yang dapat diterapkan pada suatu variabel yang dapat menyimpan banyak data dengan tipe sejenis atau homogen. Kita mempelajari bagaimana cara menggunakan data array seperti array 1 dimensi 2 dimensi dan multi dimensi. pada materi tersebut kita belajar tentang array yang dimana kita bisa tau kapan kita menggunakan array berjenis 1 dimensi, 2 dimensi dan multi dimensi. pada array 1 dimensi bisadigunakan untuk wadah sebuah nilai dengan tipe data yang sama, pada array 2 dimensi dan array multidimensi bisa digunakan pada matriks dan tabel sedangkan pada array multidimensi. 

## Referensi

[1] Wilis Kaswidjanti, Algoritma dan Pemrograman Lanjut, Yogyakarta: Universitas Pembangunan Nasional “Veteran” Yogyakarta , 2024.

[2] Putri, Meidyan P., et al. ALGORITMA DAN STRUKTUR DATA. P.CV WIDINA MEDIA UTAMA, 2022.

[3] Evi Lestari Pratiwi, Konsep Algoritma dan Pemograman, Banjarmasin: Poliban Press 2020
