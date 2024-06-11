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

