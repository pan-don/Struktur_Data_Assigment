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