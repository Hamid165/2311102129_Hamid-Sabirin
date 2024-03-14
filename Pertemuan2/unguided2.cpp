#include <iostream>
using namespace std;
int main()
{
    // Deklarasi array 3 dimensi
    int arr_129[3][3][3];
    // Input elemen
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr_129[x][y][z];
            }
        }
        cout << endl;
    }
    // Output Array
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Data Array[" << x << "][" << y << "][" << z<< "] = " << arr_129[x][y][z] << endl;
            }
        }
    }
    cout << endl;
    // Menampilkan array
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << arr_129[x][y][z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
}