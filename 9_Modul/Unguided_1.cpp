#include <iostream>
using namespace std;

// fungsi rekursif dengan mengkalikan n dengan fungsi yang lebih kecil
int faktorial(int n) {
    if (n > 0) {
        return n * faktorial(n - 1);
    }
    return 1;  
}

// fungsi utama
int main() {
    int input;
    cout << "Masukan bilangan bulat positif: ";
    cin >> input;
    cout << "Faktorial dari bilangan " << input << " adalah: ";
    cout << faktorial(input);
    return 0;

}