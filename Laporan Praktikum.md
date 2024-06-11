**BAB 1**

**PENDAHULUAN**

**LATAR BELAKANG**

Graph dan tree adalah struktur data fundamental dalam ilmu komputer. Graph terdiri dari simpul (nodes) dan sisi (edges), sementara tree adalah bentuk khusus dari graph yang tidak memiliki siklus dan memiliki struktur hirarki dengan satu simpul akar (root). Pemahaman terhadap graph dan tree sangat penting karena sering digunakan dalam algoritma dan aplikasi, membantu memecahkan masalah kompleks, serta meningkatkan keterampilan pemrograman mahasiswa dengan pemahaman yang lebih baik tentang algoritma dan efisiensi kode [1]. 

Aplikasi nyata dari graph meliputi jaringan sosial, jaringan komputer, dan pemetaan rute, sedangkan tree digunakan dalam sistem file, struktur organisasi, serta algoritma pencarian dan pengurutan. Namun, memahami konsep abstrak dari graph dan tree bisa menjadi tantangan, seperti menulis kode implementasi yang efisien dan menghubungkan teori dengan aplikasi dunia nyata. 

**RUMUSAN MASALAH**

a. Bagaimana cara mahasiswa memahami konsep dasar graph dan tree dalam ilmu komputer?

b. Bagaimana cara meningkatkan kemampuan mahasiswa dalam mengimplementasikan graph dan tree pada pemrograman?

**TUJUAN PRAKTIKUM**

a. Mahasiswa diharapkan mampu memahami graph dan tree

b. Mahasiswa diharapkan mampu mengimplementasikan graph dan tree pada
pemrograman


**BAB 2**

**PEMBAHASAN**

**DASAR TEORI**

#### Graph
Graph adalah struktur data yang merepresentasikan hubungan antara objek dalam bentuk node (simpul) dan edge (sisi)[2]. Secara matematis, graph dinyatakan sebagai G = (V, E), dimana V adalah himpunan simpul dan E adalah himpunan sisi. Graph dapat digunakan dalam berbagai aplikasi seperti jaringan sosial, pemetaan jalan, dan pemodelan data.

Jenis-jenis graph meliputi:
- **Directed Graph**: Graph berarah, dimana urutan simpul pada setiap sisi memiliki arti.
- **Undirected Graph**: Graph tak berarah, dimana urutan simpul pada setiap sisi tidak diperhatikan.
- **Weight Graph**: Graph yang memiliki nilai (berat) pada setiap sisinya.

Graph dapat direpresentasikan menggunakan matriks atau linked list. Pemahaman perbedaan antara simpul vertex dan simpul edge penting dalam representasi graph.

#### Tree
Tree adalah struktur data yang menyerupai pohon nyata, terdiri dari node yang terhubung dalam sebuah hierarki. Setiap node memiliki satu simpul induk dan nol atau lebih simpul anak. Tree digunakan untuk menyimpan data hierarki seperti pohon keluarga, struktur organisasi, dan skema pertandingan [3].

**Binary Tree** adalah jenis tree dimana setiap simpul memiliki maksimal dua anak. Operasi dasar pada tree meliputi pembuatan (create), pengosongan (clear), pengecekan kekosongan (isEmpty), penyisipan (insert), pencarian (find), pembaruan (update), pengambilan (retrieve), penghapusan subtree (delete sub), dan karakteristik (characteristic). Metode traversal pada tree mencakup pre-order, in-order, dan post-order, yang menentukan urutan kunjungan simpul-simpul dalam tree.

Traversal pada tree:
- **Pre-Order**: Cetak data pada root, rekursif cetak subpohon kiri, rekursif cetak subpohon kanan.
- **In-Order**: Rekursif cetak subpohon kiri, cetak data pada root, rekursif cetak subpohon kanan.
- **Post-Order**: Rekursif cetak subpohon kiri, rekursif cetak subpohon kanan, cetak data pada root.

Tree dan graph adalah struktur data penting dalam ilmu komputer, digunakan dalam berbagai aplikasi dan membantu menyelesaikan berbagai masalah kompleks.

**GUIDED**

