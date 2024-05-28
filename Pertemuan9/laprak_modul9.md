# <h1 align="center">Laporan Praktikum Modul 9 GRAPH DAN TREE</h1>

<h1 align="center">Hamid Sabirin-2311102129</h1>

## Dasar Teori

<h2 align="center">GRAPH DAN TREE</h2>

A. Tree (Pohon)

Tree (pohon) adalah jenis struktur data yang terdiri dari simpul-simpul (nodes) yang saling terhubung (edges) secara hierarkis atau membentuk Graph terhubung yang tidak memiliki sirkuit. Pohon dapat didefinisikan sebagai kumpulan elemen di mana salah satu elemennya disebut sebagai Akar (Root), sedangkan elemen-elemen lainnya (Simpul) terbagi menjadi himpunan-himpunan yang saling tidak berhubungan yang disebut Subpohon (Subtree) atau cabang. Dalam implementasinya, nodes mewakili data, sementara edges merupakan jalur atau lintasan yang menghubungkan antara nodes. Secara mendasar, pohon digunakan untuk merepresentasikan data dengan hierarki, seperti struktur perusahaan, struktur keluarga, struktur direktori pada sistem file komputer, atau masalah lain yang melibatkan pembagian dan percabangan.

a. Jenis jenis Tree :

Binary Tree adalah tree atau pohon yang hanya boleh memiliki maksimal dua subtree dan kedua subtree tersebut harus terpisah. Sesuai dengan definisi tersebut tiap node dalam binary tree hanya boleh memiliki paling banyak dua child.

b. Jenis-Jenis Binary Tree :

1. Full BinaryTree
   Jenis binary tree ini tiap nodenya (kecuali leaf) memiliki dua child dan tiap subtree harus mempunyai panjang path yang sama.
2. Complete BinaryTree
   Jenis ini mirip dengan Full BinaryTree, namun tiap subtree boleh memiliki panjang path yang berbeda dan setiap node kecuali leaf hanya boleh memiliki 2 child.
3. Skewed BinaryTree
   Skewed BinaryTree adalah BinaryTree yang semua nodenya (kecuali leaf) hanya memiliki satu child.
4. Implementasi BinaryTree
   Binarytree dapat diimplementasikan dalam C++ dengan menggunakan double linkedlist

c. Istilah Pada tree :

1. Predesesor  
   Node yang berada diatas node tertentu.
2. Succesor  
   Node yang berada dibawah node tertentu.
3. Ancestor  
   Seluruh node yang terletak sebelum node tertentu dan terletak pada jalur yang sama.
4. Descendant  
   Seluruh node yang terletak sesudah node tertentu dan terletak pada jalur yang sama.
5. Parent  
   Predesesor satu level diatas satu node.
6. Child  
   Succesor satu level dibawah satu node.
7. Sibling  
   Node yang memiliki parent yang sama dengan satu node.
8. Subtree  
   Bagian dari tree yang berupa suatu node beserta descendant-nya.
9. Size  
   Banyaknya node dalam suatu tree.
10. Height  
    Banyaknya tingkat/level dalam suatu tree (contoh tinggi tree height 4)
11. Root (akar)
    Node dalam tree yang tidak memiliki predessor.
12. Leaf (daun)
    Node dalam tree yang tidak memiliki daun.
13. Degree (derajat)
    Banyaknya child yang memiliki suatu node.

d. Operasi pada tree :

1. Create
   membentuk sebuah tree baru yang kosong.
2. Clear
   menghapus semua elemen tree.
3. Empty
   mengetahui apakah tree kosong atau tidak.
4. Insert
   menambah node ke dalam Tree secara rekursif. Jika data yang akan dimasukkan lebih besar daripada elemen root, maka akan diletakkan di node sebelah kanan, sebaliknya jika lebih kecil maka akan diletakkan di node sebelah kiri. Untuk data pertama akan menjadi elemen root.
5. Find
   mencari node di dalam Tree secara rekursif sampai node tersebut ditemukan dengan menggunakan variable bantuan ketemu. Syaratnya adalah tree tidak boleh kosong.
