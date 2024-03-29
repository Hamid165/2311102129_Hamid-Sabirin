# <h1 align="center">Laporan Praktikum Modul 4 LINKED LIST CIRCULAR DAN NON CIRCULAR</h1>

<h1 align="center">Hamid Sabirin-2311102129</h1>

## Dasar Teori

Linked List adalah sebuah jenis struktur data yang digunakan untuk menyimpan dan mengelola data secara dinamis. Struktur data ini terdiri dari elemen-elemen individu, yang masing-masing disambungkan dengan dua pointer: next dan prev.
Jenis Linked List ada 2 yaitu sebagai berikut:

A. Linked List Non Circular adalah sebuah data structure yang terdiri dari node yang saling terhubung melalui pointer ke node berikutnya. Setiap node mempunyai field pointer yang hanya satu arah dan pada akhir node, pointer nextnya menunjuk ke NULL

B. Linked List Circular adalah sebuah data structure yang terdiri dari node yang saling terhubung melalui pointer ke node berikutnya dan sebelumnya. Setiap node mempunyai field pointer yang berisi pointer ke node berikutnya dan sebelumnya, dan bagian selanjutnya (penunjuk ke simpul berikutnya) adalah NULL.

## Guided

### 1. [Linked List Non Circular]

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
        cout << "List Kosong" << endl;
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
    Node *bantu, *hapus, *sebelum;
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
                sebelum = bantu;
            }
            if (nomor == posisi)
            {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        sebelum->next = bantu;
        delete hapus;
    }
}
// Ubah Depan
void ubahDepan(int data)
{
    if (isEmpty() == 0)
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
    if (isEmpty() == 0)
    {
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
        }
        else
        {
            cout << "Posisi bukan posisi tengah" << endl;
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
    if (isEmpty() == 0)
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

### 2. [Linked List Circular]

```C++
#include <iostream>
using namespace std;

// Deklarasi Struct Node
struct Node
{
    string data;
    Node *next;
};

Node *head, *tail, *baru, *bantu, *hapus;

void init()
{
    head = NULL;
    tail = head;
}

// Pengecekan
int isEmpty()
{
    if (head == NULL)
        return 1; // true
    else
        return 0; // false
}

// Buat Node Baru
void buatNode(string data)
{
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}

// Hitung List
int hitungList()
{
    bantu = head;
    int jumlah = 0;
    while (bantu != NULL)
    {
        jumlah++;
        bantu = bantu->next;
    }
    return jumlah;
}

// Tambah Depan
void insertDepan(string data)
{
    // Buat Node baru
    buatNode(data);

    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }
        baru->next = head;
        head = baru;
        tail->next = head;
    }
}

// Tambah Belakang
void insertBelakang(string data)
{
    // Buat Node baru
    buatNode(data);

    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }
        tail->next = baru;
        baru->next = head;
    }
}

// Tambah Tengah
void insertTengah(string data, int posisi)
{
    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        baru->data = data;
        // transversing
        int nomor = 1;
        bantu = head;
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
    if (isEmpty() == 0)
    {
        hapus = head;
        tail = head;
        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;
            delete hapus;
        }
        else
        {
            while (tail->next != hapus)
            {
                tail = tail->next;
            }
            head = head->next;
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Belakang
void hapusBelakang()
{
    if (isEmpty() == 0)
    {
        hapus = head;
        tail = head;
        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;
            delete hapus;
        }
        else
        {
            while (hapus->next != head)
            {
                hapus = hapus->next;
            }
            while (tail->next != hapus)
            {
                tail = tail->next;
            }
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Tengah
void hapusTengah(int posisi)
{
    if (isEmpty() == 0)
    {
        // transversing
        int nomor = 1;
        bantu = head;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus List
void clearList()
{
    if (head != NULL)
    {
        hapus = head->next;
        while (hapus != head)
        {
            bantu = hapus->next;
            delete hapus;
            hapus = bantu;
        }
        delete head;
        head = NULL;
    }
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan List
void tampil()
{
    if (isEmpty() == 0)
    {
        tail = head;
        do
        {
            cout << tail->data << ends;
            tail = tail->next;
        } while (tail != head);
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
    insertDepan("Ayam");
    tampil();
    insertDepan("Bebek");
    tampil();
    insertBelakang("Cicak");
    tampil();
    insertBelakang("Domba");
    tampil();
    hapusBelakang();
    tampil();
    hapusDepan();
    tampil();
    insertTengah("Sapi", 2);
    tampil();
    hapusTengah(2);
    tampil();
    return 0;
}
```

=> Penjelasan program

- Pada program di atas merupakan sebuah code linked list circular. Code tersebut memungkinkan pengguna untuk melakukan CRUD pada linked list, pada code tersbut terdapat berbagai fungsi yang menambahkan, menghapus, mengubah dan menampilkan. Pada program tersebut kita bisa menambahkan data dari depan, menghapuskan data linked list hanya satu data, update data pada linked list dengan urutan, dan menghapuskan semua data yang ada pada linked list, dan jangan lupa ketika menambahkan, menghapus, mengubah kita perlu memanggil fungsi display yang gunanya untuk menampilkan data terbaru.

## Unguided

### 1. [. Buatlah menu untuk menambahkan, mengubah, menghapus, dan melihat Nama dan NIM mahasiswa, berikut contoh tampilan output dari nomor 1:]

![soal1](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan4/assets/soal1.png)
![soal1_2](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan4/assets/soal1_2.png)

```C++
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Deklarasi Struct Node
struct Node
{
    string nama_129;
    string nama_lama_129;
    string nama_baru_129;
    string NIM_129;
    Node *next;
};

Node *head;
Node *tail;

// prosedur init
void init()
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
void tambahdepan(string nama_129, string NIM_129)
{
    Node *baru = new Node;
    baru->nama_129 = nama_129;
    baru->NIM_129 = NIM_129;
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
void tambahbelakang(string nama_129, string NIM_129)
{
    Node *baru = new Node;
    baru->nama_129 = nama_129;
    baru->NIM_129 = NIM_129;
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
void tambahtengah(string nama_129, string NIM_129, int posisi_129)
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
        baru->NIM_129 = NIM_129;
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

// Menghapus data di depan dan menampilkan nama yang dihapus
string hapusdepan()
{
    string nama_hapus = "";

    if (!null())
    {
        Node *hapus = head;

        if (head->next != NULL)
        {
            head = head->next;
            nama_hapus = hapus->nama_129;
            delete hapus;
        }
        else
        {
            nama_hapus = head->nama_129;
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List null!" << endl;
    }

    return nama_hapus;
}

// Menghapus data di belakang dan mengembalikan nama yang dihapus
string hapusdbelakang()
{
    string nama_hapus = "";

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
            nama_hapus = hapus->nama_129;
            delete hapus;
        }
        else
        {
            nama_hapus = head->nama_129;
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List null!" << endl;
    }

    return nama_hapus;
}

// Menghapus data di tengah dan menampilkan nama yang dihapus
string hapusdtengah(int posisi_129)
{
    string nama_hapus = "";

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
                nama_hapus = hapus->nama_129;
            }

            bantu = bantu->next;
            nomor++;
        }

        bantuan->next = bantu;
        delete hapus;
    }

    return nama_hapus;
}

// mengubah data di depan
void ubahdepan(string nama_129, string nama_baru_129, string NIM_129)
{

    if (!null())
    {
        if (head->nama_129 == nama_129)
        {
            head->nama_129 = nama_baru_129;
            head->NIM_129 = NIM_129;
            cout << "Data (" << nama_129 << ") telah diganti dengan data (" << nama_baru_129 << ")" << endl;
        }
        else
        {
            cout << "Data dengan nama " << nama_129 << " tidak ditemukan!" << endl;
        }
    }
    else
    {
        cout << "List masih null!" << endl;
    }
}

// mengubah data di tengah
void ubahtengah(string nama_129, string nama_baru_129, string NIM_129, int posisi_129)
{
    if (!null())
    {
        if (posisi_129 < 1 || posisi_129 > hitungjumlah())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi_129 == 1)
        {
            ubahdepan(nama_129, nama_baru_129, NIM_129);
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

            if (bantu->nama_129 == nama_129)
            {
                bantu->nama_129 = nama_baru_129;
                bantu->NIM_129 = NIM_129;
                cout << "Data (" << nama_129 << ") telah diganti dengan data (" << nama_baru_129 << ")" << endl;
            }
            else
            {
                cout << "Data dengan nama " << nama_129 << " tidak ditemukan pada posisi yang dimaksud!" << endl;
            }
        }
    }
    else
    {
        cout << "List masih null!" << endl;
    }
}
// mengubah data di belakang
void ubahbelakang(string nama_129, string nama_baru_129, string NIM_129)
{
    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->nama_129 == nama_129)
        {
            temp->nama_129 = nama_baru_129;
            temp->NIM_129 = NIM_129;
            cout << "Data (" << nama_129 << ") telah diganti dengan data (" << nama_baru_129 << ")" << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Data tidak ditemukan" << endl;
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
        cout << "|------------------------------|" << endl;
        cout << "|        DATA MAHASISWA        |" << endl;
        cout << "|------------------------------|" << endl;
        cout << "|       Nama      |    NIM     |" << endl;
        cout << "|------------------------------|" << endl;
        while (bantu != NULL)
        {
            cout << "| " << setw(15) << left << bantu->nama_129 << " | " << setw(10) << left << bantu->NIM_129 << " |" << endl;
            bantu = bantu->next;
        }
        cout << "|------------------------------|" << endl;
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
    int pilihan;
    string nama_129;
    string nama_baru_129;
    string NIM_129;
    int posisi_129;

    do
    {
        cout << "|=========================================|" << endl;
        cout << "| PROGRAM SINGLE LINKED LIST NON-CIRCULAR |" << endl;
        cout << "|=========================================|" << endl;
        cout << "|1. Tambah Depan                          |" << endl;
        cout << "|2. Tambah Belakang                       |" << endl;
        cout << "|3. Tambah Tengah                         |" << endl;
        cout << "|4. Ubah Depan                            |" << endl;
        cout << "|5. Ubah Belakang                         |" << endl;
        cout << "|6. Ubah Tengah                           |" << endl;
        cout << "|7. Hapus Depan                           |" << endl;
        cout << "|8. Hapus Belakang                        |" << endl;
        cout << "|9. Hapus Tengah                          |" << endl;
        cout << "|10. Hapus List                           |" << endl;
        cout << "|11. Tampilkan                            |" << endl;
        cout << "|0. Keluar                                |" << endl;
        cout << "|=========================================|" << endl;
        cout << "Pilihan : ";
        cin >> pilihan;

        switch (pilihan)

        {
        case 0:
            break;
        case 1:
            // Tambah Depan
            cout << "-Tambah Depan-" << endl;
            cout << "Masukkan Nama : ";
            cin >> nama_129;
            cout << "Masukkan NIM : ";
            cin >> NIM_129;
            tambahdepan(nama_129, NIM_129);
            cout << "Data telah ditambahkan" << endl;
            break;
        case 2:
            // Tambah Belakang
            cout << "-Tambah Belakang-" << endl;
            cout << "Masukkan Nama : ";
            cin >> nama_129;
            cout << "Masukkan NIM : ";
            cin >> NIM_129;
            tambahbelakang(nama_129, NIM_129);
            cout << "Data telah ditambahkan" << endl;
            break;
        case 3:
            // Tambah Tengah
            cout << "-Tambah Tengah-" << endl;
            cout << "Masukkan Nama : ";
            cin >> nama_129;
            cout << "Masukkan NIM : ";
            cin >> NIM_129;
            cout << "Masukkan Posisi: ";
            cin >> posisi_129;
            tambahtengah(nama_129, NIM_129, posisi_129);
            cout << "Data telah ditambahkan" << endl;
            break;
        case 4:
            // Ubah Depan
            cout << "-Ubah Depan-" << endl;
            cout << "Masukkan Nama yang akan diubah: ";
            cin >> nama_129;
            cout << "Masukkan Nama baru: ";
            cin >> nama_baru_129;
            cout << "Masukkan NIM baru: ";
            cin >> NIM_129;
            ubahdepan(nama_129, nama_baru_129, NIM_129);
            cout << "Data dengan nama " << nama_129 << " telah diubah menjadi " << nama_baru_129 << endl;
            break;
        case 5:
            // Ubah Belakang
            cout << "-Ubah Belakang-" << endl;
            cout << "Masukkan nama yang akan diubah: ";
            cin >> nama_129;
            cout << "Masukkan nama baru: ";
            cin >> nama_baru_129;
            cout << "Masukkan NIM baru: ";
            cin >> NIM_129;
            ubahbelakang(nama_129, nama_baru_129, NIM_129);
            cout << "Data dengan nama " << nama_129 << " telah diubah menjadi " << nama_baru_129 << endl;
            break;
        case 6: // Ubah Tengah
            cout << "-Ubah Tengah-" << endl;
            cout << "Masukkan nama yang akan diubah: ";
            cin >> nama_129;
            cout << "Masukkan nama baru: ";
            cin >> nama_baru_129;
            cout << "Masukkan NIM baru: ";
            cin >> NIM_129;
            cout << "Masukkan Posisi baru: ";
            cin >> posisi_129;
            ubahtengah(nama_129, nama_baru_129, NIM_129, posisi_129);
            cout << "Data dengan nama " << nama_129 << " telah diubah menjadi " << nama_baru_129 << endl;
            break;
        case 7:
            // Hapus Depan
            cout << "-Hapus Depan-" << endl;
            cout << "Data dengan nama " << hapusdepan() << " berhasil dihapus" << endl;
            break;
        case 8:
            // Hapus Belakang
            cout << "-Hapus Belakang-" << endl;
            cout << "Data dengan nama " << hapusdbelakang() << " berhasil dihapus" << endl;
            break;
        case 9:
            // Hapus Tengah
            cout << "-Hapus Tengah-" << endl;
            cout << "Masukkan Posisi yang akan dihapus: ";
            cin >> posisi_129;
            cout << "Data dengan nama " << hapusdtengah(posisi_129) << " berhasil dihapus" << endl;
            break;
        case 10:
            // Hapus Semua
            cout << "-Hapus List-" << endl;
            deletall();
            cout << "Data list berhasil dihapus" << endl;
            break;
        case 11:
            // Menampilkan data
            tampilkan();
            break;
        default:
            cout << "Pilihan Tidak Tersedia" << endl;
            break;
        }

    } while (pilihan != 0);

    return 0;
}

```

### Output :

<h2>Tampil Menu</h2>

![Tampilan Menu](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan4/assets/tampilan_menu.png)

<h2>Tambah Depan</h2>

![Tambah Depan](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan4/assets/tambah_depan.png)

<h2>Tambah Belakang</h2>

![Tambah Belakang](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan4/assets/tambah_belakang.png)

<h2>Tambah Tengah</h2>

![Tambah Tengah](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan4/assets/tambah_tengah.png)

<h2>Ubah Depan</h2>

![Ubah Depan](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan4/assets/ubah_depan.png)

<h2>Ubah Belakang</h2>

![Ubah Belakang](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan4/assets/ubah_belakang.png)

<h2>Ubah Tengah</h2>

![Ubah Tengah](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan4/assets/ubah_tengah.png)

<h2>Hapus Depan</h2>

![Hapus Depan](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan4/assets/hapus_depan.png)

<h2>Hapus Belakang</h2>

![Hapus Belakang](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan4/assets/hapus_belakang.png)

<h2>Hapus Tengah</h2>

![Hapus Tengah](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan4/assets/hapus_tengah.png)

<h2>Hapus List</h2>

![Hapus List](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan4/assets/hapus_list.png)

<h2>Tampilkan</h2>

![Tampilkan](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan4/assets/tampilkan.png)

=> Penjelasan Program

- Program di atas adalah program untuk lingked list yang digunakan untuk menyimpan data mahasiswa berupa nama dan umur mahasiswa. Dalam program ini terdapat berbagai fungsi yang dapat digunakan, yaitu fungsi untuk menambahkan, menghapus dan mengubah data list mahasiswa. fungsi init_129 digunakan untuk memulai list, fungsi tambah digunakan untuk menambahkan data di awal list, fungsi hapus digunakan untuk menghapus data di list, fungsi tampilkan digunakan untuk menampilkan seluruh data, pada fungsi int main terdapat sebuah menu yang nantinya kita bisa gunakan untuk melakukan operasi penambahan data penghapusan data dan pengubahan data sesuai pilihan yang ada pada menu dan kita akan menginputkan nama dan umur untuk menambahkan dan ketika mengubah di tambahkan posisi dari data pada linked list.

#### Full code Screenshot:

![Full_ss_code_unguided1](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan4/assets/fullss_unguided1.png)

### 2. [Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu tampilkan data yang telah dimasukkan. (Gunakan insert depan, belakang atau tengah)]

![soal2](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan4/assets/soal2.png)

```C++
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Deklarasi Struct Node
struct Node
{
    string nama_129;
    string nama_lama_129;
    string nama_baru_129;
    string NIM_129;
    Node *next;
};

Node *head;
Node *tail;

// prosedur init
void init()
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
void tambahdepan(string nama_129, string NIM_129)
{
    Node *baru = new Node;
    baru->nama_129 = nama_129;
    baru->NIM_129 = NIM_129;
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
void tambahbelakang(string nama_129, string NIM_129)
{
    Node *baru = new Node;
    baru->nama_129 = nama_129;
    baru->NIM_129 = NIM_129;
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
void tambahtengah(string nama_129, string NIM_129, int posisi_129)
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
        baru->NIM_129 = NIM_129;
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

// Menghapus data di depan dan menampilkan nama yang dihapus
string hapusdepan()
{
    string nama_hapus = "";

    if (!null())
    {
        Node *hapus = head;

        if (head->next != NULL)
        {
            head = head->next;
            nama_hapus = hapus->nama_129;
            delete hapus;
        }
        else
        {
            nama_hapus = head->nama_129;
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List null!" << endl;
    }

    return nama_hapus;
}

// Menghapus data di belakang dan mengembalikan nama yang dihapus
string hapusdbelakang()
{
    string nama_hapus = "";

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
            nama_hapus = hapus->nama_129;
            delete hapus;
        }
        else
        {
            nama_hapus = head->nama_129;
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List null!" << endl;
    }

    return nama_hapus;
}

// Menghapus data di tengah dan menampilkan nama yang dihapus
string hapusdtengah(int posisi_129)
{
    string nama_hapus = "";

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
                nama_hapus = hapus->nama_129;
            }

            bantu = bantu->next;
            nomor++;
        }

        bantuan->next = bantu;
        delete hapus;
    }

    return nama_hapus;
}

// mengubah data di depan
void ubahdepan(string nama_129, string nama_baru_129, string NIM_129)
{

    if (!null())
    {
        if (head->nama_129 == nama_129)
        {
            head->nama_129 = nama_baru_129;
            head->NIM_129 = NIM_129;
            cout << "Data (" << nama_129 << ") telah diganti dengan data (" << nama_baru_129 << ")" << endl;
        }
        else
        {
            cout << "Data dengan nama " << nama_129 << " tidak ditemukan!" << endl;
        }
    }
    else
    {
        cout << "List masih null!" << endl;
    }
}

// mengubah data di tengah
void ubahtengah(string nama_129, string nama_baru_129, string NIM_129, int posisi_129)
{
    if (!null())
    {
        if (posisi_129 < 1 || posisi_129 > hitungjumlah())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi_129 == 1)
        {
            ubahdepan(nama_129, nama_baru_129, NIM_129);
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

            if (bantu->nama_129 == nama_129)
            {
                bantu->nama_129 = nama_baru_129;
                bantu->NIM_129 = NIM_129;
                cout << "Data (" << nama_129 << ") telah diganti dengan data (" << nama_baru_129 << ")" << endl;
            }
            else
            {
                cout << "Data dengan nama " << nama_129 << " tidak ditemukan pada posisi yang dimaksud!" << endl;
            }
        }
    }
    else
    {
        cout << "List masih null!" << endl;
    }
}
// mengubah data di belakang
void ubahbelakang(string nama_129, string nama_baru_129, string NIM_129)
{
    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->nama_129 == nama_129)
        {
            temp->nama_129 = nama_baru_129;
            temp->NIM_129 = NIM_129;
            cout << "Data (" << nama_129 << ") telah diganti dengan data (" << nama_baru_129 << ")" << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Data tidak ditemukan" << endl;
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
        cout << "|------------------------------|" << endl;
        cout << "|        DATA MAHASISWA        |" << endl;
        cout << "|------------------------------|" << endl;
        cout << "|       Nama      |    NIM     |" << endl;
        cout << "|------------------------------|" << endl;
        while (bantu != NULL)
        {
            cout << "| " << setw(15) << left << bantu->nama_129 << " | " << setw(10) << left << bantu->NIM_129 << " |" << endl;
            bantu = bantu->next;
        }
        cout << "|------------------------------|" << endl;
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
    int pilihan;
    string nama_129;
    string nama_baru_129;
    string NIM_129;
    int posisi_129;

    do
    {
        cout << "|=========================================|" << endl;
        cout << "| PROGRAM SINGLE LINKED LIST NON-CIRCULAR |" << endl;
        cout << "|=========================================|" << endl;
        cout << "|1. Tambah Depan                          |" << endl;
        cout << "|2. Tambah Belakang                       |" << endl;
        cout << "|3. Tambah Tengah                         |" << endl;
        cout << "|4. Ubah Depan                            |" << endl;
        cout << "|5. Ubah Belakang                         |" << endl;
        cout << "|6. Ubah Tengah                           |" << endl;
        cout << "|7. Hapus Depan                           |" << endl;
        cout << "|8. Hapus Belakang                        |" << endl;
        cout << "|9. Hapus Tengah                          |" << endl;
        cout << "|10. Hapus List                           |" << endl;
        cout << "|11. Tampilkan                            |" << endl;
        cout << "|0. Keluar                                |" << endl;
        cout << "|=========================================|" << endl;
        cout << "Pilihan : ";
        cin >> pilihan;

        switch (pilihan)

        {
        case 0:
            break;
        case 1:
            // Tambah Depan
            cout << "-Tambah Depan-" << endl;
            cout << "Masukkan Nama : ";
            cin >> nama_129;
            cout << "Masukkan NIM : ";
            cin >> NIM_129;
            tambahdepan(nama_129, NIM_129);
            cout << "Data telah ditambahkan" << endl;
            break;
        case 2:
            // Tambah Belakang
            cout << "-Tambah Belakang-" << endl;
            cout << "Masukkan Nama : ";
            cin >> nama_129;
            cout << "Masukkan NIM : ";
            cin >> NIM_129;
            tambahbelakang(nama_129, NIM_129);
            cout << "Data telah ditambahkan" << endl;
            break;
        case 3:
            // Tambah Tengah
            cout << "-Tambah Tengah-" << endl;
            cout << "Masukkan Nama : ";
            cin >> nama_129;
            cout << "Masukkan NIM : ";
            cin >> NIM_129;
            cout << "Masukkan Posisi: ";
            cin >> posisi_129;
            tambahtengah(nama_129, NIM_129, posisi_129);
            cout << "Data telah ditambahkan" << endl;
            break;
        case 4:
            // Ubah Depan
            cout << "-Ubah Depan-" << endl;
            cout << "Masukkan Nama yang akan diubah: ";
            cin >> nama_129;
            cout << "Masukkan Nama baru: ";
            cin >> nama_baru_129;
            cout << "Masukkan NIM baru: ";
            cin >> NIM_129;
            ubahdepan(nama_129, nama_baru_129, NIM_129);
            cout << "Data dengan nama " << nama_129 << " telah diubah menjadi " << nama_baru_129 << endl;
            break;
        case 5:
            // Ubah Belakang
            cout << "-Ubah Belakang-" << endl;
            cout << "Masukkan nama yang akan diubah: ";
            cin >> nama_129;
            cout << "Masukkan nama baru: ";
            cin >> nama_baru_129;
            cout << "Masukkan NIM baru: ";
            cin >> NIM_129;
            ubahbelakang(nama_129, nama_baru_129, NIM_129);
            cout << "Data dengan nama " << nama_129 << " telah diubah menjadi " << nama_baru_129 << endl;
            break;
        case 6: // Ubah Tengah
            cout << "-Ubah Tengah-" << endl;
            cout << "Masukkan nama yang akan diubah: ";
            cin >> nama_129;
            cout << "Masukkan nama baru: ";
            cin >> nama_baru_129;
            cout << "Masukkan NIM baru: ";
            cin >> NIM_129;
            cout << "Masukkan Posisi baru: ";
            cin >> posisi_129;
            ubahtengah(nama_129, nama_baru_129, NIM_129, posisi_129);
            cout << "Data dengan nama " << nama_129 << " telah diubah menjadi " << nama_baru_129 << endl;
            break;
        case 7:
            // Hapus Depan
            cout << "-Hapus Depan-" << endl;
            cout << "Data dengan nama " << hapusdepan() << " berhasil dihapus" << endl;
            break;
        case 8:
            // Hapus Belakang
            cout << "-Hapus Belakang-" << endl;
            cout << "Data dengan nama " << hapusdbelakang() << " berhasil dihapus" << endl;
            break;
        case 9:
            // Hapus Tengah
            cout << "-Hapus Tengah-" << endl;
            cout << "Masukkan Posisi yang akan dihapus: ";
            cin >> posisi_129;
            cout << "Data dengan nama " << hapusdtengah(posisi_129) << " berhasil dihapus" << endl;
            break;
        case 10:
            // Hapus Semua
            cout << "-Hapus List-" << endl;
            deletall();
            cout << "Data list berhasil dihapus" << endl;
            break;
        case 11:
            // Menampilkan data
            tampilkan();
            break;
        default:
            cout << "Pilihan Tidak Tersedia" << endl;
            break;
        }

    } while (pilihan != 0);

    return 0;
}

```

### Output :

<h2>Tabel Data Mahasiswa</h2>

![unguided2_1](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan4/assets/unguided2_1.png)

<h2>Tambah Nama dan NIM sendiri</h2>

![unguided2_1](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan4/assets/unguided2_2.png)

=> Penjelasan program

- Pada progam di atas adalah program linked list yang digunakan untuk menyimmpan data mahasiswa nama dan NIM pada program tersebut terdapat berbagai fungsi yang terdiri dari menambahkan data, menghapus data, mengupdate data dan menampilkan data. pada menambahkan data kita bisa melalui depan dan urutan tertentu dan juga begitu pada hapus data dan mengupdate data linked list. Di program tersebut terdapat menu untuk menjalankan fungsi yang sudah kita buat. pada code di atas kita melakukan input data nama dan nim melaluli depan tengah ataupun belakang, dan menginputkan nama dan nim kita menggunakan fungsi tambah tengah pada menu.

#### Full code Screenshot:

![Full_ss_code_unguided2](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan4/assets/fullss_unguided2.png)

### 3. [Lakukan perintah berikut:]

![soal3](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan4/assets/soal3.png)

```C++
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Deklarasi Struct Node
struct Node
{
    string nama_129;
    string nama_lama_129;
    string nama_baru_129;
    string NIM_129;
    Node *next;
};

Node *head;
Node *tail;

// prosedur init
void init()
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
void tambahdepan(string nama_129, string NIM_129)
{
    Node *baru = new Node;
    baru->nama_129 = nama_129;
    baru->NIM_129 = NIM_129;
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
void tambahbelakang(string nama_129, string NIM_129)
{
    Node *baru = new Node;
    baru->nama_129 = nama_129;
    baru->NIM_129 = NIM_129;
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
void tambahtengah(string nama_129, string NIM_129, int posisi_129)
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
        baru->NIM_129 = NIM_129;
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
// Menghapus data di depan dan mengembalikan nama yang dihapus
string hapusdepan()
{
    string nama_hapus = ""; // Menyimpan nama yang dihapus

    if (!null())
    {
        Node *hapus = head;

        if (head->next != NULL)
        {
            head = head->next;
            nama_hapus = hapus->nama_129; // Simpan nama yang dihapus
            delete hapus;
        }
        else
        {
            nama_hapus = head->nama_129; // Simpan nama yang dihapus sebelum dihapus
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List null!" << endl;
    }

    return nama_hapus; // Kembalikan nama yang dihapus
}

// Menghapus data di belakang dan mengembalikan nama yang dihapus
string hapusdbelakang()
{
    string nama_hapus = ""; // Menyimpan nama yang dihapus

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
            nama_hapus = hapus->nama_129; // Simpan nama yang dihapus
            delete hapus;
        }
        else
        {
            nama_hapus = head->nama_129; // Simpan nama yang dihapus sebelum dihapus
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List null!" << endl;
    }

    return nama_hapus; // Kembalikan nama yang dihapus
}

// Menghapus data di tengah dan mengembalikan nama yang dihapus
string hapusdtengah(int posisi_129)
{
    string nama_hapus = ""; // Menyimpan nama yang dihapus

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
                nama_hapus = hapus->nama_129; // Simpan nama yang dihapus
            }

            bantu = bantu->next;
            nomor++;
        }

        bantuan->next = bantu;
        delete hapus;
    }

    return nama_hapus; // Kembalikan nama yang dihapus
}

// mengubah data di depan
void ubahdepan(string nama_129, string nama_baru_129, string NIM_129)
{

    if (!null())
    {
        if (head->nama_129 == nama_129)
        {
            head->nama_129 = nama_baru_129;
            head->NIM_129 = NIM_129;
            cout << "Data (" << nama_129 << ") telah diganti dengan data (" << nama_baru_129 << ")" << endl;
        }
        else
        {
            cout << "Data dengan nama " << nama_129 << " tidak ditemukan!" << endl;
        }
    }
    else
    {
        cout << "List masih null!" << endl;
    }
}

// mengubah data di tengah
void ubahtengah(string nama_129, string nama_baru_129, string NIM_129, int posisi_129)
{
    if (!null())
    {
        if (posisi_129 < 1 || posisi_129 > hitungjumlah())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi_129 == 1)
        {
            ubahdepan(nama_129, nama_baru_129, NIM_129);
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

            if (bantu->nama_129 == nama_129)
            {
                bantu->nama_129 = nama_baru_129;
                // Convert NIM_129 to string before setting it
                bantu->NIM_129 = NIM_129;
                cout << "Data (" << nama_129 << ") telah diganti dengan data (" << nama_baru_129 << ")" << endl;
            }
            else
            {
                cout << "Data dengan nama " << nama_129 << " tidak ditemukan pada posisi yang dimaksud!" << endl;
            }
        }
    }
    else
    {
        cout << "List masih null!" << endl;
    }
}
// mengubah data di belakang
void ubahbelakang(string nama_129, string nama_baru_129, string NIM_129)
{
    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->nama_129 == nama_129)
        {
            temp->nama_129 = nama_baru_129;
            temp->NIM_129 = NIM_129;
            cout << "Data (" << nama_129 << ") telah diganti dengan data (" << nama_baru_129 << ")" << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Data tidak ditemukan" << endl;
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
        cout << "|------------------------------|" << endl;
        cout << "|        DATA MAHASISWA        |" << endl;
        cout << "|------------------------------|" << endl;
        cout << "|       Nama      |    NIM     |" << endl;
        cout << "|------------------------------|" << endl;
        while (bantu != NULL)
        {
            cout << "| " << setw(15) << left << bantu->nama_129 << " | " << setw(10) << left << bantu->NIM_129 << " |" << endl;
            bantu = bantu->next;
        }
        cout << "|------------------------------|" << endl;
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
    int pilihan;
    string nama_129;
    string nama_baru_129;
    string NIM_129;
    int posisi_129;

    do
    {
        cout << "|=========================================|" << endl;
        cout << "| PROGRAM SINGLE LINKED LIST NON-CIRCULAR |" << endl;
        cout << "|=========================================|" << endl;
        cout << "|1. Tambah Depan                          |" << endl;
        cout << "|2. Tambah Belakang                       |" << endl;
        cout << "|3. Tambah Tengah                         |" << endl;
        cout << "|4. Ubah Depan                            |" << endl;
        cout << "|5. Ubah Belakang                         |" << endl;
        cout << "|6. Ubah Tengah                           |" << endl;
        cout << "|7. Hapus Depan                           |" << endl;
        cout << "|8. Hapus Belakang                        |" << endl;
        cout << "|9. Hapus Tengah                          |" << endl;
        cout << "|10. Hapus List                           |" << endl;
        cout << "|11. Tampilkan                            |" << endl;
        cout << "|0. Keluar                                |" << endl;
        cout << "|=========================================|" << endl;
        cout << "Pilihan : ";
        cin >> pilihan;

        switch (pilihan)

        {
        case 0:
            tampilkan();
            break;
            ;
        case 1:
            // Tambah Depan
            cout << "-Tambah Depan-" << endl;
            cout << "Masukkan Nama : ";
            cin >> nama_129;
            cout << "Masukkan NIM : ";
            cin >> NIM_129;
            tambahdepan(nama_129, NIM_129);
            cout << "Data telah ditambahkan" << endl;
            tampilkan();
            break;
            ;
        case 2:
            // Tambah Belakang
            cout << "-Tambah Belakang-" << endl;
            cout << "Masukkan Nama : ";
            cin >> nama_129;
            cout << "Masukkan NIM : ";
            cin >> NIM_129;
            tambahbelakang(nama_129, NIM_129);
            cout << "Data telah ditambahkan" << endl;
            tampilkan();
            break;
            ;
        case 3:
            // Tambah Tengah
            cout << "-Tambah Tengah-" << endl;
            cout << "Masukkan Nama : ";
            cin >> nama_129;
            cout << "Masukkan NIM : ";
            cin >> NIM_129;
            cout << "Masukkan Posisi: ";
            cin >> posisi_129;
            tambahtengah(nama_129, NIM_129, posisi_129);
            cout << "Data telah ditambahkan" << endl;
            tampilkan();
            break;
            ;
        case 4:
            // Ubah Depan
            cout << "-Ubah Depan-" << endl;
            cout << "Masukkan Nama yang akan diubah: ";
            cin >> nama_129;
            cout << "Masukkan Nama baru: ";
            cin >> nama_baru_129;
            cout << "Masukkan NIM baru: ";
            cin >> NIM_129;
            ubahdepan(nama_129, nama_baru_129, NIM_129);
            cout << "Data dengan nama " << nama_129 << " telah diubah menjadi " << nama_baru_129 << endl;
            tampilkan();
            break;
            ;
        case 5:
            // Ubah Belakang
            cout << "-Ubah Belakang-" << endl;
            cout << "Masukkan nama yang akan diubah: ";
            cin >> nama_129;
            cout << "Masukkan nama baru: ";
            cin >> nama_baru_129;
            cout << "Masukkan NIM baru: ";
            cin >> NIM_129;
            ubahbelakang(nama_129, nama_baru_129, NIM_129);
            cout << "Data dengan nama " << nama_129 << " telah diubah menjadi " << nama_baru_129 << endl;
            tampilkan();
            break;
            ;
        case 6: // Ubah Tengah
            cout << "-Ubah Tengah-" << endl;
            cout << "Masukkan nama yang akan diubah: ";
            cin >> nama_129;
            cout << "Masukkan nama baru: ";
            cin >> nama_baru_129;
            cout << "Masukkan NIM baru: ";
            cin >> NIM_129;
            cout << "Masukkan Posisi baru: ";
            cin >> posisi_129;
            ubahtengah(nama_129, nama_baru_129, NIM_129, posisi_129);
            cout << "Data dengan nama " << nama_129 << " telah diubah menjadi " << nama_baru_129 << endl;
            tampilkan();
            break;
            ;
        case 7:
            // Hapus Depan
            cout << "-Hapus Depan-" << endl;
            cout << "Data dengan nama " << hapusdepan() << " berhasil dihapus" << endl;
            tampilkan();
            break;
            ;
        case 8:
            // Hapus Belakang
            cout << "-Hapus Belakang-" << endl;
            cout << "Data dengan nama " << hapusdbelakang() << " berhasil dihapus" << endl;
            tampilkan();
            break;
            ;
        case 9:
            // Hapus Tengah
            cout << "-Hapus Tengah-" << endl;
            cout << "Masukkan Posisi yang akan dihapus: ";
            cin >> posisi_129;
            cout << "Data dengan nama " << hapusdtengah(posisi_129) << " berhasil dihapus" << endl;
            tampilkan();
            break;
            ;
        case 10:
            // Hapus Semua
            cout << "-Hapus List-" << endl;
            deletall();
            cout << "Data list berhasil dihapus" << endl;
            tampilkan();
            break;
            ;
        case 11:
            tampilkan();
            break;
            ;
        default:
            cout << "Pilihan Tidak Tersedia" << endl;
            break;
            ;
        }

    } while (pilihan != 0);

    return 0;
}#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Deklarasi Struct Node
struct Node
{
    string nama_129;
    string nama_lama_129;
    string nama_baru_129;
    string NIM_129;
    Node *next;
};

Node *head;
Node *tail;

// prosedur init
void init()
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
void tambahdepan(string nama_129, string NIM_129)
{
    Node *baru = new Node;
    baru->nama_129 = nama_129;
    baru->NIM_129 = NIM_129;
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
void tambahbelakang(string nama_129, string NIM_129)
{
    Node *baru = new Node;
    baru->nama_129 = nama_129;
    baru->NIM_129 = NIM_129;
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
void tambahtengah(string nama_129, string NIM_129, int posisi_129)
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
        baru->NIM_129 = NIM_129;
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

// Menghapus data di depan dan menampilkan nama yang dihapus
string hapusdepan()
{
    string nama_hapus = "";

    if (!null())
    {
        Node *hapus = head;

        if (head->next != NULL)
        {
            head = head->next;
            nama_hapus = hapus->nama_129;
            delete hapus;
        }
        else
        {
            nama_hapus = head->nama_129;
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List null!" << endl;
    }

    return nama_hapus;
}

// Menghapus data di belakang dan mengembalikan nama yang dihapus
string hapusdbelakang()
{
    string nama_hapus = "";

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
            nama_hapus = hapus->nama_129;
            delete hapus;
        }
        else
        {
            nama_hapus = head->nama_129;
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List null!" << endl;
    }

    return nama_hapus;
}

// Menghapus data di tengah dan menampilkan nama yang dihapus
string hapusdtengah(int posisi_129)
{
    string nama_hapus = "";

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
                nama_hapus = hapus->nama_129;
            }

            bantu = bantu->next;
            nomor++;
        }

        bantuan->next = bantu;
        delete hapus;
    }

    return nama_hapus;
}

// mengubah data di depan
void ubahdepan(string nama_129, string nama_baru_129, string NIM_129)
{

    if (!null())
    {
        if (head->nama_129 == nama_129)
        {
            head->nama_129 = nama_baru_129;
            head->NIM_129 = NIM_129;
            cout << "Data (" << nama_129 << ") telah diganti dengan data (" << nama_baru_129 << ")" << endl;
        }
        else
        {
            cout << "Data dengan nama " << nama_129 << " tidak ditemukan!" << endl;
        }
    }
    else
    {
        cout << "List masih null!" << endl;
    }
}

// mengubah data di tengah
void ubahtengah(string nama_129, string nama_baru_129, string NIM_129, int posisi_129)
{
    if (!null())
    {
        if (posisi_129 < 1 || posisi_129 > hitungjumlah())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi_129 == 1)
        {
            ubahdepan(nama_129, nama_baru_129, NIM_129);
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

            if (bantu->nama_129 == nama_129)
            {
                bantu->nama_129 = nama_baru_129;
                bantu->NIM_129 = NIM_129;
                cout << "Data (" << nama_129 << ") telah diganti dengan data (" << nama_baru_129 << ")" << endl;
            }
            else
            {
                cout << "Data dengan nama " << nama_129 << " tidak ditemukan pada posisi yang dimaksud!" << endl;
            }
        }
    }
    else
    {
        cout << "List masih null!" << endl;
    }
}
// mengubah data di belakang
void ubahbelakang(string nama_129, string nama_baru_129, string NIM_129)
{
    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->nama_129 == nama_129)
        {
            temp->nama_129 = nama_baru_129;
            temp->NIM_129 = NIM_129;
            cout << "Data (" << nama_129 << ") telah diganti dengan data (" << nama_baru_129 << ")" << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Data tidak ditemukan" << endl;
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
        cout << "|------------------------------|" << endl;
        cout << "|        DATA MAHASISWA        |" << endl;
        cout << "|------------------------------|" << endl;
        cout << "|       Nama      |    NIM     |" << endl;
        cout << "|------------------------------|" << endl;
        while (bantu != NULL)
        {
            cout << "| " << setw(15) << left << bantu->nama_129 << " | " << setw(10) << left << bantu->NIM_129 << " |" << endl;
            bantu = bantu->next;
        }
        cout << "|------------------------------|" << endl;
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
    int pilihan;
    string nama_129;
    string nama_baru_129;
    string NIM_129;
    int posisi_129;

    do
    {
        cout << "|=========================================|" << endl;
        cout << "| PROGRAM SINGLE LINKED LIST NON-CIRCULAR |" << endl;
        cout << "|=========================================|" << endl;
        cout << "|1. Tambah Depan                          |" << endl;
        cout << "|2. Tambah Belakang                       |" << endl;
        cout << "|3. Tambah Tengah                         |" << endl;
        cout << "|4. Ubah Depan                            |" << endl;
        cout << "|5. Ubah Belakang                         |" << endl;
        cout << "|6. Ubah Tengah                           |" << endl;
        cout << "|7. Hapus Depan                           |" << endl;
        cout << "|8. Hapus Belakang                        |" << endl;
        cout << "|9. Hapus Tengah                          |" << endl;
        cout << "|10. Hapus List                           |" << endl;
        cout << "|11. Tampilkan                            |" << endl;
        cout << "|0. Keluar                                |" << endl;
        cout << "|=========================================|" << endl;
        cout << "Pilihan : ";
        cin >> pilihan;

        switch (pilihan)

        {
        case 0:
            break;
        case 1:
            // Tambah Depan
            cout << "-Tambah Depan-" << endl;
            cout << "Masukkan Nama : ";
            cin >> nama_129;
            cout << "Masukkan NIM : ";
            cin >> NIM_129;
            tambahdepan(nama_129, NIM_129);
            cout << "Data telah ditambahkan" << endl;
            break;
        case 2:
            // Tambah Belakang
            cout << "-Tambah Belakang-" << endl;
            cout << "Masukkan Nama : ";
            cin >> nama_129;
            cout << "Masukkan NIM : ";
            cin >> NIM_129;
            tambahbelakang(nama_129, NIM_129);
            cout << "Data telah ditambahkan" << endl;
            break;
        case 3:
            // Tambah Tengah
            cout << "-Tambah Tengah-" << endl;
            cout << "Masukkan Nama : ";
            cin >> nama_129;
            cout << "Masukkan NIM : ";
            cin >> NIM_129;
            cout << "Masukkan Posisi: ";
            cin >> posisi_129;
            tambahtengah(nama_129, NIM_129, posisi_129);
            cout << "Data telah ditambahkan" << endl;
            break;
        case 4:
            // Ubah Depan
            cout << "-Ubah Depan-" << endl;
            cout << "Masukkan Nama yang akan diubah: ";
            cin >> nama_129;
            cout << "Masukkan Nama baru: ";
            cin >> nama_baru_129;
            cout << "Masukkan NIM baru: ";
            cin >> NIM_129;
            ubahdepan(nama_129, nama_baru_129, NIM_129);
            cout << "Data dengan nama " << nama_129 << " telah diubah menjadi " << nama_baru_129 << endl;
            break;
        case 5:
            // Ubah Belakang
            cout << "-Ubah Belakang-" << endl;
            cout << "Masukkan nama yang akan diubah: ";
            cin >> nama_129;
            cout << "Masukkan nama baru: ";
            cin >> nama_baru_129;
            cout << "Masukkan NIM baru: ";
            cin >> NIM_129;
            ubahbelakang(nama_129, nama_baru_129, NIM_129);
            cout << "Data dengan nama " << nama_129 << " telah diubah menjadi " << nama_baru_129 << endl;
            break;
        case 6: // Ubah Tengah
            cout << "-Ubah Tengah-" << endl;
            cout << "Masukkan nama yang akan diubah: ";
            cin >> nama_129;
            cout << "Masukkan nama baru: ";
            cin >> nama_baru_129;
            cout << "Masukkan NIM baru: ";
            cin >> NIM_129;
            cout << "Masukkan Posisi baru: ";
            cin >> posisi_129;
            ubahtengah(nama_129, nama_baru_129, NIM_129, posisi_129);
            cout << "Data dengan nama " << nama_129 << " telah diubah menjadi " << nama_baru_129 << endl;
            break;
        case 7:
            // Hapus Depan
            cout << "-Hapus Depan-" << endl;
            cout << "Data dengan nama " << hapusdepan() << " berhasil dihapus" << endl;
            break;
        case 8:
            // Hapus Belakang
            cout << "-Hapus Belakang-" << endl;
            cout << "Data dengan nama " << hapusdbelakang() << " berhasil dihapus" << endl;
            break;
        case 9:
            // Hapus Tengah
            cout << "-Hapus Tengah-" << endl;
            cout << "Masukkan Posisi yang akan dihapus: ";
            cin >> posisi_129;
            cout << "Data dengan nama " << hapusdtengah(posisi_129) << " berhasil dihapus" << endl;
            break;
        case 10:
            // Hapus Semua
            cout << "-Hapus List-" << endl;
            deletall();
            cout << "Data list berhasil dihapus" << endl;
            break;
        case 11:
            // Menampilkan data
            tampilkan();
            break;
        default:
            cout << "Pilihan Tidak Tersedia" << endl;
            break;
        }

    } while (pilihan != 0);

    return 0;
}

```

### Output :

<h2>Tambahkan data berikut diantara Farrel dan Denis: Wati 2330004</h2>

![unguided3_a](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan4/assets/soal3_a.png)

<h2>Hapus data Denis</h2>

![unguided3_b](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan4/assets/soal3_b.png)

<h2>Tambahkan data berikut di awal: Owi 2330000</h2>

![unguided3_c](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan4/assets/soal3_c.png)

<h2>Tambahkan data berikut di akhir: David 23300100</h2>

![unguided3_d](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan4/assets/soal3_d.png)

<h2>Ubah data Udin menjadi data berikut: Idin 23300045</h2>

![unguided3_e](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan4/assets/soal3_e.png)

<h2>Ubah data terkahir menjadi berikut: Lucy 23300101</h2>

![unguided3_f](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan4/assets/soal3_f.png)

<h2>Hapus data awal</h2>

![unguided3_g](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan4/assets/soal3_g.png)

<h2>Ubah data awal menjadi berikut: Bagas 2330002</h2>

![unguided3_h](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan4/assets/soal3_h.png)

<h2>Hapus data akhir</h2>

![unguided3_i](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan4/assets/soal3_i.png)

<h2>Tampilkan seluruh data</h2>

![unguided3_j](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan4/assets/soal3_j.png)

=> Penjelasan program

- Pada progam di atas adalah program linked list yang digunakan untuk menyimmpoan data mahasiswa nama dan nim pada program tersebut terdapat berbagai fungsi yang terdiri dari menambahkan data, menghapus data, mengupdate data dan menampilkan data. pada program tersebut kita melakukan berbagai operasi yaitu menambahkan data melalui depan tengah dan belakang, menghapus data melalui depan belakang dan tengah, dan mengubah data mahasiswa dari depan belakang dantengah dan menampilkan seluruh data mahasiswa tersebut.

#### Full code Screenshot:

![Full_ss_code_unguided3](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan4/assets/fullss_unguided3.png)

## Kesimpulan

Kesimpulan dari materi di atas adalah bahwa:

- Linked List Non Circular adalah tipe data yang memiliki struktur data yang tidak terhubung secara circular, dimana setiap elemen hanya mempunyai pointer ke elemen selanjutnya dan tidak mempunyai pointer ke elemen sebelumnya.

- Linked List Circular adalah tipe data yang memiliki struktur data yang terhubung secara circular, dimana setiap elemen hanya mempunyai pointer ke elemen selanjutnya dan tidak mempunyai pointer ke elemen sebelumnya namun setiap elemen juga memiliki pointer ke elemen pertama sebagai pointer prev.

## Referensi

[1] Triase, STRUKTUR DATA, Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN, 2020.

[2] Achmad Udin Zailani,Budi Apriyanto,Hadi Zakaria, STRUKTUR DATA, Banten:2 Universitas Pamulang Tangerang Selatan, 2020.
