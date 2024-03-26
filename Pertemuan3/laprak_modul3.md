# <h1 align="center">Laporan Praktikum Modul Single & Double Linked List</h1>

<h1 align="center">Hamid Sabirin-2311102129</h1>

## Dasar Teori

Linked List adalah sebuah jenis struktur data yang digunakan untuk menyimpan dan mengelola data secara dinamis. Struktur data ini terdiri dari elemen-elemen individu, yang masing-masing disambungkan dengan dua pointer: next dan prev.
Jenis Linked List ada 2 yaitu sebagai berikut:

A. Single Linked list

- Single Linked list adalah Daftar terhubung yang setiap simpul pembentuknya mempunyai satu rantai(link) ke simpul lainnya.

B. Double Linked list

- Double linked list yang mempunyai dua rantai yaitu penujuk ke sebelumnya dan ke depannya

## Guided

### 1. [Single Linked List]

```C++
#include <iostream>
using namespace std;
/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node
{
    int data;
    Node *next;
};
Node *head;
Node *tail;
// Inisialisasi Node
void init()
{
    head = NULL;
    tail = NULL;
}
// Pengecekan
bool isEmpty()
{
    if (head == NULL)
        return true;
    else
        return false;
}
// Tambah Depan
void insertDepan(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        baru->next = head;
        head = baru;
    }
}
// Tambah Belakang
void insertBelakang(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
}
// Hitung Jumlah List
int hitungList()
{
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while (hitung != NULL)
    {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}
// Tambah Tengah
void insertTengah(int data, int posisi)
{
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;
        // tranversing
        bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}
// Hapus Depan
void hapusDepan()
{
    Node *hapus;
    if (isEmpty() == false)
    {
        if (head->next != NULL)
        {
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}
// Hapus Belakang
void hapusBelakang()
{
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false)
    {
        if (head != tail)
        {
            hapus = tail;
            bantu = head;
            while (bantu->next != tail)
            {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}
// Hapus Tengah
void hapusTengah(int posisi)
{
    Node *hapus, *bantu, *bantu2;
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        int nomor = 1;
        bantu = head;
        while (nomor <= posisi)
        {
            if (nomor == posisi - 1)
            {
                bantu2 = bantu;
            }
            if (nomor == posisi)
            {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        bantu2->next = bantu;
        delete hapus;
    }
}
// Ubah Depan
void ubahDepan(int data)
{
    if (isEmpty() == false)
    {
        head->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Ubah Tengah
void ubahTengah(int data, int posisi)
{
    Node *bantu;
    if (isEmpty() == false)
    {
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else
        {
            bantu = head;
            int nomor = 1;
            while (nomor < posisi)
            {
                bantu = bantu->next;
                nomor++;
            }
            bantu->data = data;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Ubah Belakang
void ubahBelakang(int data)
{
    if (isEmpty() == false)
    {
        tail->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Hapus List
void clearList()
{
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}
// Tampilkan List
void tampil()
{
    Node *bantu;
    bantu = head;
    if (isEmpty() == false)
    {
        while (bantu != NULL)
        {
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
int main()
{
    init();
    insertDepan(3);
    tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7, 2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();
    return 0;
}
```

=> Penjelasan program

- Pada code di atas merupakan code unutk linked list non circular pada program di atas terdapat beberapa fungsi yang digunakan yang terdiri dari menambahkan data dari depan belakang dan tengah, ada juga mengubah atau mengupdate data dari depan belakang dan tengah, dan ada fungsi hapus dari depan belakang dan tengah juga, selanjutnya juga terdapat fungsi untuk menampilkan data. pada code di atas kita bisa menambahkan sebuah data dengan cara memanggil fungsi dan di ikuti oleh isi parameter fungsi tersebut. kita juga bisa mengubah data yang kita inginkan seperti melaluli depan belakang maupun tengah dengan cara yang sama seperti menambahkan yaitu memanggil fungsi ubah data dan di ikuti oleh parameter, dan fungi hapus pada fungsi tersebut kita bisa menghapus sebuah data dari depan belakang dan tengah dengan cara memanggil fungsi hapus dan di ikuti parameter jika menghapus dengan cara memilih hapus tengah, setelah memanggil fungsi pastikan untuk memanggil fungsi menampilkan data untuk melihat data yang baru seperti setelah menambahkan, mengubah ataupun menghapus data dari linked list.