**GUIDED 1**

### Program Graph
```C++
#include <iostream>
#include <iomanip>
#include <string> 

using namespace std;

string simpul[7] = {"Ciamis", "Bandung", "Bekasi", "Tasikmalaya", "Cianjur", "Purwokerto", "Yogyakarta"};

int busur[7][7] = {
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 9, 15, 0},
    {0, 5, 0, 9, 5, 0, 0},
    {0, 0, 0, 2, 4, 0, 8},
    {3, 0, 0, 1, 0, 0, 0},
    {0, 0, 7, 0, 0, 9, 4},
    {0, 0, 8, 0, 8, 0, 0}
};

void tampilGraph() {
    for (int baris = 0; baris < 7; baris++) {
        cout << simpul[baris] << " : ";
        for (int kolom = 0; kolom < 7; kolom++) {
            if (busur[baris][kolom] != 0)
                cout << " -> " << simpul[kolom] << "(" << busur[baris][kolom] << ")";
        }
        cout << endl; // Fix the missing semicolon
    }
}

int main() {
    tampilGraph();
    return 0;
}
```
**BAGIAN 1**
```C++
#include <iostream>
#include <iomanip>
#include <string>
```
Interpretasi : 

<iostream>: Ini adalah pustaka standar C++ yang menyediakan fungsi-fungsi untuk operasi input dan output, seperti cin dan cout, yang digunakan untuk membaca dari dan menulis ke aliran standar (biasanya terminal atau konsol).

<iomanip>: Pustaka ini menyediakan berbagai fungsi dan manipulator untuk mengatur format output, seperti setw untuk mengatur lebar bidang output, setprecision untuk mengatur presisi titik desimal, dll.

<string>: Ini adalah pustaka standar C++ yang menyediakan kelas string dan fungsi-fungsi terkait untuk manipulasi string, seperti mencari panjang string, menggabungkan string, memotong string, dll.

**BAGIAN 2**
```C++
string simpul[7] = {"Ciamis", "Bandung", "Bekasi", "Tasikmalaya", "Cianjur", "Purwokerto", "Yogyakarta"};

int busur[7][7] = {
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 9, 15, 0},
    {0, 5, 0, 9, 5, 0, 0},
    {0, 0, 0, 2, 4, 0, 8},
    {3, 0, 0, 1, 0, 0, 0},
    {0, 0, 7, 0, 0, 9, 4},
    {0, 0, 8, 0, 8, 0, 0}
};
```
Interpretaasi : 

Array simpul yang berisi nama-nama kota dan array dua dimensi busur yang merepresentasikan bobot atau jarak antara kota-kota, graf berbobot dengan jelas. Setiap indeks dalam array simpul menandakan identitas unik untuk setiap simpul dalam graf, sementara nilai-nilai dalam array busur menunjukkan bobot dari busur yang menghubungkan simpul-simpul tersebut. 

**BAGIAN 3**
```C++
void tampilGraph() {
    for (int baris = 0; baris < 7; baris++) {
        cout << simpul[baris] << " : ";
        for (int kolom = 0; kolom < 7; kolom++) {
            if (busur[baris][kolom] != 0)
                cout << " -> " << simpul[kolom] << "(" << busur[baris][kolom] << ")";
        }
        cout << endl; // Fix the missing semicolon
    }
}
```
Interpretasi : 

Fungsi `tampilGraph()` digunakan untuk menampilkan representasi graf berbobot dalam bentuk matriks ke layar. Dalam fungsi ini, setiap baris dari array `busur` diproses secara berurutan. Untuk setiap baris, fungsi mencetak nama simpul dari array `simpul` yang sesuai, diikuti dengan daftar simpul terhubung dan bobotnya. Jika bobot dari busur antara dua simpul tidak nol, maka simpul tersebut dianggap terhubung, dan informasi tentang simpul tersebut ditampilkan ke layar dalam format "simpul_sumber -> simpul_tujuan(bobot)". Hal ini memungkinkan pengguna untuk dengan mudah memahami hubungan dan bobot antar simpul dalam graf.

**BAGIAN 4**
```C++
int main() {
    tampilGraph();
    return 0;
}
```
Interpretasi : 

