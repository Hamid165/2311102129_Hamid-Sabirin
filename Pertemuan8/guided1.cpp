#include <iostream>
using namespace std;
int main()
{
    // varibale nilai data, variable nilai angka yang di cari dan variable true false
    int n = 10;
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};
    int cari = 10;
    bool ketemu = false;
    int i;
    // Algoritma Sequential Search
    for (i = 0; i < n; i++)
    {
        if (data[i] == cari)
        {
            ketemu = true;
            break;
        }
    }
    // menampilkan judul dan data
    cout<< "\tProgram Sequential Search Sederhana\n"<< endl;
    cout << "data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;
    // percabangan untuk mengetahui nilai angka di temukan pada indeks keberapa
    if (ketemu)
    {
        cout << "\nAngka " << cari << " ditemukan pada indeks ke-"<< i << endl;
    }
    else
    {
        cout << cari << " tidak dapat ditemukan pada data." << endl;
    }
    return 0;
}