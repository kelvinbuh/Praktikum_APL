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

void tambahFighter() {
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
}

void tampilkanFighter(int index = 0) {
    if (index >= numfighters) {
        return;
    }
    cout << fighters[index].nomor << ". " << fighters[index].nama << endl;
    tampilkanFighter(index + 1); 
}

void updateRanking() {
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
}

void hapusFighter() {
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
                cout << "fighter berhasil dihapus" << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "fighter tidak ditemukan" << endl;
        }
    }
}

bool isDaftarKosong() {
    return numfighters == 0;
}

bool isDaftarPenuh() {
    return numfighters >= max_fighters;
}

void pesanDaftarKosong() {
    cout << "tidak ada fighter" << endl;
}

void pesanDaftarPenuh() {
    cout << "pound-for-pound hanya sampai 10 saja" << endl;
}

int main() {
    do {
        string nama;
        int nomor;

        cout << "masukan nama :";
        cin >> nama;
        cout << "masukan nim : ";
        cin >> nomor;

        if (verifyLogin(nama, nomor)){
            cout << "login berhasil" << endl;
            break;
        }
        else{
            attempt++;
            if (attempt == 3){
                cout << "anda salah login sebanyak 3 kali. program berhenti" << endl;
                return 0;
            }
            cout << "nama atau nim salah. silahkan coba lagi" << endl;
        }
    } while (true);

    do {
        cout << "==================================" << endl;
        cout << "daftar rangking pound-for-pound UFC athlete" << endl;
        cout << "1. Tambahkan fighter" << endl;
        cout << "2. Tampilkan fighter" << endl;
        cout << "3. Update rangking" << endl;
        cout << "4. Hapus fighter" << endl;
        cout << "5. Keluar" << endl;
        cout << "==================================" << endl;
        cout << "masukan pilihan anda : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                if (isDaftarPenuh()) {
                    pesanDaftarPenuh();
                } else {
                    tambahFighter();
                }
                break;
            case 2:
                if (isDaftarKosong()) {
                    pesanDaftarKosong();
                } else {
                    cout << "daftar fighter" << endl;
                    tampilkanFighter();
                }
                break;
            case 3:
                updateRanking();
                break;
            case 4:
                hapusFighter();
                break;
            case 5:
                cout << "PROGRAM BERHENTI" << endl;
                break;
            default:
                cout << "pilihan tidak ada di menu, silahkan coba lagi" << endl;
                break;
        }
    } while (pilihan != 5);

    cin.get();
    return 0;
}


