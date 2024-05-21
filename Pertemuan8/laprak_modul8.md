# <h1 align="center">Laporan Praktikum Modul 8 SEARCHING</h1>

<h1 align="center">Hamid Sabirin-2311102129</h1>

## Dasar Teori

<h2 align="center">SEARCHING</h2>
Algoritma pencarian (searching algorithm) secara umum merupakan suatu algoritma yang menerima sebuah argumen kunci sebagai input dan menggunakan langkah-langkah tertentu untuk mencari rekaman yang sesuai dengan kunci tersebut. Setelah proses pencarian dilakukan, terdapat dua kemungkinan hasil yang dapat diperoleh, yaitu data yang dicari ditemukan (berhasil) atau tidak ditemukan (gagal).

Pada algoritma pencarian atau searching algorithm terdapat beberapa metode pencarian yaitu sebagai berikut :

1. Sequential Search

Sequential Search adalah proses membandingkan setiap elemen array satu persatu secara beruntun dimulai dari elemen pertama hingga elemen yang dicari ditemukan atau hingga elemen terakhir dari array. Metode Sequential Search atau disebut pencarian beruntun dapat digunakan untuk melakukan pencarian data baik pada array yang sudah terurut maupun yang belum terurut.

Adapun Proses Algoritma Sequential Searching adalah sebagai berikut:
a. Pertama data melakukan perbandingan satu per satu secara berurutan dalam kumpulan data dengan data yang di cari sampai data tersebut ditemukan atau tidak ditemukan.
b. Pada dasarnya, pencarian ini hanya melakukan pengulangan data dari 1 sampai dengan jumlah data (n).
c. Setiap pengulangan, dibandingkan data ke-i dengan data yang sedang dicari.
d. Apabila data sama dengan yang dicari, berarti data telah berhasil di temukan. Sebaliknya apabila sampai akhir melakukan pengulangan tidak ada data yang sama dengan yang dicari, berarti data tidak ada yang ditemukan.

2. Binary Search

Pencarian Biner (binary Search) adalah metode pencarian data pada array yang telah terurut, metode ini lebih effisien dari pada metode pencarian linier dimana semua elemen di dalam array diuji satu persatu sampai ditemukan elemen yang diinginkan. Algoritma ini bekerja dengan cara memilih record dengan indeks tengah dari tabel dan membandingkannya dengan record yang hendak dicari. Jika record tersebut lebih rendah atau lebih tinggi, maka tabel tersebut dibagi dua dan bagian tabel yang bersesuaian akan diproses kembali secara rekursi.

a. Pertama pengambilan data dimulai dari posisi 1 sampai dengan posisi akhir (n).
b. Selanjutnya mencari posisi data yang tengah dengan menggunakan rumus (posisi akhir)/2.
c. Setelah itu data yang akan dicari dibanndingkan dengan data yangberada ditengah, apakah data
d. terseebut sama atau lebih kecil, atau lebih besar.
e. Seandainya data tersebut lebih besar, maka proses pencarian yang dicarikan dengan posisi awal adalah 6.posisi tengah + 1.7.Jika data sama dengan data yang dicari, berarti data tersebut telah ditemukan.

## Guided

### 1. [Buatlah sebuah project dengan menggunakan sequential search sederhana untuk melakukan pencarian data.]

```C++
#include <iostream>
using namespace std;
int main()
{
    // varibale nilai data, variable nilai angka yang di cari dan variable true false
    int n = 10;
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};
    int cari = 10;
    bool ketemu = false;
    int i;
    // Algoritma Sequential Search
    for (i = 0; i < n; i++)
    {
        if (data[i] == cari)
        {
            ketemu = true;
            break;
        }
    }
    // menampilkan judul dan data
    cout<< "\tProgram Sequential Search Sederhana\n"<< endl;
    cout << "data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;
    // percabangan untuk mengetahui nilai angka di temukan pada indeks keberapa
    if (ketemu)
    {
        cout << "\nAngka " << cari << " ditemukan pada indeks ke-"<< i << endl;
    }
    else
    {
        cout << cari << " tidak dapat ditemukan pada data." << endl;
    }
    return 0;
}
```

=> Penjelasan program

