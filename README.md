# Asesmen Akhir Semester - Struktur Data

Identitas Pengumpul

Nama: ULUNG PUTRA SADEWO

NIM: 103122400013

Kelas: Struktur Data SE-08-01

1. Kode Program

Berikut adalah kode program untuk **simulasi timeline aplikasi MyTelu menggunakan struktur data Doubly Linked List**. Program ini mampu menambah data postingan secara terurut, menampilkan seluruh postingan, mencari postingan berdasarkan username, dan menemukan postingan terpopuler.

```cpp
/*
 * File: main.cpp
 * Author: ULUNG PUTRA SADEWO
 * NIM: 103122400013
 * Deskripsi: Program utama untuk mendemonstrasikan fungsionalitas
 * Doubly Linked List pada aplikasi timeline MyTelu.
 */
#include <iostream>
#include "Assesmen.h"

using namespace std;

int main() {
    // 1. Lengkapi identitas Anda
    cout << "=============================" << endl;
    cout << "NAMA: [ULUNG PUTRA SADEWO]" << endl;
    cout << "NIM: [103122400013]" << endl;
    cout << "=============================\n" << endl;

    // Membuat list baru untuk timeline
    List timeline = createNewList();
    address P;

    // SOAL 5.a: Menambahkan data postingan baru secara terurut berdasarkan ID
    // Data ditambahkan tidak berurutan untuk menguji fungsi insertSortedByID
    infotype post1 = {102, "Ngoding terus Pusing brok akwkwkwk", 150, "budi_s"};
    P = allocate(post1);
    insertSortedByID(timeline, P);

    infotype post2 = {98, "Hello World", 99, "citra_d"};
    P = allocate(post2);
    insertSortedByID(timeline, P);

    infotype post3 = {115, "Asik rame", 500, "admin_official"};
    P = allocate(post3);
    insertSortedByID(timeline, P);

    infotype post4 = {101, "Jangan lupa makan siang.", 250, "budi_s"};
    P = allocate(post4);
    insertSortedByID(timeline, P);

    cout << "4 postingan berhasil ditambahkan.\n" << endl;

    // Menampilkan seluruh list yang sudah terurut
    cout << "--- Menampilkan seluruh timeline (terurut berdasarkan ID) ---" << endl;
    printList(timeline);
    cout << endl;

    // SOAL 5.b: Menampilkan postingan berdasarkan username tertentu
    cout << "--- [Soal 5.b] Menampilkan postingan dari user @budi_s ---" << endl;
    printByUsername(timeline, "budi_s");
    cout << endl;

    // SOAL 5.c: Menampilkan postingan terpopuler
    cout << "--- [Soal 5.c] Menampilkan postingan terpopuler ---" << endl;
    printMostPopular(timeline);
    cout << endl;

    // --- Demonstrasi Fungsi Tambahan (delete) ---
    cout << "--- Demonstrasi fungsi delete ---" << endl;

    // Menghapus postingan terakhir (ID 115)
    address deletedElement;
    deleteLast(timeline, deletedElement);
    cout << "Menghapus postingan terakhir (ID: " << info(deletedElement).id_post << "). Timeline sekarang:" << endl;
    printList(timeline);
    cout << endl;

    // Menghapus postingan setelah ID 98 (yaitu ID 101)
    infotype cari;
    cari.id_post = 98;
    address prec = findElement(timeline, cari); // Cari elemen dengan ID 98

    if (prec != NIL) {
        deleteAfter(timeline, prec, deletedElement);
        cout << "Menghapus postingan setelah ID 98 (yaitu ID: " << info(deletedElement).id_post << "). Timeline sekarang:" << endl;
        printList(timeline);
    }
    cout << endl;


    return 0;
}

/*
 * File: Assesmen.h
 * Author: ULUNG PUTRA SADEWO
 * NIM: 103122400013
 * Deskripsi: File header yang berisi deklarasi struktur data
 * dan semua subprogram untuk Doubly Linked List.
 */
#include <iostream>
#include <stdlib.h>

#define first(L) (L).first
#define last(L) (L).last 
#define next(P) (P)->next
#define prev(P) (P)->prev
#define info(P) (P)->info
#define NIL NULL

using namespace std;

//deklarasi struct infotype
struct infotype {
    int id_post;
    string konten;
    int likes;
    string username;
};

//deklarasi struct linked list
typedef struct elmlist *address;
struct elmlist {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

//deklarasi subprogram
address allocate(infotype data);
List createNewList();
bool isEmpty(List a);
void insertFirst(List &a, address p);
void insertAfter(List &a, infotype x, address p);
void insertLast(List &a, address p);
void deleteFirst(List &a, address &p);
void deleteAfter(List &a, address prec, address &p);
void deleteLast(List &a, address &p);
int length(List a);
address findElement(List a, infotype x);
void printList(List a);

//deklarasi subprogram split list
void insertSortedByID(List &a, address p);
void printByUsername(List a, string username);
void printMostPopular(List a);

/*
 * File: Assesmen.cpp
 * Author: ULUNG PUTRA SADEWO
 * NIM: 103122400013
 * Deskripsi: File implementasi dari semua subprogram
 * yang dideklarasikan di Assesmen.h.
 */
#include "Assesmen.h" //sesuaikan dengan file header yang dibuat

address allocate (infotype data){
    address p = new elmlist;
    info(p) = data;
    next(p) = NIL;
    prev(p) = NIL;
    return p;
}


List createNewList(){
    List a;
    first(a) = NIL;
    last(a) = NIL;
    return a;
}

bool isEmpty (List a){
   return first(a) == NIL && last(a) == NIL;
}

void insertFirst (List &a, address p){
    if (isEmpty(a)) {
        first(a) = p;
        last(a) = p;
    } else {
        next(p) = first(a);
        prev(first(a)) = p;
        first(a) = p;
    }
}

//silahkan uncomment untuk NIM genap
void insertLast(List &a, address p){
    if (isEmpty(a)) {
        insertFirst(a, p);
    } else {
        prev(p) = last(a);
        next(last(a)) = p;
        last(a) = p;
    }
}

void insertAfter(List &a, infotype x, address p){
    //tidak wajib diisi
}

// Parameter p diubah menjadi pass-by-reference (address &p) agar bisa mengembalikan nilai
void deleteFirst(List &a, address &p){
    if (isEmpty(a)) {
        cout << "list kosong" << endl;
        p = NIL;
    } else if (first(a) != last(a)){
        p = first(a);
        first(a) = next(p);
        prev(first(a)) = NIL;
        next(p) = NIL;
    } else { //tinggal 1 elemen
        p = first(a);
        first(a) = NIL;
        last(a) = NIL;
    }
}

// Parameter p diubah menjadi pass-by-reference (address &p) agar bisa mengembalikan nilai
void deleteLast(List &a, address &p){
    if (isEmpty(a)) {
        cout << "list kosong" << endl;
        p = NIL;
    } else if (next(first(a))==NIL){
        p = first(a);
        first(a) = NIL;
        last(a) = NIL;
    }else{
        p = last(a);
        last(a) = prev(p);
        prev(p) = NIL;
        next(last(a)) = NIL;
    }
}

void deleteAfter(List &a, address prec, address &p) {
    if (prec == NIL || next(prec) == NIL) {
        // Tidak bisa menghapus jika prec tidak ada atau prec adalah elemen terakhir
        p = NIL;
        cout << "Tidak dapat menghapus elemen setelah elemen yang diberikan." << endl;
    } else {
        p = next(prec);
        next(prec) = next(p);

        if (next(p) != NIL) {
            prev(next(p)) = prec;
        } else {
            // Elemen yang dihapus adalah elemen terakhir, update last
            last(a) = prec;
        }
        next(p) = NIL;
        prev(p) = NIL;
    }
}

int length(List a) {
    int jml = 0;
    address p = first(a);
    if(p == NIL){
       return 0;
    }else {
       // Perulangan harus sampai p menjadi NIL
       while(p != NIL){
           jml++;
           p = next(p);
       }
       return jml;
    }
}

// Tipe return diubah menjadi address
address findElement (List a, infotype x) {
    address Q = first(a);
    while(Q != NIL) {
        // Perbandingan dilakukan pada ID post sebagai unique identifier
        if(info(Q).id_post == x.id_post) {
            return Q;
        }
        Q = next(Q);
    }
    return NIL; // Mengembalikan NIL jika tidak ditemukan
}

void printList(List a){
    address p = first(a);
    if (isEmpty(a)) {
        cout << "Timeline kosong." << endl;
    } else {
        cout << " MyTelu Timeline " << endl;
        while (p != NIL) {
            cout << "ID: " << info(p).id_post << endl;
            cout << "User: @" << info(p).username << endl;
            cout << "Konten: " << info(p).konten << endl;
            cout << "Likes: " << info(p).likes << endl;
            cout << "--------------------------" << endl;
            p = next(p);
        }
    }
}

// Implementasi fungsi-fungsi tambahan sesuai soal

void insertSortedByID(List &a, address p) {
    if (isEmpty(a) || info(p).id_post <= info(first(a)).id_post) {
        insertFirst(a, p);
    } else if (info(p).id_post >= info(last(a)).id_post) {
        insertLast(a, p);
    } else {
        address q = first(a);
        while (info(p).id_post > info(next(q)).id_post) {
            q = next(q);
        }
        next(p) = next(q);
        prev(p) = q;
        prev(next(q)) = p;
        next(q) = p;
    }
}

void printByUsername(List a, string username) {
    address p = first(a);
    bool found = false;
    cout << "Postingan oleh @" << username << ":" << endl;
    cout << "==========================" << endl;
    while (p != NIL) {
        if (info(p).username == username) {
            cout << "ID: " << info(p).id_post << endl;
            cout << "Konten: " << info(p).konten << endl;
            cout << "Likes: " << info(p).likes << endl;
            cout << "--------------------------" << endl;
            found = true;
        }
        p = next(p);
    }
    if (!found) {
        cout << "Tidak ditemukan postingan dari user @" << username << "." << endl;
    }
}

void printMostPopular(List a) {
    if (isEmpty(a)) {
        cout << "Timeline kosong, tidak ada postingan terpopuler." << endl;
        return;
    }

    address p = first(a);
    address mostPopular = p;

    p = next(p); // Mulai dari elemen kedua
    while (p != NIL) {
        if (info(p).likes > info(mostPopular).likes) {
            mostPopular = p;
        }
        p = next(p);
    }

    cout << "--- Postingan Terpopuler ---" << endl;
    cout << "ID: " << info(mostPopular).id_post << endl;
    cout << "User: @" << info(mostPopular).username << endl;
    cout << "Konten: " << info(mostPopular).konten << endl;
    cout << "Likes: " << info(mostPopular).likes << endl;
    cout << "--------------------------" << endl;
}

2. Penjelasan Kode

Penjelasan Kode

Program ini terstruktur dalam tiga file utama: Assesmen.h: File header yang mendefinisikan semua struktur data (infotype, elmlist, List) dan mendeklarasikan semua fungsi (primitif dan tambahan) yang digunakan. 
Assesmen.cpp: File implementasi yang berisi logika dari semua fungsi yang dideklarasikan di file header. 
main.cpp: File utama yang berfungsi sebagai driver untuk menjalankan skenario simulasi aplikasi MyTelu.

Struktur Data: 
Program menggunakan Doubly Linked List, di mana setiap elemen (elmlist) memiliki pointer next ke elemen berikutnya dan pointer prev ke elemen sebelumnya. Data yang disimpan (infotype) berupa struct yang berisi id_post, konten, likes, dan username.

Alur Logika Utama: 
1.main(): Fungsi main pertama-tama membuat sebuah list kosong bernama timeline menggunakan createNewList(). 
2. Penambahan Data (Soal 5.a): Beberapa data infotype postingan dibuat. Setiap data kemudian dialokasikan sebagai elemen baru menggunakan allocate() dan disisipkan ke dalam timeline menggunakan insertSortedByID(). Fungsi ini memastikan list selalu terurut menaik berdasarkan id_post. 
3. Menampilkan Data: printList() dipanggil untuk menampilkan seluruh isi timeline yang sudah terurut. printByUsername() (Soal 5.b) dipanggil untuk mencari dan menampilkan semua postingan dari username tertentu. printMostPopular() (Soal 5.c) dipanggil untuk mencari dan menampilkan satu postingan dengan jumlah likes terbanyak. 4. Operasi Hapus: Program juga mendemonstrasikan fungsi deleteLast() dan deleteAfter() untuk menunjukkan manipulasi data pada list.

Penjelasan Fungsi dan Prosedur:

address allocate(infotype data): Fungsi ini bertanggung jawab untuk mengalokasikan memori baru untuk satu elemen (node) list. Elemen baru ini kemudian diisi dengan infotype data yang diberikan, dan pointer next serta prev diinisialisasi ke NIL. Fungsi ini mengembalikan alamat dari elemen yang baru dibuat.

List createNewList(): Fungsi ini membuat dan menginisialisasi sebuah objek List baru. first dan last dari list baru ini diatur ke NIL, menandakan bahwa list tersebut masih kosong.

bool isEmpty(List a): Fungsi ini memeriksa apakah sebuah list kosong dengan memverifikasi apakah first(a) dan last(a) keduanya menunjuk ke NIL. Mengembalikan true jika kosong, false jika tidak.

void insertFirst(List &a, address p): Prosedur ini menyisipkan elemen p sebagai elemen pertama dalam list a. Jika list kosong, p menjadi first dan last. Jika tidak, p dihubungkan ke first yang lama, dan first diperbarui menjadi p.

void insertLast(List &a, address p): Prosedur ini menyisipkan elemen p sebagai elemen terakhir dalam list a. Jika list kosong, ia memanggil insertFirst. Jika tidak, p dihubungkan setelah last yang lama, dan last diperbarui menjadi p.

void insertAfter(List &a, infotype x, address p): (Tidak diimplementasikan dalam konteks soal ini, namun merupakan primitif standar untuk menyisipkan elemen p setelah elemen dengan info x.)

void deleteFirst(List &a, address &p): Prosedur ini menghapus elemen pertama dari list a. Alamat elemen yang dihapus disimpan di p. List diperbarui agar elemen kedua menjadi first. Menangani kasus list kosong dan list dengan satu elemen.

void deleteLast(List &a, address &p): Prosedur ini menghapus elemen terakhir dari list a. Alamat elemen yang dihapus disimpan di p. List diperbarui agar elemen sebelum last menjadi last yang baru. Menangani kasus list kosong dan list dengan satu elemen.

void deleteAfter(List &a, address prec, address &p): Prosedur ini menghapus elemen yang berada tepat setelah elemen prec. Alamat elemen yang dihapus disimpan di p. Pointer next dari prec dan prev dari elemen setelah p disesuaikan. Menangani kasus di mana elemen yang dihapus adalah last.

int length(List a): Fungsi ini menghitung jumlah elemen dalam list a dengan melakukan traversial dari first hingga NIL.

address findElement(List a, infotype x): Fungsi ini mencari elemen dalam list a yang memiliki id_post sama dengan x.id_post. Mengembalikan alamat elemen jika ditemukan, atau NIL jika tidak.

void printList(List a): Prosedur ini melakukan traversial dari first hingga NIL dan mencetak detail (ID, User, Konten, Likes) dari setiap postingan dalam list.

void insertSortedByID(List &a, address p): [Soal 5.a] Prosedur ini menyisipkan elemen postingan p ke dalam list a sedemikian rupa sehingga list tetap terurut secara ascending berdasarkan id_post. Ini memeriksa apakah harus disisipkan di awal, akhir, atau di tengah list.

void printByUsername(List a, string username): [Soal 5.b] Prosedur ini melakukan traversial list dan mencetak semua postingan yang username-nya cocok dengan username yang diberikan.

void printMostPopular(List a): [Soal 5.c] Prosedur ini mencari dan mencetak detail dari postingan yang memiliki jumlah likes terbanyak di dalam list.

3. Output Program

Berikut adalah hasil eksekusi program (output) ketika dijalankan.

Hasil Eksekusi Skenario Simulasi MyTelu:

Output di bawah ini menunjukkan satu alur eksekusi lengkap dari file main.cpp.

Pertama, program mengonfirmasi bahwa 4 data postingan berhasil ditambahkan menggunakan insertSortedByID().
Kemudian, program menampilkan seluruh isi timeline yang sudah terurut berdasarkan ID.

4 postingan berhasil ditambahkan.

--- Menampilkan seluruh timeline (terurut berdasarkan ID) ---
 MyTelu Timeline 
ID: 98
User: @citra_d
Konten: Hello World
Likes: 99
--------------------------
ID: 101
User: @budi_s
Konten: Jangan lupa makan siang.
Likes: 250
--------------------------
ID: 102
User: @budi_s
Konten: Ngoding terus Pusing brok akwkwkwk
Likes: 150
--------------------------
ID: 115
User: @admin_official
Konten: Asik rame
Likes: 500
--------------------------

Selanjutnya, program menjalankan Soal 5.b, yaitu mencari dan menampilkan semua postingan dari user @budi_s.

--- [Soal 5.b] Menampilkan postingan dari user @budi_s ---
Postingan oleh @budi_s:
==========================
ID: 101
Konten: Jangan lupa makan siang.
Likes: 250
--------------------------
ID: 102
Konten: Ngoding terus Pusing brok akwkwkwk
Likes: 150
--------------------------

Setelah itu, program menjalankan Soal 5.c, yaitu mencari dan menampilkan satu postingan terpopuler (likes terbanyak).

--- [Soal 5.c] Menampilkan postingan terpopuler ---
--- Postingan Terpopuler ---
ID: 115
User: @admin_official
Konten: Asik rame
Likes: 500
--------------------------

Terakhir, program mendemonstrasikan fungsi hapus, yaitu deleteLast() (menghapus ID 115) dan deleteAfter() (menghapus ID 101), sambil menampilkan kondisi list setelah tiap operasi hapus.
--- Demonstrasi fungsi delete ---
Menghapus postingan terakhir (ID: 115). Timeline sekarang:
 MyTelu Timeline
ID: 98
User: @citra_d
Konten: Hello World
Likes: 99
--------------------------
ID: 101
User: @budi_s
Konten: Jangan lupa makan siang.
Likes: 250
--------------------------
ID: 102
User: @budi_s
Konten: Ngoding terus Pusing brok akwkwkwk
Likes: 150
--------------------------

Menghapus postingan setelah ID 98 (yaitu ID: 101). Timeline sekarang:
 MyTelu Timeline
ID: 98
User: @citra_d
Konten: Hello World
Likes: 99
--------------------------
ID: 102
User: @budi_s
Konten: Ngoding terus Pusing brok akwkwkwk
Likes: 150
--------------------------



=============================
NAMA: [ULUNG PUTRA SADEWO]
NIM: [103122400013]
=============================

4. Penjelasan Lanjutan (Analisis Output)

Bagian ini menganalisis mengapa output yang dihasilkan sudah benar sesuai dengan skenario yang dijalankan:

Pada Penambahan dan Tampilan Awal: Program melaporkan 4 postingan berhasil ditambahkan. Saat printList() dipanggil, output menampilkan data secara terurut berdasarkan ID (98, 101, 102, 115), bukan berdasarkan urutan data itu dibuat. Ini membuktikan bahwa fungsi insertSortedByID() (Soal 5.a) telah berhasil menyisipkan setiap elemen baru ke posisi yang tepat sehingga list selalu terurut.

Pada Pencarian Username (Soal 5.b): Program diminta mencari postingan dari @budi_s. Output dengan benar hanya menampilkan postingan ID 101 dan ID 102. Ini sesuai dengan data lengkap di list, di mana hanya dua postingan tersebut yang memiliki username @budi_s. Ini menunjukkan fungsi printByUsername() berhasil melakukan traversial (penelusuran) dan seleksi data dengan benar.

Pada Pencarian Terpopuler (Soal 5.c): Program diminta mencari postingan dengan 'likes' terbanyak. Output menampilkan ID 115 dengan 500 likes. Jika dibandingkan dengan semua data (likes: 99, 250, 150, 500), nilai 500 adalah yang tertinggi. Ini membuktikan fungsi printMostPopular() berhasil menemukan elemen dengan nilai 'likes' maksimum di dalam list.

Pada Operasi Hapus:

deleteLast(): Program menghapus ID 115 (yang merupakan elemen terakhir). List yang ditampilkan sesudahnya (berakhir di ID 102) membuktikan bahwa elemen last dari list telah berhasil dihapus.

deleteAfter(ID 98): Program menghapus elemen setelah ID 98 (yaitu ID 101). List final yang ditampilkan (ID 98 lalu langsung ke ID 102) membuktikan bahwa pointer next dari ID 98 dan pointer prev dari ID 102 telah berhasil disambungkan, sehingga ID 101 terhapus dari list.

Semua tahapan output ini menunjukkan bahwa logika untuk menyisipkan data terurut, mencari data spesifik, dan menghapus data (baik dari akhir ataupun tengah) pada Doubly Linked List telah diimplementasikan dengan benar.

5. Kesimpulan

Berdasarkan implementasi dan pengujian kode di atas, dapat disimpulkan bahwa:

Struktur data Doubly Linked List sangat fundamental untuk mengelola kumpulan data dinamis (seperti timeline postingan), memungkinkan operasi penyisipan dan penghapusan yang efisien di berbagai posisi (awal, tengah, dan akhir).

Manipulasi pointer next dan prev adalah mekanisme inti yang efektif untuk melakukan traversial (penelusuran) dan manipulasi node. Ini terbukti dalam keberhasilan fungsi insertSortedByID yang menjaga list tetap terurut, serta fungsi deleteLast dan deleteAfter yang menangani penghapusan node dengan benar.

Program telah berhasil memenuhi semua spesifikasi tugas yang diberikan (Soal 5.a, 5.b, dan 5.c), yaitu menyisipkan data secara terurut berdasarkan ID, mencari dan menampilkan data berdasarkan kriteria spesifik (username), serta menemukan data dengan nilai maksimum (likes terbanyak).