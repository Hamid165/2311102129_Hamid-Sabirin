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

// Menghapus data di depan dan mengembalikan nama yang dihapus
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

// Menghapus data di tengah dan mengembalikan nama yang dihapus
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

    while (bantu != NULL && bantu->nama_129 != nama_129)
    {
        sebelum = bantu;
        bantu = bantu->next;
    }

    if (bantu == NULL)
    {
        cout << "Data tidak ditemukan!" << endl;
        return;
    }

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
}