### 2. [Double Linked List]

```C++
#include <iostream>
using namespace std;
// PROGRAM SINGLE LINKED LIST CIRCULAR
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
};
// Deklarasi Struct Node
class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }
    //upload data
    void push(int data)
    {
        // membuat node
        Node *newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr)
        {
            head->prev = newNode;
        }
        else
        {
            tail = newNode;
        }
        head = newNode;
    }
    // hapus data
    void pop()
    {
        //jika list kosong
        if (head == nullptr)
        {
            return;
        }
        Node *temp = head;
        head = head->next;

        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        else
        {
            tail = nullptr;
        }
        delete temp;
    }
    //update data
    bool update(int oldData, int newData)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->data == oldData)
            {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    //delete semua data
    void deleteAll()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
    //menampilkan semua data
    void display()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};
// fungsi utama
int main()
{
    // membuat list
    DoublyLinkedList list;
    while (true)
    {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
            // menambahkan data
        case 1:
        {
            int data;
            cout << "Enter data to add: ";
            cin >> data;
            list.push(data);
            break;
        }
        // menghapus data
        case 2:
        {
            list.pop();
            break;
        }
        // memperbarui data
        case 3:
        {
            int oldData, newData;
            cout << "Enter old data: ";
            cin >> oldData;
            cout << "Enter new data: ";
            cin >> newData;
            bool updated = list.update(oldData,newData);
            if (!updated)
            {
                cout << "Data not found" << endl;
            }
            break;
        }
        // menghapus semua data
        case 4:
        {
            list.deleteAll();
            break;
        }
        // menampilkan semua data
        case 5:
        {
            list.display();
            break;
        }
        // keluar
        case 6:
        {
            return 0;
        }
        default:
        {
            cout << "Invalid choice" << endl;
            break;
        }
        }
    }
    return 0;
}
```

=> Penjelasan program

- Pada program di atas merupakan sebuah code linked list circular. Code tersebut memungkinkan pengguna untuk melakukan CRUD pada linked list, pada code tersbut terdapat berbagai fungsi yang contohnya pop, delete, add, dan update. Pada program tersebut kita bisa menambahkan data dari depan, menghapuskan data linked list hanya satu data, update data pada linked list dengan urutan, dan menghapuskan semua data yang ada pada linked list, dan jangan lupa ketika menambahkan, menghapus, mengubah kita perlu memanggil fungsi display yang gunanya untuk menampilkan data terbaru.

## Unguided

### 1. [Buatlah program menu Single Linked List Non-Circular untuk menyimpan Nama dan usia mahasiswa, dengan menggunakan inputan dari user. Lakukan operasi berikut: a. Masukkan data sesuai urutan berikut. (Gunakan insert depan, belakang atau tengah). Data pertama yang dimasukkan adalah nama dan usia anda]

![soal1](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan3/assets/soal1.png)

