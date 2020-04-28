#include <iostream>

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
    cout << "=========================================================================================" << endl;
    cout << "=                                      Data Mahasiswa                                   =" << endl;
    cout << "=========================================================================================" << endl;
    cout << "= 1. Tampil Mahasiswa                     |  8.  Hapus Mahasiswa                        =" << endl;
    cout << "= 2. Tampil Matkul                        |  9.  Hapus Matkul                           =" << endl;
    cout << "= 3. Tampil Relasi Mahasiswa Dan Matkul   |  10. Tampil Mahasiswa Tidak Lulus Matkul    =" << endl;
    cout << "= 4. Tambah Mahasiswa                     |  11. Tampil Matkul Paling Banyak Dipilih    =" << endl;
    cout << "= 5. Tambah Matkul                        |  12. Cari Mahasiswa Berdasarkan NIM         =" << endl;
    cout << "= 6. Tambah Relasi Mahasiswa Dan Matkul   |  13. Tampil Presentase Kelulusan Matkul     =" << endl;
    cout << "= 7. Edit Nama Mata Kuliah                |  14. Keluar Program                         =" << endl;
    cout << "=========================================================================================" << endl;
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

        cout << endl << "Input Lagi (Y/N) ? ";
        cin >> input;
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

        cout << endl << endl << "Cari Lagi (Y/N) ? ";
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
        P = findElmMahasiswa(LP, nama);

        if(P != NULL){
          delete_relasiMaha(LR, LP, nama);
          cout << "Sukses menghapus data mahasiswa " << nama << endl;
          cout << endl << "Hapus Lagi (Y/N) ? ";
          cin >> input;
        } else{
            cout << "Nama yang dimasukkan tidak ada di list." << endl;
            cout << endl << "Input Lagi (Y/N) ? ";
            cin >> input;
        }
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

        C = findElmMatkul(LC, nama);
        if(C != NULL){
          delete_relasiMatk(LR, LC, nama);
          cout << "Sukses menghapus data matkul " << nama << endl;
          cout << endl << "Hapus Lagi (Y/N) ? ";
          cin >> input;
        } else{
            cout << "Nama yang dimasukkan tidak ada di list." << endl;
            cout << endl << "Input Lagi (Y/N) ? ";
            cin >> input;
        }
    }
}

void edit_matkul(){
    string nama, edit_nama, input;
    input = "y";
    while(input == "Y" || input == "y"){
        cout << endl << "Silahkan Memasukkan Nama Mata Kuliah Yang Ingin Di Upadate :" << endl;
        getline(cin, input);

        cout << "Nama Mata Kuliah : ";
        getline(cin, nama);

        C = findElmMatkul(LC, nama);
        if(C != NULL){
          cout << "Edit Nama Mata Kuliah : ";
          getline(cin, edit_nama);
          info(C) = edit_nama;

          cout << "Sukses mengedit nama matkul " << nama << " menjadi " << edit_nama << endl;
          cout << endl << "Edit Lagi (Y/N) ? ";
          cin >> input;
        } else{
            cout << "Nama yang dimasukkan tidak ada di list." << endl;
            cout << endl << "Input Lagi (Y/N) ? ";
            cin >> input;
        }
    }
}

void pilih_menu_list(){
    menu();
    int pilih_menu;

    cout << endl << "Silahkan Memilih Menu : ";
    cin >> pilih_menu;

    if(pilih_menu == 1){
        printInfo(LP);
    } else if(pilih_menu == 2){
        printInfoMatkul(LR, LC);
    } else if(pilih_menu == 3){
        printInfoMahasiswa(LR, LP);
    } else if(pilih_menu == 4){
        tambah_mahasiswa();
    } else if(pilih_menu == 5){
        tambah_matkul();
    } else if(pilih_menu == 6){
        tambah_relasi();
    } else if(pilih_menu == 7){
        edit_matkul();
    } else if(pilih_menu == 8){
        hapus_mahasiswa();
    } else if(pilih_menu == 9){
        hapus_matkul();
    } else if(pilih_menu == 10){
        printTidakLulus(LR, LC);
    } else if(pilih_menu == 11){
        printMatkulBanyakDipilih(LR, LC);
    } else if(pilih_menu == 12){
        cariMahasiswaByNIM();
    } else if(pilih_menu == 13){
        presentase(LR, LC);
    } else {
        exit(EXIT_FAILURE);
    }
    pilih_menu_list();
}

void data(){
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
}

int main()
{
    data();
    pilih_menu_list();
    return 0;
}

