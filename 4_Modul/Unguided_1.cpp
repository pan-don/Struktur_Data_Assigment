#include <iostream>
#include <iomanip>
using namespace std;

// deklarasi variabel
string kalimat = "tanah airku";
char cari;

// fungsi pengurutan menggunakan algoritma selection_sort
void selection_sort() {
    int temp, min, i, j;
    for(i = 0; i < kalimat.length(); i++) {
        min = i;
        for(j = i + 1; j < kalimat.length(); j++) {
            if(kalimat[j] < kalimat[min]) {
                min = j;
            }
        }
        temp = kalimat[i];
        kalimat[i] = kalimat[min];
        kalimat[min] = temp;
    }
}

// fungsi pencarian menggunakan algoritma binary_search
void binary_search() {
    int awal, akhir, b_flag = 0; // b_flag: untuk tanda jika data ditemukan
    int tengah; // untuk menyimpan nilai tengah (median)
    awal = 0; // menentukan panjang array
    akhir = 6; // menentukan panjang array
    while (b_flag == 0 && awal <= akhir) {
        tengah = (awal + akhir) / 2; // rumus median
        if(kalimat[tengah] == cari) { // jika array ke-tengah sama dengan cari
            b_flag = 1; // mengisi nilai b_flag dengan 1
            break;
        } else if(kalimat[tengah] < cari) {
            awal = tengah + 1; // mengatur ulang nilai awal
        } else {
            akhir = tengah - 1; // mengatur ulang nilai akhir
        }
    }
    if(b_flag == 1) { // menampilkan indeks data yang dicari
        cout << "\n Data ditemukan pada index ke-" << tengah << endl;
    } else { // jika data yang dicari tidak ditemukan
        cout << "\n Data tidak ditemukan\n";
    }
}

int main() {
    // menampilkan kalimat
    cout << "\n Data : '" << kalimat << "'" <<endl;
    // input huruf yang dicari
    cout << "\n Masukkan data yang ingin Anda cari : ";
    cin >> cari;
    // urutkan data dengan selection sort
    selection_sort();
    // tampilkan data setelah diurutkan
    cout << "\n Data diurutkan : '" << kalimat << "'" <<endl;
    binary_search();
    return 0;
}