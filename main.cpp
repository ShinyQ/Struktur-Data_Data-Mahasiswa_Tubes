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
    cout << "= 6. Tambah Relasi Mahasiswa Dan Matkul   |  12. Cari Matkul                           =" << endl;
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

        cout << "Nama Mata Kuliah : ";
        getline(cin, nama_matkul);

        cout << "Masukkan Status Kelulusan : ";
        getline(cin, status);

        P = findElmMahasiswa(LP, nama_mahasiswa);
        C = findElmMatkul(LC, nama_matkul);

        cout << endl << "Input Lagi (Y/N) ? ";
        cin >> input;
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

        P = alokasi_mahasiswa("Iqbal", "1301194***");
        insertFirst(LP, P);

        C = alokasi_matkul("Struktur Data");
        insertFirst(LC, C);

        C = alokasi_matkul("Kalkulus IIB");
        insertFirst(LC, C);

        P = findElmMahasiswa(LP, "Iqbal");
        C = findElmMatkul(LC, "Struktur Data");
        R = alokasi(P,C, "Tidak Lulus");
        insertFirst(LR,R);

        P = findElmMahasiswa(LP, "Kurniadi");
        C = findElmMatkul(LC, "Kalkulus IIB");
        R = alokasi(P,C, "Lulus");
        insertFirst(LR,R);

        P = findElmMahasiswa(LP, "Iqbal");
        C = findElmMatkul(LC, "Kalkulus IIB");
        R = alokasi(P,C, "Lulus");
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
    } else if(pilih_menu == 9){
        printTidakLulus(LR, LC);
    } else if(pilih_menu == 10){
        printMatkulBanyakDipilih(LR, LC);
    } else {
        exit(EXIT_FAILURE);
    }
    main();

//
//    /** KELEBIHAN DARI BENTUK III: jika salah satu matkul diedit **/
//    C = findElm(LC, "Struktur Data");
//    info(C) = "Data Structure";
//
//    cout<<endl<<"Setelah matkul Diedit"<<endl;
//    cout<<"list mahasiswa"<<endl;
//    printInfo(LP);
//
//    cout<<endl<<"list matkul"<<endl;
//    printInfo(LC);
//
//    cout<<endl<<"list relasi"<<endl;
//    printInfo(LR);
    return 0;
}
