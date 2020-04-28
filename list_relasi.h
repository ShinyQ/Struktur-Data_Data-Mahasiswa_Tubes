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
void deleteFirst(List_relasi &L);
void deleteLast(List_relasi &L);
void deleteAfter(List_relasi &L, address_relasi &P);
void printTidakLulus(List_relasi L, List_matkul M);
void printMatkulBanyakDipilih(List_relasi L, List_matkul M);
void findMahasiswaByNIM(List_relasi L, List_mahasiswa M, string nim);
void delete_relasiMaha(List_relasi &L, List_mahasiswa &M, string nama);
void delete_relasiMatk(List_relasi &L, List_matkul &M, string nama);

/*From list_mahasiswa*/
void deleteFirst(List_mahasiswa &L);
void deleteLast(List_mahasiswa &L);
void deleteAfter(List_mahasiswa &L, address_mahasiswa &P);


/*from list_matkul*/
void deleteFirst(List_matkul &L);
void deleteLast(List_matkul &L);
void deleteAfter(List_matkul &L, address_matkul &P);


/** PERLU MODIFIKASI */
address_relasi alokasi(address_mahasiswa P, address_matkul C, string status);
address_relasi findElm(List_relasi L, address_mahasiswa P, address_matkul C);
void printInfoMatkul(List_relasi L, List_matkul M);
void printInfoMahasiswa(List_relasi L, List_mahasiswa M);
void presentase(List_relasi LR, List_matkul LM);

