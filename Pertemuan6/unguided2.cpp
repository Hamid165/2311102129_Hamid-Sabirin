#include <iostream>
#include <stack>

using namespace std;

// Fungsi untuk membalikkan kalimat
void Pembalik(string kalimat_129)
{
    // Inisialisasi stack
    stack<string> st;
    string kata_129 = "";
    // Memecah kalimat menjadi kata-kata
    for (size_t i = 0; i < kalimat_129.length(); i++)
    {
        // Memeriksa apakah karakter saat ini adalah spasi
        if (kalimat_129[i] == ' ')
        {
            // Memasukkan kata ke dalam stack
            st.push(kata_129);
            // Mengosongkan kembali string kata
            kata_129 = "";
        }
        else
        {
            // Memasukkan karakter ke dalam string kata
            kata_129 = kalimat_129[i] + kata_129;
        }
    }

    // Memasukkan kata terakhir ke dalam stack
    st.push(kata_129);

    // Mencetak kata-kata dari stack untuk menghasilkan kalimat yang terbalik
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}
int main()
{
    // Input kalimat
    string kalimat_129;
    cout << "Masukkan Kata : ";
    getline(cin, kalimat_129);
    // Menampilkan kalimat setelah diturunkan
    cout << "Hasil Kata Setelah Diturunkan : ";
    Pembalik(kalimat_129);

    return 0;
}
