#include <iostream>

using namespace std;

int main()
{
    // variable untuk data cari true false nilai dan jumlah angka
    int a = 10; 
    int data_129[a] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int cari_129;
    bool ketemu_129 = false;
    int jumlahAngka_129 = 0;
    
    // menampilkan dara awall
    cout << "data = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4}" << endl;
    cout << "Masukkan angka yang ingin Anda cari: ";
    // input cari
    cin >> cari_129;

    // perulangan untuk apakah nilai data sama dengan apa yang di cari
    for (int i = 0; i < a; ++i)
    {
        if (data_129[i] == cari_129)
        {
            ketemu_129 = true;
            jumlahAngka_129++;
        }
    }

    //percabangan ketika data di temukan dan data tidak di temukan
    if (ketemu_129)
    {
        cout << "\nAngka " << cari_129 << " ditemukan sebanyak " << jumlahAngka_129 << endl;
    }
    else
    {
        cout << cari_129 << " tidak dapat ditemukan pada data." << endl;
    }
    return 0;
}
