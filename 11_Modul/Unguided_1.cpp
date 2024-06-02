#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // menentukan jumlah simpul
    int jumlah;
    cout << "Silahkan masukan jumlah simpul: ";
    cin >> jumlah;
    if (jumlah <= 0) {
        cout << "Jumlah simpul harus lebih dari 0!" << endl;
        return -1;
    }
    cout << endl;

    // memasukan data kedalam simpul
    string simpul[jumlah];
    cout << "Silahkan masukan nama simpul" << endl;
    for (int i=0; i < jumlah; i++) {
        cout << "Simpul " << (i+1) << " : ";
        cin >> simpul[i];
    }
    cout << endl;

    // memasukan bobot busur
    int busur[jumlah][jumlah];
    cout << "Silahkan masukan bobot antar simpul" << endl;
    for (int baris=0; baris < jumlah; baris++) {
        for (int kolom=0; kolom < jumlah; kolom++) {
            cout << simpul[baris] << " --> " << simpul[kolom] << " = "; 
            cin >> busur[baris][kolom];
        }

    }
    cout << endl;

    // menampilkan bobot busur pada setiap simpul
    cout << setw(5) << ' ';
    for (int i=0; i < jumlah; i++) {
        cout << setw(7) << right << simpul[i];
    }
    cout << endl;
    for (int baris=0; baris < jumlah; baris++) {
            cout << setw(5) << left << simpul[baris]; 
        for (int kolom=0; kolom < jumlah; kolom++) {
            cout << setw(7) << right <<busur[baris][kolom];
        }
        cout << endl;
    }

    return 0;
}