6. Traverse
   yaitu operasi kunjungan terhadap node-node dalam pohon dimana masing-masing node akan dikunjungi sekali.
7. Count
   menghitung jumlah node dalam Tree.
8. Height
   mengetahui kedalaman sebuah Tree
9. Find Min dan Find Max
   mencari nilai terkecil dan terbesar pada Tree
10. Child
    mengetahui anak dari sebuah node (jika punya)

B. Graph
Graf merupakan kumpulan noktah (simpul) dalam bidang dua dimensi yang terhubung oleh serangkaian garis (sisi). Graph dapat digunakan untuk merepresentasikan objek-objek diskrit dan hubungan antara objek-objek tersebut. Representasi visual dari graf dilakukan dengan menyatakan objek sebagai noktah, bulatan, atau titik (Vertex), sementara hubungan antara objek diwakili oleh garis (Edge).

a. Istilah pada Graph :

1. Vertex
   Vertex merupakan himpunan node/titik pada sebuah graph.
2. Edge
   Edge merupakan sebuah himpunan garis yang menghubungkan tiapnode/vertex.
3. Adjacent
   Adjacent adalah sebuah Dua buah titik dikatakan berdekatan (adjacent) jika keduanya terhubung dengan sebuah sisi.
4. Weight
   Weight merupakan Sebuah graph G = (V, E) disebut sebuah graph berbobot (weight graph) apabila terdapat sebuah fungsi bobot bernilai real W pada himpunan E,
5. Path
   Path adalah sebuah jalur yang setiap vertex itu berbeda
6. Cycle
   Cycle circuit merupakan lintasan yang berawal dan berakhir pada simpul yang sama.

b. jenis graph :

1. Graf Tak-Berarah (Undirected Graph)
   Graf yang sisinya tidak mempunyai orientasi arah disebut graf tak terarah. Pada graf tak berarah, urutan pasangan simpul yang dihubungkan oleh sisi tidak diperhatikan
2. Graf Berarah (Dirrected Graph atau Digraph)
   Graf yang setiap sisinya diberikan orientasi arah disebut sebagai graf berarah. Pada graf berarah menyatakan sisi berarah yang berbed.
3. Graph Berbobot (Weighted Graph)
   Jika setiap busur mempunyai nilai yang menyatakan hubungan antara dua buah simpul, maka busur tersebut dinyatakan memiliki bobot. Bobot sebuah busur dapat menyatakan panjang sebuah jalan dari dua buah titik, jumlah rata-rata kendaraan per hari yang melalui sebuah jalan, dan lain-lain

## Guided

### 1. [Program Graph.]

```C++
#include <iostream>
#include <iomanip>
using namespace std;

// variable untuk menampung sebuah data simpul yang isinya berupa kota yang di dalam array berjumlahkan 7 kota
string simpul[7] = {"ciamis", "Bandung", "Bekasi", "Tasikmalaya", "Cianjur", "Purwokerto", "Yogyakarta"};

// variable sebuah arrray 2 dimensi yang berisikan 7 baris dan 7 kolom yang berisikan nilai angka integer
int busur[7][7] = {
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 0, 15, 0},
    {0, 6, 0, 0, 6, 0, 0},
    {0, 5, 0, 0, 2, 4, 0},
    {23, 0, 0, 10, 0, 0, 8},
    {0, 0, 0, 0, 7, 0, 3},
    {0, 0, 0, 0, 9, 4, 0},
};

// fungsi utama untuk menampilkan graph yang telah di buat pada fungsi di atas
int main()
{
    tampilGraph();
    return 0;
}
```

=> Penjelasan program

- Kode di atas merupakan implementasi sederhana dari representasi graf dalam bentuk matriks berbobot. Terdapat dua variabel yang digunakan: `simpul` yang berisi nama-nama simpul atau kota, dan `busur` yang merupakan matriks berisi bobot-bobot antar simpul. Setiap baris dan kolom pada matriks `busur` mewakili simpul, dan nilai pada setiap sel matriks menunjukkan bobot dari busur yang menghubungkan dua simpul. Fungsi `tampilGraph()` yang tidak terdefinisi dalam kode akan bertanggung jawab untuk menampilkan graf yang terbentuk berdasarkan matriks bobot. Sebagai contoh, jika kita ingin mengetahui bobot dari busur yang menghubungkan simpul "Bandung" dan "Bekasi", kita akan mencari nilai pada `busur[1][2]`, yang akan mengembalikan nilai 5, menunjukkan bahwa terdapat busur dengan bobot 5 antara kedua kota tersebut.

