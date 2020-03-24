#ifndef LIST_mahasiswa_H_INCLUDED
#define LIST_mahasiswa_H_INCLUDED

#include <iostream>
using namespace std;

#define first(L) L.first
#define next(P) P->next
#define info(P) P->info

typedef int infotype_mahasiswa;
typedef struct elmlist_mahasiswa *address_mahasiswa;

struct elmlist_mahasiswa {
    infotype_mahasiswa info;
    address_mahasiswa next;
};

struct List_mahasiswa {
    address_mahasiswa first;
};


/** TIDAK PERLU MODIFIKASI */
void createList(List_mahasiswa &L);
void insertFirst(List_mahasiswa &L, address_mahasiswa P);
void insertAfter(List_mahasiswa &L, address_mahasiswa Prec, address_mahasiswa P);
void insertLast(List_mahasiswa &L, address_mahasiswa P);
void deleteFirst(List_mahasiswa &L, address_mahasiswa &P);
void deleteLast(List_mahasiswa &L, address_mahasiswa &P);
void deleteAfter(List_mahasiswa &L, address_mahasiswa Prec, address_mahasiswa &P);


/** PERLU MODIFIKASI */
address_mahasiswa alokasi(infotype_mahasiswa x);
void dealokasi(address_mahasiswa &P);
address_mahasiswa findElm(List_mahasiswa L, infotype_mahasiswa x);
void printInfo(List_mahasiswa L);

#endif
