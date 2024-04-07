# <h1 align="center">Laporan Praktikum Modul Sorting</h1>
<p align="center">Afan Ramadhan</p>

## Dasar Teori

Sorting atau pengurutan merupakan teknik untuk mengurutkan sebuah larik data baik secara menaik(ascending) dan menurun(discending). Algoritma Pengurutan digunakan untuk menyusun ulang larik atau daftar elemen tertentu sesuai dengan operator pembanding pada elemen. Operator pembanding digunakan untuk menentukan urutan baru dari elemen-elemen dalam struktur data yang bersangkutan. Terdapat 3 algoritma pengurutan yang sering digunakan diantaranya adalah Bubble sort, Selection sort, dan Insertion sort.

Diantara ketiga algoritma dasar ini, Bubble sort dan Selection sort tidak efisien tetapi sangat mudah untuk dikodekan. Algoritma ini sangat penting dalam studi akademis tetapi tidak menjadi perhatian dalam praktik. Di sisi lain, Insertion sort meskipun berada di kelas orde n2 berkinerja baik untuk mengurutkan ukuran sampel yang kecil bersama dengan algoritme kelas n2. Insertion sort lebih cepat di antara algoritma-algoritma pengurutan kelas n2 [1]. berikut adalah penjelasan mengenai algoritma pengurutan tersebut secara lebih lengkap:

#### 1. Bubble Sort

Bubble sort adalah algoritma pengurutan berbasis perbandingan di mana setiap pasangan elemen yang berdekatan dibandingkan satu sama lain dan elemen-elemen tersebut ditukar jika tidak dalam urutan yang diperlukan. Untuk algoritma bubble sort secara ascending, posisi akhir dari elemen terbesar ditetapkan terlebih dahulu dan kemudian elemen yang lebih kecil menempati tempat terakhirnya, yaitu urutan diurutkan dari tempat terakhir ke tempat pertama [2]. Bubble sort melakukan pengurutan dengan membandingkan n elemen dan menukar elemen yang tidak diurut yankan ke dalam urutan, proses ini diulang untuk n lintasang sama.

#### 2. Selection Sort

Selection sort adalah algoritma pengurutan berbasis perbandingan di mana elemen terkecil dipilih dan ditempatkan pada posisi pertama dalam urutan (dalam pengurutan menaik) dan kemudian elemen terkecil kedua dipilih dari elemen yang tersisa dan sekali lagi dimasukkan ke dalam posisi kedua, prosesnya terus berlanjut hingga semua elemen diurutkan dan mencapai posisi akhir [2]. Algoritma ini berulang kali memilih elemen terkecil (atau terbesar) dari bagian yang tidak diurutkan dari daftar dan menukarnya dengan elemen pertama dari bagian yang tidak diurutkan. Proses ini diulangi untuk bagian yang belum diurutkan sampai seluruh daftar terurut. Dengan konsep ini algoritma selection sort memiliki kompleksitas waktu O(n^2) dalam kasus terburuk.

#### 2. Insertion Sort

Insertion sort mirip dengan cara kita menyusun kartu remi di tangan kita. Kita membandingkan kartu yang baru diambil dengan setiap kartu yang sudah ada di tangan kita dan kemudian menempatkannya pada posisi yang tepat dan jika tangan kita kosong, kartu yang baru diambil mengambil posisi pertama, tetapi dalam kasus insertion sort, kita membandingkan elemen-elemen, bukan kartu dan menempatkannya pada posisi yang tepat. Kita menyimpan elemen pertama di tempatnya dan membandingkan elemen kedua dengan elemen pertama dan menyimpannya di tempat yang tepat kemudian kita membandingkan elemen ketiga dengan elemen pertama dan kedua dan menyisipkannya ke tempat yang tepat. Iterasi ini terus berlanjut hingga kita mencapai akhir urutan [2].

## Guided 

### 1. Mengurutkan secara ascending untuk data numerik bertipe double menggunakan Algoritma Bubble Sort

