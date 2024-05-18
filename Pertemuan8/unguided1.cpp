#include <iostream>
#include <string>

using namespace std;
// Fungsi untuk mengurutkan karakter dalam string menggunakan Bubble Sort
void bubble_sort(string &kalimat_129)
{
    int n = kalimat_129.size();
    // Perulangan untuk setiap elemen dalam string
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (kalimat_129[j] > kalimat_129[j + 1])
            {
                swap(kalimat_129[j], kalimat_129[j + 1]);
            }
        }
    }
}
// Fungsi untuk mencari karakter dalam string yang sudah diurutkan
void binary_search(const string &kalimat_129, char cari_129)
{
    bool ditemukan = false;
    cout << "Kata setelah diurutkan: " << kalimat_129 << endl;
    cout << "Huruf '" << cari_129 << "' ditemukan pada indeks ke: ";
    // Perulangan untuk mencari huruf dalam string
    for (size_t i = 0; i < kalimat_129.size(); ++i)
    {
        if (kalimat_129[i] == cari_129)
        {
            ditemukan = true;
            cout << i << " ";
        }
    }
    cout << endl;
    // percabangan jika tidak menemukan huruf pada kata
    if (!ditemukan)
    {
        cout << "Huruf '" << cari_129 << "' tidak ditemukan dalam kalimat." << endl;
    }
}

int main()
{
    string kalimat_129;
    char cari_129;

    cout << "Masukkan kalimat: ";
    getline(cin, kalimat_129);

    // Urutkan kalimat menggunakan bubble sort
    bubble_sort(kalimat_129);
    cout << "Kalimat setelah diurutkan: " << kalimat_129 << endl;

    cout << "Masukkan huruf yang ingin Anda cari: ";
    cin >> cari_129;

    // Cari huruf dalam kalimat menggunakan binary search
    binary_search(kalimat_129, cari_129);

    return 0;
}
