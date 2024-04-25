# <h1 align="center">Laporan Praktikum Modul Searching</h1>
<p align="center">Afan Ramadhan</p>

## Dasar Teori

algoritma pencarian adalah algoritma yang dirancang untuk memecahkan masalah pencarian. Algoritma pencarian merupakan prosedur langkah demi langkah untuk menemukan sebuah data tertentu diantara kumpulan data. metode ini dapat dianggap sebagai metode yang mendasar dalam dunia komputasi. Dalam dunia komputer, algoritma ini menentukan seberapa cepat aplikasi berjalan. Banyak program-program yang berjalan menggunakan prinsip algoritma pencarian diantaranya seperti pencarian produk pada sebuah e-commerce. salah satu algoritma pencarian dasar yang sering digunakan adalah sequential/linear search dan binary search. 

### A. Sequential Search

Disebut linear atau sekuensial karena algoritma ini memindai elemen-elemen dalam daftar secara linier atau berurutan dengan memindai satu per satu elemen dalam daftar. Secara umum waktu yang dibutuhkan oleh pencarian linear adalah O(N) karena notasi Big-O hanya menentukan suku-suku ber-orde tertinggi dan mengabaikan koefisien dan suku-suku yang lebih rendah. Karena implementasinya yang paling sederhana, notasi ini dapat diterapkan pada list dan juga semua jenis linkedlist. Jadi mudah untuk mengimplementasikan tetapi tidak berguna ketika ukuran daftar terlalu besar besar. Karena waktu yang dibutuhkan sebanding dengan jumlah total jumlah elemen N [1].

### B. Binary Search 

Algoritma pencarian biner dapat diterapkan pada larik yang elemen-elemennya harus dibutuhkan dalam bentuk terurut. Setiap 
iterasi pencarian biner mempersempit interval pencarian hingga setengahnya dari interval pencarian pada iterasi sebelumnya. Waktu yang dibutuhkan oleh pencarian biner adalah O (log2 N). Algoritma binary search yang asli tidak dapat diterapkan pada linked karena pada dasarnya linked list bersifat dinamis dan tidak diketahui tidak diketahui di mana elemen tengah sebenarnya dialokasikan. Jadi Algoritma pencarian biner hanya dapat diterapkan pada array terurut 
baik yang statis maupun dinamis [1]. 

## Guided 

### 1. Buatlah sebuah project dengan menggunakan sequential search sederhana untuk melakukan pencarian data. Source code:

```C++
#include <iostream> 
using namespace std;

int main(){
    int n = 10;
    int angka[n]={9, 4, 1, 7, 5, 12, 4, 13, 4, 10};
    int cari = 10;
    bool ketemu = false;
    int i;

    // Algoritma Sequential Search
    for(i = 0; i < n; i++){
        if(angka[i] == cari){
            ketemu = true;
            break;
        }
    }

    cout << "\tProgam Sequential Search Sederhana\n" << endl;
    cout << "Data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;
    if (ketemu){
        cout << "\nAngka " << cari << " ditemukan pada indeks ke-" 
        << i << "\n" << endl;
    }
    else{
        cout << cari << " tidak dapat ditemukan pada data.\n" << endl;
    }
    return 0;
}
```

code diatas merupakan progam untuk mencari angka 10 pada sebuah array bertipe data integer. progam diawali dengan pendeklarasian panjang dan nilai array serta variabel yang menampung bilangan yang dicari,selain itu juga terdapat variabel untuk penanda. progam dilanjutkan dengan algoritma sequential search menggunakan for loop. looping dilakukan sebanyak panjang array dan setiap elemen array akan dibandingkan dengan data yang dicari. jika data yang dicari sama dengan elemen array maka akan mengisi variabel 'ketemu' dengan nilai true. selanjutnya akan ada percabangan jika variabel 'ketemu' bernilai true maka program akan mencetak data ditemukan pada array dan jika tidak ketemu maka  akan mencetak mencetak data tidak ditemukan menggunakan perintah cout.  

### 2. Buatlah sebuah project untuk melakukan pencarian data dengan menggunakan Binary Search:

```C++
#include <iostream>
#include <iomanip>

using namespace std;

int bil_data[7] = {1, 8, 2, 5, 4, 9, 7};
int cari;

void selection_sort() {
    int temp, min, i, j;
    for(i = 0; i < 7; i++) {
        min = i;
        for(j = i + 1; j < 7; j++) {
            if(bil_data[j] < bil_data[min]) {
                min = j;
            }
        }
        temp = bil_data[i];
        bil_data[i] = bil_data[min];
        bil_data[min] = temp;
    }
}

void binary_search() {
    int awal, akhir, tengah, b_flag = 0;
    awal = 0;
    akhir = 6;
    while (b_flag == 0 && awal <= akhir) {
        tengah = (awal + akhir) / 2;
        if(bil_data[tengah] == cari) {
            b_flag = 1;
            break;
        } else if(bil_data[tengah] < cari) {
            awal = tengah + 1;
        } else {
            akhir = tengah - 1;
        }
    }
    if(b_flag == 1) {
        cout << "\n Data ditemukan pada index ke-" << tengah << endl;
    } else {
        cout << "\n Data tidak ditemukan\n";
    }
}

int main() {
    cout << "\t BINARY SEARCH\n";
    cout << "\n Data : ";
    // tampilkan data awal
    for(int x = 0; x < 7; x++) {
        cout << setw(3) << bil_data[x];
    }
    cout << endl;
    cout << "\n Masukkan data yang ingin Anda cari : ";
    cin >> cari;
    cout << "\n Data diurutkan : ";
    // urutkan data dengan selection sort
    selection_sort();
    // tampilkan data setelah diurutkan
    for(int x = 0; x < 7; x++) {
        cout << setw(3) << bil_data[x];
    }
    cout << endl;
    binary_search();
    return 0;
}
```

code diatas merupakan program untuk mencari data yang diinput pada sebuah array bertipe data integer. progam diawali dengan deklarasi array lalu membuat fungsi pengurutan menggunakan algoritma selection sort. data yang digunakan untuk searching dengan metode binary search harus terurut terlebih dahulu secara ascending. algoritma selection sort dilakukan dengan membandingkan data sekarang dengan data yang paling kecil lalu ditukar hingga semua data terurut. setelah data terurut baru bisa dilakukan proses pencarian. pencarian menggunakan algoritma binary search dilakukan dengan menentukan nilai tengah kumpulan data lalu membandingkannya dengan data yang dicari. jika data yang dicari lebih kecil dari median maka data yang lebih besar dari median akan dihapus. data yang tersisa akan dibandingkan lagi untuk dicari nilai tengahnya dan dibandingkan dengan data yang dicari. proses tersebut akan berulang hingga data ditemukan atau data habis. 

## Unguided 

### 1. Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!

```C++
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
```

