#include <iostream>
#include <queue>
using namespace std;

// Struktur Node Tree
struct Pohon
{
    // Data dari node
    char data_2311102129;
    // Pointer ke child kiri
    Pohon *left_2311102129;
    // Pointer ke child kanan
    Pohon *right_2311102129;
    // Pointer ke parent node
    Pohon *parent_2311102129;
};
// Pointer ke root node
Pohon *root_2311102129;

// Fungsi untuk mengecek apakah tree kosong
bool isEmpty()
{
    return root_2311102129 == NULL;
}

// Fungsi untuk inisialisasi root
void init()
{
    root_2311102129 = nullptr;
}

// Fungsi untuk membuat root node
void buatNode(char data)
{
    if (root_2311102129 == nullptr)
    {
        root_2311102129 = new Pohon();
        root_2311102129->data_2311102129 = data;
        root_2311102129->left_2311102129 = nullptr;
        root_2311102129->right_2311102129 = nullptr;
        cout << "Node " << data << " berhasil dibuat sebagai root." << endl;
    }
    else
    {
        cout << "Root sudah ada!" << endl;
    }
}

// Fungsi untuk menambahkan node di sebelah kiri sebuah node tertentu
Pohon *insertLeft(char data, Pohon *parent)
{
    if (parent == nullptr)
    {
        cout << "Node parent tidak ditemukan!" << endl;
        return nullptr;
    }

    if (parent->left_2311102129 == nullptr)
    {
        Pohon *newNode = new Pohon();
        newNode->data_2311102129 = data;
        newNode->left_2311102129 = nullptr;
        newNode->right_2311102129 = nullptr;
        parent->left_2311102129 = newNode;
        cout << "Node " << data << " berhasil ditambahkan ke child kiri " << parent->data_2311102129 << endl;
        return newNode;
    }
    else
    {
        cout << "Node kiri dari " << parent->data_2311102129 << " sudah terisi!" << endl;
        return nullptr;
    }
}

// Fungsi untuk menambahkan node di sebelah kanan sebuah node tertentu
Pohon *insertRight(char data, Pohon *parent)
{
    if (parent == nullptr)
    {
        cout << "Node parent tidak ditemukan!" << endl;
        return nullptr;
    }

    if (parent->right_2311102129 == nullptr)
    {
        Pohon *newNode = new Pohon();
        newNode->data_2311102129 = data;
        newNode->left_2311102129 = nullptr;
        newNode->right_2311102129 = nullptr;
        parent->right_2311102129 = newNode;
        cout << "Node " << data << " berhasil ditambahkan ke child kanan " << parent->data_2311102129 << endl;
        return newNode;
    }
    else
    {
        cout << "Node kanan dari " << parent->data_2311102129 << " sudah terisi!" << endl;
        return nullptr;
    }
}

// Fungsi untuk mengubah data sebuah node
void update(char oldData, Pohon *node)
{
    if (node == nullptr)
    {
        cout << "Node tidak ditemukan!" << endl;
        return;
    }

    if (node->data_2311102129 == oldData)
    {
        cout << "Masukkan data baru: ";
        char newData;
        cin >> newData;
        node->data_2311102129 = newData;
        cout << "Data node: " << newData << endl;
        return;
    }

    if (node->left_2311102129 != nullptr)
    {
        update(oldData, node->left_2311102129);
    }
    if (node->right_2311102129 != nullptr)
    {
        update(oldData, node->right_2311102129);
    }
}

// Fungsi untuk mencari node berdasarkan data
Pohon *find(char data)
{
    queue<Pohon *> q;
    if (root_2311102129 != nullptr)
        q.push(root_2311102129);

    while (!q.empty())
    {
        Pohon *temp = q.front();
        q.pop();

        if (temp->data_2311102129 == data)
        {
            return temp;
        }

        if (temp->left_2311102129 != nullptr)
        {
            q.push(temp->left_2311102129);
        }
        if (temp->right_2311102129 != nullptr)
        {
            q.push(temp->right_2311102129);
        }
    }
    return nullptr;
}

// Fungsi untuk menampilkan descendant (anak-anak) dari sebuah node
void tampilkanDescendant(Pohon *node)
{
    if (node == nullptr)
    {
        cout << "Node tidak ditemukan!" << endl;
        return;
    }

    if (node->left_2311102129 != nullptr)
    {
        cout << node->left_2311102129->data_2311102129 << " ";
        tampilkanDescendant(node->left_2311102129);
    }
    if (node->right_2311102129 != nullptr)
    {
        cout << node->right_2311102129->data_2311102129 << " ";
        tampilkanDescendant(node->right_2311102129);
    }
}

