#include "list_relasi.h"

void createList(List_relasi &L) {
    first(L) = NULL;
}

address_relasi alokasi(address_mahasiswa P, address_matkul C, string status) {
    address_relasi Q = new elmlist_relasi;
    matkul(Q) = C;
    mahasiswa(Q) = P;
    info(Q) = status;
    next(Q) = NULL;
    return Q;
}

void insertFirst(List_relasi &L, address_relasi P) {
    next(P) = first(L);
    first(L) = P;
}

void printInfo(List_relasi L, List_mahasiswa M) {
    cout << endl << "Berikut Merupakan List Relasi Mahasiswa Dan Matkul : " << endl;
    address_relasi P = first(L);
    address_mahasiswa Q = first(M);
    if(P != NULL){
       do{
         cout << info(Q).nama << " : ";
         while(P != NULL){
            if(info(Q).nama == info(mahasiswa(P)).nama){
                cout << info(matkul(P)) << " (" << info(P) << "), ";
            }
            P = next(P);
         }
         cout << endl;
         P = first(L);
         Q = next(Q);
       } while((Q)!=first(M));
    } else {
        cout << "List Relasi Kosong" << endl;
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
