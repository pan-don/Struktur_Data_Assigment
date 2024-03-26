# <h1 align="center">Laporan Praktikum Modul Array</h1>
<p align="center">Afan Ramadhan</p>

## Dasar Teori

Array adalah elemen dengan jenis yang sama yang ditempatkan di lokasi memori yang berdampingan. Elemen-elemen tersebut dapat berupa satu per satu direferensikan oleh pengenal unik dengan indeks tambahan. Hal ini memungkinkan untuk mendeklarasikan beberapa nilai variabel dengan tipe tertentu dan mengaksesnya satu per satu tanpa perlu untuk mendeklarasikan variabel untuk setiap nilai. Array hanyalah sebuah blok lokasi memori berurutan untuk jenis variabel tertentu. Array dialokasikan dengan cara yang sama seperti variabel biasa, tetapi dengan tanda kurung siku ditambahkan ke namanya [] yang berisi jumlah elemen yang sesuai dengan panjang array. Elemen pada array dapat dipanggil menggunakan indeks, indeks array selalu dimauli dari nol 0 [1]. 

Secara ukuran array dibedakan menjadi 2 yaitu array tetap dan array dinamis. array tetap adalah array yang ukuran dan panjangnya telah ditentukan pada saat pendeklarasian array sehingga ukurannya tetap. Sedangkan array dinamis adalah array yang memiliki struktur data dafta ukuran variabel acak sehingga memungkinkan elemen individual untuk ditambahkan atau dihapus. pada C++ array dinamis dapat digunakan dengan menggunakan fungsi library bawaan '#include <list> std::list' yang didalamnya terdapat perintah untuk menambahkan dan menghapus elemen. 
### Array 1 Dimensi

Array 1 dimensi adalah kumpulan elemen-elemen yang bertipe data sama dan tersusun dalam satu larik atau baris. array 1 dimensi sering digunakan dalam operasi aritmatika, statistika deskriptif dan pengurutan. Pada operasi aritmatika dan statistika deskriptif array digunakan untuk menjumlahkan angka dan mencari nilai rata-rata yang terdapat didalam elemen array. Dengan adanya array juga dapat dengan mudah mengurutkan bilangan acak yang terdapat pada array. Setiap elemen array 1 dimensi dapat diakses dengan memasukan indeks dimulai dari 0 untuk elemen elemen pertama dan seterusnya. 


### Array 2 Dimensi 

array 2 dimensi merupakan variabel yang menyimpan data dengan tipe data yang sama dan dapat diakses melalui 2 indeks atau subskrip yaitu indeks baris dan indeks kolom. Array 2 dimensi mirip seperti matriks dalam matematika. Contoh penggunaan array ini sering kali digunakan untuk menentukan titik pada sebuah kordinat, membuat sebuah tabel data, dan untuk pemrosesan citra. Array 2 dimensi dapat menyimpan data dengan struktur yang lebih kompleks dari 1 dimensi sehingga memungkinkan untuk pemrosesan dan analisis data yang lebih efisien dan efektif.

### Array Multidimensi

array multidimensi merupakan struktur data yang memungkinkan menyimpan data yang lebih dari 2 dimensi. Array multidimensi sering digunakan untuk mempresentasikan data yang lebih kompleks atau tersturktur dengan baik. Struktur data yang kompleks pada array multidimensi ini membuat sulit untuk pengampikasiannya. Dalam pemrograman C++ tidak mendukung sintaks khusus untuk mengindeks array multi-dimensi. Sebagai gantinya, array seperti itu dipandang sebagai array dari sebuah array (mungkin larik, dan seterusnya), dan notasi indeks tunggal biasa [i] digunakan untuk setiap level. 

## Guided 

### 1. Progam Input Array Tiga Dimensi