// Fungsi untuk menampilkan data secara ascending (in-order traversal)
void tampilkanAscending(Pohon *node)
{
    if (node == nullptr)
    {
        return;
    }

    tampilkanAscending(node->left_2311102129);
    cout << node->data_2311102129 << " ";
    tampilkanAscending(node->right_2311102129);
}

// Fungsi untuk melakukan pre-order traversal
void PreOrder(Pohon *node)
{
    if (node == nullptr)
    {
        return;
    }

    cout << node->data_2311102129 << " ";
    PreOrder(node->left_2311102129);
    PreOrder(node->right_2311102129);
}

// Fungsi untuk melakukan in-order traversal
void InOrder(Pohon *node)
{
    if (node == nullptr)
    {
        return;
    }

    InOrder(node->left_2311102129);
    cout << node->data_2311102129 << " ";
    InOrder(node->right_2311102129);
}

// Fungsi untuk melakukan post-order traversal
void PostOrder(Pohon *node)
{
    if (node == nullptr)
    {
        return;
    }

    PostOrder(node->left_2311102129);
    PostOrder(node->right_2311102129);
    cout << node->data_2311102129 << " ";
}

// Fungsi untuk menampilkan sibling dari sebuah node
void sibling(Pohon *node)
{
    if (root_2311102129 == nullptr || root_2311102129 == node)
    {
        cout << "Root node tidak memiliki sibling." << endl;
        return;
    }

    Pohon *parent = nullptr;
    Pohon *current = root_2311102129;

    queue<Pohon *> q;
    q.push(current);

    while (!q.empty())
    {
        current = q.front();
        q.pop();

        if (current->left_2311102129 == node || current->right_2311102129 == node)
        {
            parent = current;
            break;
        }

        if (current->left_2311102129 != nullptr)
        {
            q.push(current->left_2311102129);
        }
        if (current->right_2311102129 != nullptr)
        {
            q.push(current->right_2311102129);
        }
    }

    if (parent == nullptr)
    {
        cout << "Node tidak ditemukan." << endl;
        return;
    }

    if (parent->left_2311102129 != nullptr && parent->left_2311102129 != node)
    {
        cout << "Sibling: " << parent->left_2311102129->data_2311102129 << endl;
    }
    else if (parent->right_2311102129 != nullptr && parent->right_2311102129 != node)
    {
        cout << "Sibling: " << parent->right_2311102129->data_2311102129 << endl;
    }
    else
    {
        cout << "Node tidak memiliki sibling." << endl;
    }
}

// Fungsi untuk melakukan traversal (preorder, inorder, postorder) dan menampilkan sibling
void traversalAndSibling(Pohon *node)
{
    cout << "PreOrder: ";
    if (node == nullptr)
    {
        cout << "Tree kosong" << endl;
    }
    else
    {
        PreOrder(node);
    }
    cout << endl;

    cout << "InOrder: ";
    if (node == nullptr)
    {
        cout << "Tree kosong" << endl;
    }
    else
    {
        InOrder(node);
    }
    cout << endl;

    cout << "PostOrder: ";
    if (node == nullptr)
    {
        cout << "Tree kosong" << endl;
    }
    else
    {
        PostOrder(node);
    }
    cout << endl;

    sibling(node);
}
// Fungsi untuk menampilkan child dari sebuah node
void tampilkanChild(Pohon *node)
{
    if (node == nullptr)
    {
        cout << "Node tidak ditemukan!" << endl;
        return;
    }

    if (node->left_2311102129 != nullptr)
    {
        cout << "Child kiri: " << node->left_2311102129->data_2311102129 << endl;
    }
    else
    {
        cout << "Child kiri: (tidak punya child kiri)" << endl;
    }

    if (node->right_2311102129 != nullptr)
    {
        cout << "Child kanan: " << node->right_2311102129->data_2311102129 << endl;
    }
    else
    {
        cout << "Child kanan: (tidak punya child kanan)" << endl;
    }
}

