# <h1 align="center">Laporan Praktikum Modul 7 QUEUE</h1>

<h1 align="center">Hamid Sabirin-2311102129</h1>

## Dasar Teori

<h2 align="center">QUEUE</h2>

Antrian adalah struktur data abstrak, agak mirip dengan Stacks. Tidak seperti tumpukan, antrian terbuka di kedua ujungnya. Satu ujung selalu digunakan untuk memasukkan data (enqueue) dan yang lainnya digunakan untuk menghapus data (dequeue). Antrian mengikuti metodologi First-In-First-Out, yaitu, item data yang disimpan terlebih dahulu akan diakses terlebih dahulu Seperti di tumpukan, antrian juga dapat diimplementasikan menggunakan Array, Linked-list, Pointer dan Structures. Demi kesederhanaan, akan mengimplementasikan antrian menggunakan array satu dimensi. Operasi antrian mungkin melibatkan menginisialisasi atau mendefinisikan antrian, menggunakannya, dan kemudian menghapusnya sepenuhnya dari memori.

Struktur data queue setidaknya harus memiliki operasi-operasi sebagai berikut :

1. Queue(): Membuat Queue Baru
   Operasi Queue() digunakan untuk membuat instance (objek) baru dari struktur data Queue. Instance ini kemudian dapat digunakan untuk menyimpan dan mengelola data dengan mengikuti aturan FIFO (First In First Out).

2. enqueue(item): Menambahkan Data ke Queue
   Operasi enqueue(item) digunakan untuk menambahkan item (data) ke dalam Queue. Penambahan data selalu dilakukan dari bagian belakang (rear) Queue. Bayangkan seseorang yang baru bergabung ke dalam antrian.

3. dequeue(): Menghapus Data dari Queue
   Operasi dequeue() digunakan untuk menghapus data dari Queue. Penghapusan data selalu dilakukan dari bagian depan (front) Queue. Bayangkan orang yang keluar dari antrian.

4. isEmpty(): Memeriksa Keadaan Queue
   Operasi isEmpty() digunakan untuk mengetahui apakah Queue dalam keadaan kosong atau tidak. Operasi ini akan mengembalikan nilai true jika Queue kosong, dan nilai false jika Queue berisi data.

5. isFull(): Memeriksa Kapasitas Queue
   Operasi isFull() digunakan untuk memeriksa apakah Queue penuh atau tidak. Operasi ini akan mengembalikan nilai true jika Queue penuh, dan nilai false jika masih ada ruang untuk menambahkan data.

6. size(): Menghitung Jumlah Data di Queue
   Operasi size() digunakan untuk mengidentifikasi jumlah data yang ada di dalam Queue. Operasi ini akan mengembalikan nilai integer yang menunjukkan jumlah data di dalam Queue.

## Guided

### 1. [Operasi pada queue]

```C++
#include <iostream>
using namespace std;
const int maksimalQueue = 5;
int front = 0;
int back = 0;
string queueTeller[5];
// Pengecekan antrian penuh atau tidak
bool isFull()
{
    if (back == maksimalQueue)
    {
        return true; // =1
    }
    else
    {
        return false;
    }
}
// Antriannya kosong atau tidak
bool isEmpty()
{
    if (back == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// Fungsi menambahkan antrian
void enqueueAntrian(string data)
{
    if (isFull())
    {
        cout << "Antrian penuh" << endl;
    }
    else
    {
        // Kondisi ketika queue kosong
        if (isEmpty())
        {
            queueTeller[0] = data;
            front++;
            back++;
        }
        else
        // Antrianya ada isi
        {
            queueTeller[back] = data;
            back++;
        }
    }
}
// Fungsi mengurangi antrian
void dequeueAntrian()
{ 
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        for (int i = 0; i < back; i++)
        {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}
// Fungsi menghitung banyak antrian
int countQueue()
{ 
    return back;
}
// Fungsi menghapus semua antrian
void clearQueue()
{ 
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        for (int i = 0; i < back; i++)
        {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}
// Fungsi melihat antrian
void viewQueue()
{ 
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++)
    {
        if (queueTeller[i] != "")
        {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        }
        else
        {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}
int main()
{
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
```

=> Penjelasan program

- Pada program code di atas Kode di atas merupakan program C++ yang mengimplementasikan queue untuk teller di suatu bank. Queue ini menggunakan array berukuran 5 untuk menyimpan dta antrian teller pada bank. pada progrma di atas terdapat berbagai fungsi yaitu isFull untuk mengecek apakah data pada queue itu full atau tidak, isEmpety untuk mengecek apakah antrian pada queue kosong atau tidak, enqueueAntrian digunakan untuk menambahkan data teller pada queue, dequeueAntrian digunakan untuk mengurangi antrian pada queue terller, countQueue untuk menghitung total jumlah antrian pada queue, clearQueue digunakan untuk menghapus seluruh data antrian pada queue, dan viewQueue yang berfungsi untuk menampilkan seluruh data antrian teller. jika akan menambahkan data kita hanya perlu memanggil fungsi untuk menambahkan data pada queue terlebih dahulu dan di ikuti parameternya. dan jika ingin menghapus data pada antrian kita hanya perlu memanggil fungsi unutk menghapus data pada antrian queue. dan jika ingin mengetahui jumlah antrian maka kita hanya perlu memanggil fungsi count queue untuk menampilkan jumlah antrian pada queue. Pada program tersebut yaitu queue teller menggunnakan array untuk menampung data antrian teller dan menggunakan sebuah sistem First In First Out yang dimana data pertama masuk maka data tersebut akan keluar terlebih dahulu.

