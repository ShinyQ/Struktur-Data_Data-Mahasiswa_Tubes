#include "list_mahasiswa.h"

void createList(List_mahasiswa &L) {
    first(L) = NULL;
}

address_mahasiswa alokasi_mahasiswa(string nama, string nim) {
    address_mahasiswa P;
    P = new elmlist_mahasiswa;
    info(P).nama = nama;
    info(P).nim = nim;
    next(P) = NULL;
    return P;
}

void insertFirst(List_mahasiswa &L, address_mahasiswa P) {
    address_mahasiswa Q;
    if(first(L) == NULL) {
        first(L) = P;
        next(P) = P;
    } else {
        Q = first(L);
        while(next(Q) != first(L)) {
            Q = next(Q);
        }
        next(P) = first(L);
        next(Q) = P;
        first(L) = P;
    }
}

void printInfo(List_mahasiswa L) {
    cout << endl << "Berikut Merupakan List Mahasiswa : " << endl;
    int i = 1;
    address_mahasiswa P = first(L);
    if(first(L)!=NULL) {
        do {
            cout<< i << ". " << info(P).nama << " (" << info(P).nim << ")" << endl;
            P = next(P);
            i++;
        } while((P)!=first(L));
    } else {
        cout << "List Mahasiswa Kosong" << endl;
    }
}

address_mahasiswa findElmMahasiswa(List_mahasiswa L, string x) {
    address_mahasiswa P = first(L);
    do {
        if(info(P).nama == x) {
            return P;
        }
        P = next(P);
    } while(P != first(L));
    return NULL;
}
