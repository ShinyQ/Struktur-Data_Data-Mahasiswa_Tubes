#include "list_relasi.h"

void createList(List_relasi &L) {
    first(L) = NULL;
}

address_relasi alokasi(address_mahasiswa P, address_matkul C) {
    address_relasi Q = new elmlist_relasi;
    matkul(Q) = C;
    mahasiswa(Q) = P;
    next(Q) = NULL;
    return Q;
}

void insertFirst(List_relasi &L, address_relasi P) {
    next(P) = first(L);
    first(L) = P;
}

void printInfo(List_relasi L) {
    address_relasi P = first(L);
    while(P !=NULL) {
        cout<<info(mahasiswa(P))<<"->"<<info(matkul(P))<<endl;
        P = next(P);
    }
}


address_relasi findElm(List_relasi L, address_mahasiswa P, address_matkul C) {
    address_relasi Q = first(L);
    while(Q != NULL) {
        if(mahasiswa(Q)==P && matkul(Q)== C) {
            return Q;
        }
        Q = next(Q);
    }
    return NULL;
}

void insertAfter(address_relasi &Prec, address_relasi P) {
    next(P) = next(Prec);
    next(Prec) = P;
}
