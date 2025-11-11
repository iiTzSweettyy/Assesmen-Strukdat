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
void deleteLast(List &a, address &p);
void deleteAfter(List &a, address prec, address &p);
int length(List a);
address findElement(List a, infotype x);
void printList(List a);

//deklarasi subprogram split list
void insertSortedByID(List &a, address p);
void printByUsername(List a, string username);
void printMostPopular(List a);