### 2. [Program Tree.]

```C++
#include <iostream>
#include <iomanip>
using namespace std;

// struct pohon untuk menampung sebuah data
struct Pohon
{
    char data;
    Pohon *left;
    Pohon *right;
    Pohon *parent;
};

// fungsi root dan baru
Pohon *root, *baru;
// prosedur fungsi untuk init bahwa root itu kosong
void init()
{
    root = NULL;
}
// fungsi untuk mengecek bahwa root itu kosong atau tidak
bool isEmpty()
{
    return root == NULL;
}
// fungsi untuk membuat sebuah node
void buatNode(char data)
{
    if (isEmpty())
    {
        root = new Pohon();
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "\n Node " << data << " berhasil dibuat sebagai root." << endl;
    }
    else
    {
        cout << "\n Tree sudah ada!" << endl;
    }
}
// insert data bagian child kiri kedalam node parent
Pohon *insertLeft(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->left != NULL)
        {
            cout << "\n Node " << node->data << " sudah ada child kiri !" << endl;
            return NULL;
        }
        else
        {
            Pohon *baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->left = baru;
            cout << "\n Node " << data << " berhasil ditambahkan ke child kiri " << baru->parent->data << endl;
            return baru;
        }
    }
}
// insert data bagian child kanan kedalam node parent
Pohon *insertRight(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->right != NULL)
        {
            cout << "\n Node " << node->data << " sudah ada child kanan !" << endl;
            return NULL;
        }
        else
        {
            Pohon *baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->right = baru;
            cout << "\n Node " << data << " berhasil ditambahkan ke child kanan " << baru->parent->data << endl;
            return baru;
        }
    }
}
// fungsi untuk mengupdate sebuah node
void update(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\n Node yang ingin diganti tidak ada!!" << endl;
        }
        else
        {
            char temp = node->data;
            node->data = data;
            cout << "\n Node " << temp << " berhasil diubah menjadi "
                 << data << endl;
        }
    }
}
// fungsi untuk mengambil sebuah node
void retrieve(Pohon *node)
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
            cout << "\n Data node : " << node->data << endl;
        }
    }
}
// fungsi untuk mencari sebuah node
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
            cout << "\n Data Node : " << node->data << endl;
            cout << " Root : " << root->data << endl;
            if (!node->parent)

                else cout << " Parent : (tidak punya parent)" << endl;
            cout << " Parent : " << node->parent->data << endl;
            if (node->parent != NULL && node->parent->left != node &&
                node->parent->right == node)
                cout << " Sibling : " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << " Sibling : " << node->parent->right->data << endl;
            else
                cout << " Sibling : (tidak punya sibling)" << endl;
            if (!node->left)
                cout << " Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << " Child Kiri : " << node->left->data << endl;
            if (!node->right)
                cout << " Child Kanan : (tidak punya Child kanan)" << endl;
            else
                cout << " Child Kanan : " << node->right->data << endl;
        }
    }
}
// fungsi untuk
void preOrder(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node != NULL)
        {
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}
// fungsi untuk mencetak node sekarang dan mencetak subtree kiri dan kanan
void inOrder(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node != NULL)
        {
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}
// fungsi untuk mencetak subtree kiri dan mencetak node sekarang dan mencetak subtree kanan
void postOrder(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node != NULL)
        {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}
// mencetak subtree kiri dan kanan dan mencetak node sekarang
void deleteTree(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node != NULL)
        {
            if (node != root)
            {
                node->parent->left = NULL;
                node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);
            if (node == root)
            {
                delete root;
                root = NULL;
            }
            else
            {
                delete node;
            }
        }
    }
}
// fungsi untuk menghapus subtree
void deleteSub(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\n Node subtree " << node->data << " berhasil dihapus." << endl;
    }
}
// fungsi untuk menghapus semua data tree
void clear()
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!!" << endl;
    }
    else
    {
        deleteTree(root);
        cout << "\n Pohon berhasil dihapus." << endl;
    }
}
// Cek Size Tree
int size(Pohon *node = root)
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
            return 1 + size(node->left) + size(node->right);
        }
    }
}
// Cek Height Level Tree
int height(Pohon *node = root)
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
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);
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
// Karakteristik Tree
void characteristic()
{
    cout << "\n Size Tree : " << size() << endl;
    cout << " Height Tree : " << height() << endl;
    cout << " Average Node of Tree : " << size() / height() << endl;
}
int main()
{
    // buat node a
    buatNode('A');
    Pohon *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeI, *nodeJ;
    // insert data left dan right pada node
    nodeB = insertLeft('B', root);
    nodeC = insertRight('C', root);
    nodeD = insertLeft('D', nodeB);
    nodeE = insertRight('E', nodeB);
    nodeF = insertRight('F', nodeC);
    nodeG = insertLeft('G', nodeE);
    nodeH = insertRight('H', nodeE);
    nodeI = insertLeft('I', nodeG);
    nodeJ = insertRight('J', nodeG);
    // update node
    update('Z', nodeC);
    update('C', nodeC);
    // retrive node, mencari node dan karateristik nya sebuah tree
    retrieve(nodeC);
    find(nodeC);
    characteristic();
    // menampilkan preorder, inorder, dan postorder
    cout << "\nPreOrder : ";
    preOrder();
    cout << "\nInOrder : ";
    inOrder();
    cout << "\nPostOrder : ";
    postOrder();
    return 0;
}
```