- Pada program code di atas merupakan code pencarian atau search menggunakan sequential search. pada sequential search data yang masih dalam ke adaaan acak dan pada code tersebut terdapat sbeuah data menggunakan array dan terdapat sebuah kondisi yang awalnya false, selanjutnya terdapat sebuah perulangan yang dimana perulangan tersebut digunakan untuk mencari sebuah data pada perulangan itu akan di cocokan apakan data pada array tersebut sama dengan nilai cari dan jika ketemu maka akan ditampilkan nilai cari pada indeks keberapa dan juga jika ketemu maka tidak dapat menemukan data atau tidak ada data tersebut.

### 2. [Buatlah sebuah project untuk melakukan pencarian data dengan menggunakan Binary Search]

```C++
#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

// varibale data menggunakan array dan variable cari
int dataArray[7] = {1, 8, 2, 5, 4, 9, 7};
int cari;
// fungsi perluangan untuk mengurutkan sebuah data dari terkecil ke terbesar
void selection_sort()
{
    int temp, min, i, j;
    for (i = 0; i < 7; i++)
    {
        min = i;
        for (j = i + 1; j < 7; j++)
        {
            if (dataArray[j] < dataArray[min])
            {
                min = j;
            }
        }
        t
            emp = dataArray[i];
        dataArray[i] = dataArray[min];
        dataArray[min] = temp;
    }
}
// fungsi untuk pencarian menggunakan binary search
void binarysearch()
{
    // variable awal akhir tengah dan true false
    int awal, akhir, tengah;
    bool b_flag = false;
    awal = 0;
    akhir = 6;
    // perulangan untuk mencari nilai
    while (!b_flag && awal <= akhir)
    {
        tengah = (awal + akhir) / 2;
        if (dataArray[tengah] == cari)
        {
            b_flag = true;
        }
        else if (dataArray[tengah] < cari)
        {
            awal = tengah + 1;
        }
        else
        {
            akhir = tengah - 1;
        }
    }
    // percabangan untuk mengetahui sebuah data diu temukan pada indeks keberapa
    if (b_flag)
    {
        cout << "\nData ditemukan pada index ke- " << tengah << endl;
    }
    else
    {
        cout << "\nData tidak ditemukan\n";
    }
}
int main()
{
    cout << "\tBINARY SEARCH" << endl;
    cout << "\nData: ";
    // Tampilkan data awal
    for (int x = 0; x < 7; x++)
    {
        cout << setw(3) << dataArray[x];
    }
    cout << endl;
    cout << "\nMasukkan data yang ingin Anda cari: ";
    // input nilai yang akan dicari
    cin >> cari;
    cout << "\nData diurutkan: ";
    // Urutkan data dengan selection sort
    selection_sort();
    // Tampilkan data setelah diurutkan
    for (int x = 0; x < 7; x++)
    {
        cout << setw(3) << dataArray[x];
    }
    cout << endl;
    binarysearch();
    _getche();
    return 0;
}
```

=> Penjelasan program

- Pada program code di atas merupakan code pencarian dengan metode binary search. pada program tersebut terdapat sebuah data menggunakan sebuah array dan data tersebut tidak ter urut, pada program tersebut terdapat dua fungsi yaitu selection sort dan binary search, pada selection sort tersebut digunakan untuk melakukan pengurutan sebuah data dari yang terkecil ke yang terbesar. setelah data di urutkan maka fungsi binary search terdapat sebuah nilai variable awal tengah dan akhir, ada juga variable kondisi dengan nilai false selanjutnya terdapat sebuah perulangan untuk mencari sebuah nilai pada data tersebut dengan cara menjumlahkan nilai awal dan akhir lalu dibagi dua, jika data di temukan di tengah maka data akn ditampilkan langsung dan jika data di temukan di awal maka akan di tambah satu dan jika data ditemukan pada akhir maka akn dikurangan dengan angka satu. pada fungsi utama terdapat sebuah perulangan untuk menampilkan data awal yaitu data yang jumlah nya ada 7 akan di tampilkan semua, selanutnya menginputkan nilai cari dan setelah menginputkan maka selanjutnya mengurutkan data menggunakan fungsi selection sort yang telah dibuat dan jika sudah di urutkan makan data tersebut akan di tampilkan menggunakan perulangan dan selanjutnnya menampilkan nilai yang di cari.

