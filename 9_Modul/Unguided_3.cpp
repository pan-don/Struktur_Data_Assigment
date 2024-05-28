#include <iostream>
#include <string>
#include <vector>
using namespace std;

// inisiasi jumlah baris tabel
const int TABLE_SIZE = 11;

// membuat 2 node: nim dan nilai 
class HashNode {
    public:
    string nim;
    int nilai;
    HashNode(string nim, int nilai) {
        this->nim = nim;
        this->nilai = nilai;
    }
};

class HashMap {
    private:
        vector<HashNode*> table[TABLE_SIZE];
    public:
        // mengubah key menjadi integer
        int hashFunc(string key) {
            int hash_val = 0;
            for (char c : key) {
                hash_val += c;
            }
            return hash_val % TABLE_SIZE;
        }

        // menambahkan data 
        void insert(string nim, int nilai) {
            int hash_val = hashFunc(nim);
            for (auto node : table[hash_val]) {
                if (node->nim == nim) {
                    node->nilai = nilai;
                    return;
                }
            }
            table[hash_val].push_back(new HashNode(nim, nilai));
        }

        // menghapus data
        void remove(string nim) {
            int hash_val = hashFunc(nim);
            for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++) {
                if ((*it)->nim == nim) {
                    delete *it;  // Free memory
                    table[hash_val].erase(it);
                    return;
                }
            }
        }

        // mencari nilai berdasarkan nim
        int searchByName(string nim) {
            int hash_val = hashFunc(nim);
            for (auto node : table[hash_val]) {
                if (node->nim == nim) {
                    return node->nilai;
                }
            }
            return -1;  // NIM not found
        }
        
        // menampilkan data yang terdapat pada hash table
        void print() {
            for (int i = 0; i < TABLE_SIZE; i++) {
                cout << i << ": ";
                for (auto pair : table[i]) {
                    if(pair != nullptr){
                        cout << "[" << pair->nim << ", " << pair->nilai << "] ";
                    }
                }
                cout << endl;
            }
        }

        // menampilkan data dengan rentang 80-90
        void rentang() {
            for (int i = 0; i < TABLE_SIZE; i++) {
                cout << i << ": ";
                for (auto pair : table[i]) {
                    if(pair != nullptr && pair->nilai >= 80 && pair->nilai <= 90){
                        cout << "[" << pair->nim << ", " << pair->nilai << "] ";
                    }
                }
                cout << endl;
            }
        }
};

// menu utama
int main(){
    HashMap employee_map;
    while (true) {
        int pilih;
        cout << "\nData Nilai Mahasiswa" << endl;
        cout << "--------------------" << endl;
        cout << "1. Tambah data baru" << endl;
        cout << "2. Hapus data" << endl;
        cout << "3. Cari data berdasarkan NIM" << endl;
        cout << "4. Cari data berdasarkan rentang nilai" << endl;
        cout << "5. Tampilkan data" << endl;
        cout << "6. Keluar" << endl;
        cout << "\nMasukan pilihan: ";
        cin >> pilih;
    
        switch (pilih) {
        case 1: {
            string nim;
            int nilai;
            cout << "Masukan NIM: ";
            cin >> nim;
            cout << "Masukan nilai: ";
            cin >> nilai;
            employee_map.insert(nim, nilai);
            break;
        }

        case 2: {
            string nim;
            cout << "Masukan NIM yang dihapus: ";
            cin >> nim;
            employee_map.remove(nim);
            cout << "NIM: " << nim << " berhasil dihapus!" << endl;
            break;
        }

        case 3: {
            string nim;
            cout << "Masukan NIM yang dicari: ";
            cin >> nim;
            int nilai = employee_map.searchByName(nim);
            if (nilai != -1) {
                cout << "Nilai untuk NIM " << nim << " adalah: " << nilai << endl;
            } else {
                cout << "NIM " << nim << " tidak ditemukan." << endl;
            }
            break;
        }

        case 4: {
            cout << "Data dengan rentang nilai 80-90" << endl;
            employee_map.rentang();
            break;
        }

        case 5: {
            employee_map.print();
            break;
        }

        case 6: {
            cout << "Program selesai!" << endl;
            return 0;
        }   

        default:
            cout << "Masukan pilihan yang tersedia!" << endl;
            break;
        }
    }
}