=> Penjelasan program

- Program di atas merupakan implementasi pohon biner dalam bahasa C++, yang memanfaatkan struktur data `struct Pohon` untuk merepresentasikan setiap node dalam pohon. Program dimulai dengan mendefinisikan fungsi-fungsi dasar seperti `init()` untuk menginisialisasi pohon, `isEmpty()` untuk memeriksa apakah pohon kosong, dan `buatNode()` untuk membuat node baru sebagai root. Selain itu, terdapat fungsi-fungsi untuk menambahkan node ke anak kiri atau anak kanan (`insertLeft()` dan `insertRight()`), mengupdate data suatu node (`update()`), serta mencari dan menampilkan informasi tentang suatu node (`retrieve()` dan `find()`). Fungsi `main()` berperan sebagai titik masuk utama program, di mana pohon dibuat dan operasi-operasi dilakukan. Contohnya, dalam `main()` ini, sebuah pohon dibuat dengan root berisi data 'A', kemudian beberapa node tambahan ditambahkan ke kiri dan kanan node-node tertentu. Selanjutnya, beberapa operasi dilakukan seperti mengupdate data node, mencari dan menampilkan informasi tentang node tertentu, serta menampilkan karakteristik dari pohon seperti ukuran (jumlah node) dan tinggi pohon. Terakhir, program menampilkan traversal pre-order, in-order, dan post-order dari pohon yang telah dibentuk. Ini memberikan gambaran menyeluruh tentang cara kerja program dalam memanipulasi pohon biner dan melakukan operasi-operasi dasar pada struktur data tersebut.

## Unguided

### 1. [Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya.]

![soal1] (https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan9/assets/soal1.png)

