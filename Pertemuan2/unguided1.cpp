#include <iostream>
using namespace std;

int main()
{
    // variable untuk data array, bilangan ganjil dan genap
    int jmlh_data_arr_129, data_arr_129, bil_genap_129 = 0, bil_ganjil_129 = 0;
    // input panjang array
    cout << "Masukkan jumlah data yang akan diinputkan : ";
    cin >> jmlh_data_arr_129;
    int array[jmlh_data_arr_129];

    // input data array
    for (int i = 0; i < jmlh_data_arr_129; i++)
    {
        cout << "Masukkan data ke " << i + 1 << " : ";
        cin >> data_arr_129;
        array[i] = data_arr_129;
    }
    // menampilkan isi
    cout << "Data Array : ";
    for (int i = 0; i < jmlh_data_arr_129; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    // tampilkan data array yang genap
    cout << "Nomor genap adalah : ";
    for (int i = 0; i < jmlh_data_arr_129; i++)
    {
        if (array[i] % 2 == 0)
        {
            cout << array[i] << ", ";
            bil_genap_129++;
        }
    }
    cout << endl;

    // tampilkan data array yang ganjil
    cout << "Nomor ganjil adalah : ";
    for (int i = 0; i < jmlh_data_arr_129; i++)
    {
        if (array[i] % 2 != 0)
        {
            cout << array[i] << ", ";
            bil_ganjil_129++;
        }
    }
    return 0;
}