// Fungsi untuk menghapus seluruh subtree dari sebuah node
void deleteSubtree(Pohon *&node)
{
    if (node == nullptr)
    {
        return;
    }
    // Hapus seluruh subtree dari anak kiri dan anak kanan secara rekursif
    deleteSubtree(node->left_2311102129);
    deleteSubtree(node->right_2311102129);
    // Setiap node dihapus dari memori
    delete node;
    node = nullptr;
}
void retrieve(Pohon *node)
{
    if (node != nullptr)
    {
        cout << "Data node: " << node->data_2311102129 << endl;
    }
    else
    {
        cout << "Node tidak ditemukan!" << endl;
    }
}
// Fungsi untuk menghapus sebuah node
void deleteNode(char data, Pohon *&node)
{
    if (node == nullptr)
    {
        return;
        // Jika data node sesuai dengan yang dicari
        if (node->data_2311102129 == data)
        {
            // Jika node tidak memiliki anak
            if (node->left_2311102129 == nullptr && node->right_2311102129 == nullptr)
            {
                delete node;
                node = nullptr;
                cout << "Node " << data << " berhasil dihapus." << endl;
            }
            else
            {
                // Jika node memiliki anak, panggil fungsi deleteSubtree untuk menghapus subtree
                deleteSubtree(node);
                node = nullptr;
                cout << "Node " << data << " beserta subtree berhasil dihapus." << endl;
            }
            return;
        }

        // Pencarian dilanjutkan ke anak kiri dan anak kanan
        deleteNode(data, node->left_2311102129);
        deleteNode(data, node->right_2311102129);
    }
}
// Fungsi untuk menampilkan detail sebuah node dan parent, sibling, dan child-nya
void find(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        }
        else
        {
            cout << "\n Data Node : " << node->data_2311102129 << endl;

            // Mencari parent
            Pohon *parent = nullptr;
            Pohon *current = root_2311102129;
            queue<Pohon *> q;
            q.push(current);

            while (!q.empty())
            {
                current = q.front();
                q.pop();

                if (current->left_2311102129 == node || current->right_2311102129 == node)
                {
                    parent = current;
                    break;
                }

                if (current->left_2311102129 != nullptr)
                {
                    q.push(current->left_2311102129);
                }
                if (current->right_2311102129 != nullptr)
                {
                    q.push(current->right_2311102129);
                }
            }

            // Menampilkan parent
            if (parent != nullptr)
            {
                cout << " Parent : " << parent->data_2311102129 << endl;
            }
            else
            {
                cout << " Parent : (tidak punya parent)" << endl;
            }

            // Menampilkan sibling
            if (parent != nullptr)
            {
                if (parent->left_2311102129 == node)
                {
                    if (parent->right_2311102129 != nullptr)
                        cout << " Sibling : " << parent->right_2311102129->data_2311102129 << endl;
                    else
                        cout << " Sibling : (tidak punya sibling)" << endl;
                }
                else if (parent->right_2311102129 == node)
                {
                    if (parent->left_2311102129 != nullptr)
                        cout << " Sibling : " << parent->left_2311102129->data_2311102129 << endl;
                    else
                        cout << " Sibling : (tidak punya sibling)" << endl;
                }
            }
            else
            {
                cout << " Sibling : (tidak punya sibling)" << endl;
            }

            // Menampilkan child kiri
            if (!node->left_2311102129)
                cout << " Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << " Child Kiri : " << node->left_2311102129->data_2311102129 << endl;

            // Menampilkan child kanan
            if (!node->right_2311102129)
                cout << " Child Kanan : (tidak punya Child kanan)" << endl;
            else
                cout << " Child Kanan : " << node->right_2311102129->data_2311102129 << endl;
        }
    }
}

// Fungsi untuk mencari level dari sebuah node dalam tree
void findLevel(Pohon *node, char data, int level)
{
    if (node == nullptr)
    {
        return;
    }

    // Jika data node ditemukan, tampilkan levelnya
    if (node->data_2311102129 == data)
    {
        cout << "Level node: " << level << endl;
        return;
    }

    // Pencarian dilanjutkan ke anak kiri dan anak kanan dengan meningkatkan level
    findLevel(node->left_2311102129, data, level + 1);
    findLevel(node->right_2311102129, data, level + 1);
}

// Fungsi untuk menghitung jumlah node dalam tree (size)
int size(Pohon *node = root_2311102129)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            // Jumlah node dihitung dengan rekursif pada anak kiri dan anak kanan
            return 1 + size(node->left_2311102129) + size(node->right_2311102129);
        }
    }
}

// Fungsi untuk menghitung tinggi (height) dari tree
int height(Pohon *node = root_2311102129)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            // Tinggi tree dihitung dengan mencari tinggi maksimum dari anak kiri dan anak kanan
            int heightKiri = height(node->left_2311102129);
            int heightKanan = height(node->right_2311102129);
            if (heightKiri >= heightKanan)
            {
                return heightKiri + 1;
            }
            else
            {
                return heightKanan + 1;
            }
        }
    }
}

// Fungsi untuk menampilkan karakteristik dari tree (size, height, rata-rata node per level)
void characteristic()
{
    cout << "Size Tree : " << size() << endl;
    cout << "Height Tree : " << height() << endl;
    cout << "Average Node of Tree : " << size() / height() << endl;
}

