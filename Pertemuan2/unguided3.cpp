#include <iostream>
using namespace std;

int main()
{
    //variable untuk data maksimum minimum, rata rata, i , panjang_array_129, pilihan dan Rata
    int panjang_array_129, pilih_menu_129, maks, min, total;
    double rata;
    // input panjang array oleh user
    cout << "Masukkan panjang array: ";
    cin >> panjang_array_129;
    // perulangan untuk input data array
    int array[panjang_array_129];
    cout << "Masukkan " << panjang_array_129 << " angka" << endl;
    for (int i = 0; i < panjang_array_129; i++)
    {
        cout << "Array ke-" << (i+1) << ": ";
        cin >> array[i];
    }
    // perulangan do untuk menu
    do
    {
        // menu pilihan
        cout << "Pilih menu :" << endl;
        cout << "1. Mencari Maksimum" << endl;
        cout << "2. Mencari Minimum" << endl;
        cout << "3. Mencari Rata-rata" << endl;
        cout << "4. Exit" << endl;
        cout << "Pilihan: ";
        // input pilihan menu
        cin >> pilih_menu_129;
        // switch case menu
        switch (pilih_menu_129)
        {
            case 1:
            // mencari maksimum
                maks = array[0];
                for (int i = 0; i < panjang_array_129; i++)
                {
                    if (array[i] > maks)
                        maks = array[i];
                }
                cout << "Maksimum dari array adalah: " << maks << endl;
                break;
            case 2:
            // mencari minimum
                min = array[0];
                for (int i = 0; i < panjang_array_129; i++)
                {
                    if (array[i] < min)
                        min = array[i];
                }
                cout << "Minimum dari array adalah: " << min << endl;
                break;
            case 3:
            // mencari rata-rata
                total = 0;
                for (int i = 0; i < panjang_array_129; i++)
                    total += array[i];
                rata = static_cast<double>(total) / panjang_array_129;
                cout << "Rata-rata dari array adalah: " << rata << endl;
                break;
            case 4:
                break;
            default:
                cout << "Pilihan tidak tersedia" << endl;
        }
    } while (pilih_menu_129 != 4);
    return 0;
}

