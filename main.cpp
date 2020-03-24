#include <iostream>

using namespace std;
#include "list_matkul.h"
#include "list_mahasiswa.h"
#include "list_relasi.h"

int main()
{
    cout << "Bentuk III - Contoh Relasi M-N" << endl;

    List_mahasiswa LP;
    List_matkul LC;
    List_relasi LR;
    address_matkul C;
    address_mahasiswa P;
    address_relasi R;

    createList(LP);
    createList(LC);
    createList(LR);

    /** insert mahasiswa */
    P = alokasi(3);
    insertFirst(LP, P);
    P = alokasi(7);
    insertFirst(LP, P);
    P = alokasi(2);
    insertFirst(LP, P);
    P = alokasi(4);
    insertFirst(LP, P);

    cout<<"list mahasiswa"<<endl;
    printInfo(LP);

    /** insert matkul */
    C = alokasi("A");
    insertFirst(LC, C);
    C = alokasi("D");
    insertFirst(LC, C);
    C = alokasi("E");
    insertFirst(LC, C);
    C = alokasi("O");
    insertFirst(LC, C);

    cout<<"list matkul"<<endl;
    printInfo(LC);

    /** RELASIKAN mahasiswa DENGAN matkul **/
    P = findElm(LP, 4);
    C = findElm(LC, "E");
    R = alokasi(P,C);
    insertFirst(LR,R );

    C = findElm(LC, "D");
    R = alokasi(P, C);
    insertFirst(LR,R );


    P = findElm(LP, 2);
    C = findElm(LC, "E");
    R = alokasi(P, C);
    insertFirst(LR, R );

    P = findElm(LP, 3);
    C = findElm(LC, "A");
    R = alokasi(P, C);
    insertFirst(LR,R );

    cout<<endl<<"Setelah Direlasikan"<<endl;
    cout<<"list mahasiswa"<<endl;
    printInfo(LP);

    cout<<endl<<"list matkul"<<endl;
    printInfo(LC);

    cout<<endl<<"list relasi"<<endl;
    printInfo(LR);


    /** KELEBIHAN DARI BENTUK III: jika salah satu matkul diedit **/
    C = findElm(LC, "E");
    info(C) = "X";

    cout<<endl<<"Setelah matkul Diedit"<<endl;
    cout<<"list mahasiswa"<<endl;
    printInfo(LP);

    cout<<endl<<"list matkul"<<endl;
    printInfo(LC);

    cout<<endl<<"list relasi"<<endl;
    printInfo(LR);

    return 0;
}