```C++
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Deklarasi Struct Node
struct Node
{
    string nama_129;
    int umur_129;
    Node *next;
};

Node *head;
Node *tail;

// prosedur init
void inti()
{
    head = NULL;
    tail = NULL;
}

// fungsi untuk mengecek linked list apakah nilainya null atau bukan
bool null()
{
    return head == NULL;
}

// menambahkan data di depan
void tambahdepan(string nama_129, int umur_129)
{
    Node *baru = new Node;
    baru->nama_129 = nama_129;
    baru->umur_129 = umur_129;
    baru->next = NULL;

    if (null())
    {
        head = tail = baru;
    }
    else
    {
        baru->next = head;
        head = baru;
    }
}

// menambahkan data di belakang
void tambahbelakang(string nama_129, int umur_129)
{
    Node *baru = new Node;
    baru->nama_129 = nama_129;
    baru->umur_129 = umur_129;
    baru->next = NULL;

    if (null())
    {
        head = tail = baru;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
}

// menghitung data pada linked list
int hitungjumlah()
{
    Node *hitung = head;
    int jumlah = 0;

    while (hitung != NULL)
    {
        jumlah++;
        hitung = hitung->next;
    }

    return jumlah;
}

// menambahkan data di tengah
void tambahtengah(string nama_129, int umur_129, int posisi_129)
{
    if (posisi_129 < 1 || posisi_129 > hitungjumlah())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi_129 == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        Node *baru = new Node;
        baru->nama_129 = nama_129;
        baru->umur_129 = umur_129;
        Node *bantu = head;
        int nomor = 1;

        while (nomor < posisi_129 - 1)
        {
            bantu = bantu->next;
            nomor++;
        }

        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// menghapus data di depan
void hapusdepan()
{
    if (!null())
    {
        Node *hapus = head;

        if (head->next != NULL)
        {
            head = head->next;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List null!" << endl;
    }
}

// menghapus data di belakang
void hapusdbelakang()
{
    if (!null())
    {
        Node *hapus = tail;
        Node *bantu = head;

        if (head != tail)
        {
            while (bantu->next != tail)
            {
                bantu = bantu->next;
            }

            tail = bantu;
            tail->next = NULL;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List null!" << endl;
    }
}

// menghapus data di tengah
void hapusdtengah(int posisi_129)
{
    if (posisi_129 < 1 || posisi_129 > hitungjumlah())
    {
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if (posisi_129 == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        Node *hapus;
        Node *bantu;
        Node *bantuan;
        int nomor = 1;
        bantu = head;

        while (nomor <= posisi_129)
        {
            if (nomor == posisi_129 - 1)
            {
                bantuan = bantu;
            }

            if (nomor == posisi_129)
            {
                hapus = bantu;
            }

            bantu = bantu->next;
            nomor++;
        }

        bantuan->next = bantu;
        delete hapus;
    }
}

// mengubah data di depan
void ubahdepan(string nama_129, int umur_129)
{
    if (!null())
    {
        head->nama_129 = nama_129;
        head->umur_129 = umur_129;
    }
    else
    {
        cout << "List masih null!" << endl;
    }
}

// mengubah data di tengah
void ubahtengah(string nama_129, int umur_129, int posisi_129)
{
    if (!null())
    {
        if (posisi_129 < 1 || posisi_129 > hitungjumlah())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi_129 == 1)
        {
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else
        {
            Node *bantu = head;
            int nomor = 1;

            while (nomor < posisi_129)
            {
                bantu = bantu->next;
                nomor++;
            }

            bantu->nama_129 = nama_129;
            bantu->umur_129 = umur_129;
        }
    }
    else
    {
        cout << "List masih null!" << endl;
    }
}

// mengubah data di belakang
void ubahbelakang(string nama_129, int umur_129)
{
    if (!null())
    {
        tail->nama_129 = nama_129;
        tail->umur_129 = umur_129;
    }
    else
    {
        cout << "List masih null!" << endl;
    }
}

// menghapus semua data
void deletall()
{
    Node *bantu = head;
    Node *hapus;

    while (bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }

    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

// menampilkan data
void tampilkan()
{
    Node *bantu = head;
    if (!null())
    {
        cout << "|---------------------------|" << endl;
        cout << "|       Nama       |  Umur  |" << endl;
        cout << "|---------------------------|" << endl;
        while (bantu != NULL)
        {
            cout << "| " << setw(15) << left << bantu->nama_129 << " | " << setw(7) << left << bantu->umur_129 << " |" << endl;
            bantu = bantu->next;
        }
        cout << "|---------------------------|" << endl;
    }
    else
    {
        cout << "List masih null!" << endl;
    }
}

// Fungsi untuk menghapus data berdasarkan nama
void hapusdata(string nama_129)
{
    if (!null())
    {
        cout << "List masih null!" << endl;
        return;
    }

    Node *bantu = head;
    Node *sebelum = NULL;

    // Mencari node dengan nama yang sesuai
    while (bantu != NULL && bantu->nama_129 != nama_129)
    {
        sebelum = bantu;
        bantu = bantu->next;
    }

    // Jika data tidak ditemukan
    if (bantu == NULL)
    {
        cout << "Data tidak ditemukan!" << endl;
        return;
    }

    // Jika data ditemukan di head
    if (sebelum == NULL)
    {
        hapusdepan();
    }
    else
    {
        sebelum->next = bantu->next;
        delete bantu;
        cout << "Data dengan nama " << nama_129 << " berhasil dihapus!" << endl;
    }
}

int main()
{
    // Inisialisasi linked list
    inti();
    // Tambahkan data awal
    tambahdepan("Karin", 18);
    tambahdepan("Hoshino", 18);
    tambahdepan("Akechi", 20);
    tambahdepan("Yusuke", 19);
    tambahdepan("Michael", 18);
    tambahdepan("Jane", 20);
    tambahdepan("John", 19);
    tambahdepan("Hamid", 19);

    // Tampilkan data awal
    cout << "Data Mahasiswa" << endl;
    tampilkan();
    cout << endl;

    // Menu
    int pilihan;
    string nama_129;
    int umur_129;
    int posisi_129;
    do
    {
        cout << "Data Mahasiswa :" << endl;
        cout << "1. Tambah Mahasiswa" << endl;
        cout << "2. Hapus Mahasiswa" << endl;
        cout << "3. Update Mahasiswa" << endl;
        cout << "4. Tambah Mahasiswa Urutan Tertentu" << endl;
        cout << "5. Hapus Mahasiswa Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data Mahasiswa" << endl;
        cout << "7. Tampilkan Data Mahasiswa" << endl;
        cout << "8. Exit" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            // Tambah Data
            cout << "Masukkan Nama: ";
            cin >> nama_129;
            cout << "Masukkan Umur: ";
            cin >> umur_129;
            tambahdepan(nama_129, umur_129);
            break;
        case 2:
            // Pilihan hapus data
            int hapusPilihan;
            cout << "Pilihan Hapus Data:" << endl;
            cout << "1. Hapus Data dari Depan" << endl;
            cout << "2. Hapus Data dari Belakang" << endl;
            cout << "Pilihan: ";
            cin >> hapusPilihan;

            if (hapusPilihan == 1)
            {
                hapusdepan();
            }
            else if (hapusPilihan == 2)
            {
                hapusdbelakang();
            }
            else
            {
                cout << "Pilihan tidak valid!" << endl;
            }
            break;

        case 3:
            // Update Data
            cout << "Masukkan Nama yang Akan Diupdate: ";
            cin >> nama_129;
            cout << "Masukkan Umur Baru: ";
            cin >> umur_129;
            cout << "masukan posisi : ";
            cin >> posisi_129;
            ubahtengah(nama_129, umur_129, posisi_129);
            break;
        case 4:
            // Tambah Data Urutan Tertentu
            cout << "Masukkan Nama yang Akan Ditambahkan: ";
            cin >> nama_129;
            cout << "Masukkan Umur: ";
            cin >> umur_129;
            cout << "Masukkan Posisi (indeks) untuk Menambahkan Data: ";
            cin >> posisi_129;
            tambahtengah(nama_129, umur_129, posisi_129);
            break;
        case 5:
            // Hapus Data Urutan Tertentu
            cout << "Masukkan Posisi (indeks) untuk Menghapus Data: ";
            cin >> posisi_129;
            hapusdtengah(posisi_129);
            break;
        case 6:
            // Hapus Seluruh Data
            deletall();
            break;
        case 7:
            // Tampilkan Data
            cout << "Data Mahasiswa" << endl;
            tampilkan();
            cout << endl;
            break;
        case 8:
            // Keluar
            cout << "Terima kasih!" << endl;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }
    } while (pilihan != 8);

    return 0;
}

```

