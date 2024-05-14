# <h1 align="center">Laporan Praktikum Modul Linked List</h1>
<p align="center">Afan Ramadhan</p>

## Dasar Teori

Linked List atau yang sering disebut juga Senarai Berantai adalah salah satu metode dalam Algoritma dan Struktur Data yang digunakan untuk mengatur struktur struktur data dalam suatu sistem. Senarai Berantai memiliki keunggula dibandingkan Larik dalam hal menambahkan dan menghapus elemen. Linked list pertama kali dikembangkan pada tahun 1955-1956 oleh Allen Newell, Cliff Shaw dan Harbert A. Simon di RAND Corporation sebagai struktur data utama untuk Bahasa Pemrosesan Informasi yang digunakan untuk program-program kecerdasan buatan, termasuk Mesin Teori Logika, Pemecah Masalah Umum, dan program Catur Komputer. Menggunakan linked list merupakan cara yang bagus untuk menyimpan jumlah data yang secara teoritis tak terbatas dengan jumlah kode yang kecil dan serbaguna. linked list sangat bagus karena dapat mengubah dan menulis untuk memenuhi kebutuhan khusus user. Ada berbagai macam jenis linked list diantaranya single dan double linked list [1].

Single linked list adalah kumpulan elemen data yang terhubung secara linear. Setiap node single linked list memiliki dua bagian: data yang ingin disimpan dan referensi ke node berikutnya dalam list.. Dalam single linked list, setiap simpul dibagi menjadi dua bagian: Bagian pertama berisi informasi dari elemen tersebut. Dan yang kedua bagian kedua berisi alamat simpul berikutnya dalam daftar. Ini berarti, setiap node memiliki satu penunjuk ke simpul berikutnya. Penunjuk dari simpul terakhir adalah NULL yang mewakili akhir dari daftar terkait.

Double linked list mirip dengan single linked list, namun setiap node memiliki dua bidang tautan, yaitu satu ke node sebelumnya dan satu ke node berikutnya dalam list. Dalam hal ini, dua bidang tautan ada di sana (saylpt adalah penunjuk pendahulu dan rptyang adalah penunjuk penerus), bukannya satu seperti pada daftar tertaut tunggal. Karena setiap node memiliki referensi ke node sebelumnya, maka akses ke elemen berdasarkan indeks menjadi lebih efisien dibandingkan dengan single linked list karena dapat dilakukan baik dari awal maupun akhir list.

## Guided 

### 1. Latihan Single Linked List

```C++
#include <iostream>
using namespace std;

///PROGRAM SINGLE LINKED LIST NON-CIRCULAR
//Deklarasi Struct Node
struct Node{
    //komponen/member
    int data;
    Node *next;
};
    Node *head;
    Node *tail;
//Inisialisasi Node
void init(){
    head = NULL;
    tail = NULL;
}
// Pengecekan
bool isEmpty(){
    if (head == NULL)
    return true;
    else
    return false;
}
//Tambah Depan
void insertDepan(int nilai){
    //Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
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
//Tambah Belakang
void insertBelakang(int nilai){
    //Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
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
//Tambah Tengah
void insertTengah(int data, int posisi){
    if( posisi < 1 || posisi > hitungList() ){
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if( posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else{
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;
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
//Hapus Depan
void hapusDepan() {
    Node *hapus;
    if (isEmpty() == false){
        if (head->next != NULL){
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else{
            head = tail = NULL;
        }
    }
    else{
        cout << "List kosong!" << endl;
    }
}
//Hapus Belakang
void hapusBelakang() {
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false){
        if (head != tail){
            hapus = tail;
            bantu = head;
            while (bantu->next != tail){
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        delete hapus;
        }
        else{
            head = tail = NULL;
        }
    }
    else{
        cout << "List kosong!" << endl;
    }
}
//Hapus Tengah
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
//Ubah Depan
void ubahDepan(int data){
    if (isEmpty() == false){
        head->data = data;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Ubah Tengah
void ubahTengah(int data, int posisi){
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
            bantu->data = data;
        }
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Ubah Belakang
void ubahBelakang(int data){
    if (isEmpty() == false){
        tail->data = data;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Hapus List
void clearList(){
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL){
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}
//Tampilkan List
void tampil(){
    Node *bantu;
    bantu = head;
    if (isEmpty() == false){
        while (bantu != NULL){
            cout << bantu->data << " ";
            bantu = bantu->next;
        }
        cout << endl;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
int main(){
    init();
    insertDepan(3);
    tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7,2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();
    insertTengah(7,1);
    tampil();
    return 0;
}
```

