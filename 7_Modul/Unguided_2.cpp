#include <iostream>
using namespace std;

void enqueueAntrian(string queueTeller[], int maksimalQueue,int &front, int &back,string nama) { // Menambahkan antrian
    if (back == maksimalQueue) {
        cout << "Antrian penuh" << endl;
    } else {
        if (back == 0) { // Jika antrian kosong
            queueTeller[0] = nama;
            front++;
            back++;
        } else { // Jika antrian ada isi
            queueTeller[back] = nama;
            back++;
        }
    }
}

void dequeueAntrian(string queueTeller[], int &back) { // Mengurangi antrian
    if (back == 0) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

int countQueue(int back) { // Menghitung jumlah antrian
    return back;
}

void clearQueue(string queueTeller[], int &back, int &front) { // Menghapus semua antrian
    if (back == 0) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewQueue(string queueTeller[], int maksimalQueue) { // Melihat isi antrian
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main() {
    // menentukan panjang antrian
    int maksimalQueue;
    cout << "Masukan antrian maksimal: ";
    cin >> maksimalQueue;
    if (maksimalQueue < 1){
        cout << "Antrian harus lebih dari 0" << endl;
        return -1;
    }
    // deklarasi array
    string queueTeller[maksimalQueue];
    int front = 0; // Penanda depan antrian
    int back = 0; // Penanda belakang antrian

    // loop menu
    while(true){
        cout << "\nInformasi Nama Seseorang" << endl;
        cout << "1. Tambah Nama" << endl;
        cout << "2. Hapus Nama" << endl;
        cout << "3. Hapus Semua Nama" << endl;
        cout << "4. Lihat jumlah data" << endl;
        cout << "5. Tampilkan Daftar Nama" << endl;
        cout << "6. Keluar" << endl;
        int pilih;
        cout << "Masukan pilihan: ";
        cin >> pilih;

        switch (pilih){
            case 1: {
                string nama;
                cout << "\nMasukan nama: ";
                cin >> nama;
                enqueueAntrian(queueTeller, maksimalQueue,front, back, nama);
                break;
            }
                
            case 2: {
                dequeueAntrian(queueTeller, back);
                cout << "\nNama berhasil dihapus!" << endl;
                break;
            }

            case 3: {
                clearQueue(queueTeller, back, front);
                cout << "\nSemua nama berhasil dihapus!" << endl;
                break;
            }

            case 4: {
                cout << "\nJumlah data: " << countQueue(back) << endl;
                break;
            }

            case 5: {
                viewQueue(queueTeller, maksimalQueue);
                break;
            }

            case 6: {
                cout << "\nProgam Selesai!" << endl;
                return 0;
            }

            default: {
                cout << "\nMasukan Pilihan Yang Tersedia!" << endl;
                break;
            }
        }   
    }
}