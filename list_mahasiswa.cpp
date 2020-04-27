#include "list_mahasiswa.h"

void createList(List_mahasiswa &L) {
    first(L) = NULL;
}

void dealokasi(address_mahasiswa P){
    delete P;
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
    if(first(L) == NULL){
        first(L) = P;
    } else {
        next(P) = first(L);
        first(L) = P;
    }
}

void printInfo(List_mahasiswa L) {
    cout << endl << "Berikut Merupakan List Mahasiswa : " << endl;
    int i = 1;
    address_mahasiswa P = first(L);
    if(first(L)!=NULL) {
        while(P != NULL){
            cout<< i << ". " << info(P).nama << " (" << info(P).nim << ")" << endl;
            P = next(P);
            i++;
        }
    } else {
        cout << "List Mahasiswa Kosong" << endl;
    }
}

address_mahasiswa findElmMahasiswa(List_mahasiswa L, string nama) {
    address_mahasiswa P = first(L);
    while(P != NULL){
        if(info(P).nama == nama){
            return P;
        }
        P = next(P);
    }
    return NULL;
}

address_mahasiswa findElmMahasiswaByNIM(List_mahasiswa L, string nim) {
    address_mahasiswa P = first(L);
    while(P != NULL){
        if(info(P).nim == nim){
            return P;
        }
        P = next(P);
    }
    return NULL;
}

