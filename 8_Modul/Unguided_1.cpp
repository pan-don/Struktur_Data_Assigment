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