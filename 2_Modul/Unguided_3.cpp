#include <iostream>
using namespace std;


int main(){

    // Memasukan panjang array
    int n;
    cout << "Masukan panjang array: ";
    cin >> n;
    if(n <= 0){
        "Panjang array harus lebih dari 0";
        return 1;
    }

    // Memasukan nilai elemen array
    int array[n];
    for(int i=0; i<n; i++){
        cout << "Masukan nilai array ke-" << (i+1) << ": ";
        cin >> array[i];
    }

    // Menu untuk mencari nilai minimum, maksimum, dan rata-rata
    char pilih;
    cout << "\nDaftar pencarian:\n1. Nilai minimum\n2. Nilai maksimum\n3. Nilai rata-rata" << endl;
    cout << "Pilih nilai yang ingin dicari: ";
    cin >> pilih;

    // Menampilkan array yang telah dimasukan
    cout << "\nHasil Array    : [ ";
    for(int i=0; i<n; i++){
        cout << array[i] << " ";
    }
    cout << "]" << endl;

    // Membuat variabel untuk ke-3 menu
    int min = array[0];
    int max = array[0];
    float mean;

    // Percabagan untuk mencari nilai minimum, maksimum, dan rata-rata
    switch (pilih){
        case '1':
            // Mencari nilai minimum
            for(int i=0; i<n; i++){
                if(array[i] < min){
                    min = array[i];
                }
            }
            cout << "Nilai minimum  : " << min << endl;
            break;
        
        case '2':
            // Mencari nilai maksimum
            for(int i=0; i<n; i++){
                if( array[i] > max){
                    max = array[i];
                }
            }
            cout << "Nilai maksimum : " << max << endl;
            break;
        
        case '3':
            // Mencari nilai rata-rata
            for(int i=0; i<n; i++){
                mean = mean + array[i];
            }
            cout << "Nilai rata-rata: " << (mean/n) << endl;
            break;
        
        default:
            // Jika progam tidak melewati percabangan diatas, maka akan menampilkan dibawah ini
            cout << "Masukan pilihan yang tersedia!" << endl;
            break;
    }
    return 0;
}
