#include <iostream>

using namespace std;

// Maksimal antrian
const int maks_129 = 5;

// Struktur Node untuk linked list
struct Node
{
    string nama_129;
    string nim_129;
    Node *next;
};

// Penunjuk head global untuk linked list
Node *head = nullptr;

// Fungsi untuk memeriksa apakah antrian penuh
bool isFull()
{
    return false;
}

// Fungsi untuk memeriksa apakah antrian kosong
bool isEmpty()
{
    return head == nullptr;
}

// Fungsi untuk enqueue (menambahkan) elemen ke antrian
void enqueueAntrian(string nama_129, string nim_129)
{
    Node *newNode_129 = new Node;
    newNode_129->nama_129 = nama_129;
    newNode_129->nim_129 = nim_129;
    newNode_129->next = nullptr;

    if (isEmpty())
    {
        head = newNode_129;
        return;
    }

    Node *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }

    current->next = newNode_129;
}

// Fungsi untuk dequeue (menghapus) elemen dari antrian
void dequeueAntrian()
{
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
        return;
    }

    string nama_129 = head->nama_129;
    string nim_129 = head->nim_129;
    Node *temp = head;
    head = head->next;
    delete temp;

    cout << "Data terhapus: " << nama_129 << ", Nim : " << nim_129 << endl;
}

// Fungsi untuk menghitung jumlah elemen dalam antrian
int countQueue()
{
    int count = 0;
    Node *current = head;
    while (current != nullptr)
    {
        count++;
        current = current->next;
    }
    return count;
}

// Fungsi untuk menghapus semua elemen antrian
void clearQueue()
{
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

// Fungsi untuk melihat elemen antrian
void viewQueue()
{
    cout << "Data antrian teller:" << endl;
    Node *current = head;
    int i = 1;
    while (i <= maks_129)
    {
        if (current != nullptr)
        {
            cout << i << ". " << current->nama_129 << ", Nim: " << current->nim_129 << endl;
            current = current->next;
        }
        else
        {
            cout << i << ". (kosong)" << endl;
        }
        i++;
    }
}

int main()
{
    // menambahkan antrian pada queue
    enqueueAntrian("Hamid", "2311102129");
    enqueueAntrian("Sabirin", "54321");
    // menampilkan queue
    viewQueue();
    // mengecek jumlah antrian
    cout << "Jumlah antrian = " << countQueue() << endl;
    // menghapus antrian
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    // menghapus semua antrian
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
