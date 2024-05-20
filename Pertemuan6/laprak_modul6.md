# <h1 align="center">Laporan Praktikum Modul 6 STACK</h1>

<h1 align="center">Hamid Sabirin-2311102129</h1>

## Dasar Teori

<h2 align="center">STACK</h2>

Secara sederhana, Stack (tumpukan) dapat diartikan sebagai suatu kumpulan data yang seolah-olah ada data yang diletakkan di atas data yang lain. Satu hal yang perlu diingat adalah bahwa dapat ditambah (menyisipkan) data, dan mengambil (menghapus) data lewat ujung yang sama, yang disebut sebagai ujung atas tumpukan (top of stack). Tipe data yang bersifat LIFO (Last In First Out), dimana data yang terakhir masuk akan menjadi data yang pertama kali dapat dikeluarkan. Ada dua cara penerapan prinsip stack, yakni dengan array dan linked list. Penerapan Stact di Struktur data mempunyai beberapa operasi yang harus ada antara lain adalah:

- stack(): Untuk membuat stack
- push(): Untuk menambahkan sebuah item ke dalam stack
- pop(): Untuk mengambil data dari stack (data paling atas akan dikeluarkan dari stack)
- peek(): Untuk mengidentifikasi data paling akhir yang masuk ke dalam stack
- isEmpty(): Untuk mengidentifikasi apakah stack masih kosong? Akan menghasilkan nilai TRUE jika stack masih dalam keadaan kosong
- size(): Untuk mengetahu jumlah item (elemen) dalam sebuah stack.
- Search(): Mencari keberadaan elemen tertentu dalam tumpukan.
- isFull() -periksa apakah stack penuh.
- Top(): Mendapatkan nilai atau melihat elemen teratas pada tumpukan tanpa menghapusnya.

Operasi tumpukan mungkin melibatkan menginisialisasi tumpukan, menggunakannya dan kemudian melakukan inisialisasi. Terlepas dari barang-barang dasar ini, tumpukan digunakan untuk dua operasi utama berikut :

- push() -Mendorong (menyimpan) elemen pada stack.
- pop() -Menghapus(mengakses) suatu elemen dari stack.

Ketika data di PUSH ke stack. Untuk menggunakan tumpukan secara efisien,kita perlu memeriksa status tumpukan juga. Untuk tujuan yang sama, fungsi berikut ditambahkan ke tumpukan :

- peek() -dapatkan elemen data teratas dari stack, tanpa menghapusnya.
- isFull() -periksa apakah stack penuh.
- isEmpty() -periksa apakah stack kosong.

Jadi Stack (Tumpukan) adalah sekumpulan elemen-elemen data yang disimpan dalam satu laju linier. Kumpulan elemen-elemen data hanya boleh diakses pada satu lokasi saja yaitu pada posisi Atas (TOP) tumpukan. Tumpukan disebut juga Push Down Stack yaitu penambahan elemen baru (PUSH) dan penghapusan elemen dari tumpukan (POP). Stack juga bisa di gunakan pada array dan linked list untuk operasi stack pada array sama dengan operasi pada umumnya dan operasi pada stack linked list itu terdapat ada tiga yaitu isEmpety, pop dan push yang dimana fungsinya untuk mengecek apakah stack pada linked list kosong atau tidak, mengeluarkan element dari stack pada linked list dan memasukan element ke stack di linked list.

## Guided

### 1. [Operasi pada stack]

