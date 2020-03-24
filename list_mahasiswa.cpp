#include "list_mahasiswa.h"

void createList(List_mahasiswa &L) {
    /**
    * FS : first(L) diset Nil
    */
    first(L) = NULL;
}

address_mahasiswa alokasi(infotype_mahasiswa x) {
    /**
    * FS : mengembalikan elemen list baru dengan info = x, next elemen = Nil
    */

    address_mahasiswa P;
    P = new elmlist_mahasiswa;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void insertFirst(List_mahasiswa &L, address_mahasiswa P) {
    /**
    * IS : List_mahasiswa L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List_mahasiswa L
    *      next dari last elemen menunjuk ke first elemen
    */
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
    /**
    * FS : menampilkan info seluruh elemen list L
    */
    address_mahasiswa P = first(L);
    if(first(L)!=NULL) {
        do {
            cout<<info(P)<<endl;
            P = next(P);
        } while((P)!=first(L));
    }
}

address_mahasiswa findElm(List_mahasiswa L, infotype_mahasiswa x) {
    /**
    * IS : List_mahasiswa L mungkin kosong
    * FS : mengembalikan elemen dengan info nim = x.nim,
    * FS : mengembalikan elemen dengan info = x,
           mengembalikan Nil jika tidak ditemukan
    */
    address_mahasiswa P = first(L);
    do {
        if(info(P) == x) {
            return P;
        }
        P = next(P);
    } while(P != first(L));
    return NULL;
}