Fungsi `main()` yang Anda tulis akan menampilkan graf berbobot ke layar menggunakan fungsi `tampilGraph()`. Setelah itu, program akan selesai dan mengembalikan nilai 0. Dengan demikian, ketika program dijalankan, graf akan ditampilkan dan kemudian program akan selesai.

### HASIL OUTPUT 
```C++
Ciamis :  -> Bandung(7) -> Bekasi(8)
Bandung :  -> Bekasi(5) -> Cianjur(9) -> Purwokerto(15)
Bekasi :  -> Bandung(5) -> Tasikmalaya(9) -> Cianjur(5)
Tasikmalaya :  -> Tasikmalaya(2) -> Cianjur(4) -> Yogyakarta(8)
Cianjur :  -> Ciamis(3) -> Tasikmalaya(1)
Purwokerto :  -> Bekasi(7) -> Purwokerto(9) -> Yogyakarta(4)
Yogyakarta :  -> Bekasi(8) -> Cianjur(8)

--------------------------------
Process exited after 0.07167 seconds with return value 0
Press any key to continue . . .
```

**GUIDED 2**

### TREE
```C++
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
```
**BAGIAN 1**
```C++
#include <iostream>
using namespace std;
```
Interpretasi : 

<iostream>: Ini adalah pustaka standar C++ yang menyediakan fungsi-fungsi untuk operasi input dan output, seperti cin dan cout, yang digunakan untuk membaca dari dan menulis ke aliran standar (biasanya terminal atau konsol).

**BAGIAN 2**
```C++
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
```
Interpretasi : 

Kode yang Anda berikan mendefinisikan struktur data `pohon` untuk merepresentasikan simpul-simpul dalam pohon. Selain itu, ada beberapa variabel pointer seperti `simpul`, `root`, `saatIni`, `helperA`, `helperB`, dan array `alamat` yang digunakan untuk operasi pada pohon, seperti penyisipan, penghapusan, pencarian, dan traversal. Variabel-variabel ini memudahkan manipulasi pohon dan operasi-operasi yang terkait dengannya.

**BAGIAN 3**
```C+=
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
```
Interpretasi : 

Fungsi-fungsi yang diberikan bertanggung jawab untuk operasi-operasi dasar pada pohon biner. `inisialisasi()` mengatur `root` menjadi `NULL`, `simpulBaru(char dataMasukkan)` membuat simpul baru dengan data yang diberikan, `simpulAkar()` membuat simpul akar jika belum ada, `tambahSimpul()` menambahkan simpul ke pohon, dan `bacaPohon()` mencetak isi pohon secara preorder. Dengan fungsi-fungsi ini, operasi dasar pada pohon biner dapat dilakukan secara efisien.

**BAGIAN 4**
```C++
int main() {
    inisialisasi();
    simpulAkar();
    tambahSimpul();
    bacaPohon();
    return 0;
}
```
Interpretassi : 

Fungsi `main()` yang Anda tulis melakukan urutan operasi dasar pada pohon biner. Pertama, fungsi `inisialisasi()` digunakan untuk menginisialisasi pohon, kemudian `simpulAkar()` digunakan untuk membuat simpul akar. Selanjutnya, dengan menggunakan `tambahSimpul()`, simpul-simpul tambahan dimasukkan ke dalam pohon, dan akhirnya `bacaPohon()` dipanggil untuk mencetak isi pohon secara preorder. Dengan demikian, program menginisialisasi pohon, menambahkan simpul, dan menampilkan isi pohon kepada pengguna.

### HASIL OUTPUT 
```C++
Silahkan masukkan data: WISNU
Root terbentuk...
Masukkan data kiri: Masukkan data kanan: Masukkan data kiri: Masukkan data kanan: Masukkan data kiri: AJI
Masukkan data kanan: Masukkan data kiri: Masukkan data kanan: SANJAYA
Masukkan data kiri: Masukkan data kanan: Masukkan data kiri: Masukkan data kanan: Masukkan data kiri: Masukkan data kanan: Masukkan data kiri: 1
Masukkan data kanan: 16
Masukkan data kiri: Masukkan data kanan: 10
Masukkan data kiri:
W
I S
N U A J
I S A N J A Y A
1 1 6 1
--------------------------------
Process exited after 14.34 seconds with return value 0
Press any key to continue . . .
```

