#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// deklarasi struktur node linked list
struct Node{
    string nama;
    int umur;
    Node *next;
};
    Node *head;
    Node *tail;

//Inisialisasi Node awal kosong
void init(){
    head = NULL;
    tail = NULL;
}

// Pengecekan apakah node kosong
bool isEmpty(){
    if (head == NULL)
    return true;
    else
    return false;
}

//Menambah data keurutan pertama
void tambahDepan(string nama, int umur){
    //Buat Node baru
    Node *baru = new Node;
    baru->nama = nama;
    baru->umur = umur;
    baru->next = NULL;
    if (isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
    }
    else{
        baru->next = head;
        head = baru;
    }
}
//Menambah data keurutan terakhir
void tambahBelakang(string nama, int umur){
    //Buat Node baru
    Node *baru = new Node;
    baru->nama = nama;
    baru->umur = umur;
    baru->next = NULL;
    if (isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
    }
    else{
    tail->next = baru;
    tail = baru;
    }
}

//Hitung Jumlah List
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

//menambah data dengan posisi tertentu
void tambahTengah(string nama, int umur, int posisi){
    if( posisi < 1 || posisi > hitungList() ){
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if( posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else{
        Node *baru, *bantu;
        baru = new Node();
        baru->nama = nama;
        baru->umur = umur;
        // tranversing
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

//menghapus data dengan posisi tertentu
void hapusTengah(int posisi){
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

//memperbaharui data pada urutan tertentu
void ubahTengah(string nama, int umur, int posisi){
    Node *bantu;
    if (isEmpty() == false){
        if( posisi < 1 || posisi > hitungList() ){
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if( posisi == 1){
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else{
            bantu = head;
            int nomor = 1;
            while (nomor < posisi){
                bantu = bantu->next;nomor++;
            }
            bantu->nama = nama;
            bantu->umur = umur;
        }
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}

//Tampilkan linked List
void tampil(){
    Node *bantu;
    bantu = head;
    cout << setw(15) << left << "Nama" << setw(5) << right << "Umur" << endl;
    cout << "--------------------" << endl;
    if (isEmpty() == false){
        while (bantu != NULL){
            cout << setw(15) << left << bantu->nama << setw(5) << right << bantu->umur << endl;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}

int main(){
    string nama;
    int umur;
    char lanjut;
    int posisi;
    init();

    // Mengisi data
    cout << "Menambahkan data" << endl;
    while(true){
        cout << "\nMasukan nama: ";
        cin >> nama;
        cout << "Masukan Usia: ";
        cin >> umur;
        tambahBelakang(nama, umur);
        
        cout << "lanjutkan (y/n): ";
        cin >> lanjut;
        lanjut = tolower(lanjut);
        if(lanjut == 'n'){
            break;
        }
    }

    // menghapus data nama akechi
    cout << "\nMenghapus data" << endl;
    cout << "Masukan urutan data yang dihapus: ";
    cin >> posisi;
    hapusTengah(posisi);

    // Menambah data Futaba diantara John dan Jane
    cout << "\nMenambah data pada urutan tertentu" << endl;
    cout << "Masukan nama: ";
    cin >> nama;
    cout << "Masukan umur: ";
    cin >> umur;
    cout << "Masukan posisi data: ";
    cin >> posisi;
    tambahTengah(nama, umur, posisi);

    // menambahkan data diawal Igor
    cout << "\nMenambah data diawal" << endl;
    cout << "Masukan nama: ";
    cin >> nama;
    cout << "Masukan umur: ";
    cin >> umur;
    tambahDepan(nama, umur);

    // Update data Michael dengan Reyn
    cout << "\nMemperbaharui data" << endl;
    cout << "Masukan nama baru: ";
    cin >> nama;
    cout << "Masukan umur: ";
    cin >> umur;
    cout << "\nMasukan urutan data yang di Update: ";
    cin >> posisi;
    ubahTengah(nama, umur, posisi);
    
    // menampilkan seluruh data
    tampil();
}