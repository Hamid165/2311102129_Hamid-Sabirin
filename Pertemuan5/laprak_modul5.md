# <h1 align="center">Laporan Praktikum Modul 5 HASH TABLE</h1>

<h1 align="center">Hamid Sabirin-2311102129</h1>

## Dasar Teori

<h2 align="center">HASH TABLE</h2>

- Hash Table adalah struktur data yang terdiri dari array dan fungsi yang bertujuan untuk memetakan nilai kunci unik setiap record (baris) ke nomor posisi record (hash) dalam tabel.

- Keunggulan dari struktur hash table ini adalah waktu aksesnya yang cukup cepat, jika record yang dicari langsung berada pada angka hash lokasi penyimpanannya. Akan tetapi pada kenyataannya sering sekali ditemukan hash table yang recordrecordnya mempunyai angka hash yang sama (bertabrakan).

- Karena pemetaan hash function yang digunakan bukanlah pemetaan satu-satu, (antara dua record yang tidak sama dapat dibangkitkan angka hash yang sama) maka dapat terjadi bentrokan (collision) dalam penempatan suatu data record. Untuk mengatasi hal ini, maka perlu diterapkan kebijakan resolusi bentrokan (collision resolution policy) untuk menentukan lokasi record dalam tabel. Umumnya kebijakan resolusi bentrokan adalah dengan mencari lokasi tabel yang masih kosong pada lokasi setelah lokasi yang berbentrokan.

- Penggunaan Hash Table ini sangat cocok digunakan pada aplikasi yang membutuhkan proses pencarian data secara cepat dan efisien. Hal ini karena menggunakan key yang bersifat acak untuk mengakses suatu value yang terdapat pada array.
  Jika key yang digunakan berbeda, maka proses pencarian data akan lebih cepat dan efisien. Sebab, key yang digunakan berbeda dapat memiliki value yang berbeda.

- Fungsi hash adalah fungsi yang menerima masukan sembarang string dengan panjang bebas dan menghasilkan sebuah string dengan panjang yang selalu sama yang biasa disebut dengan hash value

Dalam Hash Table terdapat 3 komponen utama, yaitu:

1. Array Dinamis “table” yang berisikan data yang dapat disimpan.
2. Fungsi Hash (yang bertugas untuk menghasilkan key dari sebuah input) yang digunakan untuk mengakses data yang terdapat pada array dinamis “table”.
3. Fungsi Rehashing (yang bertugas untuk mengatasi masalah konflik key yang terjadi ketika terdapat dua atau lebih data yang memiliki key yang sama)

## Guided

### 1. [ Hastable dengan array dinamis table]

```C++
#include <iostream>
using namespace std;
const int MAX_SIZE = 10;
// Fungsi hash sederhana
int hash_func(int key)
{
    return key % MAX_SIZE;
}
// Struktur data untuk setiap node
struct Node
{
    int key;
    int value;
    Node *next;
    Node(int key, int value) : key(key), value(value), next(nullptr) {}
};
// Class hash table
class HashTable
{
private:
    Node **table;

public:
    HashTable()
    {
        table = new Node *[MAX_SIZE]();
    }
    ~HashTable()
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            Node *current = table[i];
            while (current != nullptr)
            {
                Node *temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }
    // Insertion
    void insert(int key, int value)
    {
        int index = hash_func(key);
        Node *current = table[index];
        while (current != nullptr)
        {
            if (current->key == key)
            {
                current->value = value;
                return;
            }
            current = current->next;
        }
        Node *node = new Node(key, value);
        node->next = table[index];
        table[index] = node;
    }
    // Searching
    int get(int key)
    {
        int index = hash_func(key);
        Node *current = table[index];
        while (current != nullptr)
        {
            if (current->key == key)
            {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }
    // Deletion
    void remove(int key)
    {
        int index = hash_func(key);
        Node *current = table[index];
        Node *prev = nullptr;
        while (current != nullptr)
        {
            if (current->key == key)
            {
                if (prev == nullptr)
                {
                    table[index] = current->next;
                }
                else
                {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }
    // Traversal
    void traverse()
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            Node *current = table[i];
            while (current != nullptr)
            {
                cout << current->key << ": " << current->value
                     << endl;
                current = current->next;
            }
        }
    }
};
int main()
{
    HashTable ht;
    // Insertion
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);
    // Searching
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;
    // Deletion
    ht.remove(4);
    // Traversal
    ht.traverse();
    return 0;
}
```

