#include <iostream>
using namespace std;


// class dengan akses default: private
class buah_a{
    string asam;
    string manis;
};

// class yang sudah dirubah akses defaultnya ke public
class buah_b{
    public:
    string dikotil;
    string monokotil;
};


// struct dengan akses default: public
struct hewan_a{
    string herbivora;
    string karnivora;
};

// struct yang sudah dibuah akses defaultnya ke private
struct hewan_b{
    private:
    string darat;
    string laut;
};


/*
Class dan struct yang bersifat public, anggotanya dapat 
diakses di fungsi yang lain
*/
int main(){
    // mengisi nili ke class
    class buah_b buah1, buah2;
    buah1.dikotil = "kentang";
    buah2.monokotil = "kelapa";
    // mencetak isi class
    cout << "\nBuah dikotil   : " << buah1.dikotil
         << "\nBuah monokotil : " << buah2.monokotil << endl;

    // mengisi nili ke struct
    struct hewan_a hewan1, hewan2;
    hewan1.herbivora = "kuda";
    hewan2.karnivora = "singa";
    // mencetak isi struct
    cout << "Hewan herbivora: " << hewan1.herbivora
         << "\nHewan karnivora: " << hewan2.karnivora << endl;
}