### Output :

<h1>Masukkan data sesuai urutan</h1>

![unguided_output 1a](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan3/assets/soal1a.png)

<h1>Hapus data Akechi</h1>

![unguided_output 1b](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan3/assets/soal1b.png)

<h1>Tambahkan data berikut diantara John dan Jane : Futaba 18</h1>

![unguided_output 1c](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan3/assets/soal1c.png)

<h1>Tambahkan data berikut diawal : Igor 20</h1>

![unguided_output 1d](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan3/assets/soal1d.png)

<h1>Ubah data Michael menjadi : Reyn 18</h1>

![unguided_output 1e](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan3/assets/soal1e.png)

<h1>Tampilkan seluruh data</h1>

![unguided_output 1f](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan3/assets/soal1f.png)

=> Penjelasan Program

- Program di atas adalah program untuk lingked list yang digunakan untuk menyimpan data mahasiswa berupa nama dan umur mahasiswa. Dalam program ini terdapat berbagai fungsi yang dapat digunakan, yaitu fungsi untuk menambahkan, menghapus dan mengubah data list mahasiswa. fungsi init_129 digunakan untuk memulai list, fungsi tambah digunakan untuk menambahkan data di awal list, fungsi hapus digunakan untuk menghapus data di list, fungsi tampilkan digunakan untuk menampilkan seluruh data, pada fungsi int main terdapat sebuah menu yang nantinya kita bisa gunakan untuk melakukan operasi penambahan data penghapusan data dan pengubahan data sesuai pilihan yang ada pada menu dan kita akan menginputkan nama dan umur untuk menambahkan dan ketika mengubah di tambahkan posisi dari data pada linked list.

