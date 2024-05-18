#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;
// varibale data menggunakan array dan variable cari
int dataArray[7] = {1, 8, 2, 5, 4, 9, 7};
int cari;
// fungsi perluangan untuk mengurutkan sebuah data dari terkecil ke terbesar
void selection_sort()
{
    int temp, min, i, j;
    for (i = 0; i < 7; i++)
    {
        min = i;
        for (j = i + 1; j < 7; j++)
        {
            if (dataArray[j] < dataArray[min])
            {
                min = j;
            }
        }
        t
            emp = dataArray[i];
        dataArray[i] = dataArray[min];
        dataArray[min] = temp;
    }
}
// fungsi untuk pencarian menggunakan binary search
void binarysearch()
{
    // variable awal akhir tengah dan true false
    int awal, akhir, tengah;
    bool b_flag = false;
    awal = 0;
    akhir = 6;
    // perulangan untuk mencari nilai
    while (!b_flag && awal <= akhir)
    {
        tengah = (awal + akhir) / 2;
        if (dataArray[tengah] == cari)
        {
            b_flag = true;
        }
        else if (dataArray[tengah] < cari)
        {
            awal = tengah + 1;
        }
        else
        {
            akhir = tengah - 1;
        }
    }
    // percabangan untuk mengetahui sebuah data diu temukan pada indeks keberapa
    if (b_flag)
    {
        cout << "\nData ditemukan pada index ke- " << tengah << endl;
    }
    else
    {
        cout << "\nData tidak ditemukan\n";
    }
}
int main()
{
    cout << "\tBINARY SEARCH" << endl;
    cout << "\nData: ";
    // Tampilkan data awal
    for (int x = 0; x < 7; x++)
    {
        cout << setw(3) << dataArray[x];
    }
    cout << endl;
    cout << "\nMasukkan data yang ingin Anda cari: ";
    // input nilai yang akan dicari
    cin >> cari;
    cout << "\nData diurutkan: ";
    // Urutkan data dengan selection sort
    selection_sort();
    // Tampilkan data setelah diurutkan
    for (int x = 0; x < 7; x++)
    {
        cout << setw(3) << dataArray[x];
    }
    cout << endl;
    binarysearch();
    _getche();
    return 0;
}