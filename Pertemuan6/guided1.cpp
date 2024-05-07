#include <iostream>
using namespace std;

string arraybuku[5];
int maksimal = 5, top = 0;

// Fungsi untuk mengecek apakah stack sudah penuh
bool isFull()
{
    return (top == maksimal);
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty()
{
    return (top == 0);
}

// Prosedur untuk menambahkan data ke dalam stack
void pushArrayBuku(string data)
{
    if (isFull())
    {
        cout << "data telah penuh" << endl;
    }
    else
    {
        arraybuku[top] = data;
        top++;
    }
}

// Prosedur untuk menghapus data dari stack
void popArrayBuku()
{
    if (isEmpty())
    {
        cout << "Tidak ada data yang bisa dihapus" << endl;
    }
    else
    {
        arraybuku[top - 1] = "";
        top--;
    }
}

// Prosedur untuk melihat data pada posisi tertentu dalam stack
void peekArrayBuku(int posisi)
{
    if (isEmpty())
    {
        cout << "Tidak ada data yang bisa ditampilkan" << endl;
    }
    else
    {
        int index = top;
        for (int i = 1; i <= posisi; i++)
        {
            index--;
        }
        cout << "Posisi ke " << posisi << " adalah " << arraybuku[index] << endl;
    }
}

// Fungsi untuk menghitung jumlah data dalam stack
int countStack()
{
    return top;
}

// Prosedur untuk mengubah data pada posisi tertentu dalam stack
void changeArrayBuku(int posisi, string data)
{
    if (posisi > top)
    {
        cout << "Posisi melebihi data" << endl;
    }
    else
    {
        int index = top;
        for (int i = 1; i <= posisi; i++)
        {
            index--;
        }
        arraybuku[index] = data;
    }
}

// Prosedur untuk menghapus semua data dalam stack
void destroyArrayBuku()
{
    for (int i = top; i >= 0; i--)
    {
        arraybuku[i] = "";
    }
    top = 0;
}

// Prosedur untuk mencetak semua data dalam stack
void printArrayBuku()
{
    if (isEmpty())
    {
        cout << "Tidak ada data yang dicetak" << endl;
    }
    else
    {
        for (int i = top - 1; i >= 0; i--)
        {
            cout << arraybuku[i] << endl;
        }
    }
}

int main()
{
    // Menambahkan beberapa data ke dalam stack
    pushArrayBuku("Inggris");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Kalkulus");

    // Mencetak semua data dalam stack
    printArrayBuku();
    cout << endl;
    // Menampilkan status stack
    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;
    // Melihat data pada posisi tertentu dalam stack
    peekArrayBuku(2);
    // Menghapus data dari stack
    popArrayBuku();
    // Menghitung jumlah data dalam stack
    cout << "Banyaknya data: " << countStack() << endl;
    // Mengubah data pada posisi tertentu dalam stack
    changeArrayBuku(2, "Bahasa Jerman");
    // Mencetak semua data dalam stack setelah perubahan
    printArrayBuku();
    cout << endl;
    // Menghapus semua data dalam stack
    destroyArrayBuku();
    // Menampilkan jumlah data setelah dihapus
    cout << "Jumlah data setelah dihapus: " << top << endl;
    // Mencetak semua data dalam stack setelah dihapus
    printArrayBuku();
    return 0;
}

