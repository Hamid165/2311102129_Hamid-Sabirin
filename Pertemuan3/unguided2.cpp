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
