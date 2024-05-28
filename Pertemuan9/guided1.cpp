#include <iostream>
#include <iomanip>
using namespace std;

// variable untuk menampung sebuah data simpul yang isinya berupa kota yang di dalam array berjumlahkan 7 kota

string simpul[7] = {"ciamis", "Bandung", "Bekasi", "Tasikmalaya", "Cianjur", "Purwokerto", "Yogyakarta"};

// variable sebuah arrray 2 dimensi yang berisikan 7 baris dan 7 kolom yang berisikan nilai angka integer
int busur[7][7] = {
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 0, 15, 0},
    {0, 6, 0, 0, 6, 0, 0},
    {0, 5, 0, 0, 2, 4, 0},
    {23, 0, 0, 10, 0, 0, 8},
    {0, 0, 0, 0, 7, 0, 3},
    {0, 0, 0, 0, 9, 4, 0},
};
void tampilGraph()
{
    for (int baris = 0; baris < 7; baris++)
    {
        cout << " " << setiosflags(ios::left) << setw(15) << simpul[baris] << " : ";
        for (int kolom = 0; kolom < 7; kolom++)
        {
            if (busur[baris][kolom] != 0)
            {
                cout << " " << simpul[kolom] << "(" << busur[baris][kolom] << ")";
            }
        }
        cout << endl;
    }
}
// fungsi utama untuk menampilkan graph yang telah di buat pada fungsi di atas
int main()
{
    tampilGraph();
    return 0;
}

