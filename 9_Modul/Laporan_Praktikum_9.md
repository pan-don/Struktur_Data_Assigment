# <h1 align="center">Laporan Praktikum Modul Rekursif & Hash Table</h1>
<p align="center">Afan Ramadhan</p>

## Dasar Teori

Rekursi adalah secara langsung atau tidak langsung memanggil fungsinya sendiri, dan proses pemanggilannya disebut rekursi. Masalah yang dapat diselesaikan secara rekursif adalah dengan membagi masalah menjadi satu atau lebih masalah kecil yang serupa [1]. Rekursif merupakan sebuah teknik di pemrograman, di mana sebuah fungsi memanggil dirinya sendiri. Mirip dengan loop (pengulangan), yang kedua tujuannya memanggil aksi yang sama berkali-kali. Rekursi sering digunakan untuk menyelesaikan masalah yang lebih kompleks yang tidak bisa (sulit) diselesaikan dengan loop biasa atau kode implementasinya akan sangat sulit dibaca jika menggunakan loop (iterasi).

Hash table merupakan struktur data yang secara asosiatif menyimpan data. Dalam hal ini, data disimpan dalam format array, di mana setiap nilai data memiliki nilai indeks uniknya sendiri. Tabel hash digunakan untuk mengindeks sekumpulan array untuk memudahkan proses pencarian. Sebagai contoh PIN perusahaan menggunakan 5 digit, rentang nilainya adalah 00000-99999. Hash function adalah fungsi yang digunakan untuk mengubah nilai kunci menjadi nilai yang disebut alamat hash. Alamat hash ini mewakili indeks posisi dalam array [1]. Array yang digunakan untuk menyimpan data melalui hashing di namakan tabel hash. Tabel hash biasanya disebut sebagai struktur data, yang digunakan untuk menyimpan data berdasarkan fungsi hash. 

## Guided 

### 1. Rekursif Langsung (Direct Recursion)

```C++
#include <iostream>
using namespace std;
//Code ini berfungsi untuk melakukan hitung mundur
//dari angka yang diinputkan
void countdown(int n) {
    if (n == 0) {
        return;  
    }

    cout << n << " ";
    countdown(n - 1);
}

int main() {
    cout << "Rekursif Langsung: ";
    countdown(5); //5 merupakan input nya
    cout << endl;
    return 0;
}
```

Code diatas merupakan progam untuk melakukan hitung mundur dari bilangan menggunakan fungsi rekursif. Pada fungsi utama main memanggil fungsi coutdown dengan memasukan  (n = 5) didalamnya. Fungsi coutdown sendiri digunakan untuk melakukan rekursif langsung dengan menampilkan hasil hitung mundur dan akan diarahkan ke fungsi itu lagi dengan (n - 1) sehingga fungsi akan menampilkan angka '5 4 3 2 1'. Apabila (n = 0) maka progam akan keluar dari fungsi.

### 2. Rekursif Tidak Langsung (Indirect Recursion)

```C++
#include <iostream>
using namespace std;

void functionB(int n);

void functionA(int n) {
    if (n > 0) {
        cout << n << " ";
        functionB(n - 1); // Panggilan rekursif tidak langsung
    }
}

void functionB(int n) {
    if (n > 0) {
        cout << n << " ";
        functionA(n / 2); // Panggilan rekursif tidak langsung
    }
}

int main() {
    int num = 5;
    cout << "Rekursif Tidak Langsung: ";
    functionA(num);
    return 0;
}
```

Code diatas merupakan progam untuk melakukan hitung mundur menggunakan rekursif dengan 2 fungsi. Pada fungsi utama main, progam memanggil fungsi 'functionA' dengan angka yang sudah dideklarasikan sebelumnya yaitu 5 pada variabel num. Pada fungsi A, jika (n > 0) maka fungsi akan menampilkan n dan kemudian mengarahkan ke fungsi B dengan (n - 1). Di fungsi B, jika (n > 0) maka fungsi akan menampilkan n dan mengarahkan balik ke fungsi A dengan (n / 2). Progam akan terus berputar di kedua fungsi sampai (n = 0). Jika memasukan angka 5 pada functionA seperti diawal, maka output yang dikeluarkan akan seperti ini '5 4 2 1'.

### 3. Hash Table

