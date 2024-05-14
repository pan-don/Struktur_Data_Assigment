# <h1 align="center">Laporan Praktikum Modul Stack dan Queue</h1>
<p align="center">Afan Ramadhan</p>

## Dasar Teori

Stack atau tumpukan adalah suatu stuktur data yang penting dalam pemrograman dengan metode pemrosesan yang bersifat LIFO(Last In First Out) dimana objek/benda yang terakhir masuk ke dalam stack akan menjadi benda pertama yang dikeluarkan dari stack. Dengan model demikian, maka hanya bagian paling atas saja dari stack (TOP) yang bisa di akses. Salah satu kelebihan stack adalah bahwa struktur data tersebut dapat di implementasikan baik pada array maupun pada linked list [1]. Penyisipan elemen ke dalam stack disebut operasi push, dan penghapusan elemen dari stack disebut operasi pop. Di dalam stack, kita selalu melacak elemen terakhir yang ada di dalam daftar dengan penunjuk yang disebut top.

Kebalikan dari stack, queue (antrian) adalah suatu jenis struktur data yang dapat diproses dengan sifat FIFO (First In First Out), dimana elemen yang pertama kali masuk ke antrian akan keluar pertama kalinya. Ada dua jenis operasi yang bias dilakukan di antrian : enqueue (memasukkan elemen baru ke dalam elemen) dan dequeue (adalah mengeluarkan satu elemen dari suatu antrian). Antrian dapat dibuat dengan menggunakan: Liniear Array dan Circular Array [1]. Penyisipan elemen dalam antrean disebut operasi enqueue dan penghapusan elemen disebut operasi dequeue. Dalam antrean, kita selalu mempertahankan dua penunjuk, satu penunjuk menunjuk ke elemen yang disisipkan pertama kali dan masih ada dalam daftar dengan penunjuk depan dan penunjuk kedua menunjuk ke elemen yang disisipkan terakhir dengan penunjuk belakang.

## Guided 

### 1. Stack

```C++
#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull() {
    return (top == maksimal);
}

bool isEmpty() {
    return (top == 0);
}

void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    } else {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[top - 1] = "";
        top--;
    }
}

void peekArrayBuku(int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}

int countStack() {
    return top;
}

void changeArrayBuku(int posisi, string data) {
    if (posisi > top) {
        cout << "Posisi melebihi data yang ada" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        arrayBuku[index] = data;
    }
}

void destroyArraybuku() {
    for (int i = top; i >= 0; i--) {
        arrayBuku[i] = "";
    }
    top = 0;
}

void cetakArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main() {
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout << "\n";
    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;
    peekArrayBuku(2);
    popArrayBuku();
    cout << "Banyaknya data = " << countStack() << endl;
    changeArrayBuku(2, "Bahasa Jerman");
    cout << endl;
    cetakArrayBuku();
    cout << "\n";
    destroyArraybuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;
    cetakArrayBuku();

    return 0;
}
```

code diatas merupakan progam untuk menyimpan array bertipe data string yang didalamnya terdapat judul-judul buku menggunakan struktur data stack. Progam diawali dengan mendeklarasikan array dengan panjang 5 elemen dan variabel 'top' untuk menentukan isi data yang ditandakan oleh fungsi 'isFull' dan 'isEmpty'. Progam dilanjutkan dengan membuat fungsi-fungsi untuk memanipulasi array pada struktur data stack seperti memasukan data (push), menghapus data terakhir (pop), melihat seluruh data (cetak), melihat data tertentu (peek), dan menghapus seluruh data (clear). Pada fungsi utama 5 data buku ditambahkan menggunakan fungsi 'PushArrayBuku' yang sudah dideklarasikan sebelumnya. setelah itu menampilkan  
elemen array ke 2 yang kemudian dilanjutkan dengan menghapus data terakhir menggunakan 'PopArrayBuku'. lalu mengupdate data ke 2 dengan 'bahasa Jerman' menggunakan 'ChangeArrayBuku'. progam diakhiri dengan menghapus semua data menggunakan 'destroyArrayBuku'. setiap langkah manipulasi data tersebut akan menampilkan seluruh data menggunakan 'CetakArrayBuku' untuk melihat hasil manipulasi sehingga lebih mudah untuk dipahami.