**UNGUIDED**

**UNGUIDED 1**
```C++
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
```
**BAGIAN 1**
```C++
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
using namespace std;
```
Interpretasi :


 `<iostream>`: Pustaka ini digunakan untuk operasi input dan output, seperti `cin` dan `cout`.
 
 `<vector>`: Pustaka ini menyediakan struktur data dinamis yang disebut vector, yang dapat digunakan untuk menyimpan elemen-elemen dalam urutan tertentu.
 
 `<map>`: Pustaka ini menyediakan struktur data associative yang disebut map, yang memetakan kunci ke nilai.
 
 `<sstream>`: Pustaka ini menyediakan fasilitas untuk memanipulasi string seperti input/output stream.

**BAGIAN 2**
```C++
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
```
Interpretasi : 

Struktur data map digunakan untuk memetakan nama kota ke nomor unik, sedangkan vektor 2 dimensi (vector<vector<int>>) digunakan untuk menyimpan matriks berbobot yang merepresentasikan jarak antar kota. Fungsi inisialisasi menginisialisasi matriks berbobot dengan nilai -1, tambahKota menambahkan kota baru ke peta nama kota, tambahJarak menambahkan jarak antara dua kota ke matriks, dan cetakGraph mencetak matriks berbobot dengan format yang terbaca. Dengan demikian, program ini memungkinkan pengguna untuk membuat, mengedit, dan mencetak graf berbobot antar kota dengan mudah.


**BAGIAN 3**
```C++
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
```
Interpretasi :

Program ini meminta pengguna untuk memasukkan jumlah kota, nama kota, dan jarak antar kota. Setelah inisialisasi matriks berbobot, pengguna diminta untuk memasukkan jarak antara setiap pasangan kota. Setelah semua data dimasukkan, program mencetak matriks berbobot yang merepresentasikan jarak antar kota

### HASIL OUTPUT 
```C++
Masukkan jumlah kota: 2
Masukkan nama kota:
Kota ke-1: 2
Kota ke-2: 2
Masukkan jarak antar kota (dalam kilometer):
Jarak dari 1 ke 2: 2
Jarak dari 2 ke 1: 2
Jarak antar kota:
Jarak dari 0 ke 1 : 2 km
Jarak dari 1 ke 0 : 2 km

--------------------------------
Process exited after 4.594 seconds with return value 0
Press any key to continue . . .
```

**UNGUIDED 2**
```C++
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

struct Pohon {
    int data;
    Pohon* kiri;
    Pohon* kanan;
};

Pohon* buatSimpul(int data) {
    Pohon* simpul = new Pohon;
    simpul->data = data;
    simpul->kiri = NULL;
    simpul->kanan = NULL;
    return simpul;
}

Pohon* masukkanData(Pohon* root, int data) {
    if (root == NULL) {
        return buatSimpul(data);
    } else {
        if (data < root->data) {
            root->kiri = masukkanData(root->kiri, data);
        } else {
            root->kanan = masukkanData(root->kanan, data);
        }
        return root;
    }
}

void preOrder(Pohon* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preOrder(root->kiri);
        preOrder(root->kanan);
    }
}

void inOrder(Pohon* root) {
    if (root != NULL) {
        inOrder(root->kiri);
        cout << root->data << " ";
        inOrder(root->kanan);
    }
}

void postOrder(Pohon* root) {
    if (root != NULL) {
        postOrder(root->kiri);
        postOrder(root->kanan);
        cout << root->data << " ";
    }
}

int main() {
    Pohon* root = NULL;
    int choice, data;

    do {
        cout << "\nMenu:\n";
        cout << "1. Masukkan data ke dalam tree\n";
        cout << "2. Tampilkan tree dalam Pre-Order\n";
        cout << "3. Tampilkan tree dalam In-Order\n";
        cout << "4. Tampilkan tree dalam Post-Order\n";
        cout << "5. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan data: ";
                cin >> data;
                root = masukkanData(root, data);
                break;
            case 2:
                cout << "Pre-Order Traversal: ";
                preOrder(root);
                cout << endl;
                break;
            case 3:
                cout << "In-Order Traversal: ";
                inOrder(root);
                cout << endl;
                break;
            case 4:
                cout << "Post-Order Traversal: ";
                postOrder(root);
                cout << endl;
                break;
            case 5:
                cout << "Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (choice != 5);

    return 0;
}
```
**BAGIAN 1**
```C++
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
using namespace std;
```
Interpretasi :

