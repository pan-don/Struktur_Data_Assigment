# <h1 align="center">Laporan Praktikum Modul Priority Queue dan Heaps</h1>
<p align="center">Afan Ramadhan</p>

## Dasar Teori

Antrean prioritas adalah struktur data fundamental yang terdiri dari satu set pasangan kunci-nilai di mana kunci menunjukkan prioritas (secara konvensi, kunci yang lebih kecil menunjukkan prioritas yang lebih tinggi). Antrean prioritas tipikal hanya mengimplementasikan dua operasi: Insert, yang menambahkan item dengan prioritas terkait ke dalam antrean, dan DeleteMin, yang menghapus item dengan prioritas tertinggi dari antrean. Struktur data ini banyak digunakan dalam algoritma mulai dari aplikasi tingkat tinggi hingga kernel sistem tingkat rendah. Implementasi efisiennya dalam lingkungan multithreaded sangat penting untuk sistem multi-core modern dan masa depan [1].

Berbeda dengan antrian biasa yang mengikuti aturan First In First Out (FIFO), di mana elemen yang pertama masuk akan dilayani terlebih dahulu, antrean prioritas memungkinkan elemen dengan prioritas tertinggi untuk selalu diakses terlebih dahulu meskipun mereka baru saja masuk ke dalam antrian. Min-heap dan max-heap merupakan implementasi yang efisien dari antrean prioritas yang menggunakan struktur pohon biner untuk mempertahankan properti prioritasnya. Implementasi heap memungkinkan operasi insert dan delete dengan kompleksitas waktu rata-rata O(log N), menjadikannya pilihan yang populer untuk aplikasi yang memerlukan pengelolaan elemen-elemen dengan prioritas dinamis.

## Guided 

### 1. Implementasi Priority Queue dan Heaps

```C++
#include <iostream>
#include <algorithm>
using namespace std;

int H[50];
int heapsize = -1;

int parent(int i) {
    return (i - 1) / 2;
}

int leftchild(int i) {
    return ((2 * i) + 1);
}

int rightchild(int i) {
    return ((2 * i) + 2);
}

void shiftup(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void shiftdown(int i) {
    int maxindex = i;
    int l = leftchild(i);
    if (l <= heapsize && H[l] > H[maxindex]) {
        maxindex = l;
    }
    int r = rightchild(i);
    if (r <= heapsize && H[r] > H[maxindex]) {
        maxindex = r;
    }
    if (i != maxindex) {
        swap(H[i], H[maxindex]);
        shiftdown(maxindex);
    }
}

void insert(int p) {
    heapsize = heapsize + 1;
    H[heapsize] = p;
    shiftup(heapsize);
}

int extractmax() {
    int result = H[0];
    H[0] = H[heapsize];
    heapsize = heapsize - 1;
    shiftdown(0);
    return result;
}

void changepriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftup(i);
    } else {
        shiftdown(i);
    }
}

int getmax() {
    return H[0];
}

void remove(int i) {
    H[i] = getmax() + 1;
    shiftup(i);
    extractmax();
}

int main() {
    insert(45);
    insert(20);
    insert(14);
    insert(12);
    insert(31);
    insert(7);
    insert(11);
    insert(13);
    insert(7);

    cout << "Priority Queue: ";
    for (int i = 0; i <= heapsize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    cout << "Node with maximum priority: " << extractmax() << "\n"; 
    cout << "Priority queue after extracting maximum: ";
    for (int i = 0; i <= heapsize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    changepriority(2, 49);
    cout << "Priority queue after priority change: ";
    for (int i = 0; i <= heapsize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    remove(3);
    cout << "Priority queue after removing the element: ";
    for (int i = 0; i <= heapsize; ++i) {
        cout << H[i] << " ";
    }
    return 0;
}
```

code diatas merupakan sebuah progam untuk mengimplementasikan antrian prioritas menggunakan Heaps. pada bagian awal, mendeklarasikan array 'H' dan variabel 'heapsize' yang menentukan ukuran heap saat ini. selanjutnya membuat fungsi-fungsi yang menunjuk keberadaan node child dan parent serta membuat fungsi lainnya untuk memanipulasi queue seperti manambahkan, menghapus, mengupdate, dan lainnya. pada fungsi main menambahkan 9 data menggunakan fungsi insert. kemudian mencetak dan menghapus node parent/nilai maksimal. terakhir mengupdate data indeks ke 2 dengan angka 49 serta menghapus data indeks ke 3. Setiap langkah akan menampilkan seluruh data sehingga memudahkan untuk mengetahui cara kode tersebut bekerja.

## Unguided 

### 1. Modifikasi guided diatas yang mana heap dikonstruksi secara manual berdasarkan user.

