#include <iostream>
using namespace std;

struct hewan{
    string nama_hewan;
    string kelamin;
    string berkembang;
    string pernafasan;
    string habitat;
    bool karnivora;
};

struct hewan_darat{
    hewan info_hewan;
    int kaki;
    bool menyusui;
    string suara;
};hewan_darat hewan1;

struct hewan_laut{
    hewan info_hewan;
    string sirip;
    string self_defence;
};hewan_laut hewan2;

int main(){
    // hewan pertama
    hewan1.info_hewan.nama_hewan = "Kuda";
    hewan1.info_hewan.kelamin = "cewek";
    hewan1.info_hewan.berkembang = "vivipar";
    hewan1.info_hewan.pernafasan = "Paru-paru";
    hewan1.info_hewan.habitat = "Darat";
    hewan1.info_hewan.karnivora = false; 
    hewan1.kaki = 4;
    hewan1.menyusui = true;
    hewan1.suara = "Mengeong";
    cout << "Nama Hewan : " << hewan1.info_hewan.nama_hewan << endl;
    cout << "Jenis kelamin : " << hewan1.info_hewan.kelamin << endl;
    cout << "Cara berkembangbiak : " << hewan1.info_hewan.berkembang << endl;
    cout << "Pernafasan : " << hewan1.info_hewan.pernafasan << endl;
    cout << "Tempat hidup : " << hewan1.info_hewan.habitat << endl;
    cout << "Apakah karnivora? " << hewan1.info_hewan.karnivora << endl;
    cout << "Jumlah kaki : " << hewan1.kaki << endl;
    cout << "Apakah menyusui" << hewan1.menyusui << endl;
    cout << "Suara: " << hewan1.suara << endl;

    // data hewan ke dua
    hewan2.info_hewan.nama_hewan = "Hiu";
    hewan2.info_hewan.kelamin = "cowok";
    hewan2.info_hewan.berkembang = "ovovivipar";
    hewan2.info_hewan.pernafasan = "Paru-paru";
    hewan2.info_hewan.habitat = "laut";
    hewan2.info_hewan.karnivora = true; 
    hewan2.sirip = "lancip";
    hewan2.self_defence= "gigi tajam";
    cout << "\nNama Hewan : " << hewan2.info_hewan.nama_hewan << endl;
    cout << "Jenis kelamin : " << hewan2.info_hewan.kelamin << endl;
    cout << "Cara berkembangbiak : " << hewan2.info_hewan.berkembang << endl;
    cout << "Pernafasan : " << hewan2.info_hewan.pernafasan << endl;
    cout << "Tempat hidup : " << hewan2.info_hewan.habitat << endl;
    cout << "Apakah karnivora? " << hewan1.info_hewan.karnivora << endl;
    cout << "Bentuk sirip : " << hewan2.sirip << endl;
    cout << "Pertahanan diri : " << hewan2.self_defence << endl;
}