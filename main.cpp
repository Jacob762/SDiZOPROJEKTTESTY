#include <iostream>
#include "Struktury/Tablica/tablica.h"
#include "Struktury/Lista/lista.h"
#include "Struktury/Kopiec/kopiec.h"
#include "Struktury/BRTree/RBTree.h"
#include "Struktury/Tablica/tablicaTesty.h"
#include "Struktury/Lista/listaTesty.h"
#include "Struktury/Kopiec/kopiecTesty.h"
#include "Struktury/BRTree/RBTreeTesty.h"
using namespace std;

void testyMenu();

int main() {
    testyMenu();
}

void testyMenu(){
    int para[3];
    tablicaTesty tab = tablicaTesty();
    listaTesty list = listaTesty();
    kopiecTesty kopiec = kopiecTesty();
    RBTreeTesty tree = RBTreeTesty();
    kopiec.test(1000,300,15);
    cout<<"XD"<<endl;
    kopiec.test(2000,300,15);
    cout<<"XD"<<endl;
    kopiec.test(5000,300,15);
    cout<<"XD"<<endl;
    kopiec.test(10000,300,15);
    cout<<"XD"<<endl;
    kopiec.test(20000,300,15);
    cout<<"XD"<<endl;
    kopiec.test(50000,300,15);
    for(;;){
        cout<<"Podaj parametry danych"<<endl;
        cout<<"Wielkosc zestawu:"<<endl;
        cin>>para[0];
        cout<<"Ilosc operacji:"<<endl;
        cin>>para[1];
        cout<<"Ilosc wynikow:"<<endl;
        cin>>para[2];
        cout<<"Wybierz strukture"<<endl;
        cout<<"1. tablica dynamiczna"<<endl;
        cout<<"2. lista dwukierunkowa"<<endl;
        cout<<"3. kopiec"<<endl;
        cout<<"4. drzewo czerwono-czarne"<<endl;
        cout<<"5. Wyjdz"<<endl;
        int n;
        cin>>n;
        switch (n) {
            case 1:
                tab.test(para[0],para[1],para[2]);
                break;
            case 2:
                list.test(para[0],para[1],para[2]);
                break;
            case 3:
                kopiec.test(para[0],para[1],para[2]);
                break;
            case 4:
                tree.rbtTesty(para[0],para[1],para[2]);
                break;
            case 5:
                exit(2138);
        }
    }
}