```C++
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

// Fungsi untuk mencetak header matriks
void printHeader(const vector<string> &simpul_2311102129, int n)
{
    cout << setw(15) << " ";
    for (int i = 0; i < n; i++)
    {
        cout << setw(15) << simpul_2311102129[i];
    }
    cout << endl;
}

// Fungsi untuk mencetak baris matriks ketetanggaan
void printRows(const vector<string> &simpul_2311102129, const vector<vector<int>> &busur_2311102129, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << setw(15) << simpul_2311102129[i];
        for (int j = 0; j < n; j++)
        {
            cout << setw(15) << busur_2311102129[i][j];
        }
        cout << endl;
    }
}

// Fungsi untuk menampilkan graf berdasarkan matriks ketetanggaan
void tampilGraph(const vector<string> &simpul_2311102129, const vector<vector<int>> &busur_2311102129, int n)
{
    printHeader(simpul_2311102129, n);
    printRows(simpul_2311102129, busur_2311102129, n);
}

int main()
{
    // Mendeklarasikan variabel untuk menyimpan jumlah simpul
    int n;

    // Mencetak prompt untuk meminta input jumlah simpul
    cout << "Silakan masukkan jumlah simpul: ";

    // Membaca input jumlah simpul dari pengguna
    cin >> n;

    // Deklarasi vektor untuk menyimpan nama simpul
    vector<string> simpul(n);

    // Meminta input nama simpul dari pengguna
    for (int i = 0; i < n; i++)
    {
        cout << "Nama simpul " << i + 1 << " : ";
        cin >> simpul[i];
    }

    // Deklarasi vektor dua dimensi untuk menyimpan bobot antar simpul matriks ini akan menyimpan bobot untuk setiap pasangan simpul
    vector<vector<int>> busur(n, vector<int>(n, 0));

    // Mencetak prompt untuk meminta input bobot antar simpul
    cout << "Silakan masukkan bobot antar simpul" << endl;

    // Meminta input bobot antar simpul dari pengguna
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << simpul[i] << "--> " << simpul[j] << " = ";
            cin >> busur[i][j];
        }
    }

    // Memanggil fungsi tampilGraph untuk menampilkan representasi matriks ketetanggaan dari graf yang telah diinput
    tampilGraph(simpul, busur, n);

    return 0;
}

```

### Output :

<h2>Menghitung Jarak kota ke kota lainya</h2>

![soal 1](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan9/assets/unguided2.png)

=> Penjelasan Program

- Program di atas adalah program C++ yang memungkinkan pengguna untuk memasukkan jumlah simpul dan bobot antar simpul dari sebuah graf, dan kemudian menampilkan representasi matriks ketetanggaan dari graf tersebut. Pertama-tama, program meminta pengguna untuk memasukkan jumlah simpul dan nama-nama simpul. Ini dilakukan dengan menggunakan vektor simpul untuk menyimpan nama-nama simpul. Selanjutnya, program meminta pengguna untuk memasukkan bobot antar simpul menggunakan vektor dua dimensi busur yang menyimpan bobot untuk setiap pasangan simpul. Setelah semua input diterima, fungsi tampilGraph dipanggil untuk menampilkan matriks ketetanggaan yang menggambarkan graf berdasarkan input pengguna. Fungsi printHeader digunakan untuk mencetak header matriks dengan menggunakan nama-nama simpul. Fungsi printRows mencetak baris matriks dengan nama simpul di awal setiap baris dan bobot antar simpul di sel-sel matriks. Fungsi tampilGraph memanggil kedua fungsi tersebut untuk menampilkan matriks ketetanggaan secara keseluruhan. Cara kerja program ini adalah dengan meminta input pengguna untuk jumlah simpul, nama-nama simpul, dan bobot antar simpul. Setelah itu, program akan menampilkan matriks ketetanggaan yang merepresentasikan graf berdasarkan input pengguna. Dengan demikian, pengguna dapat memvisualisasikan hubungan antar simpul dalam graf menggunakan representasi matriks ketetanggaan.

#### Full code Screenshot:

![Full_ss_code_unguided1](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan9/assets/ssfull_unguided2.png)

### 2. [Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan berikan fungsi tambahan untuk menampilkan node child dan descendant dari node yang diinput kan!]

```C++
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
        cout << "13. Exit\n";
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
            tampilkanDescendant(find(data));
            cout << endl;
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
            cout << "Keluar dari program.\n";
            break;

        default:
            cout << "Pilihan tidak valid!\n";
            break;
        }
    } while (pilihan != 13);

    return 0;
}
```

### Output :

<h2>menampilkan node child dan descendant dari node yang diinput</h2>

