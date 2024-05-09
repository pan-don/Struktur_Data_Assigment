#include <iostream>
#include <string>
# include <iomanip>
using namespace std;

//  struktur node double linked list
class Node {
    public:
    string produk;
    int harga;
    Node* prev;
    Node* next;
};

// fungsi yang digunakan untuk memanipulasi linked list
class DoublyLinkedList {
        public:
        Node* head;
        Node* tail;
        // inisiasi bahwa linked list awalnya kosong
        DoublyLinkedList() {
            head = nullptr;
            tail = nullptr;
    }

    // menambahkan data pada akhir linked list
    void tambah_data(string produk, int harga) {
        Node* baru = new Node;
        baru->harga = harga;
        baru->produk = produk;
        baru->prev = head;
        baru->next = nullptr;
        if (head != nullptr) {
            tail->next = baru;
        } 
        else {
            head = baru;
        }
        tail = baru;
    }

    // menghapus data terakhir linked list
    void hapus_data() {
        Node* bantu;
        Node* hapus;
        if (head != nullptr) {
            if (head != tail) {
                hapus = tail;
                bantu = head;
                while (bantu->next != tail){
                    bantu = bantu->next;
                }
                tail = bantu;
                tail->next = NULL;
                delete hapus;
            }
            else {
                head = tail = NULL;
            }
            cout << "Data terakhir berhasil dihapus!" << endl;
        }
        else {
            cout << "List kosong!" << endl;
            return;
        }
    }

    // memperbaharui data tertentu
    bool update_data(string produklama, string produkbaru, int hargabaru) {
        Node* current = head;
        while (current != nullptr) {
            if (current->produk == produklama) {
                current->produk = produkbaru;
                current->harga = hargabaru;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // menghapus semua data linked list
    void hapus_semua() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    // menghitung panjang list
    int hitungList(){
        Node *hitung;
        hitung = head;
        int jumlah = 0;
        while( hitung != NULL ){
            jumlah++;
            hitung = hitung->next;
        }
        return jumlah;
    }

    // menambahkan data pada urutan tertentu
    void tambah_tertentu(string produk, int harga, int posisi){
        if( posisi < 1 || posisi > hitungList() ){
            cout << "Posisi diluar jangkauan" << endl;
        }
        else if( posisi == 1){
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else{
            Node *baru, *bantu;
            baru = new Node();
            baru->produk = produk;
            baru->harga = harga;
            bantu = head;
            int nomor = 1;
            while( nomor < posisi - 1 ){
                bantu = bantu->next;
                nomor++;
            }
            baru->next = bantu->next;
            bantu->next = baru;
        }
    }

    // menghapus data pada urutan tertentu
    void hapus_tertentu(int posisi){
        Node *hapus, *bantu, *bantu2;
        if( posisi < 1 || posisi > hitungList() ){
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if( posisi == 1){
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else{
            int nomor = 1;
            bantu = head;
            while( nomor <= posisi ){
                if( nomor == posisi-1 ){
                    bantu2 = bantu;
                }
                if( nomor == posisi ){
                    hapus = bantu;
                }
                bantu = bantu->next;
                nomor++;
            }
            bantu2->next = bantu;
        delete hapus;
        }
    }

    // menampilkan double linked list
    void tampilkan() {
        Node* current = head;
        int i=1;
        cout << endl;
        cout << "----------------------------" << endl;
        cout << setw(18) << left << "   Produk" << setw(10) << right << "Harga" << endl;
        cout << "----------------------------" << endl;
        while (current != nullptr) {
            cout << i <<". "<<setw(15) << left << current->produk << "Rp." << setw(7) << right << current->harga << endl;
            current = current->next;
            i++;
        }
        cout << "----------------------------" << endl;
    }
};

int main() {
    DoublyLinkedList list;
    // loop untuk menu utama
    while (true) {
        cout << "\n------------------------------" << endl;
        cout << "   Toko Skincare Purwokerto   " << endl;
        cout << "------------------------------" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;
        int pilih;
        cout << "Masukan pilihan: ";
        cin >> pilih;
        
        // percabangan untuk pilihan yang dituju
        switch (pilih) {
            case 1: {
                cout << "\nTambah Barang" << endl;
                string produk;
                int harga;
                cout << "Masukan nama produk  : ";
                cin >> produk;
                cout << "Masukan harga produk : ";
                cin >> harga;
                list.tambah_data(produk, harga);
                break;
            }
            case 2: {
                list.hapus_data();
                break;
            }
            case 3: {
                cout << "\nUpdate Data" << endl;
                string produklama, produkbaru;
                int hargabaru;
                cout << "Masukan produk lama: ";
                cin >> produklama;
                cout << "Masukan produk baru: ";
                cin >> produkbaru;
                cout << "Masukan harga baru : ";
                cin >> hargabaru;
                bool updated = list.update_data(produklama, produkbaru, hargabaru);
                if(updated){
                    cout << "Produk berhasil diperbaharui!" << endl;
                }
                else if (!updated) {
                    cout << "Produk tidak ditemukan!" << endl;
                }
                break;
            }

            case 4: {
                cout << "\nTambah Data Tertentu" << endl;
                string produk;
                int harga, posisi;
                cout << "Masukan produk produk: ";
                cin >> produk;
                cout << "Masukan harga produk: ";
                cin >> harga;
                cout << "Masukan urutan posisi: ";
                cin >> posisi;
                list.tambah_tertentu(produk, harga, posisi);
                break;
            }

            case 5: {
                cout << "\nHapus Data Tertentu" << endl;
                int posisi;
                cout << "Masukan urutan data yang dihapus: ";
                cin >> posisi;
                list.hapus_tertentu(posisi);
                break;
            }

            case 6: {
                list.hapus_semua();
                cout << "Semua data berhasil dihapus!" << endl;
                break;
            }

            case 7: {
                list.tampilkan();
                break;
            }

            case 8: {
                cout << "\nProgam Selesai!" << endl;
                return 0;
            }
            default: {
                cout << "\nPilih nomor yang tersedia!" << endl;
                break;
            }
        }
    }
    return 0;
}