=> Penjelasan program

- Pada code program di atas yaitu untuk mengimplementasikan tipe data Hash Table yang bersifat non-circular, dideklarasikan sebuah struct bernama Node yang berisi 3 field, yaitu key, value, dan pointer next. Kemudian dideklarasikan sebuah class HashTable yang berisi variabel array table yang berisi pointer ke Node yang terletak di indeks tersebut. HashTable juga mempunyai method insert, delete, get, dan traverse. Prosedur insert berfungsi untuk menambahkan sebuah element ke dalam hash table dengan key tertentu dan value tertentu. prosedur delete berfungsi untuk menghapus elemen dengan key tertentu. Prosedur get berfungsi untuk mengembalikan value dari elemen dengan key tertentu. Prosedur traverse berfungsi untuk mengembalikan semua key-value dalam hash table. Di dalam main function, terdapat sebuah program sederhana yang menggunakan HashTable untuk menambahkan, menghapus, dan mengembalikan elemen-elemen dalam hash table, dan menampilkan hasilnya ke layar user.

### 2. [Implementasi HashMap untuk Penyimpanan Nama dan Nomor Telepon]

```C++
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int TABLE_SIZE = 11;

// Struktur untuk node dalam tabel hash
class HashNode
{
public:
    string name;
    string phone_number;

    HashNode(string name, string phone_number)
    {
        this->name = name;
        this->phone_number = phone_number;
    }
};

// Kelas HashMap untuk mengelola tabel hash
class HashMap
{
private:
    vector<HashNode *> table[TABLE_SIZE];

public:
    // Fungsi hash untuk menghasilkan indeks dari suatu kunci
    int hashFunc(string key)
    {
        int hash_val = 0;
        for (char c : key)
        {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }

    // Fungsi untuk menambahkan data baru ke dalam tabel hash
    void insert(string name, string phone_number)
    {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val])
        {
            if (node->name == name)
            {
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, phone_number));
    }

    // Fungsi untuk menghapus data berdasarkan nama
    void remove(string name)
    {
        int hash_val = hashFunc(name);
        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++)
        {
            if ((*it)->name == name)
            {
                table[hash_val].erase(it);
                return;
            }
        }
    }

    // Fungsi untuk mencari nomor telepon berdasarkan nama
    string searchByName(string name)
    {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val])
        {
            if (node->name == name)
            {
                return node->phone_number;
            }
        }
        return "";
    }

    // Fungsi untuk mencetak seluruh tabel hash
    void print()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            cout << i << ": ";
            for (auto pair : table[i])
            {
                if (pair != nullptr)
                {
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    HashMap employee_map;

    // Menambahkan beberapa data ke dalam tabel hash
    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");

    // Mencari dan mencetak nomor telepon
    cout << "Nomer Hp Mistah : " << employee_map.searchByName("Mistah") << endl;
    cout << "Phone Hp Pastah : " << employee_map.searchByName("Pastah") << endl;

    // Menghapus data dan mencetak tabel hash
    employee_map.remove("Mistah");
    cout << "Nomer Hp Mistah setelah dihapus : " << employee_map.searchByName("Mistah") << endl
         << endl;

    // Mencetak seluruh tabel hash
    cout << "Hash Table : " << endl;
    employee_map.print();

    return 0;
}
```

=> Penjelasan program

