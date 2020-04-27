#include "list_relasi.h"
#include <cmath>

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

void dealokasi(address_relasi P){
    delete P;
}

void insertFirst(List_relasi &L, address_relasi P) {
    if(first(L) == NULL){
        first(L) = P;
    } else {
        next(P) = first(L);
        first(L) = P;
    }
}

void printInfo(List_relasi L, List_mahasiswa M) {
    cout << endl << "Berikut Merupakan List Relasi Mahasiswa Dan Matkul : " << endl;
    address_relasi P = first(L);
    address_mahasiswa Q = first(M);
    if(P != NULL){
       while(Q != NULL){
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
       }
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

/*List Relasi*/

void deleteFirst(List_relasi &L){
    address_relasi Q = first(L);
    if(Q == NULL){
        cout << "List Relasi Kosong" << endl;
    }else if(next(Q) == NULL){
        first(L) = NULL;
    }else{
        first(L) = next(Q);
        next(Q) = NULL;
        Q = NULL;
    }
}

void deleteLast(List_relasi &L){
    address_relasi Q = first(L);

    if(Q == NULL){
        cout << "List Relasi Kosong" << endl;
    }else if(next(Q) == NULL){
        first(L) = NULL;
    }else{
        while(next(next(Q)) != NULL){
            Q = next(Q);
        }
        next(Q) = NULL;
    }
}

void deleteAfter(List_relasi &L, address_relasi &P){
    address_relasi Q = first(L);
    if(Q == NULL){
        cout << "List udah kosong" << endl;
    }else {
        while(next(Q) != P){
            Q = next(Q);
        }
        next(Q) = next(P);
        next(P) = NULL;
    }
}

void delete_relasiMaha(List_relasi &L, List_mahasiswa &M, string nama){

    address_relasi P = first(L);
    address_mahasiswa Q = first(M);
    address_mahasiswa R = findElmMahasiswa(M, nama);
    if(R != NULL){
        while(P != NULL){
            if(info(mahasiswa(P)).nama == nama){
                if(P == first(L)){
                    deleteFirst(L);
                } else if(next(P) == NULL){
                    deleteLast(L);
                } else {
                    deleteAfter(L, P);
                }
                P = first(L);
            } else {
                P = next(P);
            }
        }

        if(Q == R){
            cout << "First";
            deleteFirst(M);
        } else if(next(R) == NULL){
            cout << "Last";
            deleteLast(M);
        } else {
            cout << "After";
            deleteAfter(M, R);
        }
    } else {
        cout << "Data Mahasiswa Tersebut Tidak Ada";
    }
}

void delete_relasiMatk(List_relasi &L, List_matkul &M, string nama){

    address_relasi P = first(L);
    address_matkul Q = first(M);
    address_matkul R = findElmMatkul(M, nama);
    cout << "TEST 1" << endl;
    if(R != NULL){
        while(P != NULL){
            if(info(matkul(P)) == nama){
                if(P == first(L)){
                    deleteFirst(L);
                } else if(next(P) == NULL){
                    deleteLast(L);
                } else {
                    deleteAfter(L, P);
                }
                P = first(L);
            } else {
                P = next(P);
            }
        }

        if(Q == R){
            cout << "First";
            deleteFirst(M);
        } else if(next(R) == NULL){
            cout << "Last";
            deleteLast(M);
        } else {
            cout << "After";
            deleteAfter(M, R);
        }
    } else {
        cout << "Data Matkul Tersebut Tidak Ada";
    }
}

/*From list mahasiswa*/

void deleteFirst(List_mahasiswa &L){
    address_mahasiswa Q = first(L);
    if(Q == NULL){
        cout << "List Mata Kuliah Kosong" << endl;
    }else if(next(Q) == NULL){
        first(L) = NULL;
    }else{
        first(L) = next(Q);
        next(Q) = NULL;
    }
    delete Q;

}
void deleteLast(List_mahasiswa &L){
    address_mahasiswa Q = first(L);

    if(Q == NULL){
        cout << "List Relasi Kosong" << endl;
    }else if(next(Q) == NULL){
        first(L) = NULL;
    }else{
        while(next(next(Q)) != NULL){
            Q = next(Q);
        }
        next(Q) = NULL;
    }
}

void deleteAfter(List_mahasiswa &L, address_mahasiswa &P){
    address_mahasiswa Q = first(L);
    if(Q == NULL){
        cout << "List udah kosong" << endl;
    }else {
        while(next(Q) != P){
            Q = next(Q);
        }
        next(Q) = next(P);
        next(P) = NULL;
    }
    delete P;
}

/*From List Matkul*/

void deleteFirst(List_matkul &L){
    address_matkul Q = first(L);
    if(Q == NULL){
        cout << "List Mata Kuliah Kosong" << endl;
    }else if(next(Q) == NULL){
        first(L) = NULL;
    }else{
        first(L) = next(Q);
        next(Q) = NULL;
    }
    delete Q;

}

void deleteLast(List_matkul &L){
    address_matkul Q = first(L);

    if(Q == NULL){
        cout << "List Relasi Kosong" << endl;
    }else if(next(Q) == NULL){
        first(L) = NULL;
    }else{
        while(next(next(Q)) != NULL){
            Q = next(Q);
        }
        next(Q) = NULL;
    }
}

void deleteAfter(List_matkul &L, address_matkul &P){
    address_matkul Q = first(L);
    if(Q == NULL){
        cout << "List udah kosong" << endl;
    }else {
        while(next(Q) != P){
            Q = next(Q);
        }
        next(Q) = next(P);
        next(P) = NULL;
    }
    delete P;
}

void presentase(List_relasi LR, List_matkul LM){
    address_relasi P;
    address_matkul Q;
    double sumR,sumRLulus,persen;
    sumRLulus = 0.0;
    sumR = 0.0;
    persen = 0.0;

    P = first(LR);
    Q = first(LM);

    if(Q != NULL){
        if(P != NULL){
            cout << endl << "Berikut merupakan presentase kelulusan setiap mata kuliah : " << endl;
            while(Q != NULL){
                cout << info(Q) << " : ";
                while(P != NULL){
                    if(info(matkul(P)) == info(Q)){
                        if(info(P) == "Lulus" || info(P) == "lulus"){
                            sumRLulus++;
                        } else {

                        }
                        sumR++;
                    }
                    P = next(P);
                }
                persen = sumRLulus / sumR;
                cout << "Tingkat Kelulusan "<< round(persen*100.0) << "%" << " Dari " << sumR << " Orang." << endl;

                P = first(LR);
                sumRLulus = 0.0;
                sumR = 0.0;

                Q = next(Q);
            }
        }else{
            while(Q != NULL){
                cout << info(Q) << " : - " << endl;
            }
        }
    }else{
        cout << "Tidak ada matkul yang tersedia." << endl;
    }
}
