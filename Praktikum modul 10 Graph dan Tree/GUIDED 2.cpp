#include <iostream>
using namespace std;

struct pohon {
    pohon* kanan;
    char data;
    pohon* kiri;
};

pohon* simpul;
pohon* root;
pohon* saatIni;
pohon* helperA;
pohon* helperB;
pohon* alamat[256];

void inisialisasi() {
    root = NULL;
}

void simpulBaru(char dataMasukkan) {
    simpul = new pohon;
    simpul->data = dataMasukkan;
    simpul->kanan = NULL;
    simpul->kiri = NULL;
}

void simpulAkar() {
    if (root == NULL) {
        char dataAnda;
        cout << "Silahkan masukkan data: ";
        cin >> dataAnda;
        simpulBaru(dataAnda);
        root = simpul;
        cout << "Root terbentuk..." << endl;
    } else {
        cout << "Root sudah ada..." << endl;
    }
}

void tambahSimpul() {
    if (root != NULL) {
        int i = 1, j = 1, penanda = 0;
        char dataUser;
        alamat[i] = root;
        while (penanda == 0 && j < 256) {
            cout << "Masukkan data kiri: ";
            cin >> dataUser;
            if (dataUser != '0') {
                simpulBaru(dataUser);
                saatIni = alamat[i];
                saatIni->kiri = simpul;
                j++;
                alamat[j] = simpul;
            } else {
                penanda = 1;
                j++;
                alamat[j] = NULL;
            }
            if (penanda == 0) {
                cout << "Masukkan data kanan: ";
                cin >> dataUser;
                if (dataUser != '0') {
                    simpulBaru(dataUser);
                    saatIni = alamat[i];
                    saatIni->kanan = simpul;
                    j++;
                    alamat[j] = simpul;
                } else {
                    penanda = 1;
                    j++;
                    alamat[j] = NULL;
                }
            }
            i++;
        }
    }
}

void bacaPohon() {
    if (root != NULL) {
        int i = 1, n = 1, pencacah = 0;
        cout << endl;
        while (alamat[i] != NULL) {
            saatIni = alamat[i];
            cout << saatIni->data << " ";
            pencacah++;
            if (pencacah == n) {
                cout << endl;
                pencacah = 0;
                n = n * 2;
            }
            i++;
        }
    }
}

int main() {
    inisialisasi();
    simpulAkar();
    tambahSimpul();
    bacaPohon();
    return 0;
}