// Fungsi utama
int main()
{
    // variable pilihan data parent data parent node dan selected node
    int pilihan;
    char data, parentData;
    Pohon *parentNode;
    Pohon *selectedNode;
    // Inisialisasi tree
    init();

    do
    {
        // menu
        cout << "\nMenu:\n";
        cout << "1. Buat Root\n";
        cout << "2. Insert Left\n";
        cout << "3. Insert Right\n";
        cout << "4. Update\n";
        cout << "5. Retrieve\n";
        cout << "6. Tampilkan Descendant\n";
        cout << "7. Tampilkan Ascending\n";
        cout << "8. Traversal (preorder, inorder, postorder, sibling)\n";
        cout << "9. Delete Node\n";
        cout << "10. Find Level\n";
        cout << "11. Karateristik\n";
        cout << "12. Detail tree\n";
        cout << "13. Node child\n";
        cout << "14. Exit\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan)

        {
        case 1:
            // Membuat root node
            cout << "Masukkan data root: ";
            cin >> data;
            buatNode(data);
            break;

        case 2:
            // Mencari parent node
            cout << "Masukkan data parent: ";
            cin >> parentData;
            parentNode = find(parentData);
            if (parentNode == nullptr)
            {
                cout << "Node parent tidak ditemukan!" << endl;
                break;
            }
            // Menambahkan node sebagai anak kiri
            cout << "Masukkan data node: ";
            cin >> data;
            insertLeft(data, parentNode);
            break;

        case 3:
            // Mencari parent node
            cout << "Masukkan data parent: ";
            cin >> parentData;
            parentNode = find(parentData);
            if (parentNode == nullptr)
            {
                cout << "Node parent tidak ditemukan!" << endl;
                break;
            }
            // Menambahkan node sebagai anak kanan
            cout << "Masukkan data node: ";
            cin >> data;
            insertRight(data, parentNode);
            break;

        case 4:
            // Memperbarui data node
            cout << "Masukkan data node yang ingin diupdate: ";
            cin >> data;
            update(data, root_2311102129);
            break;

        case 5:
            // Mendapatkan data node
            cout << "Masukkan data node yang ingin diretrieve: ";
            cin >> data;
            retrieve(find(data));
            break;

        case 6:
            // Menampilkan descendant dari sebuah node
            cout << "Masukkan data node: ";
            cin >> data;
            selectedNode = find(data);
            if (selectedNode == nullptr)
            {
                cout << "Node tidak ditemukan." << endl;
            }
            else
            {
                cout << "Descendant dari node " << data << ": ";
                tampilkanDescendant(selectedNode);
                cout << endl;
            }
            break;

        case 7:
            // Menampilkan data secara ascending
            tampilkanAscending(root_2311102129);
            cout << endl;
            break;

        case 8:
            // Menampilkan traversal (preorder, inorder, postorder) dan sibling
            cout << "Masukkan data node yang ingin ditampilkan traversal dan siblingnya: ";
            cin >> data;
            selectedNode = find(data);
            if (selectedNode == nullptr)
            {
                cout << "Node tidak ditemukan." << endl;
            }
            else
            {
                cout << "Traversal dan Sibling dari node " << data << ":\n";
                traversalAndSibling(selectedNode);
            }
            break;

        case 9:
            // Menghapus sebuah node
            cout << "Masukkan data node yang ingin dihapus: ";
            cin >> data;
            deleteNode(data, root_2311102129);
            break;

        case 10:
            // Mencari level dari sebuah node
            cout << "Masukkan data node yang ingin dicari levelnya: ";
            cin >> data;
            findLevel(root_2311102129, data, 1);
            break;

        case 11:
            // Menampilkan karakteristik dari tree
            cout << "Detail Tree : " << endl;
            characteristic();
            break;

        case 12:
            // Menampilkan detail sebuah node beserta parent, sibling, dan child-nya
            cout << "Masukkan data node : ";
            cin >> data;
            cout << "Detail tree dari node " << data << " adalah : " << endl;
            find(find(data));
            break;
        case 13:
            // Menampilkan child dari sebuah node
            cout << "Masukkan data node: ";
            cin >> data;
            selectedNode = find(data);
            if (selectedNode == nullptr)
            {
                cout << "Node tidak ditemukan." << endl;
            }
            else
            {
                tampilkanChild(selectedNode);
            }
            break;

        case 14:
            cout << "Keluar dari program.\n";
            break;

        default:
            cout << "Pilihan tidak valid!\n";
            break;
        }
    } while (pilihan != 14);

    return 0;
}
