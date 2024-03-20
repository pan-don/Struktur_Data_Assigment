# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Afan ramadhan</p>

## Dasar Teori

tipe data adalah klasifikasi nilai suatu variabel yang membantu operasi komputer untuk mengenali nilai data tanpa menghasilkan error. tipe data dapat memudahkan komputer dalam menerjemahkan informasi dan meminimalkan kesalahan karena pada dasarnya komputer hanya memahami bahasa biner(0 dan 1). dalam bahasa pemrograman, tipe data di klasifikasikan dalam berbagai jenis diantaranya:
 - Tipe data primitif
 - Tipe data abstrak
 - Tipe data koleksi

### 1. Tipe Data Primitif

tipe data primitif adalah tipe data dasar yang tersedia dalam  pemrograman komputer dan biasanya didukung langsung oleh bahasa pemrograman itu sendiri tanpa harus mendefinisikan terlebih dahulu. berikut adalah contoh tipe data primitif yang paling sering digunakan: 
 1. Integer(int): merupakan tipe data yang digunakan untuk meyimpan bilangan bulat seperti 1, 0, -9, dan lainnya.
 2. Float: merupakan tipe data yang digunakan untuk meyimpan bilangan desimal seperti 3.14, 2.5, -0.1, dan lain-lain.
 3. Character(char): digunakan untuk meyimpan huruf. tipe data ini biasanya menggunakan tanda petik untuk mendifinisikannya 
 4. boolean(bool): tipe data yang berisi nilai boolean yaitu  benar atau salah.

### 2. Tipe Data Abstrak

tipe data abstrak adalah tipe data yang didefinisikan oleh pengguna itu sendiri. pada umumnya tipe data abstrak tidak didefinisikan secara langsung melainkan hanya melalui operasi matematis tertentu. berikut contoh tipe data abstrak:
 1. Class: berfungsi untuk mendefinisikan tipe data baru dengan menyatukan data(attribut) dan metode terkait. class biasanya digunakan untuk membuat objek dalam OOP. pada C++, class memiliki akses default public yang berarti anggota pada class dapat digunakan pada fungsi lain.
 2. Struct: tipe data yang digunakan untuk mengelompokkan beberapa tipe data yang berbeda ke dalam satu unit.ada sedikit perbedaan antara struct dan class. akses default struct adalah privat, artinya anggota dari struct hanya bisa digunakan di dalam struct itu sendiri. 

### 3. Tipe Data Koleksi

tipe data koleksi adalah  tipe data yang digunakan untuk mengelompokkan dan menyimpan beberapa elemen data dalam satu unit. Tipe data koleksi memungkinkan untuk menyimpan dan mengelola sekumpulan data dengan cara yang terstruktur dan mudah diakses. beberapa yang termasuk tipe data koleksi yang sering digunakan sebagai berikut:
 1. Array adalah tipe data koleksi yang menyimpan sejumlah elemen data yang serupa dalam satu unit. Elemen-elemen dalam array diakses menggunakan indeks numerik.
 2. Map adalah tipe data koleksi yang memetakan kunci ke nilai. Map memungkinkan untuk mengakses nilai berdasarkan kunci yang terkait.
 3. vector adalah tipe data koleksi yang dapat menyimpan elemen-elemen dalam urutan tertentu.  Vector memiliki kemampuan untuk menyesuaikan ukurannya secara otomatis saat elemen-elemen baru ditambahkan atau dihapus.

## Guided 

### 1. Tipe Data Primitif

```C++
#include <iostream>
using namespace std;

// main progam
int main(){
    char op;
    float num_1, num_2;

    //  It allows user to enter numbers
    cin >> op;
    //  It allows user to enter operator +, -, *, /
    cin >> num_2 >> num_1;

    // switch statement begins
    switch (op){
        // if user enter +
        case '+':
            cout << num_1 + num_2;
            break;
        //  if user enter -
        case '-':
            cout << num_1 - num_2;
            break;
        //  if user enter *
        case '*':
            cout << num_1 * num_2;
            break;
        // of user enter /
        case '/':
            cout << num_1 / num_2;
            break;
        // if the operator is other than +, -, *, /
        // error message will display
        default:
            cout << "error! operator is not correct";
    } // swicth statement ends
    return 0;
}
```
Kode diatas merupakan progam kalkulator sederhana. Didalam kalkulator tesedia 4 macam operasi seperti tambah(+), kurang(-), kali(*), dan bagi(/). Progam dibuat menggunakan satu fungsi 'main'. Fungsi berisi dimulai dengan pembuatan variabel 'op' bertipe data karakter dan diisi dengan pilihan operator(+, -, *, /) serta variabel 'num_1' dan 'num_1' bertipe data float yang diisi bilangan yang akan dioperasikan.

