# <h1 align="center">Laporan Praktikum Modul Graph Dan Tree</h1>
<p align="center">Afan Ramadhan</p>

## Dasar Teori

Sebuah graf seperti halnya struktur data pohon adalah kumpulan objek atau entitas yang dikenal sebagai node yang terhubung satu sama lain melalui sekumpulan sisi [1]. Sebuah pohon mengikuti beberapa aturan yang menentukan hubungan antara node, sedangkan graf tidak mengikuti aturan apa pun yang mendefinisikan hubungan di antara node. Sebuah graf berisi sekumpulan sisi dan simpul, dan sisi-sisi dapat menghubungkan simpul-simpul tersebut dengan berbagai cara. Dalam Graf, setiap simpul memiliki nama atau indeks yang berbeda untuk mengidentifikasi secara unik setiap simpul dalam graf. Graf tidak memiliki simpul pertama, simpul kedua, simpul ketiga, dan seterusnya serta Tidak ada urutan node.

Struktur data pohon adalah struktur data hirarkis yang terdiri dari simpul-simpul yang dihubungkan dengan sisi-sisi. Setiap node dapat memiliki beberapa node anak, tetapi hanya satu node induk. Simpul paling atas dalam pohon disebut simpul akar. Ada berbagai macam jenis pohon diantaranya adalah Binary tree. Binary tree merupakan tree yang syaratnya setiap node hanya boleh memiliki paling banyak dua subtree, dan kedua subtree tersebut harus dipisahkan. Dengan definisi ini, setiap node di binary tree hanya dapat memiliki paling banyak dua child [1]. 

## Guided 

### 1. Program Graph

```C++
#include <iostream>
#include <iomanip>
using namespace std;

string simpul[7] = {
    "Ciamis",
    "Bandung",
    "Bekasi",
    "Tasikmalaya",
    "Cianjur",
    "Purwokerto",
    "Yogyakarta"
};

int busur[7][7] = {
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 9, 15, 0},
    {0, 5, 0, 9, 5, 0, 0},
    {0, 0, 0, 2, 4, 0, 8},
    {3, 0, 0, 1, 0, 0, 0},
    {0, 0, 7, 0, 0, 9, 4},
    {0, 0, 0, 0, 8, 0, 0}
};

void tampilGraph() {
    for (int baris = 0; baris < 7; baris++) {
        cout << simpul[baris] << ": ";
        for (int kolom = 0; kolom < 7; kolom++) {
            if (busur[baris][kolom] != 0) {
                cout << " -> " << simpul[kolom] << "(" << busur[baris][kolom] << ")";
            }
        }
        cout << endl;
    }
}

int main() {
    tampilGraph();
    return 0;
}
```
Kode di atas merupakan progam graph yang menampilkan jarak antar kota dengan bobot tertentu. Pada bagian awal, mendeklarasikan array 'simpul' yang berisi 7 nama kota dan array 2 dimensi 'busur' yang mempresentasikan jarak antar kota. Kemudian membuat fungsi 'tampilgraph' yang berguna untuk menampilkan bobot busur untuk setiap kota. Karena array 'busur' merupakan array 2 dimensi maka digunakan nested loop untuk menampilkan seleruh nilai yang terkandung dalam array tersebut. Pada fungsi main, memanggil fungsi 'tampilgraph' yang sudah dideklarasikan tadi sehingga akan menampilkan graph berbobot yang menghubungkan antar kota.  

### 2. Program Tree