- Pada program di atas merupakan contoh implementasi hash table pada C++ yang dapat menyimpan dan mengelola data berpasangan nama-nomer hp. Hash table dideklarasikan dengan konstanta TABLE_SIZE yang bernilai 11. Method insert() digunakan untuk menambahkan pasangan nama-nomer hp ke dalam hash table, sedangkan method remove() digunakan untuk menghapus pasangan nama-nomer hp dari hash table. Method searchByName() digunakan untuk mencari nomer hp berdasarkan nama, dan method print() digunakan untuk menampilkan isi hash table secara detail. Contoh penggunaan dari hash table di atas dapat dilihat pada main() yang menambahkan beberapa pasangan nama-nomer hp, menghapus pasangan nama-nomer hp, dan mencari nomer hp berdasarkan nama. Dalam contoh di atas, hash table dideklarasikan sebagai variabel bernama employee_map dan dapat diisi dengan data pasangan nama-nomer hp. Kemudian, pada main() terdapat beberapa contoh penggunaan dari hash table di atas. Pertama, menambahkan beberapa pasangan nama-nomer hp dengan menggunakan method insert(). Kemudian, menghapus pasangan nama-nomer hp dengan menggunakan method remove(). Setelah itu, mencari nomer hp berdasarkan nama dengan menggunakan method searchByName(). Terakhir, menampilkan isi hash table dengan menggunakan method print()Setelah memanggil main(), kita dapat melihat bahwa data yang baru disimpan dan dapat diakses dengan cara mencari nomer hp berdasarkan nama.

## Unguided

### 1. [Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. Dengan ketentuan :]

![soal1](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan5/assets/soal.png)

```C++
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
```

### Output :

<h2>Setiap mahasiswa memiliki NIM dan nilai.</h2>

![soal a](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan5/assets/soal1_a.png)

<h2>Program memiliki tampilan pilihan menu berisi poin C</h2>

![soal b](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan5/assets/soal1_b.png)

<h2>mplementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai (80 – 90)</h2>

![soal c](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan5/assets/soal1_c.png)

=> Penjelasan Program

- Pada program code di atas merupakan code impelentasikan dari hash table data mahasiswa, pada code di atas terdapat beberapa buah prosedur yang nanti akan di gunakan seperti menambahkan data, menghapus data, mencari data, menampilkan data dengan rentan nilai 80-90 dan mencetak data. pada menambahkan data kita menginputkan nama, nim dan nilai mahasiswa. pada menghapus data kita hanya perlu menginputkan nim dari mahasiswanya dan pada mencari data kita juga hanya memerlukan nim dan menu menampilkan data dengan nilai rentan 80-90 kita memanggil fungsi mencari rentan nilai dan menyimpan data tersebut pada vector dan akan di cek apakah kosong atau tidak jika tidak maka akan menampilkan data dengan rentan 80-90 dan menu terakhir yaitu menampilkan data.

#### Full code Screenshot:

![Full_ss_code_unguided1](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan5/assets/fullss_unguided1.png)

## Kesimpulan

Kesimpulan dari materi di atas adalah bahwa:

Hash Table adalah tipe data yang mempunyai Key dan Value, dan kita dapat mengakses data dengan Key yang digunakan. untuk mengakses data dari hash table kita mempunyai fungsi yang dapat di gunakan seperti menambahkan data, menghapus data, mencari data berdasarkan Key, dan mencari data berdasarkan rentang nilai. Setelah menambahkan data kita dapat menghapus data berdasarkan Key, dan mencari data berdasarkan Key atau rentang nilai dan menampilkan data yang sesuai dengan rentang nilai yang kita tentukan.

## Referensi

[1] Rizki Alif Salman Alfarisy, Perbandingan Kinerja Berbagai Algoritma Fungsi Hash pada Algoritma Rabin-Karp, Bandung: Institut Teknologi Bandung, 2019.

[2] Izhar Rahim, Nizirwan Anwar, Agung Mulyo Widodo, Kundang Karsono Juman, Iwan Setiawan, Komparasi Fungsi Hash Md5 Dan Sha256 Dalam Keamanan Gambar Dan Teks, Banten:2 Universitas Pamulang Tangerang Selatan, 2020.
