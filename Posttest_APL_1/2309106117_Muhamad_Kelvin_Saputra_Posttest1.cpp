#include <iostream>
using namespace std;

int main() {
    int menu;
    float hasil, hasilr, hasilf, hasilk;
    string nama;
    int nim;
    int percobaan = 0;
    char lanjut;

    do {
        percobaan = 0; // reset percobaan setiap iterasi
        while (percobaan < 3) {
            cout << "Masukkan nama: ";
            cin >> nama;
            cout << "Masukkan NIM: ";
            cin >> nim;

            if (nama == "kelvin" && nim == 117) {
                cout << "Selamat datang, Kelvin!\n";
                break;
            } else {
                cout << "Nama atau NIM salah. Anda memiliki " << 2 - percobaan << " percobaan tersisa.\n";
                percobaan++;
            }
        }

        if (percobaan == 3) {
            cout << "Anda telah melebihi batas percobaan. Program berhenti.\n";
            return 0;
        }

        cout << "Program konversi suhu\n";
        cout << "1. konversi celcius" << endl;
        cout << "2. konversi reamur" << endl;
        cout << "3. konversi farenheit" << endl;
        cout << "4. konversi kelvin" << endl;
        cout << "Konversi yang anda pilih : ";
        cin >> menu;
        cout << endl;

        
    if (menu == 1) {
        int menu_celcius;
        cout << "1. konversi ke reamur\n";
        cout << "2. konversi ke farenheit\n";
        cout << "3. konversi ke kelvin\n";
        cout << "masukan pilihan anda : ";
        cin >> menu_celcius;
        
        if (menu_celcius == 1) {
            float c;
            cout << "masukan suhu dalam celcius : ";
            cin >> c;
            hasilr = (4.0/5.0) * c;
            cout << "suhu menjadi " << hasilr << " derajat reamur" << endl;
        }

        if (menu_celcius == 2) {
            float c;
            cout << "masukan suhu dalam celcius : ";
            cin >> c;
            hasilf = (9.0/5.0) * c + 32.0;
            cout << "suhu menjadi " << hasilf << " derajat farenheit" << endl;
        }

        if (menu_celcius == 3) {
            float c;
            cout << "masukan suhu dalam celcius : ";
            cin >> c;
            hasilk = c + 273.0;
            cout << "suhu menjadi " << hasilk << " kelvin" << endl;
        }
    }

    if (menu == 2) {
        int menu_reamur;
        cout << "1. konversi ke celcius\n";
        cout << "2. konversi ke farenheit\n";
        cout << "3. konversi ke kelvin\n";
        cout << "masukan pilihan anda : ";
        cin >> menu_reamur;

        if (menu_reamur == 1) {
            float r;
            cout << "masukan suhu dalam reamur : ";
            cin >> r;
            hasil = (5.0/4.0) * r;
            cout << "suhu menjadi " << hasil << " dalam derajat celcius" << endl;
        }

        if (menu_reamur == 2) {
            float r;
            cout << "masukan suhu dalam reamur : ";
            cin >> r;
            hasilf = (9.0/4.0) * r + 32.0;
            cout << "suhu menjadi " << hasilf << " dalam derajat farenheit" << endl;
        }

        if (menu_reamur == 3) {
            float r;
            cout << "masukan suhu dalam reamur : ";
            cin >> r;
            hasilk = (5.0/4.0) * r + 273.0;
            cout << "suhu menjadi " << hasilk << " dalam kelvin" << endl;
        }
    }
    
    if (menu == 3) {
        int menu_farenheit;
        cout << "1. konversi ke celcius\n";
        cout << "2. konversi ke reamur\n";
        cout << "3. konversi ke kelvin\n";
        cout << "masukan pilihan anda : ";
        cin >> menu_farenheit;

        if (menu_farenheit == 1) {
            float f;
            cout << "masukan suhu dalam farenheit : ";
            cin >> f;
            hasil = (5.0/9.0) * (f - 32.0);
            cout << "suhu menjadi " << hasil << " dalam derajat celcius" << endl;
        }
        
        if (menu_farenheit == 2) {
            float f;
            cout << "masukan suhu dalam farenheit : ";
            cin >> f;
            hasilr = (4.0/9.0) * (f - 32.0);
            cout << "suhu menjadi " << hasilr << " dalam derajat reamur" << endl;
        }

        if (menu_farenheit == 3) {
            float f;
            cout << "masukan suhu dalam farenheit : ";
            cin >> f;
            hasilk = (5.0/9.0) * (f - 32.0) + 273.0;
            cout << "suhu menjadi " << hasilk << " dalam kelvin" << endl;
        }
    }

    if (menu == 4) {
        int menu_kelvin;
        cout << "1. konversi ke celcius\n";
        cout << "2. konversi ke reamur\n";
        cout << "3. konversi ke farenheit\n";
        cout << "masukan pilihan anda : ";
        cin >> menu_kelvin;

        if (menu_kelvin == 1) {
            float k;
            cout << "masukan suhu dalam kelvin : ";
            cin >> k;
            hasil = k - 273.0;
            cout << "suhu menjadi " << hasil << " dalam celcius" << endl;
        }

        if (menu_kelvin == 2) {
            float k;
            cout << "masukan suhu dalam kelvin : ";
            cin >> k;
            hasilr = (5.0/4.0) * (k - 273.0);
            cout << "suhu menjadi " << hasilr << " dalam derajat reamur" << endl;
        }

        if (menu_kelvin == 3) {
            float k;
            cout << "masukan suhu dalam kelvin : ";
            cin >> k;
            hasilf = (9.0/5.0) * (k - 273.0) + 32.0;
            cout << "suhu menjadi " << hasilf << " dalam derajat farenheit" << endl;
        }
    }

        cout << "Apakah Anda ingin melanjutkan? (y/t): ";
        cin >> lanjut;
    } while (lanjut == 'y' || lanjut == 'Y');

    cout << "Program berhenti. Terima kasih!\n";

    return 0;
}

