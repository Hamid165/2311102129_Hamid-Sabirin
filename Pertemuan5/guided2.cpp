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