#### Full code Screenshot:

![Full_ss_code_unguided1](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan3/assets/fullss_unguided1.png)

### 2. [Modifikasi Guided Double Linked List dilakukan dengan penambahan operasi untuk menambah data, menghapus, dan update di tengah / di urutan tertentu yang diminta. Selain itu, buatlah agar tampilannya menampilkan Nama produk dan harga.]

```C++
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Deklarasi Struct Node
struct Node
{
    string nama_129;
    int harga_129;
    Node *next;
};

Node *head;
Node *tail;

// prosedur init
void inti_129()
{
    head = NULL;
    tail = NULL;
}

// fungsi untuk mengecek linked list apakah nilainya null atau bukan
bool null_129()
{
    return head == NULL;
}

// menambahkan data di depan
void tambahdepan_129(string nama_129, int harga_129)
{
    Node *baru = new Node;
    baru->nama_129 = nama_129;
    baru->harga_129 = harga_129;
    baru->next = NULL;

    if (null_129())
    {
        head = tail = baru;
    }
    else
    {
        baru->next = head;
        head = baru;
    }
}

// menambahkan data di belakang
void tambahbelakang_129(string nama_129, int harga_129)
{
    Node *baru = new Node;
    baru->nama_129 = nama_129;
    baru->harga_129 = harga_129;
    baru->next = NULL;

    if (null_129())
    {
        head = tail = baru;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
}

// menghitung data pada linked list
int hitungjumlah_129()
{
    Node *hitung = head;
    int jumlah = 0;

    while (hitung != NULL)
    {
        jumlah++;
        hitung = hitung->next;
    }

    return jumlah;
}

// menambahkan data di tengah
void tambahtengah_129(string nama_129, int harga_129, int posisi)
{
    if (posisi < 1 || posisi > hitungjumlah_129())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        Node *baru = new Node;
        baru->nama_129 = nama_129;
        baru->harga_129 = harga_129;
        Node *bantu = head;
        int nomor = 1;

        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }

        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// menghapus data di depan
void hapusdepan_129()
{
    if (!null_129())
    {
        Node *hapus = head;

        if (head->next != NULL)
        {
            head = head->next;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List null!" << endl;
    }
}

// menghapus data di belakang
void hapusdbelakang_129()
{
    if (!null_129())
    {
        Node *hapus = tail;
        Node *bantu = head;

        if (head != tail)
        {
            while (bantu->next != tail)
            {
                bantu = bantu->next;
            }

            tail = bantu;
            tail->next = NULL;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List null!" << endl;
    }
}

// menghapus data di tengah
void hapusdtengah_129(int posisi)
{
    if (posisi < 1 || posisi > hitungjumlah_129())
    {
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        Node *hapus;
        Node *bantu;
        Node *bantuan;
        int nomor = 1;
        bantu = head;

        while (nomor <= posisi)
        {
            if (nomor == posisi - 1)
            {
                bantuan = bantu;
            }

            if (nomor == posisi)
            {
                hapus = bantu;
            }

            bantu = bantu->next;
            nomor++;
        }

        bantuan->next = bantu;
        delete hapus;
    }
}

// mengubah data di depan
void ubahdepan_129(string nama_129, int harga_129)
{
    if (!null_129())
    {
        head->nama_129 = nama_129;
        head->harga_129 = harga_129;
    }
    else
    {
        cout << "List masih null!" << endl;
    }
}

// mengubah data di tengah
void ubahtengah_129(string nama_129, int harga_129, int posisi)
{
    if (!null_129())
    {
        if (posisi < 1 || posisi > hitungjumlah_129())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else
        {
            Node *bantu = head;
            int nomor = 1;

            while (nomor < posisi)
            {
                bantu = bantu->next;
                nomor++;
            }

            bantu->nama_129 = nama_129;
            bantu->harga_129 = harga_129;
        }
    }
    else
    {
        cout << "List masih null!" << endl;
    }
}

// mengubah data di belakang
void ubahbelakang(string nama_129, int harga_129)
{
    if (!null_129())
    {
        tail->nama_129 = nama_129;
        tail->harga_129 = harga_129;
    }
    else
    {
        cout << "List masih null!" << endl;
    }
}

// menghapus semua data
void deletall_129()
{
    Node *bantu = head;
    Node *hapus;

    while (bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }

    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

// menampilkan data
void tampilkan()
{
    Node *bantu = head;
    if (!null_129())
    {
        cout << "|---------------------------|" << endl;
        cout << "|   Nama Produk  |   Harga  |" << endl;
        cout << "|---------------------------|" << endl;
        while (bantu != NULL)
        {
            cout << "| " << setw(15) << left << bantu->nama_129 << " | " << setw(7) << left << bantu->harga_129 << " |" << endl;
            bantu = bantu->next;
        }
        cout << "|---------------------------|" << endl;
    }
    else
    {
        cout << "List masih null!" << endl;
    }
}

// Fungsi untuk menghapus data berdasarkan nama
void hapusdata_129(string nama_129)
{
    if (!null_129())
    {
        cout << "List masih null!" << endl;
        return;
    }

    Node *bantu = head;
    Node *sebelum = NULL;

    // Mencari node dengan nama yang sesuai
    while (bantu != NULL && bantu->nama_129 != nama_129)
    {
        sebelum = bantu;
        bantu = bantu->next;
    }

    // Jika data tidak ditemukan
    if (bantu == NULL)
    {
        cout << "Data tidak ditemukan!" << endl;
        return;
    }

    // Jika data ditemukan di head
    if (sebelum == NULL)
    {
        hapusdepan_129();
    }
    else
    {
        sebelum->next = bantu->next;
        delete bantu;
        cout << "Data dengan nama " << nama_129 << " berhasil dihapus!" << endl;
    }
}

int main()
{
    // Inisialisasi linked list
    inti_129();
    // Tambahkan data awal
    tambahdepan_129("Originote", 60000);
    tambahbelakang_129("Somethinc", 150000);
    tambahbelakang_129("Skintific", 100000);
    tambahbelakang_129("Wardah", 50000);
    tambahbelakang_129("Hanasui", 30000);

    // Tampilkan data awal
    cout << "Toko Skincare Purwokerto" << endl;
    tampilkan();
    cout << endl;

    // Menu
    int pilihan;
    string nama_129;
    int harga_129;
    int posisi;
    do
    {
        cout << "Toko Skincare Purwokerto :"<<endl;
        cout << "1. Tambah Data"<<endl;
        cout << "2. Hapus Data"<<endl;
        cout << "3. Update Data"<<endl;
        cout << "4. Tambah Data Urutan Tertentu"<<endl;
        cout << "5. Hapus Data Urutan Tertentu"<<endl;
        cout << "6. Hapus Seluruh Data"<<endl;
        cout << "7. Tampilkan Data"<<endl;
        cout << "8. Exit"<<endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            // Tambah Data
            cout << "Masukkan Nama Produk: ";
            cin >> nama_129;
            cout << "Masukkan Harga: ";
            cin >> harga_129;
            tambahbelakang_129(nama_129, harga_129);
            break;
        case 2:
            // Pilihan hapus data
            int hapusPilihan;
            cout << "Pilihan Hapus Data:"<<endl;
            cout << "1. Hapus Data dari Depan"<<endl;
            cout << "2. Hapus Data dari Belakang"<<endl;
            cout << "Pilihan: ";
            cin >> hapusPilihan;

            if (hapusPilihan == 1)
            {
                hapusdepan_129();
            }
            else if (hapusPilihan == 2)
            {
                hapusdbelakang_129();
            }
            else
            {
                cout << "Pilihan tidak valid!" << endl;
            }
            break;

        case 3:
            // Update Data
            cout << "Masukkan Nama Produk yang Akan Diupdate: ";
            cin >> nama_129;
            cout << "Masukkan Harga Baru: ";
            cin >> harga_129;
            cout << "masukan posisi : ";
            cin>>posisi;
            ubahtengah_129(nama_129, harga_129, posisi);
            break;
        case 4:
            // Tambah Data Urutan Tertentu
            cout << "Masukkan Nama Produk yang Akan Ditambahkan: ";
            cin >> nama_129;
            cout << "Masukkan Harga Produk: ";
            cin >> harga_129;
            cout << "Masukkan Posisi (indeks) untuk Menambahkan Data: ";
            cin >> posisi;
            tambahtengah_129(nama_129, harga_129, posisi);
            break;
        case 5:
            // Hapus Data Urutan Tertentu
            cout << "Masukkan Posisi (indeks) untuk Menghapus Data: ";
            cin >> posisi;
            hapusdtengah_129(posisi);
            break;
        case 6:
            // Hapus Seluruh Data
            deletall_129();
            break;
        case 7:
            // Tampilkan Data
            cout << "Toko Skincare Purwokerto" << endl;
            tampilkan();
            cout << endl;
            break;
        case 8:
            // Keluar
            cout << "Terima kasih!" << endl;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }
    } while (pilihan != 8);

    return 0;
}
```

