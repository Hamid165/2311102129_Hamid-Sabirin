#include <iostream>
using namespace std;
// PROGRAM SINGLE LINKED LIST CIRCULAR
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
};
// Deklarasi Struct Node
class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }
    //upload data
    void push(int data)
    {
        // membuat node
        Node *newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr)
        {
            head->prev = newNode;
        }
        else
        {
            tail = newNode;
        }
        head = newNode;
    }
    // hapus data
    void pop()
    {
        //jika list kosong
        if (head == nullptr)
        {
            return;
        }
        Node *temp = head;
        head = head->next;
        
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        else
        {
            tail = nullptr;
        }
        delete temp;
    }
    //update data
    bool update(int oldData, int newData)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->data == oldData)
            {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    //delete semua data
    void deleteAll()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
    //menampilkan semua data
    void display()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};
// fungsi utama
int main()
{
    // membuat list
    DoublyLinkedList list;
    while (true)
    {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
            // menambahkan data
        case 1:
        {
            int data;
            cout << "Enter data to add: ";
            cin >> data;
            list.push(data);
            break;
        }
        // menghapus data
        case 2:
        {
            list.pop();
            break;
        }
        // memperbarui data
        case 3:
        {
            int oldData, newData;
            cout << "Enter old data: ";
            cin >> oldData;
            cout << "Enter new data: ";
            cin >> newData;
            bool updated = list.update(oldData,newData);
            if (!updated)
            {
                cout << "Data not found" << endl;
            }
            break;
        }
        // menghapus semua data
        case 4:
        {
            list.deleteAll();
            break;
        }
        // menampilkan semua data
        case 5:
        {
            list.display();
            break;
        }
        // keluar
        case 6:
        {
            return 0;
        }
        default:
        {
            cout << "Invalid choice" << endl;
            break;
        }
        }
    }
    return 0;
}