#### Output:
![Screenshot (203)](https://github.com/pan-don/Struktur_Data_Assigment/assets/157208689/81835b61-3994-4899-85e2-583c838c2898)

code diatas merupakan progam untuk mencari sebuah huruf pada sebuah kalimat (string). progam diawali dengan pendeklarasian variabel bertipe data string yang berisi kalimat 'tanah airku'. kemudian progam dilanjutkan ke algoritma selection sort untuk mengurutkan huruf-huruf yang terkandung dalam kalimat tersebut dari yang pertama. setelah semua huruf terurut maka progam akan diarahkan langsung ke fungsi binary_search untuk melakukan proses searching sesuai data yang dicari. proses ini diawali dengan mencari nilai tengah dari string tersebut lalu membandingkan nilai tengah dengan data yang dicari, apakah nilainya lebih besar atau kecil. jika nilainya lebih kecil maka data yang nilainya lebih besar dari median akan dihapus dan sisanya akan dicari lagi nilai tengahnya untuk dibandingkan lagi. proses tersebut akan terus berulang hingga data yang dicari ditemukan atau data terhapus semua. progam diakhiri dengan menampilkan indeks data yang dicari.

### 2. Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!

```C++
#include <iostream>
using namespace std;

int main() {
    string kalimat = "Garuda Indonesia";
    // menampilkan kalimat
    cout << "Kalimat:  " << kalimat << endl;

    int jumlahVokal = 0;
    // sequential search
    for (char huruf : kalimat) {
        // memperkecil huruf pada kalimat
        char lowercaseHuruf = tolower(huruf);
        // jika data sama dengan salah satu huruf vokal
        if (lowercaseHuruf == 'a' || lowercaseHuruf == 'e' || lowercaseHuruf == 'i' ||
            lowercaseHuruf == 'o' || lowercaseHuruf == 'u') {
            jumlahVokal++; // menambahkan angka 1 ke variabel 'JumlahVokal'
        }
    }
    // menampilkan jumlah huruf vokal
    cout << "\nJumlah huruf vokal: " << jumlahVokal << endl;   
}
```

#### Output:
![Screenshot (201)](https://github.com/pan-don/Struktur_Data_Assigment/assets/157208689/56c00c90-dd80-4a5c-9fcf-e35f8dc2b327)

progam diatas digunakan untuk mencari huruf vokal (a, i, u, e, o) pada kalimat "Garuda Indonesia". progam diawali dengan deklarasi variabel 'kalimat' bertipe data string dan 'jumlahVokal' untuk menghitung jumlah huruf vokal. progam dilanjutkan dengan algoritma sequential search menggunakan for loop. pertama, setiap huruf yang ada di variabbel 'kalimat' akan di kecilkan untuk memudahkan pencarian lalu jika setiap huruf pada kalimat merupakan huruf vokal (a, i, u, e, o) maka akan menambahkan 1 angka ke variabel 'jumlahVokal'. progam diakhiri dengan mencetak variabel 'jumlahVokal' untuk menampilkan jumlah huruf vokal yang terdapat pada kalimat 'Garuda Indonesia'. 


### 3. Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search

```C++
#include <iostream>
using namespace std;

int main(){
    // deklarasi array
    int arr[10]={9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    // menampilkan data array
    cout << "\nData: ";
    for(int i=0; i < 10; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    // deklarasi variabel 'JumlahAngka' untuk menyimpan jumlah angka 4 
    int JumlahAngka = 0;
    for(int i=0; i < 10; i++){
        // jika nilai array indeks ke-i = 4
        if(arr[i] == 4){
            JumlahAngka++; // menambahkan angka 1 ke 'JumlahAngka'
        }
    }
    // menampilkan jumlah angka 4
    cout << "Jumlah angka 4 dalam array: " << JumlahAngka << endl; 
}
```

#### Output:
![Screenshot (202)](https://github.com/pan-don/Struktur_Data_Assigment/assets/157208689/78d6c426-ffe3-4606-a592-d4861d0deb8f)

code diatas merupakan progam untuk mencari berapa banyak angka 4 pada sebuah array bertipe data integer. progam diawali dengan mendekrasikan array lalu menampilkannya menggunakan perintah for loop dan cout. pencarian angka 4 dilakukan menggunakan algoritma sequential search dengan for loop. elemen pada setiap array dibandingkan dengan angka 4, jika sama maka akan menambahkan angka 1 pada variabel 'JumlahAngka'. progam diakhiri dengan mencetak variabel 'JumlahAngka' untuk menampilkan jumlah angka 4 pada array tersebut menggunakan perintah cout 

## Kesimpulan

Algoritma pencarian adalah algoritma yang digunakan untuk mencari suatu data pada sekumpulan data. algoritma ini merupakan salah satu algoritma dasar yang sering digunakan. terdapat 2 macam algoritma pencarian yang sering digunakan yaitu sequential\linear search dan binary search. prinsip kerja algoritma sequential search adalah dengan membandingkan setiap data dengan data yang dicari dari awal hingga akhir array. algoritma ini mudah untuk dikodekan dan cocok untuk array yang tidak terurut. tetapi terdapat beberapa kelemahan seperti membutuhkan proses yang lama jika data yang dicari berada diakhir array karena kompleksitas waktu dari algoritma ini adalah O(n). selanjutnya algoritma binary search, cara kerja metode ini adalah dengan mengurutkan array secara ascending lalu mencari nilai tengahnya yang kemudian akan dibandingkan dengan data yang dicari, jika data lebih kecil maka nilai yg lebih besar dari median akan dihapus. sisa data yang ada akan dicari lagi nilai mediannya dan dibandingkan, proses ini akan terus berlanjut hingga data ketemu atau habis. kompleksitas waktu algoritma ini adalah O(log n) sehingga pencarian ini akan lebih capat dari linear search jika data yang digunakan besar. 

## Referensi
[1] Parmar, Vimal P, and Khumbhara, "International Journal of Computer Applications".Comparing Linear Search and Binary Search Algorithms to Search an Element from a Linear List Implemented through Static Array, Dynamic Array and Linked List, Vol.121, No.3, Hal.0975–8887, juli 2015.