### Output :

<h2>Tabel Produk Skincare</h2>

![tampilan_menu_produk](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan3/assets/tampilanproduk_soal2.png)

<h2>Tambah Produk Azarine</h2>

![unguided_output_2a](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan3/assets/soal2a.png)

<h2>Hapus Produk Wardah</h2>

![unguided_output_2b](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan3/assets/soal2b.png)

<h2>Update Produk Hanasui Menjadi Cleora</h2>

![unguided_output_2c](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan3/assets/soal2c.png)

<h2 >Tampilkan Menu Utama</h2>

![unguided_output_2d](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan3/assets/soal2d.png)

=> Penjelasan program

- Pada progam di atas adalah program linked list yang digunakan untuk menyimmpoan data skincare nama produk dan harga produk
pada program tersebut terdapat berbagai fungsi yang terdiri dari menambahkan data, menghapus data, mengupdate data dan menampilkan data. pada menambahkan data kita bisa melalui depan dan urutan tertentu dan juga begitu pada hapus data dan mengupdate data linked list. Di program tersebut terdapat menu untuk menjalankan fungsi yang sudah kita buat. Fungsi tersebut bisa kita gunakan pada int main dengan cara memanggil fungsi nya dan di ikuti oleh parameter.

#### Full code Screenshot:

![Full_ss_code_unguided2](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan3/assets/fullss_unguided2.png)

## Kesimpulan

Kesimpulan dari materi di atas adalah bahwa:
- Single Linked List adalah tipe data yang berbentuk list yang setiap elemen hanya mempunyai pointer ke elemen selanjutnya dan tidak mempunyai pointer ke elemen sebelumnya.

- Double Linked List adalah tipe data yang berbentuk list yang setiap elemen mempunyai dua pointer, yaitu penujuk ke elemen sebelumnya (prev) dan penujuk ke elemen selanjutnya (next).

- Double Linked List lebih efisien daripada Single Linked List karena dapat melakukan traversal dalam arah mundur melalui pointer prev. Double Linked List juga lebih efisien dalam melakukan operasi insertion dan deletion, karena tidak perlu perlu mengubah pointer pada setiap elemen yang ada sebelum elemen yang akan diubah. Double Linked List juga lebih cocok untuk digunakan dalam sistem operasi dan pengelolaan memori, karena dapat memudahkan pengaturan kembali pada penggunaan memori.

## Referensi

[1] Triase, STRUKTUR DATA, Medan: UUNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN, 2020.

