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