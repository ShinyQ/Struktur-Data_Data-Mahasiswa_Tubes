#include "list_matkul.h"
#include "list_mahasiswa.h"

#include <iostream>
using namespace std;

#define next(P) P->next
#define first(L) L.first
#define matkul(P) P->matkul
#define mahasiswa(P) P->mahasiswa
#define info(P) P->info

typedef struct elmlist_relasi *address_relasi;
typedef string infotype_relasi;

struct elmlist_relasi{
    address_relasi next;
    address_matkul matkul;
    address_mahasiswa mahasiswa;
    infotype_relasi info;
};

struct List_relasi{
    address_relasi first;
};

/** TIDAK PERLU MODIFIKASI */
void createList(List_relasi &L);
void insertFirst(List_relasi &L, address_relasi P);
void insertLast(List_relasi &L, address_relasi P);
void insertAfter(address_relasi Prec, address_relasi P);
void deleteFirst(List_relasi &L, address_relasi &P);
void deleteLast(List_relasi &L, address_relasi &P);
void deleteAfter(address_relasi Prec, address_relasi &P);
void printTidakLulus(List_relasi L, List_matkul M);
void printMatkulBanyakDipilih(List_relasi L, List_matkul M);

/** PERLU MODIFIKASI */
address_relasi alokasi(address_mahasiswa P, address_matkul C, string status);
void dealokasi(address_relasi &P);
address_relasi findElm(List_relasi L, address_mahasiswa P, address_matkul C);
void printInfo(List_relasi L, List_mahasiswa M);

