#include <iostream>
using namespace std;

int main() {
    string kalimat = "Garuda Indonesia";
    // menampilkan kalimat
    cout << "\nKalimat:  " << kalimat << endl;

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

