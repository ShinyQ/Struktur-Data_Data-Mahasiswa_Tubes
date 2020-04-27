#include "list_matkul.h"

void createList(List_matkul &L) {
    first(L) = NULL;
}

address_matkul alokasi_matkul(infotype_matkul x) {
    address_matkul P = new elmlist_matkul;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void dealokasi(address_matkul P){
    delete P;
}

void insertFirst(List_matkul &L, address_matkul P) {
    if(first(L) == NULL){
        first(L) = P;
    } else {
        next(P) = first(L);
        first(L) = P;
    }
}

void printInfo(List_matkul L) {
    cout << endl << "Berikut Merupakan List Matkul : " << endl;
    int no = 1;
    address_matkul P = first(L);
    if(P != NULL){
        while(P !=NULL) {
            cout<< no << ". " << info(P) <<endl;
            P = next(P);
            no++;
        }
    } else {
        cout << "List Matkul Kosong" << endl;
    }
}


address_matkul findElmMatkul(List_matkul L, string nama) {
    address_matkul P = first(L);
    while(P != NULL) {
        if(info(P) == nama) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}