## Unguided

### 1. [Ubahlah penerapan konsep queue pada bagian guided dari array menjadi linked list]

```C++
#include <iostream>

using namespace std;
const int maks_129 = 5;

// Struktur Node untuk linked list
struct Node
{
    string data_129;
    Node *next;
};

// Penunjuk head untuk linked list
Node *head = nullptr;

// Fungsi untuk memeriksa apakah antrian penuh
bool isFull()
{
    return false;
}

// Fungsi untuk memeriksa apakah antrian kosong
bool isEmpty()
{
    return head == nullptr;
}

// Fungsi untuk enqueue (menambahkan) elemen ke antrian
void enqueueAntrian(string data_129)
{
    Node *newNode_129 = new Node;
    newNode_129->data_129 = data_129;
    newNode_129->next = nullptr;

    if (isEmpty())
    {
        head = newNode_129;
        return;
    }

    Node *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }

    current->next = newNode_129;
}

// Fungsi untuk dequeue (menghapus) elemen dari antrian
void dequeueAntrian()
{
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
        return;
    }

    string data_129 = head->data_129;

    Node *temp = head;
    head = head->next;

    delete temp;

    cout << "Data terhapus: " << data_129 << endl;
}

// Fungsi untuk menghitung jumlah elemen dalam antrian
int countQueue()
{
    int count = 0;
    Node *current = head;
    while (current != nullptr)
    {
        count++;
        current = current->next;
    }
    return count;
}

// Fungsi untuk menghapus semua elemen antrian
void clearQueue()
{
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

// Fungsi untuk melihat elemen antrian
void viewQueue()
{
    cout << "Data antrian teller:" << endl;
    int i = 1;
    Node *current = head;
    while (current != nullptr)
    {
        cout << i << ". " << current->data_129 << endl;
        i++;
        current = current->next;
    }
}

int main()
{
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
```

### Output :

<h2>Penggunaan Linked list Pada Queue</h2>

![soal 1](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan7/assets/ssoutput_unguided1.png)

=> Penjelasan Program

- Pada program code di atas Kode di atas merupakan program C++ yang mengimplementasikan queue untuk teller di suatu bank. Queue ini menggunakan linked list untuk menyimpan data antrian teller pada bank. pada progrma di atas terdapat berbagai fungsi yaitu pada awal dibuat sebuah struktur Node untuk linked list, isFull untuk mengecek apakah data pada queue itu full atau tidak, isEmpety untuk mengecek apakah antrian pada queue kosong atau tidak, enqueueAntrian digunakan untuk menambahkan data teller pada queue, dequeueAntrian digunakan untuk mengurangi antrian pada queue terller, countQueue untuk menghitung total jumlah antrian pada queue, clearQueue digunakan untuk menghapus seluruh data antrian pada queue, dan viewQueue yang berfungsi untuk menampilkan seluruh data antrian teller. jika akan menambahkan data kita hanya perlu memanggil fungsi untuk menambahkan data pada que terlebih dahulu dan di ikuti parameternya. dan jika ingin menghapus data pada antrian kita hanya perlu memanggil fungsi unutk menghapus data pada antrian queue. dan jika ingin mengetahui jumlah antrian maka kita hanya perlu memanggil fungsi count queue untuk menampilkan jumlah antrian pada queue. Pada program tersebut yaitu queu teller menggunnakan linked list untuk menampung data antrian teller dan menggunakan sebuah sistem First In First Out yang dimana data pertama masuk maka data tersebut akan keluar terlebih dahulu. 

#### Full code Screenshot:

![Full_ss_code_unguided1](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan7/assets/fullss_unguided1.png)

### 2. [Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa]

