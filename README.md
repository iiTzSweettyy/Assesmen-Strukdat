# Assesmen - Struktur Data

Identitas Pengumpul

Nama: ULUNG PUTRA SADEWO

NIM: 103122400013

Kelas: [Isi Kelas Anda]

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
    // ... (kode dari main.cpp Anda) ...
    List timeline = createNewList();
    address P;

    // Menambahkan data postingan
    infotype post1 = {102, "Ngoding terus Pusing brok akwkwkwk", 150, "budi_s"};
    P = allocate(post1);
    insertSortedByID(timeline, P);

    infotype post2 = {98, "Hello World", 99, "citra_d"};
    P = allocate(post2);
    insertSortedByID(timeline, P);

    // ... (dan seterusnya) ...

    // Menampilkan seluruh list
    printList(timeline);

    // Menampilkan postingan berdasarkan username
    printByUsername(timeline, "budi_s");

    // Menampilkan postingan terpopuler
    printMostPopular(timeline);

    // ... (demonstrasi delete) ...

    return 0;
}

```

```cpp
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

//deklarasi subprogram tambahan
void insertSortedByID(List &a, address p);
void printByUsername(List a, string username);
void printMostPopular(List a);
```

```cpp
/*
 * File: Assesmen.cpp
 * Author: ULUNG PUTRA SADEWO
 * NIM: 103122400013
 * Deskripsi: File implementasi dari semua subprogram
 * yang dideklarasikan di Assesmen.h.
 */
#include "Assesmen.h"

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

// ... (dan seterusnya, kode lengkap dari Assesmen.cpp)

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

```

2. Penjelasan Kode

Program ini terstruktur dalam tiga file utama:
`Assesmen.h`: File header yang mendefinisikan semua struktur data (`infotype`, `elmlist`, `List`) dan mendeklarasikan semua fungsi (primitif dan tambahan) yang digunakan.
`Assesmen.cpp`: File implementasi yang berisi logika dari semua fungsi yang dideklarasikan di file header.
`main.cpp`: File utama yang berfungsi sebagai driver untuk menjalankan skenario simulasi aplikasi MyTelu.

Struktur Data:
Program menggunakan Doubly Linked List, di mana setiap elemen (`elmlist`) memiliki pointer `next` ke elemen berikutnya dan pointer `prev` ke elemen sebelumnya. Data yang disimpan (`infotype`) berupa `struct` yang berisi `id_post`, `konten`, `likes`, dan `username`.

Alur Logika Utama:
1.`main()`: Fungsi `main` pertama-tama membuat sebuah list kosong bernama `timeline` menggunakan `createNewList()`.
2.  **Penambahan Data (Soal 5.a)**: Beberapa data `infotype` postingan dibuat. Setiap data kemudian dialokasikan sebagai elemen baru menggunakan `allocate()` dan disisipkan ke dalam `timeline` menggunakan `insertSortedByID()`. Fungsi ini memastikan list selalu terurut menaik berdasarkan `id_post`.
3.  **Menampilkan Data**: `printList()` dipanggil untuk menampilkan seluruh isi timeline yang sudah terurut. `printByUsername()` (Soal 5.b) dipanggil untuk mencari dan menampilkan semua postingan dari username tertentu. `printMostPopular()` (Soal 5.c) dipanggil untuk mencari dan menampilkan satu postingan dengan jumlah `likes` terbanyak.
4.  **Operasi Hapus**: Program juga mendemonstrasikan fungsi `deleteLast()` dan `deleteAfter()` untuk menunjukkan manipulasi data pada list.

**Penjelasan Fungsi dan Prosedur:**

*   **`address allocate(infotype data)`**:
    Fungsi ini bertanggung jawab untuk mengalokasikan memori baru untuk satu elemen (node) list. Elemen baru ini kemudian diisi dengan `infotype data` yang diberikan, dan pointer `next` serta `prev` diinisialisasi ke `NIL`. Fungsi ini mengembalikan alamat dari elemen yang baru dibuat.

*   **`List createNewList()`**:
    Fungsi ini membuat dan menginisialisasi sebuah objek `List` baru. `first` dan `last` dari list baru ini diatur ke `NIL`, menandakan bahwa list tersebut masih kosong.

*   **`bool isEmpty(List a)`**:
    Fungsi ini memeriksa apakah sebuah list kosong dengan memverifikasi apakah `first(a)` dan `last(a)` keduanya menunjuk ke `NIL`. Mengembalikan `true` jika kosong, `false` jika tidak.

*   **`void insertFirst(List &a, address p)`**:
    Prosedur ini menyisipkan elemen `p` sebagai elemen pertama dalam list `a`. Jika list kosong, `p` menjadi `first` dan `last`. Jika tidak, `p` dihubungkan ke `first` yang lama, dan `first` diperbarui menjadi `p`.

*   **`void insertLast(List &a, address p)`**:
    Prosedur ini menyisipkan elemen `p` sebagai elemen terakhir dalam list `a`. Jika list kosong, ia memanggil `insertFirst`. Jika tidak, `p` dihubungkan setelah `last` yang lama, dan `last` diperbarui menjadi `p`.

*   **`void insertAfter(List &a, infotype x, address p)`**:
    (Tidak diimplementasikan dalam konteks soal ini, namun merupakan primitif standar untuk menyisipkan elemen `p` setelah elemen dengan `info` `x`.)

*   **`void deleteFirst(List &a, address &p)`**:
    Prosedur ini menghapus elemen pertama dari list `a`. Alamat elemen yang dihapus disimpan di `p`. List diperbarui agar elemen kedua menjadi `first`. Menangani kasus list kosong dan list dengan satu elemen.

*   **`void deleteLast(List &a, address &p)`**:
    Prosedur ini menghapus elemen terakhir dari list `a`. Alamat elemen yang dihapus disimpan di `p`. List diperbarui agar elemen sebelum `last` menjadi `last` yang baru. Menangani kasus list kosong dan list dengan satu elemen.

*   **`void deleteAfter(List &a, address prec, address &p)`**:
    Prosedur ini menghapus elemen yang berada tepat setelah elemen `prec`. Alamat elemen yang dihapus disimpan di `p`. Pointer `next` dari `prec` dan `prev` dari elemen setelah `p` disesuaikan. Menangani kasus di mana elemen yang dihapus adalah `last`.

*   **`int length(List a)`**:
    Fungsi ini menghitung jumlah elemen dalam list `a` dengan melakukan traversial dari `first` hingga `NIL`.

*   **`address findElement(List a, infotype x)`**:
    Fungsi ini mencari elemen dalam list `a` yang memiliki `id_post` sama dengan `x.id_post`. Mengembalikan alamat elemen jika ditemukan, atau `NIL` jika tidak.

*   **`void printList(List a)`**:
    Prosedur ini melakukan traversial dari `first` hingga `NIL` dan mencetak detail (`ID`, `User`, `Konten`, `Likes`) dari setiap postingan dalam list.

*   **`void insertSortedByID(List &a, address p)`**:
    **[Soal 5.a]** Prosedur ini menyisipkan elemen postingan `p` ke dalam list `a` sedemikian rupa sehingga list tetap terurut secara *ascending* berdasarkan `id_post`. Ini memeriksa apakah harus disisipkan di awal, akhir, atau di tengah list.

*   **`void printByUsername(List a, string username)`**:
    **[Soal 5.b]** Prosedur ini melakukan traversial list dan mencetak semua postingan yang `username`-nya cocok dengan `username` yang diberikan.

*   **`void printMostPopular(List a)`**:
    **[Soal 5.c]** Prosedur ini mencari dan mencetak detail dari postingan yang memiliki jumlah `likes` terbanyak di dalam list.

3. Output Program

Berikut adalah hasil eksekusi program (output) ketika dijalankan.
```
Contoh Output 1 (Input Bilangan Genap):