```C++
#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;

// menunjuk panjang data sekarang 
int heapsize = -1;

// mununjuk node prioritas/parent
int parent(int i) {
    return (i - 1) / 2;
}

// mununjuk anak bagian kiri
int leftchild(int i) {
    return ((2 * i) + 1);
}

// mununjuk anak bagian kanan
int rightchild(int i) {
    return ((2 * i) + 2);
}

// manaikan node
void shiftup(int H[], int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

// menurunkan node
void shiftdown(int H[], int i) {
    int maxindex = i;
    int l = leftchild(i);
    if (l <= heapsize && H[l] > H[maxindex]) {
        maxindex = l;
    }
    int r = rightchild(i);
    if (r <= heapsize && H[r] > H[maxindex]) {
        maxindex = r;
    }
    if (i != maxindex) {
        swap(H[i], H[maxindex]);
        shiftdown(H, maxindex);
    }
}

// memasukan data
void insert(int H[], int p) {
    heapsize = heapsize + 1;
    H[heapsize] = p;
    shiftup(H, heapsize);
}

// menghapus dan menampilkan node prioritas
int extractmax(int H[]) {
    int result = H[0];
    H[0] = H[heapsize];
    heapsize = heapsize - 1;
    shiftdown(H, 0);
    return result;
}

// memperbaharui data index tertentu
void changepriority(int H[], int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftup(H, i);
    } else {
        shiftdown(H, i);
    }
}

// mengambil data pertama
int getmax(int H[]) {
    return H[0];
}

// menghapus element index tertentu
void remove(int H[], int i) {
    H[i] = getmax(H) + 1;
    shiftup(H, i);
    extractmax(H);
}

// Menampilkan element pada array
void view(int H[], int heapsize) {
    cout << "\nData: ";
    for (int i = 0; i <= heapsize; ++i) {
        cout << H[i] << " ";
    }
    cout << endl;
}

int main() {
    cout << "PRIORITY QUEUE DAN HEAPS" << endl;
    // menentukan jumlah elemen array
    int n;
    cout << "Masukan panjang array: ";
    cin >> n;
    if (n < 1){
        return -1;
    }
    int H[n];

    // menambahkan data
    cout << "\nTambah Data" << endl;
    cout << "-----------" << endl;

    for (int i=0; i < n; i++) {
        int p;
        cout << "Masukan data index ke-" << i << ": ";
        cin >> p;
        insert(H, p);
    }
    // menampilkan semua elemen array
    view(H, heapsize);

    // mencetak nilai maksimum dari heap
    cout << "\nNode prioritas/nilai maksimum: " << extractmax(H); 
    view(H, heapsize);
    
    // mengupdate data
    cout << "\nUpdate data" << endl;
    cout << "-----------" << endl;
    int posisi, baru;
    cout << "Masukan data baru: ";
    cin >> baru;
    cout << "Masukan index data yang diubah: ";
    cin >> posisi;
    changepriority(H, posisi, baru);
    view(H, heapsize);
    
    // menghapus data
    cout << "\nHapus data" << endl;
    cout << "----------" << endl;
    int hapus;
    cout << "Masukan index data yang dihapus: ";
    cin >> hapus;
    remove(H, hapus);
    view(H, heapsize);
    
    // akhir progam
    cout << "\nProgam Selesai!" << endl;
    return 0;
}
```

#### Output:
![Screenshot (278)](https://github.com/pan-don/Struktur_Data_Assigment/assets/157208689/06f9ba01-dc29-4d8b-9450-2b3d1f6f63df)


kode diatas merupakan rogam untuk mengimplementasikan antrian prioritas menggunakan Heaps dengan inputan dari user. pada bagian awal, membuat fungsi untuk menunjuk node child untuk sebelah kiri dan kanan serta node parent. selanjutnya membuat fungsi lain yang digunakan untuk memanipulasi queue seperti menambahkan, menghapus, mengupdate, dan lainnya. pada fungsi utama, medeklarasikan array terlebih dahulu dengan panjang yang ditentukan oleh user. kemudian memasukan data menggunakan input sebanyak panjang array. lalu menampilkan node prioritas/nilai maksimum dan menghapusnya. seteelah itu mengupdate data dengan memasukan data yang baru dan indeks data yang diganti menggunakan inputan user. terakhir menghapus data tertentu menggunakan indeks. setiap langkah operasi yang dilakukan akan menampilkan hasil operasi sehingga mudah dalam mepahami cara kerja operasi. 

## Kesimpulan

Antrian Prioritas adalah struktur data yang mirip dengan antrian biasa, tetapi dengan satu perbedaan utama: elemen di dalam antrian prioritas memiliki prioritas, dan elemen dengan prioritas tertinggi akan dilayani terlebih dahulu. Antrian prioritas bisa diimplementasikan menggunakan heap. Kelebihan penggunaan heap untuk antrian prioritas diantaranya Operasi insertion dan extraction sangat efisien (O(log n)) dan Dapat digunakan untuk mengimplementasikan antrian prioritas max dan min. sedangkan untuk kekurangannya adalah ketika memodifikasi struktur data (misalnya, mengubah prioritas elemen) tidak seefisien operasi insertion dan extraction. Akan tetapi Secara keseluruhan, antrian prioritas dan heap adalah struktur data yang sangat berguna untuk berbagai aplikasi yang membutuhkan pemrosesan elemen berdasarkan prioritas.

## Referensi

[1] Carroll, Steven, and Alexander Goponenko, "A C++ Implementation of a Threadsafe Priority Queue Based on Multi-Dimensional Linked Lists and MRLock", journal computer science,vol.1, no.1, Hal.1-9, October 2019.