```C++
#include <iostream>
using namespace std;

void bubble_sort(double arr[], int length){
    bool not_sorted = true;
    int j=0;
    double tmp;

    while (not_sorted){
        not_sorted = false;
        j++;
        for(int i = 0; i < length - j; i++){
            if(arr[i] > arr[i + 1]){
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                not_sorted = true;
            } // end to if
        } // end of for loop
    } // end of while loop
} // end of bubble_sort

void print_array(double a[], int length){
    for(int i = 0; i < length; i++){
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main(){
    int length = 5;
    double a[] = {22.1, 15.3, 8.2, 33.21, 99.99};

    cout << "Urutan bilangan sebelum sorting: " << endl;
    print_array(a, length);

    bubble_sort(a, length);

    cout << "\nUrutan bilangan setelah sorting: " << endl;
    print_array(a, length);    
}
```
Kode di atas digunakan untuk mengurutkan array bertipe data double. Pengururutan ini menggunakan algoritma bubble sort dimana pasangan elemen yang berdekatan dibandingkan satu sama lain dan elemen tersebut ditukar sesuai secara ascending. Terdapat 3 fungsi untuk menjalankan kode ini yaitu fungsi bubble_sort, print_array, dan main. Fungsi bubble sort diawali dengan deklarasi variabel 'tmp' yang digunakan untuk menyimpan nilai minimum dan perbandingan elemen array menggunakan while loop dimana jika array ke-i lebih besar dari array selanjutnya maka nilai array akan disimpan ke variabel 'temp' yang nantinya akan ditukar dengan array ke-i. Fungsi print_array digunakan untuk mencetak array, sedangkan fungsi main merupakan fungsi utama untuk mendeklarasikan array serta tempat untuk menampilkan array setelah dan sebelum sorting.  

### 2. Mengurutkan karakter secara descending (dari terbesar hingga terkecil) menggunakan Algoritma Insertion Sort

```C++
#include <iostream>
using namespace std;

void insertion_sort(char arr[], int length){
    int i, j;
    char tmp;

    for(i = 1; i < length; i++){
        j = i;

        while(j > 0 && arr[j - 1] < arr[j]){
            tmp = arr[j];
            arr[j] =  arr[j - 1];
            arr[j -1] = tmp;
            j--;
        } // end of while loop
    } // end of for loop
} // end of insertion_sort

void print_array(char a[], int length){
    for(int i = 0; i < length; i++){
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main(){
    int length = 6;
    char a[length] = {'c', 'f', 'a', 'z', 'd', 'p'};

    cout << "Urutan karakter sebelum sorting: " << endl;
    print_array(a, length);

    insertion_sort(a, length);

    cout << "\nUrutan karakter setelah sorting: " << endl;
    print_array(a, length);
}
```
kode diatas merupakan kode pengurutan elemen array secara descending menggunakan algoritma selection sort. Kode dijalankan menggunakan tiga fungsi yaitu insertion_sort, print_array, dan main. fungsi insertion_sort diawali dengan mendeklarasikan variabel 'tmp', 'i' dan 'j'. variabel i dan j digunakan untuk interasi pada while dan for loop sedangkan variabel 'tmp' digunakan untuk menyimpan nilai array terbesar. For loop digunakan untuk perulangan sebanyak panjang array dan while loop digunakan untuk membandingkan jika array ke-j > array sebelum j dan variabel 'j' > 0. Jika persyaratan while loop terpenuhi maka akan menyimpan array ke-j ke dalam variabel 'tmp' yang nantinya akan digunakan untuk menukar antara kedua elemen array. Selanjutnya fungsi print_array digunakan untuk mencetak array, sedangkan fungsi main merupakan fungsi utama untuk mendeklarasikan array serta tempat untuk menampilkan array setelah dan sebelum sorting.

## Unguided 

### 1. Kelas S1 IF 2016 G memiliki 5 mahasiswa. Pada akhir semester mereka menerima lembar Indeks Prestasi Semester (IPS), masing-masing mahasiswa tersebut memiliki IPS sebagai berikut: {3.8, 2.9, 3.3, 4.0, 2.4}. Buatlah program untuk mengurutkan IPS mahasiswa tersebut dari yang terbesar hingga terkecil dengan menggunakan algoritma Selection Sort! (Score: 30)

