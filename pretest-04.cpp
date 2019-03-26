/*
Nama    : Ahmad Faaiz A
NPM     : 140810180023
kelas   : A
Tanggal : 26/03/2018
*************************************/

#include <iostream>
using namespace std;

struct ElemtList{
    char npm[14];
    char nama[40];
    float ipk;
    ElemtList* next;
};

typedef ElemtList* pointer;
typedef pointer List;

void createList(List& First){
    First = NULL;
}
void createElemt(pointer& pBaru){
    pBaru = new ElemtList;
    cout << "NPM : "; cin >> pBaru->npm;
    cout << "Nama : "; cin >> pBaru->nama;
    cout << "IPK : "; cin >> pBaru->ipk;
}

void insertSortNPM(List& First, pointer pBaru){
    pointer pBantu;
    if (First == NULL) {                    //add di awal
        First = pBaru;
    } else {
        pBantu = First;
        while(pBantu->next != NULL){
            if (pBaru->npm > pBantu->npm) {     //jika lebih besar
                if(pBantu->next != NULL){       //di akhir
                    pBantu->next = pBaru;
                } else {                        //di tengah
                    pBaru->next = pBantu->next;
                    pBantu->next = pBaru;
                }
            } else {                            //jika lebih kecil
                if (pBaru->npm < First->npm){   //insert first
                    pBaru->next = First;
                    First = pBaru;
                } else {                        //di tengah
                    pBaru->next = pBantu->next;
                    pBantu->next = pBaru;
                } 
            }
        }
    }
}

void traversal(List& First){
    pointer pBantu;
    if (First == NULL) {
        cout << "DATA KOSONG!" << endl;
    } else {
        while(pBantu != NULL){
            cout << pBantu->npm << "\t" << pBantu->nama << "\t" << pBantu->ipk << endl;
            pBantu = pBantu->next;
        }
    }
}
 

int main(){
    pointer p;
    List First;
    int count = 5;

    createList(First);
    for(int i = 0; i < count; i++)
    {
        createElemt(p);
        insertSortNPM(First, p);
    }

    traversal(First);

}