#include <iostream>
using namespace std;

void selection_sort(double arr[], int length){
    int max;
    float temp;

    for(int i=0; i < length - 1; i++){
        max = i;
        for(int j= i+1; j < length; j++){
            if(arr[j] > arr[max])
                max = j;
        }
        if(max !=i){
            temp = arr[i];
            arr[i] = arr[max];
            arr[max] = temp;
        }
    }
}

void print_array(double arr[], int length){
    for(int i = 0; i < length; i++){
        cout << arr[i] << "\t";
    }
    cout << endl;
}

int main(){
    int length = 5;
    double a[] = {3.8, 2.9, 3.3, 4.0, 2.4};

    cout << "lembar Indeks Prestasi Semester (IPS) sebelum sorting: " << endl;
    print_array(a, length);

    selection_sort(a, length);

    cout << "\nlembar Indeks Prestasi Semester (IPS) setelah sorting: " << endl;
    print_array(a, length);    
}