<iostream>: Pustaka ini digunakan untuk operasi input dan output, seperti cin dan cout.

<sstream>: Pustaka ini menyediakan fasilitas untuk memanipulasi string seperti input/output stream.

<vector>: Pustaka ini menyediakan struktur data dinamis yang disebut vector, yang dapat digunakan untuk menyimpan elemen-elemen dalam urutan tertentu.

<map>: Pustaka ini menyediakan struktur data associative yang disebut map, yang memetakan kunci ke nilai.

**BAGIAN 2**
```C++
struct Pohon {
    int data;
    Pohon* kiri;
    Pohon* kanan;
};

Pohon* buatSimpul(int data) {
    Pohon* simpul = new Pohon;
    simpul->data = data;
    simpul->kiri = NULL;
    simpul->kanan = NULL;
    return simpul;
}

Pohon* masukkanData(Pohon* root, int data) {
    if (root == NULL) {
        return buatSimpul(data);
    } else {
        if (data < root->data) {
            root->kiri = masukkanData(root->kiri, data);
        } else {
            root->kanan = masukkanData(root->kanan, data);
        }
        return root;
    }
}
```
Interpretasi :

Terdapat dua fungsi: buatSimpul untuk membuat dan menginisialisasi sebuah simpul baru, dan masukkanData untuk memasukkan data ke dalam pohon biner. Fungsi masukkanData menggunakan rekursi untuk mencari lokasi yang tepat untuk memasukkan data ke dalam pohon berdasarkan nilai data dan struktur pohon yang ada. Dengan demikian, kode ini digunakan untuk membuat dan mengelola pohon biner pencarian.

**BAGIAN 3**
```C++
void preOrder(Pohon* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preOrder(root->kiri);
        preOrder(root->kanan);
    }
}

void inOrder(Pohon* root) {
    if (root != NULL) {
        inOrder(root->kiri);
        cout << root->data << " ";
        inOrder(root->kanan);
    }
}

void postOrder(Pohon* root) {
    if (root != NULL) {
        postOrder(root->kiri);
        postOrder(root->kanan);
        cout << root->data << " ";
    }
}
```
Interpretasi :

Kode tersebut mencakup tiga fungsi penelusuran pohon biner: `preOrder`, `inOrder`, dan `postOrder`. Fungsi `preOrder` melakukan penelusuran dalam urutan "akar-kiri-kanan", sementara `inOrder` menelusuri pohon dalam urutan "kiri-akar-kanan", dan `postOrder` dalam urutan "kiri-kanan-akar". Setiap fungsi memproses simpul saat ini terlebih dahulu, kemudian menelusuri anak kiri, dan akhirnya anak kanan secara rekursif. Dengan menggunakan fungsi-fungsi ini, Anda dapat melakukan penelusuran pohon biner dalam berbagai urutan yang berbeda, sesuai dengan kebutuhan aplikasi.

**BAGIAN 4**
```C++
int main() {
    Pohon* root = NULL;
    int choice, data;

    do {
        cout << "\nMenu:\n";
        cout << "1. Masukkan data ke dalam tree\n";
        cout << "2. Tampilkan tree dalam Pre-Order\n";
        cout << "3. Tampilkan tree dalam In-Order\n";
        cout << "4. Tampilkan tree dalam Post-Order\n";
        cout << "5. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan data: ";
                cin >> data;
                root = masukkanData(root, data);
                break;
            case 2:
                cout << "Pre-Order Traversal: ";
                preOrder(root);
                cout << endl;
                break;
            case 3:
                cout << "In-Order Traversal: ";
                inOrder(root);
                cout << endl;
                break;
            case 4:
                cout << "Post-Order Traversal: ";
                postOrder(root);
                cout << endl;
                break;
            case 5:
                cout << "Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (choice != 5);

    return 0;
}
```
Interpretasi :

