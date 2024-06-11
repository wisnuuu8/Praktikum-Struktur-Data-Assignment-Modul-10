#include <iostream>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

map<string, int> nama_kota_2311110036; 
vector<vector<int> > graph; 

void inisialisasi(int V) {
    graph.resize(V, vector<int>(V, -1));
}

void tambahKota(string nama) {
    nama_kota_2311110036[nama] = nama_kota_2311110036.size();
}

void tambahJarak(string kota_asal, string kota_tujuan, int jarak) {
    int asal = nama_kota_2311110036[kota_asal];
    int tujuan = nama_kota_2311110036[kota_tujuan];
    graph[asal][tujuan] = jarak;
}

void cetakGraph(int V) {
    cout << "Jarak antar kota:\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (graph[i][j] != -1) {
                cout << "Jarak dari " << i << " ke " << j << " : " << graph[i][j] << " km\n";
            }
        }
    }
}

int main() {
    int V;
    cout << "Masukkan jumlah kota: ";
    cin >> V;
    inisialisasi(V);

    cout << "Masukkan nama kota:\n";
    for (int i = 0; i < V; ++i) {
        string nama;
        cout << "Kota ke-" << i+1 << ": ";
        cin >> nama;
        tambahKota(nama);
    }

    cout << "Masukkan jarak antar kota (dalam kilometer):\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (i != j) {
                string asal = static_cast<ostringstream*>( &(ostringstream() << i+1) )->str();
                string tujuan = static_cast<ostringstream*>( &(ostringstream() << j+1) )->str();
                int jarak;
                cout << "Jarak dari " << asal << " ke " << tujuan << ": ";
                cin >> jarak;
                stringstream ss;
                ss << jarak;
                string jarak_str = ss.str();
                tambahJarak(asal, tujuan, jarak);
            }
        }
    }

    cetakGraph(V);

    return 0;
}

