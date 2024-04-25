#include <iostream> 
using namespace std;

int main(){
    int n = 10;
    int angka[n]={9, 4, 1, 7, 5, 12, 4, 13, 4, 10};
    int cari = 10;
    bool ketemu = false;
    int i;

    // Algoritma Sequential Search
    for(i = 0; i < n; i++){
        if(angka[i] == cari){
            ketemu = true;
            break;
        }
    }

    cout << "\tProgam Sequential Search Sederhana\n" << endl;
    cout << "Data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;
    if (ketemu){
        cout << "\nAngka " << cari << " ditemukan pada indeks ke-" 
        << i << "\n" << endl;
    }
    else{
        cout << cari << " tidak dapat ditemukan pada data.\n" << endl;
    }
    return 0;
}