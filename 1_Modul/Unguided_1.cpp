#include <iostream>
using namespace std;

// fungsi untuk mengonversi celcius ke farenheit
float farenheit(float celcius){
    return (9.0/5.0 * celcius) + 32; // mengembalikan hasil konversi
}

// fungsi untuk mengonversi celcius ke reamur
float reamur(float celcius){
    return (4.0/5.0) * celcius; // mengembalikan hasil konversi
} 

// fungsi untuk mengonversi celcius ke kelvin
float kelvin(float celcius){
    return celcius + 273.15; // mengembalikan hasil konversi
}


int main(){
    char pilih;
    float celcius;

    cout << "===== KONVERSI SATUAN SUHU CELCIUS =====" << endl;
    cout << "Masukan suhu dalam satuan celcius: ";
    cin >> celcius; // input untuk memasukan nilai suhu celcius
    printf("\n1. Farenheit\n2. Kelvin\n3. Reamur");
    cout << "\nPilih konversi tujuan: ";
    cin >> pilih ; // input untuk memilih konversi suhu celcius


    switch (pilih){
        // jika nilai input 'pilih' = 1, maka akan diarahkan ke dikonversi farenheit
        case '1':
            cout << "\nHasil konversi suhu " << celcius << "`C: "
                 << farenheit(celcius) << "`F"<<endl;
                 break;
        // jika nilai input 'pilih' = 2, maka akan diarahkan ke dikonversi kelvin
        case '2':
            cout << "\nHasil konversi suhu " << celcius << "`c: "
                 << kelvin(celcius) << "`K" << endl; 
                 break;
        // jika nilai input 'pilih' = 3, maka akan diarahkan ke dikonversi reamur
        case '3':
            cout << "\nHasil konversi suhu " << celcius << "`c: "
                 << reamur(celcius) << "`R" << endl;
                 break;
        default:
            // jika nilai input 'pilih' selain pilihan diatas maka akan menampilkan dibawah ini
            cout << "\nMasukan pilihan yang tersedia!" << endl;
                 break;
    }
    return 0; // indikasi progam selesai dan mengembalikan nilai 0
}