progam dilanjutkan dengan perintah 'cin' yaitu perintah untuk memasukan data ke variabel 'op', 'num_1', dan 'num_2'. setelah itu progam diarahkan ke switch case. switch case merupakan perintah untuk pengkondisian dimana pengkondisian ini ditentukan oleh data yang dimasukan ke variabel 'op'. Jika variabel 'op' berisi operasi(+, -, *, /) yang nantinya akan diarahkan ke rumus dan akan menampilkan hasil dari operasi tersebut. Tetapi jika variabel 'op' berisi selain dari operasi maka akan menampilkan "error! operator is not correct". progam akan berhenti setelah melewati switch case.

### 2. Tipe Data Abstrak

```C++
#include <iostream>
#include <stdio.h>
using namespace std;

// struct
struct mahasiswa{
    const char*name;
    const char*address;
    int age;
};

int main(){
    // menggunakan struct
    struct mahasiswa mhs1, mhs2;
    // mengisi nilai ke struct
    mhs1.name = "Dian";
    mhs1.address = "Mataram";
    mhs1.age = 22;
    mhs2.name = "Bambang";
    mhs2.address = "Surabaya";
    mhs2.age = 23;

    // mencetak isi struct
    cout<<"Mahasiswa 1\n";
    cout<<"Nama  : "<<mhs1.name<<endl;
    cout<<"Alamat: "<<mhs1.address<<endl; 
    cout<<"Umur  : "<<mhs1.age<<endl;

    cout<<"\nMahasiswa 2\n";
    cout<<"Nama  : "<<mhs2.name<<endl;
    cout<<"Alamat: "<<mhs2.address<<endl; 
    cout<<"Umur  : "<<mhs2.age<<endl;
    return 0;
}
```
code progam diatas merupakan code yang berisi mengenai struct. Struct diawali dengan mendeklarasikan anggota dengan nama 'name', 'address', dan 'age'. 'name' dan 'addres' memiliki tipe data string dan 'age' memiliki tipe data integer. anggota tersebut berada disebuah struct yang dinamai 'mahasiswa'. konten yang berada didalam struct dapat dipanggil atau digunakan pada fungsi lain.

fungsi main diawali dengan mendeklarasikan dua variabel yang bertipe 'mahasiswa' dengan nama 'mhs1' dan 'mhs2'. Kemudian mengisi nilai ke dalam struktur 'mhs1' dan 'mhs2' dengan menguunakan 'name', 'address', dan 'age'. setelah mengisi nilai, menampilkan data yang berada pada variabel 'mhs1' dan 'mhs2' menggunakan perintah 'cout'.

### 3. Tipe Data Koleksi

```C++
#include <iostream>
using namespace std;

int main(){

    // deklarasi dan inisiasi array
    int nilai[5];
    nilai[0] = 23;
    nilai[1] = 50;
    nilai[2] = 34;
    nilai[3] = 78;
    nilai[4] = 90;

    // mencetak array
    cout<<"Isi array pertama: "<< nilai[0]<<endl;
    cout<<"Isi array kedua: "<< nilai[1]<<endl;
    cout<<"Isi array ketiga: "<< nilai[2]<<endl;
    cout<<"Isi array keempat: "<< nilai[3]<<endl;
    cout<<"Isi array kelima: "<< nilai[4]<<endl;
    return 0;
}
```
code progam diatas berisi mengenai array. pada bagian pertama diawali dengan pendeklarasian array dengan nama 'nilai' yang berisi 5 elemen yang bertipe data integer. 'nilai' diisi dengan angka 23, 50, 34, 78, 90 sesuai dengan urutan index. bagian kedua merupakan cara pemanggilan data array. elemen pada array dapat dipanggil menggunakan index. data 'nilai' dicetak menggunakan perintah 'cout' dengan cara menulis nama array lalu ditambahkan dengan kurung siku yang didalamnya berisi index data yang ingin dicari.      