```C++
#include <iostream>
using namespace std;

// PROGAM INPUT ARRAY 3 DIMENSI
int main(){
    // Deklarasi array
    int arr[2][3][3];
    // Input elemen
    for(int x = 0; x < 2; x++){
        for(int y = 0; y < 3; y++){
            for(int z = 0; z < 3; z++){
                cout <<"Input array[" << x << "] [" << y << "] [" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }

    //  Output array
    for(int x = 0; x < 2; x++){
        for(int y = 0; y < 3; y ++){
            for(int z = 0; z < 3; z ++){
                cout << arr[x][y][z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
}
```
Code diatas merupakan progam mengenai array 3 dimensi. progam ini dapat membuat array degan memasukan nilai elemen ke dalam array yang sudah ditentukan nilai ke-3 dimensinya. Array 3 dimensi tersebut dibuat dengan menggunakan 3 dimensi yang diwakilkan dengan huruf x,y, dan z('arr[x][y][z]'). Huruf x mewakili nilai dimensi kedalaman, huruf y mewakili nilai dimensi baris, dan huruf z mewakili nilai dimensi kolom. Untuk melakukan inputasi kedalam array 3 dimensi membutuhkan progam nesteed loop. Progam nesteed loop pada code diatas pada bagian looping pertama digunakan untuk imputasi nilai x, looping ke-2 untuk imputasi y, dan looping ke-3 untuk imputasi z. Menampilkan hasil array 3 dimensi juga harus menggunakan progam nesteed loop seperti progam imputasi sebelumnya.      

### 2. Progam Mencari Nilai maksimal Pada Array

```C++
#include <iostream>
using namespace std;

int main(){
    int maks, a, lokasi;
    cout << "Masukan panjang array: ";
    cin >> a;

    if(a <= 0){
        cout << "Panjang array harus lebih besar dari 0." << endl;
        return 1; // Return 1 to indicate error
    }

    int array[a];
    cout << "Masukan " << a << " angka\n";

    for(int i = 0; i < a; i++){
        cout << "Array ke-" << (i+1) << ": ";
        cin >> array[i];
    }

    maks = array[0];
    lokasi = 0;

    for(int i = 0; i < a; i++){
        if(array[i] > maks){
            maks = array[i];
            lokasi = i;
        }
    }

    cout << "\nNilai maksimum adalah " << maks 
         << " berada di array ke-" << (lokasi + 1) << endl;
    
    return 0; // return 0 to indicate successful execution
}
```
Code diatas merupakan progam untuk mencari nilai maksimum pada suatu array. Progam ini dapat mencari nilai tertinggi pada sebuah array acak yang bertipe data integer. Array pada code diatas harus dideklarasikan terlebih dahulu, dimulai dari menentukan panjang elemen array dan melakukan imputasi elemen array. Pada bagian imputasi panjang array harus lebih dari 0 jika tidak maka akan mengembalikan nilai 1 yang menandakan error pada code. Di bagian imputasi nilai elemen array menggunakan looping untuk memasukan nilai elemen kesetiap panjang elemen yang sudah ditentukan tadi. Setelah mendeklarasikan array selanjutnya mencari nilai maksimum menggunakan looping dan menampilkan hasilnya menggunakan perintah 'cout'. 

## Unguided 

### 1. Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user!

