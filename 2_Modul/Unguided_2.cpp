#include <iostream>
using namespace std;

// PROGAM INPUT ARRAY 3 DIMENSI
int main(){
    int a, b, c;
    cout << "Masukan x: ";  // Memasukan dimensi untuk kedalaman
    cin >> a;
    cout << "Masukan y: ";  // Memasukan dimensi untuk baris
    cin >> b;
    cout << "Masukan z: ";  // Memasukan dimensi untuk kolom
    cin >> c;
    cout << endl;

    // Memasukan nilai ke dalam array
    int arr[a][b][c];
    for(int x = 0; x < a; x++){         // Dimensi untuk kedalaman
        for(int y = 0; y < b; y++){         // Dimensi untuk baris
            for(int z = 0; z < c; z++){         // Dimensi untuk kolom
                cout <<"Input array[" << x << "] [" << y << "] [" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }

    //  Menampilkan array 
    for(int x = 0; x < a; x++){       
        for(int y = 0; y < b; y ++){
            for(int z = 0; z < c; z ++){
                cout << arr[x][y][z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
}