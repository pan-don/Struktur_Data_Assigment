#include <iostream>
using namespace std;

int main(){
    int n = 4;
    int arr[4] = {2, 1, 3, 1};
    int tmp, a;
    
    for(int i = 0; i < n; i++){
        a = 0;
        if(arr[i] == arr[a + 1])
            tmp = arr[i];
        a++;
    }

    cout << "Angka duplikat: " << tmp << endl;
}