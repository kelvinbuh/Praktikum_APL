#include <iostream>
#include <string>

using namespace std;

struct Fighter {
    string nama;
    int nomor; 
};

const int max_fighters = 10;
Fighter fighters[max_fighters];
int numfighters = 0;
int pilihan;
int attempt = 0;

bool verifyLogin(string input_nama, int input_nomor) {
    if (input_nama == "Kelvin" && input_nomor == 117) {
        return true;
    }
    return false;
}

int main() {
    do {
        string nama;
        int nomor;

        cout << "Masukkan nama: ";
        cin >> nama;
        cout << "Masukkan NIM: ";
        cin >> nomor;

        if (verifyLogin(nama, nomor)) {
            cout << "Login berhasil!\n";
            break; 
        } else {
            attempt++;
            if (attempt == 3) {
                cout << "Anda telah salah login sebanyak 3 kali. Program berhenti.\n";
                return 0;
            }
            cout << "Nama atau NIM salah. Silakan coba lagi.\n";
        }
    } while (true);


    do {
        cout <<"==================================" << endl;
        cout <<"daftar rangking pound-for-pound UFC athlete" << endl;
        cout << "1. Tambahkan fighter" << endl;
        cout << "2. Tampilkan fighter" << endl;
        cout << "3. Update rangking" << endl;
        cout << "4. Hapus fighter" << endl;
        cout << "5. Keluar" << endl;
        cout <<"==================================" << endl;
        cout << "masukan pilihan anda : ";
        cin >> pilihan;

        if (pilihan == 1) {
            if (numfighters >= max_fighters) {
                cout << "pound-for-pound hanya sampai 10 saja" << endl;
            } else {
                cout << "masukan nama fighter : ";
                cin >> fighters[numfighters].nama;
                cout << "masukan nomor untuk menaruh fighter (1-10): ";
                cin >> fighters[numfighters].nomor;
                numfighters++;
                cout << "fighters berhasil ditambahkan" << endl;
            }
        } else if (pilihan == 2) {
            if (numfighters == 0) {
                cout << "tidak ada fighter" << endl;
            } else {
                cout << "daftar fighter" << endl;
                for (int i = 0; i < numfighters; ++i) {
                    cout << fighters[i].nomor << ". " << fighters[i].nama << endl;
                }
            }
        } else if (pilihan == 3) {
            if (numfighters == 0) {
                cout << "tidak ada fighter" << endl;
            } else {
                string oldName, newName; 
                int newNomor;
                cout << "masukan nama fighter yang ingin diperbarui: ";
                cin >> oldName;
                cout << "masukan nomor baru (1-10): ";
                cin >> newNomor;
                cout << "masukan nama baru: ";
                cin >> newName;
                bool found = false;
                for (int i = 0; i < numfighters; ++i) {
                    if (fighters[i].nama == oldName) {
                        fighters[i].nama = newName;
                        fighters[i].nomor = newNomor; 
                        cout << "Nama fighter berhasil diperbarui" << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "fighter tidak ditemukan" << endl;
                }
            }
        } else if (pilihan == 4) {
            if (numfighters == 0) {
                cout << "tidak ada fighter untuk dihapus" << endl;
            } else {
                string nama;
                cout << "masukan nama fighter yang ingin dihapus : ";
                cin >> nama;
                bool found = false;
                for (int i = 0; i < numfighters; ++i) {
                    if (fighters[i].nama == nama) {
                        for (int j = i; j < numfighters - 1; ++j) {
                            fighters[j] = fighters[j + 1];
                        }
                        numfighters--;
                        cout <<"fighter berhasil dihapus" << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout <<"fighter tidak ditemukan" << endl;
                }
            }
        } else if (pilihan == 5) {
            cout << "PROGRAM BERHENTI" << endl;
        } else {
            cout << "pilihan tidak ada di menu, silahkan coba lagi" << endl;
        }
    } while (pilihan != 5);

    cin.get();
    return 0;
}