## Unguided 

### 1. Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!

```C++
#include <iostream>
using namespace std;

// fungsi untuk mengonversi celcius ke farenheit
float farenheit(float celcius){
    return (9.0/5.0 * celcius) + 32; // mengembalikan hasil konversi
}

// fungsi untuk mengonversi celcius ke reamur
float reamur(float celcius){
    return (4.0/5.0) * celcius; // mengembalikan hasil konversi
} 

// fungsi untuk mengonversi celcius ke kelvin
float kelvin(float celcius){
    return celcius + 273.15; // mengembalikan hasil konversi
}

int main(){
    char pilih;
    float celcius;

    cout << "===== KONVERSI SATUAN SUHU CELCIUS =====" << endl;
    cout << "Masukan suhu dalam satuan celcius: ";
    cin >> celcius; // input untuk memasukan nilai suhu celcius
    printf("\n1. Farenheit\n2. Kelvin\n3. Reamur");
    cout << "\nPilih konversi tujuan: ";
    cin >> pilih ; // input untuk memilih konversi suhu celcius

    switch (pilih){
        // jika nilai input 'pilih' = 1, maka akan diarahkan ke dikonversi farenheit
        case '1':
            cout << "\nHasil konversi suhu " << celcius << "`C: "
                 << farenheit(celcius) << "`F"<<endl;
                 break;
        // jika nilai input 'pilih' = 2, maka akan diarahkan ke dikonversi kelvin
        case '2':
            cout << "\nHasil konversi suhu " << celcius << "`c: "
                 << kelvin(celcius) << "`K" << endl; 
                 break;
        // jika nilai input 'pilih' = 3, maka akan diarahkan ke dikonversi reamur
        case '3':
            cout << "\nHasil konversi suhu " << celcius << "`c: "
                 << reamur(celcius) << "`R" << endl;
                 break;
        default:
            // jika nilai input 'pilih' selain pilihan diatas maka akan menampilkan dibawah ini
            cout << "\nMasukan pilihan yang tersedia!" << endl;
                 break;
    }
    return 0; // indikasi progam selesai dan mengembalikan nilai 0
}
```
#### Output:
![Screenshot (70)](https://github.com/pan-don/Struktur_Data_Assigment/assets/157208689/2febdd3f-b5d1-44e0-8b8b-2cd0a4bfd631)

code diatas merupakan progam mengenai konversi suhu celcius. dengan progam ini memungkinkan kita mengubah nilai suhu dari satuan celcius ke satuan yang lain seperti farenheit, kelvin, dan reamur. progam ini terdiri dari 4 fungsi dimana 1 fungsi utama sebagai tempat untuk memasukan data dan 3 fungsi lainnya sebagai tempat untuk mencari hasil dari nilai konversi yang telah dimasukan. 

progam diawali dengan deklarasi variabel 'pilih' yang bertipe data karakter dan 'celcius' yang bertipe data float. variabel 'pilih' berguna sebagai variabel input untuk memilih satuan konversi yang dicari. variabel 'celcius' berfungsi sebagai variabel input yang memuat nilai suhu celcius yang akan dikonversi. progam dilanjutkan dengan pengimputan variabel 'pilih' dan 'celcius' menggunakan perintah cin. variabel 'pilih' melewati proses percabangan(switch case), jika variabel yang berisi angka 1 maka akan diarahkan ke konversi farenheit, 2 ke kelvin, dan 3 ke reamur yang nantimya akan diarahkan ke fungsi konversi yang dipilih. akan tetapi jika variabel pilih berisi selain dari angka 1-3 maka progam akan menampilkan "Masukan pilihan yang tersedia!" menggunakan perintah cout.

#### Kesimpulan:

Tipe data primitive adalah tipe data yang hanya mampu menyimpan satu nilai pada setiap satu variabel. tipe data ini merupakan tipe data dasar yang sering digunakan program [1]. tipe data primitif juga biasanya memiliki representasi yang langsung didukung oleh hardware komputer, sehingga operasi menggunakan tipe data primitif seringkali lebih cepat dan efisien daripada tipe data yang lebih kompleks. Operasi matematika dan logika sederhana seringkali dapat diterapkan langsung pada tipe data primitif, seperti penjumlahan, pengurangan, perkalian, dan perbandingan. dapat dilihat pada progam diatas melakukan operasi rumus matematis menggunakan tipe data primitif dan proses tersebut dapat dijalankan secara langsung yang nantinya akan meningkatkan efisiensi waktu.

### 2. Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya

Class digunakan untuk mengorganisir data bersama yang memiliki hubungan satu sama lain. Ini membantu dalam menciptakan abstraksi yang kuat dan menyederhanakan kompleksitas program. Class menyediakan cara untuk membungkus data bersama dengan metode atau fungsi yang beroperasi pada data tersebut. Ini memungkinkan untuk mengontrol akses dan manipulasi data dengan cara yang terstruktur. Class lebih banyak digunakan untuk objek yang dimana setiap proses di dalamnya saling berhubungan[3].

Struct digunakan untuk merepresentasikan kumpulan data sederhana yang terkait secara logis. Mereka cocok untuk kasus-kasus di mana Anda hanya perlu menyimpan beberapa data bersama tanpa perilaku tambahan. Struct sering digunakan untuk membuat tipe data baru dengan mudah. Mereka tidak memerlukan banyak kode tambahan untuk penggunaan dasar, seperti pendefinisian konstruktor atau penggunaan inheritance. Struct juga biasa digunakan untuk struktur data atau objek yang sebenarnya, menyimpan data menggunakan variabel dan membuat fungsi[3].

```C++
#include <iostream>
using namespace std;