```C++
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int TABLE_SIZE = 11;
string name;
string phone_number;

class HashNode {
    public:
    string name;
    string phone_number;
    HashNode(string name, string phone_number) {
        this->name = name;
        this->phone_number = phone_number;
    }
};

class HashMap {
    private:
        vector<HashNode*> table[TABLE_SIZE];
    public:
        int hashFunc(string key) {
            int hash_val = 0;
            for (char c : key) {
            hash_val += c;
            }
            return hash_val % TABLE_SIZE; // 4 bisa aja 204,12004, 6 bisa aja 266, 300
        }

    void insert(string name, string phone_number) {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val]) {
            if (node->name == name) {
                node->phone_number = phone_number;
            return;
            }
        }
        table[hash_val].push_back(new HashNode(name, phone_number));
    }

    void remove(string name) {
        int hash_val = hashFunc(name);
        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++) {
            if ((*it)->name == name) {
                table[hash_val].erase(it);
                return;
            }
        }
    }
    
    string searchByName(string name) {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val]) {
            if (node->name == name) {
                return node->phone_number;
            }
        }
        return "";
    }

    void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
            for (auto pair : table[i]) {
                if(pair != nullptr){
                    cout << "[" << pair->name << ", " <<
                    pair->phone_number << "]";
                }
            }
        cout << endl;
        }
    }
};

int main() {
    HashMap employee_map;   
    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");
    cout << "Nomer Hp Mistah : " <<employee_map.searchByName("Mistah") <<
    endl;
    cout << "Phone Hp Pastah : " <<employee_map.searchByName("Pastah") <<
    endl;
    cout << "Phone Hp Ghana : " <<employee_map.searchByName("Ghana") <<
    endl;
    employee_map.remove("Mistah");
    cout << "Nomer Hp Mistah setelah dihapus : "
    <<employee_map.searchByName("Mistah") << endl << endl;
    cout << "Hash Table : " << endl;
    employee_map.print();
    return 0;
}
```

Code diatas merupakan progam untuk menyimpan nama dan nomor telepon orang menggunakan hash table. Pada bagian awal progam, menginpor library string dan vector. Kemudian mendeklarasikan panjang tabel, nama, dan nomor telepon. Pada fungsi HashNode membuat 2 node 'name' dan 'phone_number' yang diatur ke publik. Pada fungsi HashMap membuat vektor tabel untuk menyimpan data yang diatur ke provate dan membuat key sebagai penunjuk yang diatur ke publik. Di fungsi ini juga terdapat fungsi lagi didalamnya yang digunakan untuk pengoperasian hash table seperti manambahkan, menghapus, mencari, dan menampilkan. Pada fungsi main, merubah nama fungsi HashMap ke employee_map. Kemudian dilakukan operasi yang tersedia pada fungsi HashMap dan akan menampilkan hasilnya menggunakan fungsi print pada bagian akhir.

## Unguided 

### 1. Buatlah sebuah program Rekursif Langsung (Direct Recursion) yang menghitung nilai faktorial dari sebuah inputan bilangan bulat positif!

```C++
#include <iostream>
using namespace std;

// fungsi rekursif dengan mengkalikan n dengan fungsi yang lebih kecil
int faktorial(int n) {
    if (n > 0) {
        return n * faktorial(n - 1);
    }
    return 1;  
}

// fungsi utama
int main() {
    int input;
    cout << "Masukan bilangan bulat positif: ";
    cin >> input;
    cout << "Faktorial dari bilangan " << input << " adalah: ";
    cout << faktorial(input);
    return 0;
}
```

