# <h1 align="center">Laporan Praktikum Modul Struct</h1>
<p align="center">Afan Ramadhan</p>

## Dasar Teori

Struct adalah tipe data yang dibuat pengguna untuk mengelompokkan variabel dengan tipe data berbeda di bawah satu nama. struck termasuk kedalam tipe data abstrak karena pada setiap struck bisa didefinisikan dengan tipe data yang berbeda didalamnya. Setiap variabel dalam struct disebut anggota. Struct dapat digunakan untuk merepresentasikan data yang kompleks dengan cara yang terstruktur dan mudah dipahami. Struct mirip dengan class, tetapi dengan beberapa perbedaan utama. Struct tidak memiliki metode seperti class, dan anggotanya secara default bersifat public. struct bisa dilakukan dengan nested, artinya struck dapat dimasukan ke dalam struck lain [1].

Struct berfungsi membantu mengorganisir data yang terkait erat menjadi satu kesatuan sehingga lebih mudah untuk dikelola dan dipahami. Struct juga memungkinkan untuk membuat tipe data baru yang disesuaikan dengan kebutuhan spesifik pengguna [1]. Penggunaan struct dapat memudahkan untuk membaca kode dengan mengelompokkan data yang terkait dan memberikan nama yang deskriptif untuk setiap anggota. Mengakses anggota struct mudah dilakukan dengan menggunakan operator titik (.). 

Manfaat dari struct yaitu membantu membuat kode lebih terstruktur dan mudah dipahami terutama pada saat berurusan dengan data yang kompleks. Penggunaan struct dapat meningkatkan efektivitas pemrosesan kode dengan mengelompokkan data yang terkait dan menyediakan cara yang terorganisir untuk mengaksesnya. Kode yang terstruktur dengan baik menggunakan struct lebih mudah dipelihara dan dimodifikasi di masa depan. Struct meningkatkan keterbacaan kode dengan mengelompokkan data yang terkait dan memberikan nama yang deskriptif untuk setiap anggota.

## Guided 

### 1. Buatlah sebuah struktur dengan nama buku yang berisi judul_buku, pengarang, penerbit, tebal_halaman, harga_buku. Isi dengan nilai kemudian tampilkan.

```C++
#include <iostream>
using namespace std;

struct buku{
    string Judul_Buku;
    string Pengarang;
    string penerbit;
    int Tebal_Halaman;
    double Harga;
};buku buku1;buku buku2;

int main(){
    // Data buku 1
    buku1.Judul_Buku = "Algoritma Pemrograman";
    buku1.Pengarang = "Yunis Prademon";
    buku1.penerbit = "Gramedia Pustaka Utama";
    buku1.Tebal_Halaman = 300;
    buku1.Harga = 120000;
    // menampilkan informasi buku
    cout << "Informasi Buku" << endl;
    cout << "Judul\t\t: " << buku1.Judul_Buku << endl;
    cout << "Pengarang\t: " << buku1.Pengarang << endl;
    cout << "Penerbit\t: " << buku1.penerbit << endl;
    cout << "Jml. Halaman\t: " << buku1.Tebal_Halaman << endl;
    cout << "Harga\t\t: " << buku1.Harga << endl;

    // Data buku 2
    buku2.Judul_Buku = "The Principles of Power";
    buku2.Pengarang = "Dion Yulianto";
    buku2.penerbit = "Gramedia Pustaka Utama";
    buku2.Tebal_Halaman = 300;
    buku2.Harga = 120000;
    // menampilkan informasi buku
    cout << "Informasi Buku" << endl;
    cout << "Judul\t\t: " << buku2.Judul_Buku << endl;
    cout << "Pengarang\t: " << buku2.Pengarang << endl;
    cout << "Penerbit\t: " << buku2.penerbit << endl;
    cout << "Jml. Halaman\t: " << buku2.Tebal_Halaman << endl;
    cout << "Harga\t\t: " << buku2.Harga << endl;
}
```
Kode di atas merupakan program untuk membuat struck sederhana. progam diawali dengan mendeklarasikan struct dengan nama 'buku' yang didalamnya terdapat 5 anggota yang berisi informasi mengenai informasi buku seperti judul, pengarang, penerbit, jumlah halaman, dan harga. kemudian dilanjutkan dengan mendeklarasikan 2 objek yaitu 'buku1' dan 'buku2'. pada fungsi main(), dilakukan inisialisasi atau pengisian nilai nilai kedalam atribut-atribut 'buku1' dan 'buku2'. progam diakhiri dengan menampilkan informasi tentang buku yang terkandung dalam objek 'buku1' dan 'buku2' menggunakan perintah cout.

