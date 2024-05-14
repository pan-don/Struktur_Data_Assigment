#include <iostream>
#include <string>
using namespace std;

void push(char arrayKalimat[], int &top, int maksimal, char huruf) {
    arrayKalimat[top] = huruf;
    top++;
}

void tampilkan(char arrayKalimat[], int top) {
    for (int i = top - 1; i >= 0; i--) {
        cout << arrayKalimat[i];
    }
    cout << endl;
}

// membandingkan kalimat asli dengan kalimat yang sudah dibalik
bool cekPalindrom(char arrayKalimat[], int top) {
    for (int i = 0; i < top / 2; i++) {
        if (arrayKalimat[i] != arrayKalimat[top - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    cout << "\nCek Kalimat Palindrom" << endl;
    cout << "---------------------" << endl;
    string kalimat;
    cout << "Masukan Kalimat: ";
    getline(cin, kalimat);
    
    // Menghitung jumlah huruf dan mengabaikan spasi
    int maksimal = 0;
    for (char huruf : kalimat) {
        if (huruf != ' ') {
            maksimal++;
        }
    }

    // memasukan huruf yang terkandung dalam kalimat ke dalam array
    char arrayKalimat[maksimal];
    int top = 0;
    for (char huruf : kalimat) {
        if (huruf != ' ' && huruf != 0) {
            push(arrayKalimat, top, maksimal, huruf);
        }
    }

    // menampilkan kalimat yang dibalik dengan mengabaikan spasi
    cout << "Hasil reverse: "; 
    tampilkan(arrayKalimat, top);

    // menentukan hasil kalimat polindorm atau tidak
    if (cekPalindrom(arrayKalimat, top)) {
        // jika cekPolindrom bernilai true
        cout << "\nKalimat tersebut palindrom" << endl;
    } else {
        // jika cekPolindrom bernilai false
        cout << "\nBukan Kalimat palindrom" << endl;
    }
    return 0;
}