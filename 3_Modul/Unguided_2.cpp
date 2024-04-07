#include <iostream>
#include <cstring>
using namespace std;


void bubble_sort(const char* arr[], int length){
    bool not_sorted = true;
    int j = 0;
    const char* tmp;

    while (not_sorted){
        not_sorted = false;
        j++;
        for(int i = 0; i < length - j; i++){
            // Menggunakan strcmp untuk membandingkan string secara keseluruhan
            if(strcmp(arr[i], arr[i + 1]) > 0){
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                not_sorted = true;
            }
        }
    } 
}


void print_array(const char* a[], int length){
    for(int i = 0; i < length; i++){
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main(){
    int length = 10;
    const char* a[] = {"siti", "situ", "sana", "ana", "ani", "caca", "cici", "dida", "dodo", "dadi"};

    cout << "Urutan nama warga sebelum sorting: " << endl;
    print_array(a, length);

    bubble_sort(a, length);

    cout << "\nUrutan nama warga setelah sorting: " << endl;
    print_array(a, length);    
}