### 2. Queue 

```C++
#include <iostream>
using namespace std;

const int maksimalQueue = 5; // Maksimal antrian
int front = 0; // Penanda depan antrian
int back = 0; // Penanda belakang antrian
string queueTeller[5]; // Array untuk menyimpan antrian

bool isFull() { // Pengecekan antrian penuh atau tidak
    if (back == maksimalQueue) {
        return true; // =1
    } else {
        return false;
    }
}

bool isEmpty() { // Antrian kosong atau tidak
    if (back == 0) {
        return true;
    } else {
        return false;
    }
}

void enqueueAntrian(string data) { // Menambahkan antrian
    if (isFull()) {
        cout << "Antrian penuh" << endl;
    } else {
        if (isEmpty()) { // Jika antrian kosong
            queueTeller[0] = data;
            front++;
            back++;
        } else { // Jika antrian ada isi
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian() { // Mengurangi antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

int countQueue() { // Menghitung jumlah antrian
    return back;
}

void clearQueue() { // Menghapus semua antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewQueue() { // Melihat isi antrian
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
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
```

code diatas merupakan progam untuk menyimpan data nama orang pada array menggunakan struktur data queue. progam diawali dengan mendeklarasikan array dengan panjang 5 elemen dan variabel front serta back sebagai penenda antrian. Kemudian membuat fungsi 'isfull' dan 'isempty' untuk mengecek antrian penuh atau tidak. Progam dilanjutkan dengan membuat fungsi-fungsi operasi queue seperti 'enqueueAntrian' untuk menambahkan data kedalam antrian, 'viewQueue' untuk melihat seluruh data, 'dequeueAntrian' untuk menghapus data yang pertama masuk, dan 'clearQueue' untuk menghapus keseluruhan data. Pada fungsi utama, menambahkan nama andi dan miya kedalam array. lalu menghapus nama andi yang kemudian menghapus keseluruhan data. setiap langkah pada operasi tersebut akan menampilkan keseluruhan data sehingga memudahkan untuk memahami hasil operasi yang dilakukan. 

## Unguided 

### 1. Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.

```C++
#include <iostream>
#include <string>
using namespace std;

void push(char arrayKalimat[], int &top, int maksimal, char huruf) {
    arrayKalimat[top] = huruf;
    top++;
}

void tampilkan(char arrayKalimat[], int top) {
    for (int i = top - 1; i >= 0; i--) {
        cout << arrayKalimat[i];
    }
    cout << endl;
}

// membandingkan kalimat asli dengan kalimat yang sudah dibalik
bool cekPalindrom(char arrayKalimat[], int top) {
    for (int i = 0; i < top / 2; i++) {
        if (arrayKalimat[i] != arrayKalimat[top - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    cout << "\nCek Kalimat Palindrom" << endl;
    cout << "---------------------" << endl;
    string kalimat;
    cout << "Masukan Kalimat: ";
    getline(cin, kalimat);
    
    // Menghitung jumlah huruf dan mengabaikan spasi
    int maksimal = 0;
    for (char huruf : kalimat) {
        if (huruf != ' ') {
            maksimal++;
        }
    }

    // memasukan huruf yang terkandung dalam kalimat ke dalam array
    char arrayKalimat[maksimal];
    int top = 0;
    for (char huruf : kalimat) {
        if (huruf != ' ' && huruf != 0) {
            push(arrayKalimat, top, maksimal, huruf);
        }
    }

    // menampilkan kalimat yang dibalik dengan mengabaikan spasi
    cout << "Hasil reverse: "; 
    tampilkan(arrayKalimat, top);

    // menentukan hasil kalimat polindorm atau tidak
    if (cekPalindrom(arrayKalimat, top)) {
        // jika cekPolindrom bernilai true
        cout << "\nKalimat tersebut palindrom" << endl;
    } else {
        // jika cekPolindrom bernilai false
        cout << "\nBukan Kalimat palindrom" << endl;
    }
    return 0;
}
```

#### Output:

