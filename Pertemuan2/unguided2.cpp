#include <iostream>
using namespace std;
int main()
{
    int jumlah_element_129;
    cout <<"masukan jumlah element array : ";
    cin >> jumlah_element_129;

    // Deklarasi array jumlah_element_129 dimensi
    int arr_129[jumlah_element_129][jumlah_element_129][jumlah_element_129];
    // Input elemen
    for (int x = 0; x < jumlah_element_129; x++)
    {
        for (int y = 0; y < jumlah_element_129; y++)
        {
            for (int z = 0; z < jumlah_element_129; z++)
            {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr_129[x][y][z];
            }
        }
        cout << endl;
    }
    // Output Array
    for (int x = 0; x < jumlah_element_129; x++)
    {
        for (int y = 0; y < jumlah_element_129; y++)
        {
            for (int z = 0; z < jumlah_element_129; z++)
            {
                cout << "Data Array[" << x << "][" << y << "][" << z<< "] = " << arr_129[x][y][z] << endl;
            }
        }
    }
    cout << endl;
    // Menampilkan array
    for (int x = 0; x < jumlah_element_129; x++)
    {
        for (int y = 0; y < jumlah_element_129; y++)
        {
            for (int z = 0; z < jumlah_element_129; z++)
            {
                cout << arr_129[x][y][z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
}