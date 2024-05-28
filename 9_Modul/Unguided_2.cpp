#include <iostream>
using namespace std;

int faktorialB(int n);

int faktorialA(int n) {
    if (n > 0) {
        return n * faktorialB(n - 1); // Panggilan rekursif tidak langsung
    }
    return 1;
}

int faktorialB(int n) {
    if (n > 0) {
        return n * faktorialA(n-1); // Panggilan rekursif tidak langsung
    }
    return 1;
}

int main() {
    int input;
    cout << "Masukan bilangan bulat positif: ";
    cin >> input;
    cout << "Faktorial dari bilangan " << input << " adalah: ";
    cout << faktorialA(input);
    return 0;
}
