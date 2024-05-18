#include <iostream>
#include <string>

using namespace std;

int main()
{
    // variable kalimat dan total vokal huruf
    string kalimat_129;
    int jumlahVokal_129 = 0;

    cout << "Masukkan kalimat: ";
    getline(cin, kalimat_129);
    // perulangan apakah huruf dan kalimat sama atau tidak
    for (char huruf_129 : kalimat_129)
    {
        if (huruf_129 == 'a' || huruf_129 == 'e' || huruf_129 == 'i' || huruf_129 == 'o' || huruf_129 == 'u' ||
            huruf_129 == 'A' || huruf_129 == 'E' || huruf_129 == 'I' || huruf_129 == 'O' || huruf_129 == 'U')
        {
            jumlahVokal_129++;
        }
    }

    cout << "Kalimat: " << kalimat_129 << endl;

    cout << "\nJumlah huruf vokal dalam kalimat: " << jumlahVokal_129 << endl;

    return 0;
}