## Unguided

### 1. [Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!]

```C++
#include <iostream>
#include <string>

using namespace std;
// Fungsi untuk mengurutkan karakter dalam string menggunakan Bubble Sort
void bubble_sort(string &kalimat_129)
{
    int n = kalimat_129.size();
    // Perulangan untuk setiap elemen dalam string
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (kalimat_129[j] > kalimat_129[j + 1])
            {
                swap(kalimat_129[j], kalimat_129[j + 1]);
            }
        }
    }
}
// Fungsi untuk mencari karakter dalam string yang sudah diurutkan
void binary_search(const string &kalimat_129, char cari_129)
{
    bool ditemukan = false;
    cout << "Kata setelah diurutkan: " << kalimat_129 << endl;
    cout << "Huruf '" << cari_129 << "' ditemukan pada indeks ke: ";
    // Perulangan untuk mencari huruf dalam string
    for (size_t i = 0; i < kalimat_129.size(); ++i)
    {
        if (kalimat_129[i] == cari_129)
        {
            ditemukan = true;
            cout << i << " ";
        }
    }
    cout << endl;
    // percabangan jika tidak menemukan huruf pada kata
    if (!ditemukan)
    {
        cout << "Huruf '" << cari_129 << "' tidak ditemukan dalam kalimat." << endl;
    }
}

int main()
{
    string kalimat_129;
    char cari_129;

    cout << "Masukkan kalimat: ";
    getline(cin, kalimat_129);

    // Urutkan kalimat menggunakan bubble sort
    bubble_sort(kalimat_129);
    cout << "Kalimat setelah diurutkan: " << kalimat_129 << endl;

    cout << "Masukkan huruf yang ingin Anda cari: ";
    cin >> cari_129;

    // Cari huruf dalam kalimat menggunakan binary search
    binary_search(kalimat_129, cari_129);

    return 0;
}
```

### Output :

<h2>Binary Search huruf pada kata</h2>

![soal 1](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/10a3909638f14ce036f04b749602c16af101d689/Pertemuan8/assets/ssoutput_unguided1.png)

=> Penjelasan Program

- Pada program code di atas merupakan sebuah code untuk pencarian binary search huruf pada sebuah kata, pada code tersebut terdapat fungsi selection sort dimana fungsi tersebut digunakan untuk memecah kata menjadi huruf dan mengurutkan dari terkecil ke tersbesar. selanjutnya terdapat sebuah code fungsi binary search yang digunakan untuk mencari data yang sudah di urutkan oleh fungsi selection sort pada fungsi tersebut terdapat variable dengan nilai false dan menampilkan kata yang sudah di urutkan selanjutnya ada sebuah perulangan yang digunakan uinutk mencari huruf pada sebuah kata yang sudah diurutkan jika huruf ditemukan maka akn ditampilkan.

#### Full code Screenshot:

![Full_ss_code_unguided1](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/10a3909638f14ce036f04b749602c16af101d689/Pertemuan8/assets/fullss_unguided1.png)

### 2. [Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!]

```C++
#include <iostream>
#include <string>

using namespace std;

int main()
{
    // variable kalimat dan total vokal huruf
    string kalimat_129;
    int jumlahVokal_129 = 0;

    cout << "Masukkan kalimat: ";
    getline(cin, kalimat_129);
    // perulangan apakah huruf dan kalimat sama atau tidak
    for (char huruf_129 : kalimat_129)
    {
        if (huruf_129 == 'a' || huruf_129 == 'e' || huruf_129 == 'i' || huruf_129 == 'o' || huruf_129 == 'u' ||
            huruf_129 == 'A' || huruf_129 == 'E' || huruf_129 == 'I' || huruf_129 == 'O' || huruf_129 == 'U')
        {
            jumlahVokal_129++;
        }
    }

    cout << "Kalimat: " << kalimat_129 << endl;

    cout << "\nJumlah huruf vokal dalam kalimat: " << jumlahVokal_129 << endl;

    return 0;
}
```

### Output :

<h2>Sequential Search menghitung banyak huruf vokal</h2>