```C++
#include <iostream>
using namespace std;

// MENCARI BILANGAN GENAP DAN GANJIL PADA ARRAY
int main(){
    // Memasukan panjang array
    int n;
    cout << "Masukan panjang array: ";
    cin  >> n;
    if(n <= 0){
        cout << "Panjang array harus lebih dari 0";
        return 1;
    }

    // Memasukan nilai pada array
    int array[n];
    for(int i=0; i < n; i++){
        cout << "Masukan array ke-" << (i+1) << ": ";
        cin  >> array[i];
    }

    // Menampilkan array yang sudah dimasukan
    cout << "\nData Array: ";
    for(int i=0; i < n;i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    // Mencari dan menampilkan bilangan genap
    cout << "Genap : ";
    for(int i=0; i < n; i++){
        if(array[i] % 2 == 0){      // jika nilai array ke-i modulus 2 = 0, maka bernilai genap
            cout << array[i] << " ";
        }
    }
    cout << endl;

    // Mencari dan menampilkan bilangan ganjil
    cout << "Ganjil: ";
    for(int i=0; i < n; i++){
        if(array[i] % 2 == 1){       // jika nilai array ke-i modulus 2 = 1, maka bernilai ganjil
            cout << array[i] << " ";
        }
    }
    cout << endl;
}
```
#### Screenshot:
![Screenshot (75)](https://github.com/pan-don/Struktur_Data_Assigment/assets/157208689/ee814e49-a43e-42af-90f8-c964b7f4252f)

Code diatas merupakan program untuk mencari bilangan ganjil dan genap pada sebuah array. Program ini menggunakan array yang harus dideklarasikan terlebih dahulu. Pada bagian awal dilakukan inputasi untuk menentukan panjang array dan memasukan nilai elemen array bertipe data integer. Setelah mendeklarasikan array, progam akan menampilkan array yang sudah dibuat. Selanjutnya progam akan mencari bilangan genap dan ganjil menggunakan looping. Didalam looping akan ada percabangan, jika nilai elemen modulus 2 = 0 maka bilangan akan bernilai genap dan jika nilai elemen array modulus 2 = 1 maka bilangan akan bernilai ganjil. Looping tersebut akan terus berjalan sebanyak jumlah elemen array. Hasil akan ditampilkan menggunakan perintah 'cout'.

### 2. Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!

``` C++
#include <iostream>
using namespace std;

// PROGAM INPUT ARRAY 3 DIMENSI
int main(){
    int a, b, c;
    cout << "Masukan x: ";  // Memasukan dimensi untuk kedalaman
    cin >> a;
    cout << "Masukan y: ";  // Memasukan dimensi untuk baris
    cin >> b;
    cout << "Masukan z: ";  // Memasukan dimensi untuk kolom
    cin >> c;
    cout << endl;

    // Memasukan nilai ke dalam array
    int arr[a][b][c];
    for(int x = 0; x < a; x++){         // Dimensi untuk kedalaman
        for(int y = 0; y < b; y++){         // Dimensi untuk baris
            for(int z = 0; z < c; z++){         // Dimensi untuk kolom
                cout <<"Input array[" << x << "] [" << y << "] [" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }

    //  Menampilkan array 
    for(int x = 0; x < a; x++){       
        for(int y = 0; y < b; y ++){
            for(int z = 0; z < c; z ++){
                cout << arr[x][y][z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
}
```
#### Screenshot:

![Screenshot (76)](https://github.com/pan-don/Struktur_Data_Assigment/assets/157208689/f7aca27c-3ffc-4cfe-a3c6-e94af1b0633e)

Code diatas merupakan progam mengenai array 3 dimensi. progam ini dapat membuat array dengan menentukan dimensinya dan memasukan nilai elemen ke dalam array. Array 3 dimensi tersebut dibuat dengan menggunakan 3 dimensi yang diwakilkan dengan huruf x,y, dan z('arr[x][y][z]'). Huruf x mewakili nilai dimensi kedalaman, huruf y mewakili nilai dimensi baris, dan huruf z mewakili nilai dimensi kolom. Untuk melakukan inputasi kedalam array 3 dimensi membutuhkan progam nesteed loop. Progam nesteed loop pada code diatas pada bagian looping pertama digunakan untuk imputasi nilai x, looping ke-2 untuk imputasi y, dan looping ke-3 untuk imputasi z. Menampilkan hasil array 3 dimensi juga harus menggunakan progam nesteed loop seperti progam imputasi sebelumnya.

### 3. Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user!

```C++
#include <iostream>
using namespace std;

int main(){

    // Memasukan panjang array
    int n;
    cout << "Masukan panjang array: ";
    cin >> n;
    if(n <= 0){
        "Panjang array harus lebih dari 0";
        return 1;
    }

    // Memasukan nilai elemen array
    int array[n];
    for(int i=0; i<n; i++){
        cout << "Masukan nilai array ke-" << (i+1) << ": ";
        cin >> array[i];
    }

    // Menu untuk mencari nilai minimum, maksimum, dan rata-rata
    char pilih;
    cout << "\nDaftar pencarian:\n1. Nilai minimum\n2. Nilai maksimum\n3. Nilai rata-rata" << endl;
    cout << "Pilih nilai yang ingin dicari: ";
    cin >> pilih;

    // Menampilkan array yang telah dimasukan
    cout << "\nHasil Array    : [ ";
    for(int i=0; i<n; i++){
        cout << array[i] << " ";
    }
    cout << "]" << endl;

    // Membuat variabel untuk ke-3 menu
    int min = array[0];
    int max = array[0];
    float mean;

    // Percabagan untuk mencari nilai minimum, maksimum, dan rata-rata
    switch (pilih){
        case '1':
            // Mencari nilai minimum
            for(int i=0; i<n; i++){
                if(array[i] < min){
                    min = array[i];
                }
            }
            cout << "Nilai minimum  : " << min << endl;
            break;
        
        case '2':
            // Mencari nilai maksimum
            for(int i=0; i<n; i++){
                if( array[i] > max){
                    max = array[i];
                }
            }
            cout << "Nilai maksimum : " << max << endl;
            break;
        
        case '3':
            // Mencari nilai rata-rata
            for(int i=0; i<n; i++){
                mean = mean + array[i];
            }
            cout << "Nilai rata-rata: " << (mean/n) << endl;
            break;
        
        default:
            // Jika progam tidak melewati percabangan diatas, maka akan menampilkan dibawah ini
            cout << "Masukan pilihan yang tersedia!" << endl;
            break;
    }
    return 0;
}
```
#### Screenshot:

![Screenshot (77)](https://github.com/pan-don/Struktur_Data_Assigment/assets/157208689/56e78330-ee07-4194-93f8-47275353b976)

Code diatas merupakan progam untuk mencari nilai minimal, maksimal, dan rata-rata pada sebuah array. Dengan program ini dapat mencari ketiga nilai diatas pada array yang sudah dideklarasikan terlebih dahulu. Pada bagian awal program dilakukan pendeklarasian array dengan memasukan panjang dan nilai elemen pada array. Setelah mendekrasikan array progam akan mengarahkan ke pemilihan untuk mencari nilai minimal, maksimal, dan rata-rata. Pemilihan tersebut menggunakan perintah swicth case, jika memilih angka 1-3 maka akan diarahkan ke progam untuk mencari nilai tersebut dan jika memilih selain angka 1-3 maka program akan menampilkan 'Masukan pilihan yang tersedia!'. hasil dari swicth case akan ditampilkan menggunakan perintah 'cout'.

## Kesimpulan

Array adalah kumpulan variabel yang berisi data-data dengan tipe data yang sama dalam satu memori. Di dalam array dapat memuat lebih dari satu data tetapi harus bertipe data yang sama. Ada 3 hal penting dalam pendeklarasian array yaitu ada nama, panjang, dan tipe data array. Elemen-elemen yang terdapat pada array dapat dipanggil menggunakan index yang dimulai dari 0. Ada banyak hal yang bisa dengan mudah jika dilakukan dengan array seperti searching, sorthing, dan operasi aritmatika. Seperti contoh diatas kita dapat dengan mudah mencari bilangan genap atau ganjil pada sebuah larik data integer. Menurut ukurannya, array dibedakan menjadi 2 yaitu array tetap/stastik dan array dinamis. array tetap/stastik adalah array yang sudah ditentukan ukurannya pada saat pendeklarasian. Sedangkan array dinamis adalah array yang tidak ditentukan terlebih dahulu pada saat pendeklarasian dan ukurannya dapat bertambah seiring menambahkan elemen dalam array.

## Referensi
[1] L. Marllina,"PENGEMBANGAN SISTEM ARRAY DALAM MENENTUKAN
NILAI RATA-RATA TINGGI BADAN", REGY, vol. 1, No. 2, Mar. 2023.