#### Output:
![Screenshot (306)](https://github.com/pan-don/Struktur_Data_Assigment/assets/157208689/7ec4f1ef-45e4-4a5a-ba68-a826c65218f1)

Code diatas merupakan progam untuk mencari nilai faktorial dari bilangan yang dimasukan user menggunakan teknik rekursif 1 fungsi. Pada fungsi main, user diminta untuk memasukan bilangan yang ingin dicari nilai rekursifnya dan akan disimpan pada variabel 'input'. Pencarian nilai faktorial dialakukan pada fungsi 'faktorial' dimana jika (n > 0) maka akan mengembalikan nilai dari perkailan n dengan fungsi itu sendiri dengan (n - 1). Dan jika (n = 0) maka akan mengembalikan nilai 1 yang menandakan progam selesai. Hasil faktorial akan ditampikan pada fungsi main dengan perintah cout.

### 2. Buatlah versi program Rekursif Tidak Langsung (Indirect Recursion) dari soal nomor 1 di atas!

```C++
#include <iostream>
using namespace std;

int faktorialB(int n);

int faktorialA(int n) {
    if (n > 0) {
        return n * faktorialB(n - 1); // Panggilan rekursif tidak langsung
    }
    return 1;
}

int faktorialB(int n) {
    if (n > 0) {
        return n * faktorialA(n-1); // Panggilan rekursif tidak langsung
    }
    return 1;
}

int main() {
    int input;
    cout << "Masukan bilangan bulat positif: ";
    cin >> input;
    cout << "Faktorial dari bilangan " << input << " adalah: ";
    cout << faktorialA(input);
    return 0;
}
```

#### Output:
![Screenshot (307)](https://github.com/pan-don/Struktur_Data_Assigment/assets/157208689/db0f0d12-c6a3-4ded-8dba-285b4a97d491)

Code diatas merupakan progam untuk mencari nilai faktorial dari suatu bilangan yang diinputkan user menggunakan teknik rekursif 2 fungsi. Untuk menjalankan teknik ini, dibutuhkan 2 buah fungsi yaitu fungsi 'faktorialA' dan 'faktorialB'. Pada fungsi main, user diminta untuk memasukan bilangan yang akan di fatorialkan dan inputan tersebut akan disimpan dalam variabel 'input'. Variabel tersebut akan difaktorialkan ke fungsi 'faktorialA'. Pada fungsi 'faktorialA', jika (n > 0) maka progam akan mengembalikan perkalian n dengan fungsi 'faktorialB' dengan (n - 1). Pada fungsi 'faktorialB', jika (n > 0) maka progam akan mengembalikan perkalian n dengan fungsi 'faktorialA' dengan (n - 1). Progam akan terus berputar hingga (n = 0) dan  akan mengembalikan hasil faktorial dari bilangan yang diinputkan serta akan menampilkan hasilnya pada fungsi main menggunakan perintah cout

### 3. Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai.

```C++
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// inisiasi jumlah baris tabel
const int TABLE_SIZE = 11;

// membuat 2 node: nim dan nilai 
class HashNode {
    public:
    string nim;
    int nilai;
    HashNode(string nim, int nilai) {
        this->nim = nim;
        this->nilai = nilai;
    }
};

class HashMap {
    private:
        vector<HashNode*> table[TABLE_SIZE];
    public:
        // mengubah key menjadi integer
        int hashFunc(string key) {
            int hash_val = 0;
            for (char c : key) {
                hash_val += c;
            }
            return hash_val % TABLE_SIZE;
        }

        // menambahkan data 
        void insert(string nim, int nilai) {
            int hash_val = hashFunc(nim);
            for (auto node : table[hash_val]) {
                if (node->nim == nim) {
                    node->nilai = nilai;
                    return;
                }
            }
            table[hash_val].push_back(new HashNode(nim, nilai));
        }

        // menghapus data
        void remove(string nim) {
            int hash_val = hashFunc(nim);
            for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++) {
                if ((*it)->nim == nim) {
                    delete *it;  // Free memory
                    table[hash_val].erase(it);
                    return;
                }
            }
        }

        // mencari nilai berdasarkan nim
        int searchByName(string nim) {
            int hash_val = hashFunc(nim);
            for (auto node : table[hash_val]) {
                if (node->nim == nim) {
                    return node->nilai;
                }
            }
            return -1;  // NIM not found
        }
        
        // menampilkan data yang terdapat pada hash table
        void print() {
            for (int i = 0; i < TABLE_SIZE; i++) {
                cout << i << ": ";
                for (auto pair : table[i]) {
                    if(pair != nullptr){
                        cout << "[" << pair->nim << ", " << pair->nilai << "] ";
                    }
                }
                cout << endl;
            }
        }

        // menampilkan data dengan rentang 80-90
        void rentang() {
            for (int i = 0; i < TABLE_SIZE; i++) {
                cout << i << ": ";
                for (auto pair : table[i]) {
                    if(pair != nullptr && pair->nilai >= 80 && pair->nilai <= 90){
                        cout << "[" << pair->nim << ", " << pair->nilai << "] ";
                    }
                }
                cout << endl;
            }
        }
};

// menu utama
int main(){
    HashMap employee_map;
    while (true) {
        int pilih;
        cout << "\nData Nilai Mahasiswa" << endl;
        cout << "--------------------" << endl;
        cout << "1. Tambah data baru" << endl;
        cout << "2. Hapus data" << endl;
        cout << "3. Cari data berdasarkan NIM" << endl;
        cout << "4. Cari data berdasarkan rentang nilai" << endl;
        cout << "5. Tampilkan data" << endl;
        cout << "6. Keluar" << endl;
        cout << "\nMasukan pilihan: ";
        cin >> pilih;
    
        switch (pilih) {
        case 1: {
            string nim;
            int nilai;
            cout << "Masukan NIM: ";
            cin >> nim;
            cout << "Masukan nilai: ";
            cin >> nilai;
            employee_map.insert(nim, nilai);
            break;
        }

        case 2: {
            string nim;
            cout << "Masukan NIM yang dihapus: ";
            cin >> nim;
            employee_map.remove(nim);
            cout << "NIM: " << nim << " berhasil dihapus!" << endl;
            break;
        }

        case 3: {
            string nim;
            cout << "Masukan NIM yang dicari: ";
            cin >> nim;
            int nilai = employee_map.searchByName(nim);
            if (nilai != -1) {
                cout << "Nilai untuk NIM " << nim << " adalah: " << nilai << endl;
            } else {
                cout << "NIM " << nim << " tidak ditemukan." << endl;
            }
            break;
        }

        case 4: {
            cout << "Data dengan rentang nilai 80-90" << endl;
            employee_map.rentang();
            break;
        }

        case 5: {
            employee_map.print();
            break;
        }

        case 6: {
            cout << "Program selesai!" << endl;
            return 0;
        }   

        default:
            cout << "Masukan pilihan yang tersedia!" << endl;
            break;
        }
    }
}
```

#### Output:
![Screenshot (308)](https://github.com/pan-don/Struktur_Data_Assigment/assets/157208689/7049cedc-13c8-436f-b046-85114448ced7)

Code diatas merupakan progam menu untuk menyimpan nilai mahasiswa dengan key NIM menggunakan hash table. Pada bagian awal progam, menentukan jumlah baris hash table dan membuat fungsi HashNode untuk mendeklarasikan 2 buah node yaitu 'nim' dan 'nilai' yang bersifat publik. Kemudian membuat fungsi HashMap yang didalamnya terdapat fungsi lagi seperti fungsi HashFunc yang digunakan untuk hashing key (NIM) dan fungsi lainnya yang digunakan untuk operasi hash table seperti menambahkan, menghapus, menampilkan, dan mencari data. Pada fungsi main, menginisialisasi fungsi HashMap dan merubahnya dengan nama 'employee_map'. Selain itu juga terdapat pilihan menu yang berisi tentang operasi hash table. User dapat memilih operasi-operasi yang diinginkan dengan mengimputkan nomor pilihan yang nantinya akan diarahkan ke fungsi yang dipilih.

## Kesimpulan

Rekursif merupakan teknik dalam pemrograman dimana sebuah fungsi memanggil fungsi dirinya sendiri yang lebih kecil untuk memecahkan masalah yang lebih kecil dari masalah yang lebih besar. Kebanyakan rekursif akan memecahkan masalah secara descending. Contohnya seperti diatas, dimana teknik rekursif digunakan untuk mencari bilangan faktorial yaitu bilangan yang dikalikan dengan bilangan (n -1) sampai angka 1. Beberapa algoritma, seperti quicksort, mergesort, dan backtracking  dapat diimplementasikan secara lebih alami dan intuitif dengan pendekatan rekursif dibandingkan iteratif. Rekursi menggunakan stack untuk menyimpan state dari setiap panggilan fungsi. Untuk masalah yang memerlukan banyak panggilan rekursif, ini bisa menyebabkan penggunaan memori yang besar dan bahkan stack overflow.

Hash table adalah struktur data yang menyediakan cara yang efisien untuk menyimpan dan mengambil data menggunakan kunci. Digunakan untuk penyimpanan dan pengambilan data dengan cepat berdasarkan kunci, seperti dalam implementasi tabel simbol dalam kompilator, caching, dan berbagai aplikasi yang membutuhkan pencarian cepat. Algoritma hash digunakan secara luas terutama dalam otentikasi login dan memverifikasi integritas pesan. Dalam hal ini, algoritma hash dapat membantu menjaga integritas pesan. Hash table menawarkan waktu akses yang sangat cepat dengan kompleksitas waktu O(1) untuk operasi pencarian, penyisipan, dan penghapusan. Meskipun hash table memiliki kompleksitas waktu O(1), ada kondisi dimana kinerjanya menjadi O(n). Seperti ketika terdapat dua kunci berbeda menghasilkan hash yang sama.

## Referensi

[1] Bahit, Muhammad. "Algoritma Pemrograman Terstruktur", 1st ed. Banjarmasin, Indonesian: Poliban Press, 2024, pp. 24-90.