![soal 2](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/10a3909638f14ce036f04b749602c16af101d689/Pertemuan8/assets/ssoutput_unguided2.png)

=> Penjelasan Program

- Pada kode di atas merupakan sebuah program untuk mencari semua total huruf vokal yang ada pada sebuah kalimat atau kata. pada code tersebut perlu membuat sebuah variable untuk menampung sebuah kalimat dan jumlah vokal nanti. selanjutnya kita menginputkan sebuah kata kalimat yang dimana pada kata tersebut akan di cari total huruf vokalnya, dan terdapat sebuah perulangan yang berisikan percabangan dimana berisikan huruf vokal sama dengan huruf yaitu huruf vokal jika nanti ada maka akan menampilkan jumlah dari seluruh huruf vokal pada kalimat yang telah di inputkan.

#### Full code Screenshot:

![Full_ss_code_unguided2](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/10a3909638f14ce036f04b749602c16af101d689/Pertemuan8/assets/fullss_unguided2.png)

### 3. [Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!]

```C++
#include <iostream>

using namespace std;

int main()
{
    // variable untuk data cari true false nilai dan jumlah angka
    int a = 10;
    int data_129[a] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int cari_129;
    bool ketemu_129 = false;
    int jumlahAngka_129 = 0;

    // menampilkan dara awall
    cout << "data = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4}" << endl;
    cout << "Masukkan angka yang ingin Anda cari: ";
    // input cari
    cin >> cari_129;

    // perulangan untuk apakah nilai data sama dengan apa yang di cari
    for (int i = 0; i < a; ++i)
    {
        if (data_129[i] == cari_129)
        {
            ketemu_129 = true;
            jumlahAngka_129++;
        }
    }

    //percabangan ketika data di temukan dan data tidak di temukan
    if (ketemu_129)
    {
        cout << "\nAngka " << cari_129 << " ditemukan sebanyak " << jumlahAngka_129 << endl;
    }
    else
    {
        cout << cari_129 << " tidak dapat ditemukan pada data." << endl;
    }
    return 0;
}
```

### Output :

<h2>Sequential Search menghitung total nilai cari angka pada sebuah data</h2>

![soal 3](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/10a3909638f14ce036f04b749602c16af101d689/Pertemuan8/assets/ssoutput_unguided3.png)

=> Penjelasan Program

- Pada program code di atas merupakan sebuah porogram sequential search untuk mencari sebuah nilai angka dengan jumalh total ada berapa angka yang di cari pada sebuah data. pada code di terdapat sebuah sebuah variable yang dimana untuk menampung sebuah data yang nanti kita akan cari dan variable dengan nilai false dan jumlah angka untuk menampung nantinya, selanjutnya terdapat sebuah perulangan yang dimana untuk mencari sebuah nilai yang akan di cari dan disamakn dengan data jika nilai tersebut sama dengan sebuah nilai pada data maka akan di tampung pada variable, jika data tersebut ditemukan maka akan menampilkan nilai tersebut ditemukan sebanyak berapa kali pada sebuah data tersebut.

#### Full code Screenshot:

![Full_ss_code_unguided3](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/10a3909638f14ce036f04b749602c16af101d689/Pertemuan8/assets/fullss_unguided3.png)

## Kesimpulan

- Algoritma pencarian adalah suatu algoritma yang digunakan untuk menemukan data atau elemen tertentu pada suatu struktur data. Pencarian dapat dilakukan pada struktur data yang berbeda seperti array, linked list, dan stack. Jika terdapat sebuah data dengan nilai kecil dan tidak terurut maka gunakan lah metode sequential search dan jika terdapat sebuah data yang besar dan terurut maka gunakan lah binary search.

## Referensi

[1] Anisya Sonita, IMPLEMENTASI ALGORITMA SEQUENTIAL SEARCHING UNTUK PENCARIAN NOMOR SURAT PADA SISTEM ARSIP ELEKTRONIK, Bengkulu : Universitas Muhammadiyah Bengkulu, 2019.

[2] Leonard Umbu Bulu Mone, Penerapan Algoritma Binary Search Pada Sistem Informasi Perpustakaan, Sumatra: Universitas Kristen Wira Wacana Sumba, 2023