```C++
#include <iostream>
using namespace std;

string arraybuku[5];
int maksimal = 5, top = 0;

// Fungsi untuk mengecek apakah stack sudah penuh
bool isFull()
{
    return (top == maksimal);
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty()
{
    return (top == 0);
}

// Prosedur untuk menambahkan data ke dalam stack
void pushArrayBuku(string data)
{
    if (isFull())
    {
        cout << "data telah penuh" << endl;
    }
    else
    {
        arraybuku[top] = data;
        top++;
    }
}

// Prosedur untuk menghapus data dari stack
void popArrayBuku()
{
    if (isEmpty())
    {
        cout << "Tidak ada data yang bisa dihapus" << endl;
    }
    else
    {
        arraybuku[top - 1] = "";
        top--;
    }
}

// Prosedur untuk melihat data pada posisi tertentu dalam stack
void peekArrayBuku(int posisi)
{
    if (isEmpty())
    {
        cout << "Tidak ada data yang bisa ditampilkan" << endl;
    }
    else
    {
        int index = top;
        for (int i = 1; i <= posisi; i++)
        {
            index--;
        }
        cout << "Posisi ke " << posisi << " adalah " << arraybuku[index] << endl;
    }
}

// Fungsi untuk menghitung jumlah data dalam stack
int countStack()
{
    return top;
}

// Prosedur untuk mengubah data pada posisi tertentu dalam stack
void changeArrayBuku(int posisi, string data)
{
    if (posisi > top)
    {
        cout << "Posisi melebihi data" << endl;
    }
    else
    {
        int index = top;
        for (int i = 1; i <= posisi; i++)
        {
            index--;
        }
        arraybuku[index] = data;
    }
}

// Prosedur untuk menghapus semua data dalam stack
void destroyArrayBuku()
{
    for (int i = top; i >= 0; i--)
    {
        arraybuku[i] = "";
    }
    top = 0;
}

// Prosedur untuk mencetak semua data dalam stack
void printArrayBuku()
{
    if (isEmpty())
    {
        cout << "Tidak ada data yang dicetak" << endl;
    }
    else
    {
        for (int i = top - 1; i >= 0; i--)
        {
            cout << arraybuku[i] << endl;
        }
    }
}

int main()
{
    // Menambahkan beberapa data ke dalam stack
    pushArrayBuku("Inggris");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Kalkulus");

    // Mencetak semua data dalam stack
    printArrayBuku();
    cout << endl;
    // Menampilkan status stack
    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;
    // Melihat data pada posisi tertentu dalam stack
    peekArrayBuku(2);
    // Menghapus data dari stack
    popArrayBuku();
    // Menghitung jumlah data dalam stack
    cout << "Banyaknya data: " << countStack() << endl;
    // Mengubah data pada posisi tertentu dalam stack
    changeArrayBuku(2, "Bahasa Jerman");
    // Mencetak semua data dalam stack setelah perubahan
    printArrayBuku();
    cout << endl;
    // Menghapus semua data dalam stack
    destroyArrayBuku();
    // Menampilkan jumlah data setelah dihapus
    cout << "Jumlah data setelah dihapus: " << top << endl;
    // Mencetak semua data dalam stack setelah dihapus
    printArrayBuku();
    return 0;
}
```

=> Penjelasan program

- Pada program code di atas Kode di atas merupakan program C++ yang mengimplementasikan stack untuk menyimpan data buku. Stack ini menggunakan array berukuran 5 untuk menyimpan judul buku. Berikut penjelasan dari setiap fungsi dalam program Kode di atas merupakan program C++ yang mengimplementasikan stack untuk menyimpan data buku.Stack ini menggunakan array berukuran 5 untuk menyimpan judul buku. pada code tersebut terdapat fungsi yaitu isFull, isEmpety, push, pop, peek, count, change, destroy dan print fungsi tersebut digunakan untuk mengecek data full atau kosong, menambahkan, menghapus, melihat data, menghitung, mengubah, menghapus semua, dan mencetak. unutuk menambahkan kita bisa menggunakan push yang dimana kita mengecek terlebih dahulu apakah tempat stack full atau tidak jika tidak maka akan ditambahkan, selanjutnya kita bisa mengecek full menggunakan isFull untuk mengecek stack full atau tidak, isEmpety juga bisa digunakan untuk mengecek apakah stack kosong atau tidak dengan memberikan output true atau false melihat data pada posisi berapa pada stack bisa menggunakan peek, untuk menghapus satu data menggunakan pop dan di cek apakah data kosong atau tidak pada stack, menghitung jumlah keseluruhan data pada stack menggunakan count dengan mengembalikan return top pada variable yang dibuat mengubah data menggunakan change yang dimana harus menggunakan index urutan pada stack untuk mengubah data sebelumnya menjadi yang baru dan di cek apakah ada datanya atau tidak pada stack tersebut, ketika akan menghapus semua data yang ada pada stack kita bisa menggunakan destroy yang dimana kita bisa mengecek terlebih dahulu apakah ada data pada stack tersebut jika da maka akan di hapus semua data nya pada stack tersbut. dan ketika akan menampilkan sebuah data maka menggunakan print maka akan menampilkan seluruh data yang ada pada stack tersebut. untuk menggunakan fungsi tersebut kita hanya perlu memanggil sebuah fungsi atau prosedur yang telah di buat dan di ikuti oleh parameter yang ada pada fungsi maupu prosedur.