// class dengan akses default: private
class buah_a{
    string asam;
    string manis;
};

// class yang sudah dirubah akses defaultnya ke public
class buah_b{
    public:
    string dikotil;
    string monokotil;
};

// struct dengan akses default: public
struct hewan_a{
    string herbivora;
    string karnivora;
};

// struct yang sudah dibuah akses defaultnya ke private
struct hewan_b{
    private:
    string darat;
    string laut;
};

/*
Class dan struct yang bersifat public, anggotanya dapat 
diakses di fungsi yang lain
*/
int main(){
    // mengisi nilai ke class
    class buah_b buah1, buah2;
    buah1.dikotil = "kentang";
    buah2.monokotil = "kelapa";
    // mencetak isi class
    cout << "\nBuah dikotil   : " << buah1.dikotil
         << "\nBuah monokotil : " << buah2.monokotil << endl;

    // mengisi nilai ke struct
    struct hewan_a hewan1, hewan2;
    hewan1.herbivora = "kuda";
    hewan2.karnivora = "singa";
    // mencetak isi struct
    cout << "Hewan herbivora: " << hewan1.herbivora
         << "\nHewan karnivora: " << hewan2.karnivora << endl;
}
```
### Output:
![Screenshot (71)](https://github.com/pan-don/Struktur_Data_Assigment/assets/157208689/d24c3d46-a7e6-4862-afbc-efcc8de395ff)

code ini menjelaskan mengenai class dan struct. di dalam kode ini terdapat 2 class dan 2 struct yang mana di masing-masing tipe data abstrak ini ada yang menggunakan akses default sesuai warisan dan ada yang telah diubah. class memiliki akses default private sehingga hanya bisa diakses secara internal. sedangkan struct memiliki akses default public yang berarti class tersebut bisa diakses secara eksternal. akan tetapi akses dafault tersebut dapat dirubah menggunakan perintah 'public:' atau 'private:'.

progam diawali dengan deklarasi anggota pada dua buah tipe data abstrak class dan struct. pada bagian akhir progam menggunakan fungsi main mendeklarasikan variabel 'buah1', 'buah2', 'hewan1', dan 'hewan2' menggunakan tipe data abstrak 'buah_b' dan 'hewan_a' yang merupakan class dan struct yang memiliki akses default public. selanjutnya mengisi nilai kedalam variabel tersebut yang nantinya akan dicetak menggunakan perintah cout.

### 3. Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map.

 1. array: cara dasar C++ untuk merepresentasikan urutan objek dalam memori. Jika apa yang dinginkan adalah urutan panjang tetap sederhana dari objek-objek dengan tipe tertentu dalam memori, array adalah solusi yang ideal [1].
 2. map:  struktur data asosiatif yang memetakan kunci ke nilai. Dalam banyak bahasa pemrograman, termasuk C++, map biasanya diimplementasikan sebagai koleksi berurut dari pasangan kunci-nilai, di mana setiap kunci harus unik.

#### Perbedaan array dan map 

array adalah kumpulan elemen dengan tipe data sama sedangkan map adalah struktur hash dari pasangan kunci dan nilai serta bisa menggunakan berbagai tipe data[2]. elemen pada array diakses menggunakan index bilangan bulat yang dimulai dari 0 sedangkan elemen map diakses menggunakan kunci dari setiap elemen. array dapat berupa 1D, 2D, atau multidimensi sedangkan map berupa multimap, multimap tidak terurut, dan lainnya.

```C++
#include <iostream>
using namespace std;
#include <map>

