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

void printTidakLulus(List_relasi L, List_matkul M){
    cout << endl << "Berikut Merupakan List Mahasiswa Tidak Lulus Matkul : " << endl;

    address_relasi P = first(L);
    address_matkul Q = first(M);
    bool found;

    if(P != NULL){
       while(Q != NULL){
         cout << info(Q) << " : ";
         while(P != NULL){
            if(info(Q) == info(matkul(P))){
                if(info(P) == "Tidak Lulus"){
                     cout << info(mahasiswa(P)).nama << ", ";
                     found = true;
                }
            }
            P = next(P);
         }

         if(!found){
            cout << "-";
         }
         cout << endl;
         found = false;
         P = first(L);
         Q = next(Q);
       }
    } else {
        cout << "List Kosong" << endl;
    }
}

void printMatkulBanyakDipilih(List_relasi L, List_matkul M){
    address_relasi P = first(L);
    address_matkul Q = first(M);
    string nama_matkul;

    int maks = 0;
    int jumlah = 0;

    if(P != NULL){
       while(Q != NULL){

         while(P != NULL){
            if(info(Q) == info(matkul(P))){
                jumlah++;
            }
            P = next(P);
         }

         if(maks == 0){
            maks = jumlah;
            nama_matkul = info(Q);
         } else if (maks < jumlah){
            maks = jumlah;
            nama_matkul = info(Q);
         }

         jumlah = 0;
         P = first(L);
         Q = next(Q);
       }
       cout << "Matkul Yang Paling Banyak Diambil Adalah " << nama_matkul << " Dengan Jumlah " << maks << " Orang" << endl;
    } else {
        cout << "List Kosong" << endl;
    }
}

void findMahasiswaByNIM(List_relasi L, List_mahasiswa M, string nim){
    address_mahasiswa Q = findElmMahasiswaByNIM(M, nim);
    address_relasi P = first(L);
    bool found;

    if(Q != NULL){
       cout << "Nama : " << info(Q).nama << endl;
       cout << "NIM : " << info(Q).nim << endl;
       cout << "Matkul Yang Diambil : ";
       if(P != NULL){
            while(P != NULL){
                if(info(Q).nama == info(mahasiswa(P)).nama){
                    found = true;
                    cout << info(matkul(P)) << " (" << info(P) << "), ";
                }
                P = next(P);
            }
       }

       if(!found && !P){
         cout << "Belum Mengambil Matkul";
       }
    } else {
        cout << "Data Mahasiswa Tersebut Tidak Ada";
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

void deleteFirst(List_mahasiswa &L, address_mahasiswa &P){
    if(first(L) == NULL){
        cout << "Listnya udah kosong" << endl;
    }else if(next(first(L)) == first(L)){
        P = first(L);
        first(L) = NULL;
    }else{
        address_mahasiswa Q;

        Q = first(L);
        while(next(Q) != first(L)){
            Q = next(Q);
        }
        P = first(L);
        first(L) = next(P);
        next(Q) = first(L);
        next(P) = NULL;
    }
}

void deleteLast(List_mahasiswa &L, address_mahasiswa &P){
    address_mahasiswa Q;
    if(first(L) == NULL){
        cout << "Listnya udah kosong" << endl;
    }else if(next(first(L)) == first(L)){
        P = first(L);
        first(L) = NULL;
    }else{
        Q = first(L);
        while(next(Q) != first(L)){

            Q = next(Q);

        }
        P = next(Q);
        next(Q) = first(L);
    }

}
void deleteAfter(List_mahasiswa &L, address_mahasiswa Prec, address_mahasiswa &P){
    if(first(L) == NULL){
        cout << "Listnya udah kosong" << endl;
    }else if(findElmMahasiswa(L, info(Prec).nama ) != NULL){
        P = next(Prec);
        next(Prec) = next(P);
        next(P) = NULL;
    }
}

void deleteFirst(List_matkul &L, address_matkul &P){
    if(first(L) == NULL){
        cout << "List udah kosong" << endl;
    }else if(first(L) == last(L)){
        P = first(L);
        first(L) = NULL;
        last(L) = NULL;
    }else{
        P = first(L);
        first(L) = next(P);
        prev(first(L)) = NULL;
        next(P) = NULL;
    }
}
void deleteLast(List_matkul &L, address_matkul &P){

    if(first(L) == NULL){

        cout << "List udah kosong" << endl;

    }else if(first(L) == last(L)){

        P = first(L);
        first(L) = NULL;
        last(L) = NULL;

    }else{

        P = last(L);
        last(L) = prev(P);
        next(last(L)) = NULL;
        prev(P) = NULL;

    }

}
void deleteAfter(List_matkul &L, address_matkul Prec, address_matkul &P){

    if(first(L) == NULL){

        cout << "List udah kosong" << endl;

    }else if(findElmMatkul(L, info(Prec)) ){

        P = next(Prec);
        next(Prec) = next(P);
        prev(next(P)) = Prec;
        next(P) = NULL;
        prev(P) = NULL;

    }

}