![Screenshot (223)](https://github.com/pan-don/training/assets/157208689/c86b1f2e-dc06-4cc7-941f-ae7205524322)

code diatas merupakan progam untuk menyimpan data nama orang ke dalam array dengan struktur data stack. pada awal progam, membuat fungsi untuk push untuk menambahkan data karakter ke dalam array, fungsi tampilkan untuk menampilkan elemen yang terdapat didalam array, dan fungsi cekpolinom untuk membandingkan kalimat yang asli dengan kalimat yang sudah dibalik kemudian mengembalikan nilainya dengan bolean. pada fungsi utama membuat perintah input untuk memasukan kalimat yang akan dicek menggunakan getline supaya bisa mengembil keseluruhan kalimat. kemudian menghitung jumlah huruf dalam kalimat tersebut dengan mengabaikan spasi yang digunakan untuk menentukan panjang array. mendeklarasikan array dan menambahkan data dengan menggunakan for loop ke dalam fungsi push. lalu menampilkan huruf-huruf pada kalimat secara terbalik. terkahir pada fungsi cekPalindrom, membandingkan huruf pertama kalimat dengan huruf terkhir kalimat menggunakan forloop hingga selesai dan akan mengembalikan nilai bolean sebagai hasilnya untuk menentukan kalimat tersebut polindrom atau tidak.

### 2. Ubah guided queue diatas agar menjadi program inputan user dan program menu

```C++
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
```

#### Output:

![Screenshot (222)](https://github.com/pan-don/training/assets/157208689/2d8550b5-33c0-41d4-a77d-fda9f9e157d9)

code tersebut merupakan progam menu untuk menyimpan nama orang menggunakan sturuktur data queue. pada bagian awal progam membuat fungsi enqueue untuk menambahkan data kedalam antrian, dequeue untuk menghapus data antrian pertama, qountqueue untuk melihat jumlah data antrian, clearqueue untuk menghapus seluruh data antrian, dan viewqueue untuk melihat seluruh antrian. pada fungsi utama, membuat menu pilihan untuk melakukan operasi queue. dengan memilih pilihan yang tersedia dimenu maka progam akan mengarahkan ke dalam fungsi yang dipilih dan mengembalikan nilainya setelah proses operasi selesai. jika memilih pilihan yang tersedia maka progam akan mencetak "Masukan Pilihan Yang Tersedia!" menggunakan perintah cout.

## Kesimpulan

Stack dan queue merupakan struktur data linear untuk menyimpan elemen berurutan, memiliki fungsi yang berbeda dalam hal bagaimana elemen tersebut diakses dan diproses. Stack menggunakan konsep LIFO untuk pengaksesan dan pemrosesan data, jadi data yang pertama kali masuk (push) adalah yang terakhir keluar (pop). Contohnya seperti kita akan membersihkan tumpukan piring kotor, yang pertama kali dibersihkan (pop) pasti piring yang berada di posisi teratas. sebaliknya untuk Queue menggunakan konsep FIFO yaitu data yang pertama kali masuk (enqueue) juga yang pertama kali keluar (dequeue). contohnya seperti antrian pada kasir di minimarket,  orang yang pertama kali datang ke meja kasir dan dilayani adalah orang yang pertama kali keluar (dequeue) [1]. 

Ada banyak progam yang menggunakan stack dan queue untuk menjalankan progamnya seperti pada pemutar musik dan fungsi rendo/undo. Program pemutar musik dapat menggunakan queue untuk mengatur daftar putar lagu. Lagu yang ditambahkan ke daftar putar akan dimasukkan ke dalam queue. Lagu yang sedang diputar saat ini berada di depan queue, dan lagu berikutnya yang akan diputar berada di urutan kedua, dan seterusnya. sedangkan untuk fungsi undo/rendo, Ketika menggunakan fitur undo/redo pada program pengolah kata, program tersebut menggunakan stack untuk menyimpan riwayat perubahan dokumen. Setiap perubahan yang dilakukan akan dimasukkan ke dalam stack. Saat Anda menekan undo, elemen terakhir dari stack akan dihapus dan dibatalkan.

## Referensi
[1] Sihombing, Johnson, "Penerapan Stack dan Queue Pada Array dan Linked List Dalam Java", journal piksi, vol.1, no.1, hal.15-24, Agust 2019.