## Unguided

### 1. [Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.]

![soal1](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan6/assets/soal.png)

```C++
#include <iostream>
#include <stack>
#include <string>
using namespace std;

// fungsi untuk mengecek apakah sebuah kalimat merupakan palindrom (kata atau frasa yang sama saat dibaca dari depan atau belakang)
bool Palindrom(string kata_129)
{
    // Inisialisasi stack
    stack<char> stack;
    // Memecah kalimat menjadi kata-kata
    for (char c : kata_129)
    {
        stack.push(c);
    }
    // Memeriksa apakah kalimat tersebut merupakan palindrom
    for (char c : kata_129)
    {
        if (stack.top() != c)
        {
            return false;
        }
        stack.pop();
    }
    return true;
}

int main()

{
    // input kalimat
    string input;
    cout << "Masukan Kalimat: ";
    getline(cin, input);
    // mengecek apakah kalimat tersebut merupakan palindrom
    if (Palindrom(input))
    {
        cout << "Kalimat tersebut merupakan : Palindrom" << endl;
    }
    else
    {
        cout << "Kata tersebut merupakan bukan : Palindrom" << endl;
    }

    return 0;
}
```

### Output :

<h2>Palindrom kata.</h2>

![soal 1](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan6/assets/ssoutput_unguided1.png)

<h2>Bukan Palindrom kata</h2>

![soal 1_1](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan6/assets/ssoutput_unguided1_1.png)

=> Penjelasan Program

- Pada code di atas merupakan code untuk palindrom, kode di atas terdapat fungsi Palindrom yang dimana fungsi tersebut nanti akan mengecek sebuah kata yang dimana kata tersebut ketika di baca dari depan dan dari belakang akan menghasilkan kata tersebut atau sama tidak berubah. pada fungsi tersebut di inisialisasikan dahulu lalu terdapat perulangan yang memecah kata yang telah diinputkan menjadi char atau satu huruf kemudian akan di simpan pada stack selanjutnya terdapat perulangan unutuk Loop for kedua digunakan untuk mengiterasi setiap karakter dalam variabel kata kembali yang dimana pada setiap iterasi Karakter teratas dalam stack dibandingkan dengan karakter c saat ini. Jika karakternya tidak sama, maka kalimat bukan palindrom dan fungsi mengembalikan false. Jika karakternya sama, karakter tersebut dipop dari stack. Jika loop for kedua selesai tanpa menemukan ketidakcocokan, berarti semua karakter di kedua sisi kalimat sama, dan kalimat tersebut merupakan palindrom.

#### Full code Screenshot:

![Full_ss_code_unguided1](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan6/assets/fullss_unguided1.png)

### 2. [Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakan stack dengan minimal 3 kata. Jelaskan output program dan source codenya beserta operasi/fungsi yang dibuat?]

![soal1](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan6/assets/soal2.png)

