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