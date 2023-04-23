//
// Created by jakub on 3/12/2023.
//

#include "kopiec.h"
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;

    kopiec::kopiec(){
        table = new int[rozmiar];
        start = false;
    }

    void kopiec::pokaz(string sp, string sn, int v) {
        string s;
        string cr, cl, cp;
        cr = cl = cp = "  ";
        cr [ 0 ] = ' '; cr [ 1 ] = ' ';
        cl [ 0 ] = ' '; cl [ 1 ] = ' ';
        cp [ 0 ] = ' ';
        if( v < rozmiar )
        {
            s = sp;
            if( sn == cr ) s [ s.length( ) - 2 ] = ' ';
            pokaz( s + cp, cr, 2 * v + 2 );

            s = s.substr ( 0, sp.length( ) - 2 );

            cout << s <<sn<< table [ v ] << endl;

            s = sp;
            if( sn == cl ) s [ s.length( ) - 2 ] = ' ';
            pokaz( s + cp, cl, 2 * v + 1 );
        }
    }

    void kopiec::dodaj(int liczba) {
        temp = new int[++rozmiar];
        for(int i=0;i<rozmiar-1;i++) temp[i] = table[i];
        temp[rozmiar-1] = liczba;
        relocate();
        sort();
    }

    void kopiec::usunKorzen() {
        if(rozmiar==0) {
            cout<<"Kopiec pusty"<<endl;
            return;
        }
        swap(table[0],table[rozmiar-1]);
        temp = new int[--rozmiar];
        for(int i=0;i<rozmiar;i++) temp[i] = table[i];
        relocate();
        int i=0;
        int j=1;
        while(j < rozmiar){
            if(j+1 < rozmiar && table[j+1] > table[j]) j++;
            if(table[i] >= table[j]) break;
            swap(table[i],table[j]);
            i = j;
            j = 2*j+1;
        }
    }

    void kopiec::sort(){
        int i=rozmiar-1;
        while(true){
            if(table[i]>table[(int)floor((((double)i)-1)/2)] && i!=0 && (int)floor((((double)i)-1)/2)>=0) {
                swap(table[i],table[(int)floor((((double)i)-1)/2)]);
                i = (int)floor((((double)i)-1)/2);
            } else break;
        }
    }

    void kopiec::relocate(){
    if(!start) delete [] table;
    table = new int[rozmiar];
    for(int i=0;i<rozmiar;i++) table[i] = temp[i];
    delete [] temp;
}

    bool kopiec::isCorrect(){
        int i=0;
        while(i<rozmiar){
            if(2*i+1>=rozmiar) break;
            if(table[i]<table[2*i+1] || table[i]<table[2*i+2] && 2*i+2<rozmiar){
                cout<<"BLAD KOPCA w "<<i<<endl;
                return false;
            } else i++;
        }
        cout<<"KOPIEC POPRAWNY"<<endl;
        return true;
    }

    void kopiec::test(int iloscTestow, int wielkoscZestawu, int iloscOperacji){
        srand(time(NULL));
        for (int i = 0; i < iloscTestow; i++) {
            for(int k=0;k<wielkoscZestawu;k++) dodaj(rand() % 1000);
            cout << "TEST " << i << endl;
            for (int j = 0; j < iloscOperacji; j++) {
                switch (rand() % 2 + 1) {
                    case 1:
                        dodaj(rand() % 1000);
                        break;
                    case 2:
                        usunKorzen();
                        break;
                }
            }
            if(isCorrect()) cout<<"TEST "<<i<< " ZALICZONY"<<endl;
            if(rozmiar!=0) for(int k=0;k<rozmiar;k++) usunKorzen();
        }
    }

    void kopiec::wczytaj(string nazwa) {
        fstream file (nazwa,std::ios_base::in);
        if (!file.is_open()) {
            cout<<"ERROR"<<endl;
            return;
        }
        int number;
        while (file >> number){
            dodaj(number);
        }
}

    void kopiec::zapisz(string nazwa) {
        if (table==NULL) cout<<"Brak utworzonej tablicy."<<endl;
        else {
            ofstream file (nazwa);
            if (!file.is_open()) {
                cout<<"ERROR"<<endl;
                return;
            }
            for (int i = 0; i < rozmiar; i++) {
                file<<table[i]<<" ";
            }
        }
    }

void kopiec::menu() {
    int n;
    int liczba;
    string name;
    for(;;){
        cout<<"Podaj numer akcji ktora chcesz wykonac:"<<endl;
        cout<<"1. Dodaj"<<endl;
        cout<<"2. Pokaz"<<endl;
        cout<<"3. Wyszukaj element"<<endl;
        cout<<"6. Usun"<<endl;
        cout<<"9. Wyjdz"<<endl;
        cout<<"10. Wczytaj dane"<<endl;
        cout<<"11. Zapisz dane"<<endl;
        cin.sync(); cin.clear();
        cin>>n;
        switch (n) {
            case 1:
                cin.sync(); cin.clear();
                cout<<"Podaj liczbe"<<endl;
                cin>>liczba;
                dodaj(liczba);
                break;
            case 2:
                pokaz("","",0);
                break;
            case 3:
                cin.sync(); cin.clear();
                cout<<"Podaj liczbe"<<endl;
                cin>>liczba;
                cout<<"Indeks liczby: "<<wyszukaj(liczba)<<endl;
                break;
            case 6:
                cin.sync(); cin.clear();
                usunKorzen();
                break;
            case 9:
                //for(int i=0;i<rozmiar;i++) usunKorzen();
                delete[] table;
                exit(2137);
            case 10:
                cin.sync(); cin.clear();
                cout<<"Podaj nazwe pliku"<<endl;
                cin>>name;
                wczytaj(name);
                break;
            case 11:
                cin.sync(); cin.clear();
                cout<<"Podaj nazwe pliku"<<endl;
                cin>>name;
                zapisz(name);
                break;
        }
    }
}

int kopiec::wyszukaj(int number) {
    if (rozmiar == 0) {
        cout << "Kopiec pusty" << endl;
        return -49;
    }
    int i=0;
    if(table[i]==number) return i;
    return szukaj(i, number);
}

int kopiec::szukaj(int indeks, int number){
        int te;
    if(table[indeks]==number) return indeks;
    if(2*indeks+1 >= rozmiar||2*indeks+2 >= rozmiar) return -34;
    te = szukaj(2*indeks+1,number);
    if(te == -34) te = szukaj(2*indeks+2,number);
    return te;
    }

