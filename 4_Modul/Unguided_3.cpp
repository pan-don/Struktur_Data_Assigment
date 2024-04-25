#include <iostream>
using namespace std;


int main(){
    // deklarasi array
    int arr[10]={9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    // menampilkan data array
    cout << "\nData: ";
    for(int i=0; i < 10; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    // deklarasi variabel 'JumlahAngka' untuk menyimpan jumlah angka 4 
    int JumlahAngka = 0;
    for(int i=0; i < 10; i++){
        // jika nilai array indeks ke-i = 4
        if(arr[i] == 4){
            JumlahAngka++; // menambahkan angka 1 ke 'JumlahAngka'
        }
    }
    // menampilkan jumlah angka 4
    cout << "Jumlah angka 4 dalam array: " << JumlahAngka << endl; 
}