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
