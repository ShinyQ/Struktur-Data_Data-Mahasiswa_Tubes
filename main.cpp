#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;
#include "list_matkul.h"
#include "list_mahasiswa.h"
#include "list_relasi.h"

List_mahasiswa LP;
List_matkul LC;
List_relasi LR;
address_matkul C;
address_mahasiswa P;
address_relasi R;
bool used = false;

void menu(){
    cout << endl;
    cout << "========================================================================================" << endl;
    cout << "=                                      Data Mahasiswa                                  =" << endl;
    cout << "========================================================================================" << endl;
    cout << "= 1. Tampil Mahasiswa                     |  7. Hapus Mahasiswa                        =" << endl;
    cout << "= 2. Tampil Matkul                        |  8. Hapus Matkul                           =" << endl;
    cout << "= 3. Tampil Relasi Mahasiswa Dan Matkul   |  9. Tampil Mahasiswa Tidak Lulus Matkul    =" << endl;
    cout << "= 4. Tambah Mahasiswa                     |  10. Tampil Matkul Paling Banyak Dipilih   =" << endl;
    cout << "= 5. Tambah Matkul                        |  11. Cari Mahasiswa Berdasarkan NIM        =" << endl;
    cout << "= 6. Tambah Relasi Mahasiswa Dan Matkul   |  12. Tampil Presentase Kelulusan Matkul    =" << endl;
    cout << "========================================================================================" << endl;
}

void tambah_mahasiswa(){
    string nama, nim, input;
    input = "y";
    while(input == "Y" || input == "y"){
        cout << endl << "Silahkan Memasukkan Data Mahasiswa :" << endl;
        getline(cin, input);

        cout << "Nama Mahasiswa : ";
        getline(cin, nama);

        cout << "NIM : ";
        getline(cin, nim);

        P = alokasi_mahasiswa(nama, nim);
        insertFirst(LP, P);
    }
}

void tambah_matkul(){
    string nama, input;
    input = "y";
    while(input == "Y" || input == "y"){
        cout << endl << "Silahkan Memasukkan Data Mata Kuliah :" << endl;
        getline(cin, input);

        cout << "Nama Mata Kuliah : ";
        getline(cin, nama);

        C = alokasi_matkul(nama);
        insertFirst(LC, C);

        cout << endl << "Input Lagi (Y/N) ? ";
        cin >> input;
    }
}

void tambah_relasi(){
    string nama_mahasiswa, nama_matkul, status, input;
    input = "y";
    while(input == "Y" || input == "y"){
        cout << endl << "Silahkan Memasukkan Data Mata Kuliah :" << endl;
        getline(cin, input);

        cout << "Nama Mahasiswa : ";
        getline(cin, nama_mahasiswa);
        P = findElmMahasiswa(LP, nama_mahasiswa);
        if(P == NULL){
            cout << "Mahasiswa Tersebut Tidak Ditemukan" << endl;
        } else {
            cout << "Nama Mata Kuliah : ";
            getline(cin, nama_matkul);
            C = findElmMatkul(LC, nama_matkul);
            if (C == NULL){
            cout << "Mata Kuliah Tersebut Tidak Ditemukan" << endl;
            } else {
                cout << "Masukkan Status Kelulusan (Lulus / Tidak Lulus) : ";
                getline(cin, status);
                if(status == "Lulus" || status == "lulus"){
                    status = "Lulus";
                    R = alokasi(P,C, status);
                    insertFirst(LR,R);
                } else if (status == "Tidak Lulus" || status == "tidak lulus"){
                    status = "Tidak Lulus";
                    R = alokasi(P,C, status);
                    insertFirst(LR,R);
                } else {
                    cout << "Input Status Tidak Valid" << endl;
                }
            }
        }

        cout << endl << "Input Lagi (Y/N) ? ";
        cin >> input;
    }
}

void cariMahasiswaByNIM(){
    string nim, input;
    input = "y";
    while(input == "Y" || input == "y"){
        cout << endl << "Masukkan NIM Mahasiswa : ";
        cin >> nim;

        findMahasiswaByNIM(LR, LP, nim);

        cout << endl << endl << "Input Lagi (Y/N) ? ";
        cin >> input;
    }
}


