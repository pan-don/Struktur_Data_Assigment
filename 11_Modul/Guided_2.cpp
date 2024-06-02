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