code diatas merupakan contoh dari implementasi dari single linked list. secara garis besar cara kerja dari kode diatas sebagai berikut. pada awal progam mendeklarasikan struktur node. Setiap node memiliki dua bagian yaitu data yang menyimpan nilai dari elemen dan next yang merupakan pointer ke node berikutnya dalam linked list. progam dilanjutkan dengan berbagai macam fungsi-fungsi yang digunakan untuk memanipulasi linked list seperti penambahan, penghapusan, pencetakan, pembaruan, dan penghapusan keseluruhan elemen linked list. data pada node bertipe data integer yang berarti linked list hanya menyimpan data bilangan bulat. Semua fungsi tadi dipanggil pada fungsi utama untuk dicetak hasilnya. dengan begitu akan mudah memahami bagaimana cara kode tersebut berjalan. 

### 2. Latihan Double Linked List

```C++
#include <iostream>
using namespace std;

class Node {
    public:int data;
    Node* prev;
    Node* next;
};
class DoublyLinkedList {
        public:
        Node* head;
        Node* tail;
        DoublyLinkedList() {
            head = nullptr;
            tail = nullptr;
    }
    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        } 
        else {
            tail = newNode;
        }
        head = newNode;
    }
    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } 
        else {
            tail = nullptr;
        }
        delete temp;
    }
    
    bool update(int oldData, int newData) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};


int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}
```

code diatas merupakan contoh dari implementasi dari double linked list. secara garis besar hampir sama dengan code progam single linked list. pada awal progam, dilakukan pendeklarasian struktur node yang terdapat 3 bagian pada setiap nodenya yaitu data yang menyimpan nilai dari elemen dan next yang merupakan pointer ke node berikutnya serta prev yang merupakan pointer ke node sebelumnya dalam linked list. kode dilanjutkan dengan membuat fungsi-fungsi untuk memanipulasi double linked list seperti penambahan, penghapusan, pencetakan, pembaruan, dan penghapusan keseluruhan elemen linked list. pada bagian fungsi utama menampilkan pilihan mengenai manipulasi data yang terdapat pada double linked list. setiap pilihan dapat dipilih menggunakan perintah swich case.

## Unguided 

### 1. Buatlah program menu Single Linked List Non-Circular untuk menyimpan Nama dan usia mahasiswa, dengan menggunakan inputan dari user

```C++
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
```
#### Output:

![Screenshot (216)](https://github.com/pan-don/training/assets/157208689/e91ffd1c-d6d8-4a8f-a938-0ee373658d6d)
![Screenshot (217)](https://github.com/pan-don/training/assets/157208689/01c21ad5-a8ce-4ce6-a00e-5617ddf9e15f)
![Screenshot (218)](https://github.com/pan-don/training/assets/157208689/5c5d2707-686a-4260-a21d-f979050e9f6b)
![Screenshot (219)](https://github.com/pan-don/training/assets/157208689/cfd30601-23e0-4600-bc28-98b5763eb1ee)
![Screenshot (220)](https://github.com/pan-don/training/assets/157208689/ecaa4a14-1490-4420-923b-99ce3195e6ef)
![Screenshot (221)](https://github.com/pan-don/training/assets/157208689/3e8d6e5d-e86e-4208-82e4-754486500b92)

code tersebut merupakan progam untuk menyimpan data nama dan usia mahasiswa di dalam single linked list. progam diawali dengan pembentukan struct node yang didalamnya terdapat 3 anggota yaitu nama, usia, dan next untuk menunjuk ke node selanjutnya. pada fungsi utama pengguna diminta untuk memasukan data nama dan usia menggunakan insert belakang lalu menghapus data dengan nama 'akechi' menggunakan hapus tengah. data ditambahkan lagi pada bagian awal menggunakan insert depan. data dengan nama michael di perbaharui dengan nama reyn. terakhir menampilkan seluruh data yang telah dimanipulasi sebelumnya.

### 2. Modifikasi Guided Double Linked List dilakukan dengan penambahan operasi untuk menambah data, menghapus, dan update di tengah / di urutan tertentu yang diminta. Selain itu, buatlah agar tampilannya menampilkan Nama produk dan harga

```C++
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
```

#### Output:

![Screenshot (211)](https://github.com/pan-don/training/assets/157208689/4f3d39dd-976c-46d7-b29f-e882fcd61477)
![Screenshot (212)](https://github.com/pan-don/training/assets/157208689/eed23aa9-12ea-41a1-9ff4-f633cebdafda)
![Screenshot (213)](https://github.com/pan-don/training/assets/157208689/c60ec34e-3c19-490f-acea-19371b0e47c6)
![Screenshot (214)](https://github.com/pan-don/training/assets/157208689/0defe0ca-511e-434a-85b7-bedd25e2f0cd)
![Screenshot (215)](https://github.com/pan-don/training/assets/157208689/b7f3e2f6-28b7-42a5-9055-189c77f0a329)

kode diatas merupakan progam penyimpanan barang pada toko skincare purwokerto menggunakan double linked list. progam diawali dengan mendeklarasikan struktur node yang didalamnya terdapat 4 anggota yaitu nama barang harga barang, next untuk menunjuk node selanjutnya dan prev untuk menunjuk node sebelumnya. progam dilanjutkan dengan membuat 7 code yang berguna untuk memanipulasi linked list diantaranya tambah data, hapus data, update data, tambah data tertentu, hapus data tertentu, hapus seluruh data,  dan tampilkan data. pada fungsi utama, pengguna dapat melakukan manipulasi linked list dengan memilih ke-7 pilihan untuk melakukan manipulasi linked list menggunakan yang nantinya akan diarahkan ke pilihan yang dituju menggunakan perintah swich case. pengguna juga dapat memilih exit untuk menghentikan keseluruhan progam.

## Kesimpulan

Linked list adalah struktur data linear yang fleksibel dan dinamis. Berbeda dengan array, elemen-elemen dalam linked list tidak disimpan di memori yang berdekatan. Sebaliknya, elemen-elemen (disebut node) terhubung satu sama lain menggunakan pointer. pada pembahasan ini terdapat 2 jenis linked list yaitu single linked list dan double linked list. pada single linked list Setiap node hanya memiliki satu pointer yang menunjuk ke node berikutnya. hal Ini memungkinkan iterasi melalui list hanya dalam satu arah (maju). sedangkan pada double linked list Setiap node memiliki dua pointer, satu menunjuk ke node berikutnya dan satu lagi menunjuk ke node sebelumnya. Ini memungkinkan iterasi bolak-balik (maju dan mundur) melalui list.

Banyak sekali progam yang menggunakan linked list untuk  mengimplementasikannya. diantaranya ada stack, queue, fungsi undo/rendo, dan lain sebaginya. progam tersebut menggunakan linked list karena  Linked list dapat tumbuh atau menyusut sesuai kebutuhan dan tidak perlu menentukan ukuran tetap di awal seperti pada array. akan tetapi terdapat beberapa kekurangan dalam penggunaan linked list seperti  tidak dapat langsung mengakses elemen tertentu dalam linked list berdasarkan indeksnya seperti array tetapi harus iterasi melalui list untuk menemukan elemen yang diinginkan. hal ini akan memakan lebih banyak waktu serta penggunaan kode yang lebih rumit dan akan memakan memori lebih banyak. 

## Referensi
[1] Dalal, Ankit, and andAnkur Atri, "An Introduction to Linked List", International Journal of Research (IJR), vol.1, no.10, hal.1281-1285, November 2014.