```C++
#include <iostream>
using namespace std;

struct pohon {
    pohon* kanan;
    char data;
    pohon* kiri;
};

// deklarasi variabel global
pohon* simpul;
pohon* root;
pohon* saatini;
pohon* helperA;
pohon* helperB;
pohon* alamat[256];

// Fungsi untuk inisialisasi root
void inisialisasi() {
    root = nullptr;
    for(int i = 0; i < 256; i++) {
        alamat[i] = nullptr;
    }
}

// membuat simpul baru
void simpulbaru(char dataMasukan) {
    simpul = new pohon;
    simpul->data = dataMasukan;
    simpul->kanan = nullptr;
    simpul->kiri = nullptr;
}

// fungsi untuk membuat simpul akar
void simpulakar() {
    if (root == nullptr) {
        char dataAnda;
        cout << "Silahkan masukan data: ";
        cin >> dataAnda;
        simpulbaru(dataAnda);
        root = simpul;
        cout << "Root terbentuk..." << endl;
    }
    else {
        cout << "Root sudah ada..." << endl;
    }
}

// fungsi untuk menambah simpul
void tambahsimpul() {
    if (root != nullptr) {
        int i = 1, j = 1, penanda = 0;
        char dataUser;
        alamat[i] = root;

        while (penanda == 0 && j < 256) {
            cout << "Masukan data kiri: ";
            cin >> dataUser;
            if (dataUser != '0') {
                simpulbaru(dataUser);
                saatini = alamat[i];
                saatini->kiri = simpul;
                j++;
                alamat[j] = simpul;
            }
            else {
                penanda = 1;
                j++;
                alamat[j] = nullptr;
            }
            if (penanda == 0) {
                cout << "Masukan data kanan: ";
                cin >> dataUser;
                if (dataUser != '0') {
                    simpulbaru(dataUser);
                    saatini = alamat[i];
                    saatini->kanan = simpul;
                    j++;
                    alamat[j] = simpul;
                }
                else {
                    penanda = 1;
                    j++;
                    alamat[j] = nullptr;
                }
            }
            i++;
        }
    }
}

// fungsi untuk membaca pohon
void bacaPohon() {
    if (root != nullptr) {
        int i = 1, n = 1, pencacah = 0;
        cout << endl;
        while (alamat[i] != nullptr) {
            saatini = alamat[i];
            cout << saatini->data << " ";
            pencacah++;
            if (pencacah == n) {
                cout << endl;
                pencacah = 0;
                n = n * 2;
            }
            i++;
        }
    }
}

// fungsi utama
int main() {
    inisialisasi();
    simpulakar();
    tambahsimpul();
    bacaPohon();
    return 0;
}
```

Code diatas digunakan untuk merepresentasikan binary tree yang memungkinkan user untuk menambahkan data dan menampilkan pohon biner tersebut. Pada bagian awal progam, mendeklarasikan struktur pohon biner yang dimana setiap simpul memiliki 2 child kanan dan kiri. Kemudian mendeklarasikan variabel global seperti root, simpul, dan array untuk menyimpan pointer ke simpul pohon. Selanjutnya mendeklarasikan beberapa fungsi seperti fungsi 'inisialisasi' untuk menginisialisasi root dengan nilai null, fungsi 'simpulbaru' untuk membuat simpul baru, fungsi 'simpulakar' untuk membuat akar phon jika root bernilai null, fungsi 'tambahsimpul' untuk menambahkan simpul ke pohon, dan fungsi 'bacapohon' untuk menampilkan pohon secara tranversal level-order. Pada fungsi utama, memanggil semua fungsi yang sudah diinisialisasi tadi yang dimulai dari inisialisasi, pembuatan simpul akar, penambahan simpul, dan membaca pohon.

## Unguided 

### 1. Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya.

```C++
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // menentukan jumlah simpul
    int jumlah;
    cout << "Silahkan masukan jumlah simpul: ";
    cin >> jumlah;
    if (jumlah <= 0) {
        cout << "Jumlah simpul harus lebih dari 0!" << endl;
        return -1;
    }
    cout << endl;

    // memasukan data kedalam simpul
    string simpul[jumlah];
    cout << "Silahkan masukan nama simpul" << endl;
    for (int i=0; i < jumlah; i++) {
        cout << "Simpul " << (i+1) << " : ";
        cin >> simpul[i];
    }
    cout << endl;

    // memasukan bobot busur
    int busur[jumlah][jumlah];
    cout << "Silahkan masukan bobot antar simpul" << endl;
    for (int baris=0; baris < jumlah; baris++) {
        for (int kolom=0; kolom < jumlah; kolom++) {
            cout << simpul[baris] << " --> " << simpul[kolom] << " = "; 
            cin >> busur[baris][kolom];
        }

    }
    cout << endl;

    // menampilkan bobot busur pada setiap simpul
    cout << setw(5) << ' ';
    for (int i=0; i < jumlah; i++) {
        cout << setw(7) << right << simpul[i];
    }
    cout << endl;
    for (int baris=0; baris < jumlah; baris++) {
            cout << setw(5) << left << simpul[baris]; 
        for (int kolom=0; kolom < jumlah; kolom++) {
            cout << setw(7) << right <<busur[baris][kolom];
        }
        cout << endl;
    }

    return 0;
}
```

