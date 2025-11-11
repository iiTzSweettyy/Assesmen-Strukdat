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
