#include <iostream>
using namespace std;

// MENCARI BILANGAN GENAP DAN GANJIL PADA ARRAY
int main(){
    // Memasukan panjang array
    int n;
    cout << "Masukan panjang array: ";
    cin  >> n;
    if(n <= 0){
        cout << "Panjang array harus lebih dari 0";
        return 1;
    }

    // Memasukan nilai pada array
    int array[n];
    for(int i=0; i < n; i++){
        cout << "Masukan array ke-" << (i+1) << ": ";
        cin  >> array[i];
    }

    // Menampilkan array yang sudah dimasukan
    cout << "\nData Array: ";
    for(int i=0; i < n;i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    // Mencari dan menampilkan bilangan genap
    cout << "Genap : ";
    for(int i=0; i < n; i++){
        if(array[i] % 2 == 0){      // jika nilai array ke-i modulus 2 = 0, maka bernilai genap
            cout << array[i] << " ";
        }
    }
    cout << endl;

    // Mencari dan menampilkan bilangan ganjil
    cout << "Ganjil: ";
    for(int i=0; i < n; i++){
        if(array[i] % 2 == 1){       // jika nilai array ke-i modulus 2 = 1, maka bernilai ganjil
            cout << array[i] << " ";
        }
    }
    cout << endl;
}
    