#### Output:
![Screenshot (331)](https://github.com/pan-don/Struktur_Data_Assigment/assets/157208689/519c6ed1-af9d-46fc-a9e7-2af093c234c5)

Kode di atas merupakan progam graph jarak antrakota dengan bobot tertentu menggunakan inputan user. Pada bagian awal progam, mendeklarasikan banyak simpul yang yang merepresentasikan jumlah kota dalam graf dan digunakan untuk mendeklarasikan array 'simpul'. Selanjutnya memasukan nama kota kedalam array 'simpul'. Kemudian mendeklarasikan array 2 dimensi dengan nama 'busur' yang digunakan untuk menentukan bobot busur antar simpul. Terakhir menampilkan graf denganbantuan library ionmanip dan nested loop sehingga simpul dan busur dapat ditampilkan menjadi seperti tabel.   

### 2. Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan tampilkan pada pre-order, inorder, dan post order!

```C++
#include <iostream>
using namespace std;

// deklarasi struck pohon
struct pohon {
    pohon* kanan;
    char data;
    pohon* kiri;
};

// deklarasi variabel global
pohon* simpul;
pohon* root;
pohon* saatini;
pohon* helperA;
pohon* helperB;
pohon* alamat[256];

// Fungsi untuk inisialisasi root
void inisialisasi() {
    root = nullptr;
    for(int i = 0; i < 256; i++) {
        alamat[i] = nullptr;
    }
}

// membuat simpul baru
void simpulbaru(char dataMasukan) {
    simpul = new pohon;
    simpul->data = dataMasukan;
    simpul->kanan = nullptr;
    simpul->kiri = nullptr;
}

// fungsi untuk membuat simpul akar
void simpulakar() {
    if (root == nullptr) {
        char dataAnda;
        cout << "Silahkan masukan data: ";
        cin >> dataAnda;
        simpulbaru(dataAnda);
        root = simpul;
        cout << "Root terbentuk..." << endl;
    }
    else {
        cout << "Root sudah ada..." << endl;
    }
}

// fungsi untuk menambah simpul
void tambahsimpul() {
    if (root != nullptr) {
        int i = 1, j = 1, penanda = 0;
        char dataUser;
        alamat[i] = root;

        while (penanda == 0 && j < 256) {
            cout << "Masukan data kiri untuk " << alamat[i]->data << "\t: ";
            cin >> dataUser;
            if (dataUser != '0') {
                simpulbaru(dataUser);
                saatini = alamat[i];
                saatini->kiri = simpul;
                j++;
                alamat[j] = simpul;
            }
            else {
                penanda = 1;
                j++;
                alamat[j] = nullptr;
            }
            if (penanda == 0) {
                cout << "Masukan data kanan untuk " << alamat[i]->data << "\t: ";
                cin >> dataUser;
                if (dataUser != '0') {
                    simpulbaru(dataUser);
                    saatini = alamat[i];
                    saatini->kanan = simpul;
                    j++;
                    alamat[j] = simpul;
                }
                else {
                    penanda = 1;
                    j++;
                    alamat[j] = nullptr;
                }
            }
            i++;
        }
    }
}

// fungsi untuk membaca pohon
void bacaPohon() {
    if (root != nullptr) {
        int i = 1, n = 1, pencacah = 0;
        cout << endl;
        cout << "Menampilkan Pohon" << endl;
        while (alamat[i] != nullptr) {
            saatini = alamat[i];
            cout << saatini->data << " ";
            pencacah++;
            if (pencacah == n) {
                cout << endl;
                pencacah = 0;
                n = n * 2;
            }
            i++;
        }
    }
}

// fungsi pre-order
void PreOrder(pohon* node) {
    if (node == nullptr) {
        return;
    }
    cout << node->data << ' ';
    PreOrder(node->kiri);
    PreOrder(node->kanan);
}

// fungsi in-order
void InOrder(pohon* node) {
    if (node == nullptr) {
        return;
    }
    InOrder(node->kiri);
    cout << node->data << ' ';
    InOrder(node->kanan);
}

// fungsi post order
void PostOrder(pohon* node) {
    if (node == nullptr) {
        return;
    }
    PostOrder(node->kiri);
    PostOrder(node->kanan);
    cout << node->data << ' ';
}

// fungsi utama
int main() {
    // input data ke dalam tree 
    inisialisasi();
    simpulakar();
    tambahsimpul();
    
    // menampilkan struktur tree
    bacaPohon();
    
    // menampilkan node dalam tree secara pre-order
    cout << "\nTranvese Pre-Order" << endl;
    PreOrder(root);
    
    // menampilkan node dalam tree secara in-order
    cout << "\n\nTranvese In-Order" << endl;
    InOrder(root);
    
    // menampilkan node dalam tree secara post order
    cout << "\n\nTranvese Post Order" << endl;
    PostOrder(root);
    return 0;
}
```

#### Output:
![Screenshot (332)](https://github.com/pan-don/Struktur_Data_Assigment/assets/157208689/0a08acf2-1734-489a-a4be-e534b0892142)

Code di atas merupakan progam untuk merepresentasikan tree dan menampilkannya secara tranversal pre-order, in-order, dan post order. Pada bagian awal progam mendeklarasikan struktur pohon biner yang dimana setiap simpul memiliki 2 child kanan dan kiri. Kemudian mendeklarasikan variabel global seperti root, simpul, dan array untuk menyimpan pointer ke simpul pohon. Selanjutnya mendeklarasikan beberapa fungsi seperti fungsi 'inisialisasi', 'simpulbaru', 'simpulakar', 'tambahsimpul', dan 'bacapohon' persis seperti bahian guided hanya saja ditambahkan fungsi untuk menampilkan pohon secara pre-order, in-order, dan post order. Pada fungsi utama, memanggil semua fungsi yang sudah diinisialisasi tadi yang dimulai dari inisialisasi, pembuatan simpul akar, penambahan simpul, dan membaca pohon secara pre-order, in-order, dan post order.

## Kesimpulan

Pada dasarnya Graph dan tree termasuk kedalam struktur data non-linear. Struktur data non-linear merupakan jenis struktur data yang tidak memiliki urutan linier antar elemennya. Graph adalah kumpulan node (disebut juga simpul) dan sisi yang menghubungkannya. sedangkan tree adalah adalah struktur data hierarki yang terdiri dari node-node yang dihubungkan oleh tepian. ada berbegai macam jenis tree salah satunya adalah binary tree, yaitu pohon yang hanya memiliki 2 child pada setiap simpulnya. Pada implementasinya Graph digunakan untuk merepresentasikan hubungan antar pengguna sedangkan tree digunakan untuk merepresentasikan ekspresi aritmatika.

Graph memiliki beberapa keunggulan seperti dapat mewakili berbagai jenis hubungan kompleks, termasuk hubungan many-to-many. Sedangkan untuk Tree, sangat cocok digunakan untuk merepresentasikan data hierarkis, seperti struktur organisasi atau file sistem. Adapun untuk kelemahnnya, Graph dengan banyak node dan edge dapat membutuhkan banyak ruang penyimpanan dan untuk tree tidak dapat mewakili hubungan many-to-many. Baik graph maupun tree memiliki keunggulan dan kelemahannya masing-masing. Pemilihan struktur data yang tepat dan efisien tergantung pada masalah yang ingin dipecahkan dan karakteristik data yang akan direpresentasikan.


## Referensi
[1] Tint, San, and Khaing Soe wai. "Connected Graph with Trees", IRE Journals, vol. 3, no. 2, pp. 257-263, Agustus 2019.