```C++
#include <iostream>
#include <stack>

using namespace std;

// Fungsi untuk membalikkan kalimat
void Pembalik(string kalimat_129)
{
    // Inisialisasi stack
    stack<string> st;
    string kata_129 = "";
    // Memecah kalimat menjadi kata-kata
    for (size_t i = 0; i < kalimat_129.length(); i++)
    {
        // Memeriksa apakah karakter saat ini adalah spasi
        if (kalimat_129[i] == ' ')
        {
            // Memasukkan kata ke dalam stack
            st.push(kata_129);
            // Mengosongkan kembali string kata
            kata_129 = "";
        }
        else
        {
            // Memasukkan karakter ke dalam string kata
            kata_129 = kalimat_129[i] + kata_129;
        }
    }

    // Memasukkan kata terakhir ke dalam stack
    st.push(kata_129);

    // Mencetak kata-kata dari stack untuk menghasilkan kalimat yang terbalik
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main()
{
    // Input kalimat
    string kalimat_129;
    cout << "Masukkan Kata : ";
    getline(cin, kalimat_129);
    // Menampilkan kalimat setelah diturunkan
    cout << "Hasil Kata Setelah Diturunkan : ";
    Pembalik(kalimat_129);

    return 0;
}

```

### Output :

<h2>Pembalikan terhadap kalimat.</h2>

![soal a](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan6/assets/ssoutput_unguided2.png)

=> Penjelasan Program

- Pada code di atas merupakan code untuk membalikan sebuah kalimat, untuk outputnya akan terbalik dari kalimat sebelumnya contohnya seperti "aku" menjadi "uka", pada fungsi di atas yaitu fungsi pembalik teradpat inisialisasi dan membuat variable untuk menampung sebuah kata nmanti, setelah itu terdapat sebuah perulangan yang dimana perulangan tersebut digunakan untuk memecah kalimat menjadi kata kata setelah di pecah menjadi kata huruf terdapat sbeuah perjabangan if else yang dimana memeriksa apakah karakter saat itu adalah spasi jika iya maka akan memasukan kata ke dalam wadah stack dan mengosongkan kembali string kata, dan jika else maka akan memasukan karakter kedalam wadah variable string ytang telah di buat bukan masuk ke dalam stack jika sudah maka memasukan kata terakhir kedalam stack, kemudian menampilkan kata kata dari stack yang sudah di pecahkan dan digabungkan tetapi dalam bentuyk kalimat yang terbalik pada outputnya

#### Full code Screenshot:

![Full_ss_code_unguided1](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan6/assets/fullss_unguided2.png)

## Kesimpulan

Dari Materi stack yang telah di uji cobakan di atas adalah bahwa:

- Dari percobaan tersebut dapat disimpulkan bahwa stack adalah struktur data yang mengikuti prinsip LIFO (Last In First Out), di mana data terakhir yang dimasukkan menjadi data pertama yang dapat dikeluarkan. Stack dapat diimplementasikan menggunakan array atau linked list, dengan operasi dasar seperti push (menambahkan elemen), pop (mengambil elemen teratas), peek (melihat elemen teratas tanpa menghapusnya), isEmpty (memeriksa apakah kosong), dan size (mengetahui jumlah elemen). Operasi tambahan seperti isFull juga diperlukan untuk memeriksa status stack. Prinsip stack sangat berguna dalam pengolahan data terstruktur dan pengelolaan memori komputer.

## Referensi

[1] Wanra Tarigan, Algoritma Pemograman dan Struktur Data, Purbalingga: EUREKA MEDIA AKSARA, 2022.

[2] Khoirudin, Algoritma & Struktur Data dengan Phyton 3, Semarang: Universitas Semarang Press, 2019.

[3] Rizki Muliono, Pemrograman C++ ALGORITMA & STRUKTUR DATA, Medan: UNIVERSITAS MEDAN AREA, 2019.

[4] Dr. Hindarto, Ade Eviyanti, ALGORITMA & PEMOGRAMAN MENGGUNAKAN MATLAB, Sidoarjo: UMSIDA Press , 2020.

[5] Januardi nasir, Algoritma dan Struktur Data Dengan Pemograman Pascaldan Phyton, Padang: CV. Gita Lentera, 2024.
