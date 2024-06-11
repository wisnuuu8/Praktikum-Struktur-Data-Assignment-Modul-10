**BAB 1**

**PENDAHULUAN**

**LATAR BELAKANG**

Graph dan tree adalah struktur data fundamental dalam ilmu komputer. Graph terdiri dari simpul (nodes) dan sisi (edges), sementara tree adalah bentuk khusus dari graph yang tidak memiliki siklus dan memiliki struktur hirarki dengan satu simpul akar (root). Pemahaman terhadap graph dan tree sangat penting karena sering digunakan dalam algoritma dan aplikasi, membantu memecahkan masalah kompleks, serta meningkatkan keterampilan pemrograman mahasiswa dengan pemahaman yang lebih baik tentang algoritma dan efisiensi kode. 

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
Graph adalah struktur data yang merepresentasikan hubungan antara objek dalam bentuk node (simpul) dan edge (sisi). Secara matematis, graph dinyatakan sebagai G = (V, E), dimana V adalah himpunan simpul dan E adalah himpunan sisi. Graph dapat digunakan dalam berbagai aplikasi seperti jaringan sosial, pemetaan jalan, dan pemodelan data.

Jenis-jenis graph meliputi:
- **Directed Graph**: Graph berarah, dimana urutan simpul pada setiap sisi memiliki arti.
- **Undirected Graph**: Graph tak berarah, dimana urutan simpul pada setiap sisi tidak diperhatikan.
- **Weight Graph**: Graph yang memiliki nilai (berat) pada setiap sisinya.

Graph dapat direpresentasikan menggunakan matriks atau linked list. Pemahaman perbedaan antara simpul vertex dan simpul edge penting dalam representasi graph.

#### Tree
Tree adalah struktur data yang menyerupai pohon nyata, terdiri dari node yang terhubung dalam sebuah hierarki. Setiap node memiliki satu simpul induk dan nol atau lebih simpul anak. Tree digunakan untuk menyimpan data hierarki seperti pohon keluarga, struktur organisasi, dan skema pertandingan.

**Binary Tree** adalah jenis tree dimana setiap simpul memiliki maksimal dua anak. Operasi dasar pada tree meliputi pembuatan (create), pengosongan (clear), pengecekan kekosongan (isEmpty), penyisipan (insert), pencarian (find), pembaruan (update), pengambilan (retrieve), penghapusan subtree (delete sub), dan karakteristik (characteristic). Metode traversal pada tree mencakup pre-order, in-order, dan post-order, yang menentukan urutan kunjungan simpul-simpul dalam tree.

Traversal pada tree:
- **Pre-Order**: Cetak data pada root, rekursif cetak subpohon kiri, rekursif cetak subpohon kanan.
- **In-Order**: Rekursif cetak subpohon kiri, cetak data pada root, rekursif cetak subpohon kanan.
- **Post-Order**: Rekursif cetak subpohon kiri, rekursif cetak subpohon kanan, cetak data pada root.

Tree dan graph adalah struktur data penting dalam ilmu komputer, digunakan dalam berbagai aplikasi dan membantu menyelesaikan berbagai masalah kompleks.

**GUIDED**

**GUIDED 1**
Program Graph