void hapus_mahasiswa(){
    string nama, input;
    input = "y";
    while(input == "Y" || input == "y"){

        cout << endl << "Silahkan Memasukkan Nama Mahasiswa Yang Ingin Dihapus :" << endl;
        getline(cin, input);

        cout << "Nama Mahasiswa : ";
        getline(cin, nama);

        delete_relasiMaha(LR, LP, nama);
    }
}

void hapus_matkul(){
    string nama, input;
    input = "y";
    while(input == "Y" || input == "y"){
        cout << endl << "Silahkan Memasukkan Nama Mata Kuliah Yang Ingin Dihapus :" << endl;
        getline(cin, input);

        cout << "Nama Mata Kuliah : ";
        getline(cin, nama);

        delete_relasiMatk(LR, LC, nama);
    }
}

int main()
{
    int pilih_menu;
    if(used == false){
        createList(LP);
        createList(LC);
        createList(LR);
        used = true;

        // Data Dummy
        P = alokasi_mahasiswa("Kurniadi", "1301194024");
        insertFirst(LP, P);

        P = alokasi_mahasiswa("Iqbal", "130119318");
        insertFirst(LP, P);

        P = alokasi_mahasiswa("Aulia", "130119000");
        insertFirst(LP, P);

        P = alokasi_mahasiswa("Ajeng", "130119123");
        insertFirst(LP, P);

        C = alokasi_matkul("Struktur Data");
        insertFirst(LC, C);

        C = alokasi_matkul("Kalkulus IIB");
        insertFirst(LC, C);

        C = alokasi_matkul("Matriks Dan Vektor");
        insertFirst(LC, C);

        P = findElmMahasiswa(LP, "Iqbal");
        C = findElmMatkul(LC, "Struktur Data");
        R = alokasi(P,C, "Lulus");
        insertFirst(LR,R);

        P = findElmMahasiswa(LP, "Kurniadi");
        C = findElmMatkul(LC, "Struktur Data");
        R = alokasi(P,C, "Lulus");
        insertFirst(LR,R);

        P = findElmMahasiswa(LP, "Kurniadi");
        C = findElmMatkul(LC, "Matriks Dan Vektor");
        R = alokasi(P,C, "Lulus");
        insertFirst(LR,R);

        P = findElmMahasiswa(LP, "Aulia");
        C = findElmMatkul(LC, "Struktur Data");
        R = alokasi(P,C, "Tidak Lulus");
        insertFirst(LR,R);

        P = findElmMahasiswa(LP, "Iqbal");
        C = findElmMatkul(LC, "Kalkulus IIB");
        R = alokasi(P,C, "Lulus");
        insertFirst(LR,R);

        P = findElmMahasiswa(LP, "Kurniadi");
        C = findElmMatkul(LC, "Kalkulus IIB");
        R = alokasi(P,C, "Tidak Lulus");
        insertFirst(LR,R);

        P = findElmMahasiswa(LP, "Aulia");
        C = findElmMatkul(LC, "Kalkulus IIB");
        R = alokasi(P,C, "Tidak Lulus");
        insertFirst(LR,R);

        P = findElmMahasiswa(LP, "Ajeng");
        C = findElmMatkul(LC, "Kalkulus IIB");
        R = alokasi(P,C, "Tidak Lulus");
        insertFirst(LR,R);
    }

    menu();
    cout << endl << "Silahkan Memilih Menu : ";
    cin >> pilih_menu;

    if(pilih_menu == 1){
        printInfo(LP);
    } else if(pilih_menu == 2){
        printInfo(LC);
    } else if(pilih_menu == 3){
        printInfo(LR, LP);
    } else if(pilih_menu == 4){
        tambah_mahasiswa();
    } else if(pilih_menu == 5){
        tambah_matkul();
    } else if(pilih_menu == 6){
        tambah_relasi();
    } else if(pilih_menu == 7){
        hapus_mahasiswa();
    } else if(pilih_menu == 8){
        hapus_matkul();
    } else if(pilih_menu == 9){
        printTidakLulus(LR, LC);
    } else if(pilih_menu == 10){
        printMatkulBanyakDipilih(LR, LC);
    } else if(pilih_menu == 11){
        cariMahasiswaByNIM();
    }else if(pilih_menu == 12){
        presentase(LR, LC);
    }else {
        exit(EXIT_FAILURE);
    }
    main();

    return 0;
}