```C++
#include <iostream>
using namespace std;

// Maksimal antrian
const int maks_129 = 5;

// Struktur Node untuk linked list
struct Node
{
    string nama_129;
    string nim_129;
    Node *next;
};

// Penunjuk head untuk linked list
Node *head = nullptr;

// Fungsi untuk memeriksa apakah antrian penuh
bool isFull()
{
    return false;
}

// Fungsi untuk memeriksa apakah antrian kosong
bool isEmpty()
{
    return head == nullptr;
}

// Fungsi untuk enqueue (menambahkan) elemen ke antrian
void enqueueAntrian(string nama_129, string nim_129)
{
    Node *newNode_129 = new Node;
    newNode_129->nama_129 = nama_129;
    newNode_129->nim_129 = nim_129;
    newNode_129->next = nullptr;

    if (isEmpty())
    {
        head = newNode_129;
        return;
    }

    Node *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }

    current->next = newNode_129;
}

// Fungsi untuk dequeue (menghapus) elemen dari antrian
void dequeueAntrian()
{
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
        return;
    }

    string nama_129 = head->nama_129;
    string nim_129 = head->nim_129;
    Node *temp = head;
    head = head->next;
    delete temp;

    cout << "Data terhapus: " << nama_129 << ", Nim : " << nim_129 << endl;
}

// Fungsi untuk menghitung jumlah elemen dalam antrian
int countQueue()
{
    int count = 0;
    Node *current = head;
    while (current != nullptr)
    {
        count++;
        current = current->next;
    }
    return count;
}

// Fungsi untuk menghapus semua elemen antrian
void clearQueue()
{
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

// Fungsi untuk melihat elemen antrian
void viewQueue()
{
    cout << "Data antrian mahasiswa:" << endl;
    int i = 1;
    Node *current = head;
    while (current != nullptr)
    {
        cout << i << ". " << current->nama_129 << ", Nim : " << current->nim_129 << endl;
        i++;
        current = current->next;
    }
}

int main()
{
    // menambahkan antrian pada queue
    enqueueAntrian("Budi", "12345");
    enqueueAntrian("Ani", "54321");
    // menampilkan queue
    viewQueue();
    // mengecek jumlah antrian
    cout << "Jumlah antrian = " << countQueue() << endl;
    // menghapus antrian
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    // menghapus semua antrian
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
```

### Output :

<h2>Mengubah Antrian Queue Nama dan Nim</h2>

![soal a](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan7/assets/ssoutput_unguided2.png)

=> Penjelasan Program

- Pada program code di atas Kode di atas merupakan program C++ yang mengimplementasikan queue untuk teller di suatu bank. Queue ini menggunakan Linked list untuk menyimpan data antrian teller pada bank. pada progrma di atas terdapat berbagai fungsi yaitu pada awal dibuat sebuah struktur Node linked list untuk data mahasiswa yaitu nama dan nim, isFull untuk mengecek apakah data pada queue itu full atau tidak, isEmpety untuk mengecek apakah antrian pada queue kosong atau tidak, enqueueAntrian digunakan untuk menambahkan data mahasiswa yaitu nama dan nim pada queue, dequeueAntrian digunakan untuk mengurangi antrian mahasiswa pada queue, countQueue untuk menghitung total jumlah antrian mahasiswa pada queue, clearQueue digunakan untuk menghapus seluruh data antrian mahasiswa pada queue, dan viewQueue yang berfungsi untuk menampilkan seluruh data antrian mahasiswa. jika akan menambahkan data mahasiswa kita hanya perlu memanggil fungsi untuk menambahkan data pada que terlebih dahulu dan di ikuti parameternya nama dan nim. dan jika ingin menghapus data pada antrian kita hanya perlu memanggil fungsi dequeueAntrian untuk menghapus data pada antrian queue. dan jika ingin mengetahui jumlah antrian maka kita hanya perlu memanggil fungsi count queue untuk menampilkan jumlah antrian pada queue. Pada program tersebut yaitu queu teller menggunnakan linked list untuk menampung data antrian teller dan menggunakan sebuah sistem First In First Out yang dimana data pertama masuk maka data tersebut akan keluar terlebih dahulu.

#### Full code Screenshot:

![Full_ss_code_unguided1](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan7/assets/fullss_unguided2.png)

## Kesimpulan

- Dari percobaan tersebut dapat disimpulkan bahwa queue adalah struktur data yang mengikuti prinsip FIFO (First In First Out), di mana data pertama yang dimasukkan menjadi data pertama yang dapat dikeluarkan. Queue dapat diimplementasikan menggunakan array atau linked list, dengan operasi dasar seperti enqueue (menambahkan elemen), dequeue (mengambil elemen pertama), peek (melihat elemen pertama tanpa menghapusnya), isEmpty (memeriksa apakah kosong), dan size (mengetahui jumlah elemen). Operasi tambahan seperti isFull juga diperlukan untuk memeriksa status queue. Prinsip queue sangat berguna dalam pengolahan data terstruktur dan pengelolaan memori komputer.

## Referensi

[1] Khoirudin, Algoritma & Struktur Data dengan Phyton 3, Semarang: Universitas Semarang Press, 2019.

[2] Rizki Muliono, Pemrograman C++ ALGORITMA & STRUKTUR DATA, Medan: UNIVERSITAS MEDAN AREA, 2019.

[3] Dr. Hindarto, Ade Eviyanti, ALGORITMA & PEMOGRAMAN MENGGUNAKAN MATLAB, Sidoarjo: UMSIDA Press , 2020.
