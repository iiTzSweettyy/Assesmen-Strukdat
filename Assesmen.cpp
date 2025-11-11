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

// Tipe return diubah menjadi address, perbandingan struct diperbaiki
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