### 2. Buatlah sebuah struktur dengan skema seperti dibawah, isi dengan nilai kemudian jalankan.

```C++
#include <iostream>
using namespace std;

struct hewan{
    string nama_hewan;
    string kelamin;
    string berkembang;
    string pernafasan;
    string habitat;
    bool karnivora;
};

struct hewan_darat{
    hewan info_hewan;
    int kaki;
    bool menyusui;
    string suara;
};hewan_darat hewan1;

struct hewan_laut{
    hewan info_hewan;
    string sirip;
    string self_defence;
};hewan_laut hewan2;

int main(){
    // hewan pertama
    hewan1.info_hewan.nama_hewan = "Kuda";
    hewan1.info_hewan.kelamin = "cewek";
    hewan1.info_hewan.berkembang = "vivipar";
    hewan1.info_hewan.pernafasan = "Paru-paru";
    hewan1.info_hewan.habitat = "Darat";
    hewan1.info_hewan.karnivora = false; 
    hewan1.kaki = 4;
    hewan1.menyusui = true;
    hewan1.suara = "Mengeong";
    cout << "Nama Hewan : " << hewan1.info_hewan.nama_hewan << endl;
    cout << "Jenis kelamin : " << hewan1.info_hewan.kelamin << endl;
    cout << "Cara berkembangbiak : " << hewan1.info_hewan.berkembang << endl;
    cout << "Pernafasan : " << hewan1.info_hewan.pernafasan << endl;
    cout << "Tempat hidup : " << hewan1.info_hewan.habitat << endl;
    cout << "Apakah karnivora? " << hewan1.info_hewan.karnivora << endl;
    cout << "Jumlah kaki : " << hewan1.kaki << endl;
    cout << "Apakah menyusui" << hewan1.menyusui << endl;
    cout << "Suara: " << hewan1.suara << endl;

    // data hewan ke dua
    hewan2.info_hewan.nama_hewan = "Hiu";
    hewan2.info_hewan.kelamin = "cowok";
    hewan2.info_hewan.berkembang = "ovovivipar";
    hewan2.info_hewan.pernafasan = "Paru-paru";
    hewan2.info_hewan.habitat = "laut";
    hewan2.info_hewan.karnivora = true; 
    hewan2.sirip = "lancip";
    hewan2.self_defence= "gigi tajam";
    cout << "\nNama Hewan : " << hewan2.info_hewan.nama_hewan << endl;
    cout << "Jenis kelamin : " << hewan2.info_hewan.kelamin << endl;
    cout << "Cara berkembangbiak : " << hewan2.info_hewan.berkembang << endl;
    cout << "Pernafasan : " << hewan2.info_hewan.pernafasan << endl;
    cout << "Tempat hidup : " << hewan2.info_hewan.habitat << endl;
    cout << "Apakah karnivora? " << hewan2.info_hewan.karnivora << endl;
    cout << "Bentuk sirip : " << hewan2.sirip << endl;
    cout << "Pertahanan diri : " << hewan2.self_defence << endl;
}
```

code diatas menggambarkan tentang cara kerja struck bersarang. pada bagian awal, struck utama dideklarasikan dengan nama 'hewan' yang didalamnya terdapat 6 informasi mengenai ciri-ciri hewan. progam dilanjutkan dengan mendeklarasikan struck 'hewan_darat' dan 'hewan'laut' yang didalamnya memuat struck pertama dengan tambahan atribut yang spesifik terkait ciri-ciri hewan laut dan darat. pada fungsi main(), membuat objek 'hewan_darat' dengan nama 'hewan1' dan 'hewan_laut' dengan nama 'hewan2'. kemudian dilakukan pengisian nilai kedalam objek 'hewan1' dan 'hewan2'. progam diakhiri dengan menampilkan informasi 'hewan1' dan 'hewan2' menggunakan perintah cout.

## Unguided 

### 1. Modifikasi tugas guided pertama, sehingga setiap item yang terdapat pada struct buku berupa array yang berukuran 5, isi dengan data kemudian tampilkan.