fungsi main, sebuah menu interaktif ditampilkan kepada pengguna yang memungkinkannya untuk melakukan berbagai operasi pada pohon biner. Pengguna dapat memilih untuk: (1) memasukkan data ke dalam pohon, (2) menampilkan pohon dalam urutan pre-order, (3) menampilkan pohon dalam urutan in-order, (4) menampilkan pohon dalam urutan post-order, atau (5) keluar dari program. Setiap pilihan menu dijalankan dengan melakukan panggilan ke fungsi-fungsi terkait: masukkanData untuk memasukkan data, dan preOrder, inOrder, dan postOrder untuk menampilkan pohon dalam urutan yang sesuai. Program akan terus berjalan dan menampilkan menu hingga pengguna memilih untuk keluar dengan memilih opsi keluar (pilihan 5).

### HASIL OUTPUT
```C++
Menu:
1. Masukkan data ke dalam tree
2. Tampilkan tree dalam Pre-Order
3. Tampilkan tree dalam In-Order
4. Tampilkan tree dalam Post-Order
5. Keluar
Pilihan Anda: 1
Masukkan data: 20

Menu:
1. Masukkan data ke dalam tree
2. Tampilkan tree dalam Pre-Order
3. Tampilkan tree dalam In-Order
4. Tampilkan tree dalam Post-Order
5. Keluar
Pilihan Anda: 1
Masukkan data: 3

Menu:
1. Masukkan data ke dalam tree
2. Tampilkan tree dalam Pre-Order
3. Tampilkan tree dalam In-Order
4. Tampilkan tree dalam Post-Order
5. Keluar
Pilihan Anda: 1
Masukkan data: 6

Menu:
1. Masukkan data ke dalam tree
2. Tampilkan tree dalam Pre-Order
3. Tampilkan tree dalam In-Order
4. Tampilkan tree dalam Post-Order
5. Keluar
Pilihan Anda: 2
Pre-Order Traversal: 20 3 6

Menu:
1. Masukkan data ke dalam tree
2. Tampilkan tree dalam Pre-Order
3. Tampilkan tree dalam In-Order
4. Tampilkan tree dalam Post-Order
5. Keluar
Pilihan Anda: 3
In-Order Traversal: 3 6 20

Menu:
1. Masukkan data ke dalam tree
2. Tampilkan tree dalam Pre-Order
3. Tampilkan tree dalam In-Order
4. Tampilkan tree dalam Post-Order
5. Keluar
Pilihan Anda: 4
Post-Order Traversal: 6 3 20

Menu:
1. Masukkan data ke dalam tree
2. Tampilkan tree dalam Pre-Order
3. Tampilkan tree dalam In-Order
4. Tampilkan tree dalam Post-Order
5. Keluar
Pilihan Anda: 5
Terima kasih!

--------------------------------
Process exited after 30 seconds with return value 0
Press any key to continue . . .
```

**DAFTAR PUSTAKA**

Lailiyah, S., Kusaeri, K., & Rizki, W. Y. (2020). Identifikasi proses berpikir siswa dalam menyelesaikan masalah aljabar dengan menggunakan representasi graf. Jurnal Riset Pendidikan Matematika, 7(1), 24–45. https://doi.org/10.21831/jrpm.v7i1.32257

Meilina, P. (2015). Penerapan Data Mining dengan Metode Klasifikasi Menggunakan Decision Tree dan Regresi. Jurnal Teknologi Universitas Muhammadiyah Jakarta, 7(1), 11–20. jurnal.ftumj.ac.id/index.php/jurtek

Nugraha, D. W. (2011). Aplikasi Algoritma Prim untuk Menentukan Minimum Spanning Tree Suatu Graf Berbobot Berorientasi Objek. Teknik Elektro UNTAD Palu, 1(2), 70–79. deny_wiria_nugraha@yahoo.co.id

