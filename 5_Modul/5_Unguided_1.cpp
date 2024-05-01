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