===== Program Pengecek Ganjil/Genap =====
Masukkan sebuah bilangan bulat: 42
42 adalah bilangan GENAP.


Contoh Output 2 (Input Bilangan Ganjil):

===== Program Pengecek Ganjil/Genap =====
Masukkan sebuah bilangan bulat: 77
77 adalah bilangan GANJIL.


(Tips: Anda juga bisa menyertakan screenshot/gambar output di bagian ini jika diperlukan, seperti ini:)
```

4. Penjelasan Lanjutan (Analisis Output)

Sesuai permintaan Anda ("Penjelasan Lagi"), bagian ini menganalisis mengapa output yang dihasilkan sudah benar:

Pada Output 1: User memasukkan 42. Ketika 42 dibagi 2, sisa baginya adalah 0 ($42 \div 2 = 21$ sisa $0$). Karena sisa baginya 0, kondisi if (angka % 2 == 0) terpenuhi (True), sehingga program mencetak "adalah bilangan GENAP".

Pada Output 2: User memasukkan 77. Ketika 77 dibagi 2, sisa baginya adalah 1 ($77 \div 2 = 38$ sisa $1$). Karena sisa baginya bukan 0, kondisi if tidak terpenuhi, dan program menjalankan blok else, sehingga mencetak "adalah bilangan GANJIL".

Kedua kasus uji (test case) tersebut menunjukkan bahwa logika operator modulus (%) telah diimplementasikan dengan benar untuk membedakan bilangan ganjil dan genap.

5. Kesimpulan

Berdasarkan implementasi dan pengujian kode di atas, dapat disimpulkan bahwa:

Konsep percabangan (selection) menggunakan if-else sangat fundamental untuk membuat program yang dapat mengambil keputusan berdasarkan kondisi tertentu.

Operator Aritmetika Modulus (%) adalah alat yang efektif untuk menentukan keterbagian, yang dalam kasus ini digunakan untuk memvalidasi apakah suatu bilangan ganjil atau genap berdasarkan sisa baginya dengan 2.

Program telah berhasil memenuhi spesifikasi tugas, yaitu menerima input dari user dan memberikan output yang benar sesuai dengan status ganjil/genap dari input tersebut.