```C++
#include <iostream>
#include <array>
using namespace std;

// Struct yang memuat tipe data abstrak terkait informasi buku
struct info_buku{
    string judul_buku;
    string pengarang;
    string penerbit;
    int jumlah_halaman;
    int harga;
};

int main(){
    const int n = 5; // panjang array
    array<info_buku, n> DataBuku; // deklarasi array
    // mengisi data ke dalam array
    DataBuku[0]={"Selamat Tingal", "Tere Liye", "Sabak Grip", 350, 85500};
    DataBuku[1]={"Pulang", "Tere Liye", "Republika Penerbit", 404, 90000};
    DataBuku[2]={"Si Anak Spesial", "Tere Liye", "Republika Penerbit", 329, 70000};
    DataBuku[3]={"Bumi", "Tere Liye", "Sabak Grip", 438, 92700};
    DataBuku[4]={"Berjuta Rasanya", "Tere Liye", "Mahaka", 205, 50000};

    // menampilkan data array menggunakan for loop
    for(int i=0; i < n; i ++){
        cout << "Informasi Buku ke-" << (i+1) << endl;
        cout << "Judul Buku\t: " << DataBuku[i].judul_buku << endl;
        cout << "Pengarang\t: " << DataBuku[i].pengarang << endl;
        cout << "Penerbit\t: " << DataBuku[i].penerbit << endl;
        cout << "Jml. Halaman\t: " << DataBuku[i].jumlah_halaman << endl;
        cout << "Harga\t\t: " << DataBuku[i].harga << endl<< endl;
        cout << endl;
    }
}
```
#### Output:
![Screenshot (204)](https://github.com/pan-don/Struktur_Data_Assigment/assets/157208689/6bf02f9c-7037-405f-8c8f-81c91827d22f)

code diatas merupakan progam untuk menampilkan array yang berasal dari struck 'info_buku'. pada bagian awal code, import library <array> untuk dapat menggunakan method array yang terdapat didalamnya. kemudian, mendefinisikan srtuck 'info_buku' yang dimana anggotanya berisi informasi mengenai ciri-ciri buku. pada fungsi main() dilanjutkan dengan mendeklarasikan array 'DataBuku' sepanjang 5 elemen yang dimana setiap elemen diisi dengan struktur 'info_buku'. pada bagian akhir, dengan menggunakan for loop menampilkan informasi masing-masing buku pada array. code akan menampilkan judul, pengarang, penerbit, jumlah halaman, dan harga buku menggunakan perintah cout.

### 2. Apa yang terjadi jika deklarasi variabel struct yang dibuat pada tugas guided I, berjenis Array. Bagaimana cara mengisi data dan menampilkannya?

Untuk mengisi data dari struck kedalam array dibutuhkan library <array>. pada pendefinisian array menggunakan code: "array<*nama_struck, *panjang_array>*nama_array;". array tersebut masih kosong sehingga harus diisi dengan cara menuliskan nama array beserta indeksnya(contoh: DataBuku[0] = untuk data array pertama). kemudian mengisi data sesuai dengan anggota yang terdapat didalam struck menggunakan kurung kurawal ({}). semua data pada array harus diisi sesuai dengan panjang yang sudah ditentukan diawal. untuk memanggil elemen array menggunakan code: "*nama_array[indeks].*nama_anggota_struck". walaupun anggota struck lebih dari 1, array yang dihasilkan merupakan array 1 dimensi. 

## Kesimpulan

struck adalah tipe data abstrak yang digunakan untuk mengelompokan beberapa variabel dengan tipe data berbeda sehingga menjadi satu kesatuan. dengan struck memungkinkan progam untuk untuk membuat tipe data baru sesuai dengan kebutuhan yang terdiri dari sejumlah variabel yang memiliki jenis data dan ukuran yang berbeda. struk sangat berguna untuk mengelompokan data yang saling terkait seperti struck 'info_buku' diatas yang berisi data mengenai informasi buku. dengan menggunakan struck dapat meningkatkan efisiensi waktu jika harus menulis objek dengan atribut yang sama. seperti namanya, struck membuat data menjadi terstruktur dan terorganisir sehingga memudahkan untuk dipahami. oleh karena itu struck menjadi tipe data yang sangat berguna dalam pengembangan perangkat lunak untuk mengelola dan memanipulasi data dengan cara yang lebih efisien.

## Referensi
[1] Mutongwa, Sanja Michael, and Silvance Abeka, "Journal of Scientific and Engineering Research". A Comparative Study of C, C++, C# and Java Programming Languages:Underpinning Structure Equation Modeling, Data Structures and Algorithm, vol. 6, no. 12, hal.162-171, 2019.