![soal 2](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan9/assets/unguided1_a.png)
![soal 2](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan9/assets/unguided1_b.png)
![soal 2](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan9/assets/unguided1_c.png)
![soal 2](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan9/assets/unguided1_d.png)
![soal 2](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan9/assets/unguided1_e.png)
![soal 2](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan9/assets/unguided1_f.png)
![soal 2](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan9/assets/unguided1_g.png)
![soal 2](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan9/assets/unguided1_h.png)
![soal 2](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan9/assets/unguided1_i.png)
![soal 2](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan9/assets/unguided1_j.png)
![soal 2](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan9/assets/unguided1_k.png)
![soal 2](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan9/assets/unguided1_l.png)
![soal 2](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan9/assets/unguided1_m.png)
![soal 2](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan9/assets/unguided1_n.png)
![soal 2](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan9/assets/unguided1_o.png)
![soal 2](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan9/assets/unguided1_p.png)
![soal 2](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan9/assets/unguided1_q.png)

=> Penjelasan Program

- Program di atas adalah implementasi struktur data pohon biner menggunakan bahasa C++. Struktur data pohon biner direpresentasikan dengan struktur `Pohon`, yang memiliki pointer ke node anak kiri, anak kanan, dan parentnya. Fungsi `isEmpty()` digunakan untuk memeriksa apakah pohon kosong, sedangkan fungsi `init()` digunakan untuk menginisialisasi pohon. Fungsi `buatNode()` digunakan untuk membuat node baru, sementara `insertLeft()` dan `insertRight()` digunakan untuk menambahkan node sebagai anak kiri atau anak kanan dari suatu node tertentu. Fungsi `update()` memperbarui data suatu node, sedangkan `find()` mencari node berdasarkan datanya. Selain itu, terdapat fungsi-fungsi lain seperti `tampilkanDescendant()` untuk menampilkan semua descendant dari suatu node, `tampilkanAscending()` untuk menampilkan data secara ascending, dan `PreOrder()`, `InOrder()`, serta `PostOrder()` untuk melakukan traversal pre-order, in-order, dan post-order. Fungsi `sibling()` digunakan untuk menampilkan sibling dari suatu node, sementara `traversalAndSibling()` melakukan traversal dan menampilkan sibling suatu node. Fungsi `deleteSubtree()` digunakan untuk menghapus seluruh subtree dari suatu node, sementara `deleteNode()` digunakan untuk menghapus suatu node beserta subtree-nya. Fungsi `findLevel()` digunakan untuk mencari level dari suatu node dalam pohon, dan `size()` serta `height()` digunakan untuk menghitung jumlah node dan tinggi pohon. Fungsi `characteristic()` menampilkan karakteristik dari pohon seperti size, height, dan rata-rata node per level. Fungsi `main()` merupakan fungsi utama yang menjalankan program. Program ini menampilkan menu interaktif yang memungkinkan pengguna untuk membuat pohon, menambahkan dan menghapus node, menampilkan karakteristik pohon, dan melakukan operasi-operasi lainnya. Contohnya, pengguna dapat membuat pohon biner, menambahkan node baru, menghapus node, dan menampilkan karakteristik pohon melalui menu interaktif yang tersedia.

#### Full code Screenshot:

![Full_ss_code_unguided3](https://github.com/Hamid165/2311102129_Hamid-Sabirin/blob/main/Pertemuan9/assets/ssfull_unguided1.png)

## Kesimpulan

- Tree dan graph adalah struktur data yang penting untuk merepresentasikan hubungan hierarkis dan non-hierarkis antara elemen-elemen dalam sebuah dataset. Dalam program ini, kita dapat membuat, menambahkan, menghapus, dan memperbarui data pada pohon, serta menampilkan karakteristik pohon seperti ukuran, tinggi, dan rata-rata node per level. Selain itu, karakteristik graph seperti jumlah simpul, jumlah simpul yang terhubung, dan jumlah simpul yang terhubung secara langsung juga dapat ditampilkan. Dengan adanya pohon dan graph ini, manipulasi data dengan struktur hierarkis atau non-hierarkis dapat dilakukan dengan mudah dan efisien.

## refrensi9

[1] Rizki Muliono, Pemrograman C++ ALGORITMA & STRUKTUR DATA : 2019.

[2] Moh. Erkamim, BUKU AJAR ALGORITMA DAN STRUKTUR DATA : 2024.

[3] Triase ,STRUKTUR DATA : 2020.
