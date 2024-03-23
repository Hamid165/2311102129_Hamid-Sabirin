#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
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
void init_129()
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
void tambah_depan_129(string nama_129, int umur_129)
{
    Node *baru = new Node;
    baru->nama_129 = nama_129;
    baru->umur_129 = umur_129;
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
void tambah_belakang_129(string nama_129, int umur_129)
{
    Node *baru = new Node;
    baru->nama_129 = nama_129;
    baru->umur_129 = umur_129;
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
int hitung_jumlah_129()
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
void tambah_tengah_129(string nama_129, int umur_129, int posisi)
{
    if (posisi < 1 || posisi > hitung_jumlah_129())
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
        baru->umur_129 = umur_129;
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
void hapus_depan_129()
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
void hapus_belakang_129()
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
void hapus_tengah_129(int posisi)
{
    if (posisi < 1 || posisi > hitung_jumlah_129())
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
void ubah_depan_129(string nama_129, int umur_129)
{
    if (!null_129())
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
void ubah_tengah_129(string nama_129, int umur_129, int posisi)
{
    if (!null_129())
    {
        if (posisi < 1 || posisi > hitung_jumlah_129())
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
            bantu->umur_129 = umur_129;
        }
    }
    else
    {
        cout << "List masih null!" << endl;
    }
}

// mengubah data di belakang
void ubah_belakang_129(string nama_129, int umur_129)
{
    if (!null_129())
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
void delete_all_129()
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
void tampilkan_129()
{
    Node *bantu = head;

    if (!null_129())
    {
        cout << "|-------------------------|" << endl;
        cout << "|     NAMA   |    UMUR    |" << endl;
        cout << "|-------------------------|" << endl;
        while (bantu != NULL)
        {
            cout << "| " << setw(10) << left << bantu->nama_129 << " | " << setw(10) << left << bantu->umur_129 << " |" << endl;
            bantu = bantu->next;
        }
        cout << "|-------------------------|" << endl;
    }
    else
    {
        cout << "List masih null!" << endl;
    }
}

int main()
{
    // soal a
    init_129();
    tambah_depan_129("Karin", 18);
    tambah_depan_129("Hoshino", 18);
    tambah_depan_129("Akechi", 20);
    tambah_depan_129("Yusuke", 19);
    tambah_depan_129("Michael", 18);
    tambah_depan_129("Jane", 20);
    tambah_depan_129("John", 19);
    tambah_depan_129("Hamid", 19);
    // tampilkan_129();
    // soal b
    hapus_tengah_129(6);
    // tampilkan_129();
    // soal c
    tambah_tengah_129("Futaba", 18, 3);
    // tampilkan_129();
    // soal d
    tambah_depan_129("Igor", 20);
    tampilkan_129();
    // soal e dan f
    ubah_tengah_129("Reyn", 18, 6);
    tampilkan_129();

    return 0;
}
