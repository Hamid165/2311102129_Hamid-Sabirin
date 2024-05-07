#include <iostream>
#include <stack>
#include <string>
using namespace std;

// fungsi untuk mengecek apakah sebuah kalimat merupakan palindrom 
bool Palindrom(string kata_129)
{
    // Inisialisasi stack
    stack<char> stack;
    // Memecah kalimat menjadi kata-kata
    for (char c : kata_129)
    {
        stack.push(c);
    }
    // Memeriksa apakah kalimat tersebut merupakan palindrom
    for (char c : kata_129)
    {
        if (stack.top() != c)
        {
            return false;
        }
        stack.pop();
    }
    return true;
}

int main()

{
    // input kalimat
    string input;
    cout << "Masukan Kalimat: ";
    getline(cin, input);
    // mengecek apakah kalimat tersebut merupakan palindrom
    if (Palindrom(input))
    {
        cout << "Kalimat tersebut merupakan : Palindrom" << endl;
    }
    else
    {
        cout << "Kata tersebut merupakan bukan : Palindrom" << endl;
    }

    return 0;
}