```C++
#include <iostream>
using namespace std;

// Algoritma pengurutan menggunakan bubble sort
void selection_sort(double arr[], int length){
    // deklarasi variabel max untuk menyimpan nilai maksimum dan 
    // temp untuk menyimpan bilangan yang akan ditukar.
    int max;
    float temp;

    for(int i=0; i < length - 1; i++){
        max = i;
        for(int j= i+1; j < length; j++){
            // jika array ke-j lebih besar dari array ke-max maka 
            // menyimpan j sebagai indeks array paling maksimum ke variabel max.
            if(arr[j] > arr[max])
                max = j;
        }
        if(max !=i){
            temp = arr[i];
            arr[i] = arr[max];
            arr[max] = temp;
        }
    }
}

// fungsi untuk menampilkan array bertipe data double.
void print_array(double arr[], int length){
    for(int i = 0; i < length; i++){
        cout << arr[i] << "\t";
    }
    cout << endl;
}

// fungsi utama untuk menampilkan array sebelum dan sesudah sorting.
int main(){
    int length = 5;
    double a[] = {3.8, 2.9, 3.3, 4.0, 2.4};

    // menampilkan array sebelum sorting menggunakan fungsi print_array
    cout << "lembar Indeks Prestasi Semester (IPS) sebelum sorting: " << endl;
    print_array(a, length);
    
    // menampilkan array sesudah sorting menggunakan fungsi print_array
    // yang sudah diururtkan menggunakan fungsi selection_sort.
    cout << "\nlembar Indeks Prestasi Semester (IPS) setelah sorting: " << endl;
    selection_sort(a, length);
    print_array(a, length);    
}
```
#### Output:
![Screenshot (184)](https://github.com/pan-don/Struktur_Data_Assigment/assets/157208689/05450a1a-5fc4-461f-af28-eb3aad2cb01d)

Kode diatas merupakan kode untuk mengurutkan nilai lembar Indeks Prestasi Semester (IPS) mahasiswa secara menaik. Pengurutan ini menggunakan algoritma selection sort pada array dengan panjang 5 dan bertipe data double. Terdapat 3 fungsi dalam kode ini yaitu selection_sort, print_array, dan main. fungsi selection_sort, seperti namanya fungsi ini digunakan untuk mengurutkan dengan menyeleksi array ke-i dengan elemen array lainnnya, jika elemen tersebut lebih besar dari array ke-i maka akan ditukar. Proses ini menggunakan nesteed for loop sehingga memiliki kompleksitas waktu O(n^2) dan di dalamnya terdapat percabangan jika array ke-j lebih besar dari variabel 'max' maka akan ditukar hingga semua data terurut. Selanjutnya fungsi print_array digunakan untuk mencetak array, sedangkan fungsi main merupakan fungsi utama untuk mendeklarasikan array serta tempat untuk menampilkan array setelah dan sebelum sorting.

### 2. Pak RT memiliki 10 warga dengan nama: siti, situ, sana, ana, ani, caca, cici, dida, dodo, dan dadi. Supaya mudah dalam melakukan pencarian, Pak RT akan mengurutkan nama-nama tersebut sesuai dengan alfabet. Buatlah program untuk membantu Pak RT dengan menggunakan algoritma Bubble Sort! (Score: 30)

```C++
#include <iostream>
#include <cstring> // header yang menyediakan fungsi untuk mengoperasikan string karakter
using namespace std;

// Algoritma pengurutan menggunakan bubble sort
void bubble_sort(const char* arr[], int length){
    bool not_sorted = true;
    int j = 0;
    const char* tmp;

    while (not_sorted){
        not_sorted = false;
        j++;
        for(int i = 0; i < length - j; i++){
            // Menggunakan strcmp untuk membandingkan string secara keseluruhan
            if(strcmp(arr[i], arr[i + 1]) > 0){
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                not_sorted = true;
            } //akhir if statment
        } // akhir for loop
    } // akhir while loop
}

// fungsi untuk menampilkan array bertipe data const char*/string
void print_array(const char* a[], int length){
    for(int i = 0; i < length; i++){
        cout << a[i] << "\t";
    }
    cout << endl;
}

// fungsi utama untuk menampilkan array sebelum dan sesudah sorting.
int main(){
    int length = 10;
    const char* a[] = {"siti", "situ", "sana", "ana", "ani", "caca", "cici", "dida", "dodo", "dadi"};

    // menampilkan array sebelum sorting menggunakan fungsi print_array
    cout << "Urutan nama warga sebelum sorting: " << endl;
    print_array(a, length);
    
    // menampilkan array sesudah sorting menggunakan fungsi print_array
    // yang sudah diurutkan menggunakan fungsi bubble sort
    cout << "\nUrutan nama warga setelah sorting: " << endl;
    bubble_sort(a, length);
    print_array(a, length);    
}
```
#### Output:
![Screenshot (185)](https://github.com/pan-don/Struktur_Data_Assigment/assets/157208689/55b0f4e3-5d33-4367-8db5-e307fe7ca743)

Kode di atas digunakan untuk mengurutkan array bertipe data const char* atau string. Pengurutan ini dilakukan secara ascending dan menggunakan algoritma bubble sort. Terdapat 3 fungsi yang menjalankan progam ini yaitu bubble_sort, print_array, dan main. Pada fungsi bubble sort diawali dengan deklarasi variabel 'tmp' yang digunakan untuk menyimpan nilai minimum serta variabel 'i' dan 'j' sebagai iterasi untuk while dan for loop. Pengurutan dilakukan dengan membandingkan satu persatu antara elemen yang berdekatan dengan menggunakan perintah 'strcmp'. 'Strcmp' merupakan perintah untuk membandingkan data bertipe string secara keseluruhan, 'strcmp' dapat dipanggil menggunakan header '<cstring>'. Selanjutnya fungsi print_array digunakan untuk mencetak array, sedangkan fungsi main merupakan fungsi utama untuk mendeklarasikan array serta tempat untuk menampilkan array setelah dan sebelum sorting.  

### 3. Buatlah program yang meminta user menginputkan suatu bilangan n dan meminta user untuk menginputkan sejumlah n karakter. Kemudian program akan melakukan sorting secara menaik (ascending) dan menurun (descending)! (Score: 40)

```C++
#include <iostream>
using namespace std;

// fungsi sorting secara ascending
void ascending(char arr[], int length){
    int min;
    char temp;

    for(int i=0; i < length - 1; i++){
        min = i;
        for(int j= i+1; j < length; j++){
            // jika array ke-j < array ke-min maka
            // menyimpan j ke variabel min sebagai indek array dgn nilai minimum
            if(arr[j] < arr[min])
                min = j;
        }
        if(min !=i){
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

// fungsi sorting secara descending
void descending(char arr[], int length){
    int max;
    char tmp;

    for(int i=0; i < length - 1; i++){
        max = i;
        for(int j= i+1; j < length; j++){
            // jika array ke-j > array ke-min maka
            // menyimpan j ke variabel min sebagai indek array dgn nilai maksimum
            if(arr[j] > arr[max])
                max = j;
        }
        if(max !=i){
            tmp = arr[i];
            arr[i] = arr[max];
            arr[max] = tmp;
        }
    }
}

// fungsi untuk menampilkan array bertipe data char
void print_array(char arr[], int length){
    for(int i = 0; i < length; i++){
        cout << arr[i] << "\t";
    }
    cout << endl;
}

// fungsi utama untuk menampilkan array sebelum dan sesudah sort
int main(){
    cout << "Progam Sorting Karakter" << endl;
    // menentukan panjang array
    int length;
    cout << "Input (n) = ";
    cin >> length;
    if(length <= 0){
        cout << "Panjang karakter harus lebih dari 0";
        return 1;
    }

    // memasukan data karakter ke dalam elemen array
    char arr[length];
    for(int i = 0; i < length; i++){
        cout << "Masukan karakter ke-" << (i+1) << ": ";
        cin >> arr[i];
    }

    // menampilkan array sebelum di sorting
    cout << "\nUrutan karakter sebelum sorting:" << endl;
    print_array(arr, length);

    // menampilkan array yang sudah di sorting secara ascending
    cout << "\nUrutan karakter setelah ascending sort:" << endl;
    ascending(arr, length);
    print_array(arr, length);
    
    // menampilkan array yang sudah di sorting secara descending
    cout << "\nUrutan karakter setelah descending sort:" << endl;
    descending(arr, length);
    print_array(arr, length);
}   
```
#### Output:
![Screenshot (186)](https://github.com/pan-don/Struktur_Data_Assigment/assets/157208689/0cc8d235-1e74-48de-ba58-a182e65e7719)

Kode di atas merupakan kode untuk mengurutkan array bertipe data char dengan data yang diinputkan sendiri oleh user. Terdapat 2 hasil pengurutan yaitu secara ascending dan descending dimana keduanya menggunakan algoritma selection sort dalam mengurutkannya. Pada fungsi main, pengguna diminta untuk mendeklarasikan array dengan memasukan panjang array dan nilai didalamnya. Kemudian progam akan diarahkan ke fungsi ascending dan descending yang mana hasinya akan dicetak menggunakan fungsi print_array. Didalam fungsi main selain mendeklarasikan array juga akan menampilkan array yang dibuat serta array setelah pengurutan ascending dan descending. 

## Kesimpulan

Algoritma sorting adalah suatu langkah yang bertujuan untuk mengurutkan elemen-elemen yang berada pada sebuah himpunan data(array) menjadi urutan yang diinginkan. Pengurutan ini dapat dilakukan secara menaik(ascending) dan menurun(descending). Terdapat berbagai macam algoritma yang dapat digunakan untuk melakukan pengurutan, 3 diantaranya yang populer adalah bubble sort, selection sort, dan insetion sort. Algoritma ini mempunyai kompleksitas waktu O(n^2) sehingga memakan waktu cukup lama untuk memproses data yang besar. Walaupun begitu algoritma ini mudah dikodekan sehingga banyak yang menggunakannya. Pengurutan data sangat membantu dalam berbagai hal, seperti membantu melakukan pencarian data yang lebih efisisen dan memungkinkan data ditampilkan secara lebih terstruktur dan mudah dibaca. 

## Referensi
[1]  O.K. Durrani, S. AbdulHayan, Performance Measurement of Popular Sorting
Algorithm Implemented using Java and Python, Ramanagara: VTU; 2023.
[2] P. Kavdikar, Comparative study of sorting algorithms, New Delhi: 2021.