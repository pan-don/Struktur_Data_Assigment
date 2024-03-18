#include <iostream>
using namespace std;

// main progam
int main(){
    char op;
    float num_1, num_2;


    //  It allows user to enter numbers
    cin >> op;
    //  It allows user to enter operator +, -, *, /
    cin >> num_2 >> num_1;

    // switch statement begins
    switch (op){
        // if user enter +
        case '+':
            cout << num_1 + num_2;
            break;
        //  if user enter -
        case '-':
            cout << num_1 - num_2;
            break;
        //  if user enter *
        case '*':
            cout << num_1 * num_2;
            break;
        // of user enter /
        case '/':
            cout << num_1 / num_2;
            break;
        // if the operator is other than +, -, *, /
        // error message will display
        default:
            cout << "error! operator is not correct";
    } // swicth statement ends
    return 0;
}