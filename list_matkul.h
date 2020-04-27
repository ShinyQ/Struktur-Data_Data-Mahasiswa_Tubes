#ifndef LIST_MATKUL_H_INCLUDED
#define LIST_MATKUL_H_INCLUDED

#include <iostream>
using namespace std;

#define next(P) P->next
#define first(L) L.first
#define info(P) P->info

typedef string infotype_matkul;
typedef struct elmlist_matkul *address_matkul;

struct elmlist_matkul{
    infotype_matkul info;
    address_matkul next;
};

struct List_matkul{
    address_matkul first;
};

/** TIDAK PERLU MODIFIKASI */
void createList(List_matkul &L);
void insertFirst(List_matkul &L, address_matkul P);
void insertLast(List_matkul &L, address_matkul P);
void deleteFirst(List_matkul &L, address_matkul &P);
void deleteLast(List_matkul &L, address_matkul &P);
void deleteAfter(List_matkul &L, address_matkul Prec, address_matkul &P);


/** PERLU MODIFIKASI */
address_matkul alokasi_matkul(infotype_matkul x);
void dealokasi(address_matkul P);
address_matkul findElmMatkul(List_matkul L, string x);
void printInfo(List_matkul L);

#endif
