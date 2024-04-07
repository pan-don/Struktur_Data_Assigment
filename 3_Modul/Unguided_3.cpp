#include <iostream>
using namespace std;

// fungsi sorting secara ascending
void ascending(char arr[], int length){
    int min;
    char temp;

    for(int i=0; i < length - 1; i++){
        min = i;
        for(int j= i+1; j < length; j++){
            // jika array ke-j < array ke-min maka
            // menyimpan j ke variabel min sebagai indek array dgn nilai minimum
            if(arr[j] < arr[min])
                min = j;
        }
        if(min !=i){
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

// fungsi sorting secara discending
void discending(char arr[], int length){
    int max;
    char tmp;

    for(int i=0; i < length - 1; i++){
        max = i;
        for(int j= i+1; j < length; j++){
            // jika array ke-j > array ke-min maka
            // menyimpan j ke variabel min sebagai indek array dgn nilai maksimum
            if(arr[j] > arr[max])
                max = j;
        }
        if(max !=i){
            tmp = arr[i];
            arr[i] = arr[max];
            arr[max] = tmp;
        }
    }
}

// fungsi untuk menampilkan array bertipe data char
void print_array(char arr[], int length){
    for(int i = 0; i < length; i++){
        cout << arr[i] << "\t";
    }
    cout << endl;
}

// fungsi utama untuk menampilkan array sebelum dan sesudah sort
int main(){
    cout << "Progam Sorting Karakter" << endl;
    // menentukan panjang array
    int length;
    cout << "Input (n) = ";
    cin >> length;
    if(length <= 0){
        cout << "Panjang karakter harus lebih dari 0";
        return 1;
    }

    // memasukan data karakter ke dalam elemen array
    char arr[length];
    for(int i = 0; i < length; i++){
        cout << "Masukan karakter ke-" << (i+1) << ": ";
        cin >> arr[i];
    }

    // menampilkan array sebelum di sorting
    cout << "\nUrutan karakter sebelum sorting:" << endl;
    print_array(arr, length);

    // menampilkan array yang sudah di sorting secara ascending
    cout << "\nUrutan karakter setelah ascending sort:" << endl;
    ascending(arr, length);
    print_array(arr, length);
    
    // menampilkan array yang sudah di sorting secara discending
    cout << "\nUrutan karakter setelah discending sort:" << endl;
    discending(arr, length);
    print_array(arr, length);
}   