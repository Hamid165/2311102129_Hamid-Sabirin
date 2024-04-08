#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// Deklarasi konstanta TABLE_SIZE
const int TABLE_SIZE = 10;
// Deklarasi class HashNode
class HashNode
{
public:
    string nim_129;
    string nama_129;
    int nilai_129;

    // Konstruktor untuk membuat node baru dengan NIM, nama, dan nilai
    HashNode(string nim_129, string nama_129, int nilai_129)
    {
        this->nim_129 = nim_129;
        this->nama_129 = nama_129;
        this->nilai_129 = nilai_129;
    }
};
// Deklarasi class HashMap
class HashMap
{
private:
    vector<HashNode *> table[TABLE_SIZE];

public:
    // Fungsi hash untuk menghasilkan indeks dari sebuah NIM
    int hashFunc(string key)
    {
        int hash_val = 0;
        for (char c : key)
        {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }

    // Fungsi untuk menambahkan data mahasiswa ke tabel hash
    void tambah_data_129(string nim_129, string nama_129, int nilai_129)
    {
        int hash_val = hashFunc(nim_129);
        for (auto node : table[hash_val])
        {
            if (node->nim_129 == nim_129)
            {
                node->nilai_129 = nilai_129;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(nim_129, nama_129, nilai_129));
        cout << "Data mahasiswa berhasil ditambahkan." << endl;
    }

    // Fungsi untuk menghapus data mahasiswa dari tabel hash berdasarkan NIM
    void hapus_data_129(string nim_129)
    {
        int hash_val = hashFunc(nim_129);
        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++)
        {
            if ((*it)->nim_129 == nim_129)
            {
                table[hash_val].erase(it);
                cout << "Data mahasiswa dengan NIM " << nim_129 << " berhasil dihapus." << endl;
                return;
            }
        }
        cout << "Data mahasiswa dengan NIM " << nim_129 << " tidak ditemukan." << endl;
    }

    // Fungsi untuk mencari data mahasiswa berdasarkan NIM
    HashNode *cari_data_nim_129(string nim_129)
    {
        int hash_val = hashFunc(nim_129);
        for (auto node : table[hash_val])
        {
            if (node->nim_129 == nim_129)
            {
                return node;
            }
        }
        return nullptr;
    }

    // Fungsi untuk mencari data mahasiswa berdasarkan rentang nilai
    vector<HashNode *> cari_rentang_nilai_129(int minScore, int maxScore)
    {
        vector<HashNode *> result;
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            for (auto node : table[i])
            {
                if (node->nilai_129 >= minScore && node->nilai_129 <= maxScore)
                {
                    result.push_back(node);
                }
            }
        }
        return result;
    }

    // Fungsi untuk mencetak data mahasiswa dalam bentuk tabel
    void tampilkan_data_129()
    {
        cout << "|----------------------------------------------|" << endl;
        cout << "| No.  | NIM       | Nama          | Nilai     |" << endl;
        cout << "|----------------------------------------------|" << endl;
        int no = 1;

        for (int i = 0; i < TABLE_SIZE; i++)
        {
            for (auto node : table[i])
            {
                cout << "| " << setw(4) << no++ << " | " << setw(10) << node->nim_129 << " | " << setw(14) << node->nama_129 << " | " << setw(7) << node->nilai_129 << " |" << endl;
            }
        }
        cout << "-----------------------------------------------" << endl;
    }
};
// Fungsi utama
int main()
{
    HashMap mahasiswa_map;
    int pilihan;
    string nim_129, nama_129;
    int nilai_129;

    do
    {
        // Tampilkan menu pilihan
        cout << "Menu:" << endl;
        cout << "1. Tambah data mahasiswa" << endl;
        cout << "2. Hapus data mahasiswa" << endl;
        cout << "3. Cari data mahasiswa berdasarkan NIM" << endl;
        cout << "4. Cari data mahasiswa berdasarkan rentang nilai (80-90)" << endl;
        cout << "5. Tampilkan data mahasiswa" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan)
        {
            // Tambah data mahasiswa
        case 1:
            cout << "Masukkan nama mahasiswa: ";
            cin.ignore();
            getline(cin, nama_129);
            cout << "Masukkan NIM mahasiswa: ";
            cin >> nim_129;
            cout << "Masukkan nilai mahasiswa: ";
            cin >> nilai_129;
            mahasiswa_map.tambah_data_129(nim_129, nama_129, nilai_129);
            break;
            // Hapus data mahasiswa
        case 2:
            cout << "Masukkan NIM mahasiswa yang ingin dihapus: ";
            cin >> nim_129;
            mahasiswa_map.hapus_data_129(nim_129);
            break;
            // Cari data mahasiswa berdasarkan NIM
        case 3:
            cout << "Masukkan NIM mahasiswa yang ingin dicari: ";
            cin >> nim_129;
            {
                HashNode *mahasiswa = mahasiswa_map.cari_data_nim_129(nim_129);
                if (mahasiswa != nullptr)
                {
                    cout << "Nama mahasiswa dengan NIM : " << nim_129 << ",Nama : " << mahasiswa->nama_129 << ", Nilai: " << mahasiswa->nilai_129 << endl;
                }
                else
                {
                    cout << "Mahasiswa dengan NIM : " << nim_129 << " tidak ditemukan" << endl;
                }
            }
            break;
            // Cari data mahasiswa berdasarkan rentang nilai 80-90
        case 4:
            cout << "Mahasiswa dengan nilai antara 80 dan 90:" << endl;
            {
                vector<HashNode *> mahasiswaInRange = mahasiswa_map.cari_rentang_nilai_129(80, 90);
                if (mahasiswaInRange.empty())
                {
                    cout << "Tidak ada mahasiswa dalam rentang nilai tersebut" << endl;
                }
                else
                {
                    for (auto mahasiswa : mahasiswaInRange)
                    {
                        cout << "NIM: " << mahasiswa->nim_129 << ", Nama: " << mahasiswa->nama_129 << ", Nilai: " << mahasiswa->nilai_129 << endl;
                    }
                }
            }
            break;
            // Tampilkan data mahasiswa
        case 5:
            cout << "Data mahasiswa:" << endl;
            mahasiswa_map.tampilkan_data_129();
            break;
        case 6:
            cout << "Keluar." << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 6);

    return 0;
}