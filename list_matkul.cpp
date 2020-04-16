#include "list_matkul.h"

void createList(List_matkul &L) {
    first(L) = NULL;
    last(L) = NULL;
}

address_matkul alokasi_matkul(infotype_matkul x) {
    address_matkul P = new elmlist_matkul;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void insertFirst(List_matkul &L, address_matkul P) {
    if(first(L) == NULL) {
        last(L) = P;
        first(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
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


address_matkul findElmMatkul(List_matkul L, string x) {
    address_matkul P = first(L);
    while(P != NULL) {
        if(info(P) == x) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void insertAfter(address_matkul &Prec, address_matkul P) {
    prev(next(Prec)) = P;
    next(P) = next(Prec);
    prev(P) = Prec;
    next(Prec) = P;
}