int main(){
    // contoh array
    int harga[3];
    harga[0] = 2500;
    harga[1] = 1000;
    harga[2] = 500;
    // mencetak array
    cout << "\nIsi array ke-1: " << harga[0] << endl;
    cout << "Isi array ke-2: " << harga[1] << endl;
    cout << "Isi array ke-3: " << harga[2] << endl;

    // contoh map
    map < string, int > nilai;
    nilai["matematika"] = 73;
    nilai["statistika"] = 82;
    nilai["kalkulus"] = 79;
    // mencetak map
    cout << "Isi map ke-1: " << nilai["matematika"] << endl;
    cout << "Isi map ke-2: " << nilai["statistika"] << endl;
    cout << "Isi map ke-3: " << nilai["kalkulus"] << endl;
}
```
#### Output:
![Screenshot (72)](https://github.com/pan-don/Struktur_Data_Assigment/assets/157208689/8ad949bd-179a-43de-9470-76be4d00623e)

kode diatas merupakan perbandingan penggunaan array dan map. pada penggunaan array harus dedifinisikan terlebih dahulu tipe data, nama array, dan panjang array. pada code diatas deklarasi array menggunakan nama 'nilai' dengan tipe data integer dan memiliki panjang 3 index. pengisian nilai ke array dimulai dari mendefinisikan letak data yang akan dimasukan ke dalam array menggunakan index. suatu data array dapat dipanggil dengan mencantumkan nama array serta index yang akan dituju menggunakan perintah cout.

kode yang kedua merupakan contoh penggunaan map. untuk membuat map harus menyertakan header '<map>' yang berisi perintah map. penggunaan map hampir sama seperti array. dalam map terdapat key dan value dimana key sebagai kata kunci untuk mengakses nilai yang terkandung dalam suatu map. seperti contoh diatas jika memasukan katakunci 'statistika' maka akan keluar nilai berupa 82. map dapat diisi dengan berbagai tipe data. 

## Kesimpulan
tipe data merupakan klasifikasi nilai suatu variabel yang membantu operasi komputer untuk mengenali nilai data tanpa menghasilkan error. ada 3 jenis tipe data diantaranya tipe data primitif, abstrak, dan koleksi. diantara ketiga jenis tersebut tentu memiliki kelebihan dan kekurangan masing-masing. contohnya tipe data primitif yang merupakan tipe data dasar yang mudah dipahami tetapi susah  jika menangani data yang kompleks. 
tipe data abstrak yang lebih sering digunakan untuk meangani data yang kompleks tetapi untuk membuatnya harus didefinisikan terlebih dahulu. tipe data koleksi yang dapat menyimpan data secara bersamaan tetapi akan memakan lebih banyak memori. jadi akan lebih bijak jika menggunakan tipe data sesuai dengan keperluan sehingga dapat meningkatkan efisiensi dalam melakukan pemrosesan data. 

## Referensi
[1] B. Stroustrup, "C++ Programming language", 4th, Boston: Addison-Wesley, 2013,pp 171-449.
[2] Jonathan, (18, Ceptember, 2023), Difference between Array and Map[Online], Avaible: https://www.geeksforgeeks.org/difference-between-array-and-map, [Accesed 20 Mei 2024]
[3] A. Arsito, (25, January, 2021), Swift: Class vs. Struct, Avaible: https://medium.com/dipantry/swift-class-vs-struct-c0b279b1dfaf, [Accesed 20 Mei 2024] 