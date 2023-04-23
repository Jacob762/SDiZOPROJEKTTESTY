//
// Created by Jakub Klawon on 08/03/2023.
//

#include <fstream>
#include "tablicaTesty.h"
#include <cmath>

using namespace std;

    tablicaTesty::tablicaTesty() {
    tablicaTest = tablica();
    }

void tablicaTesty::test(int wielkoscZestawu,int iloscOperacji,int iloscWynikow){
    chrono::high_resolution_clock::time_point t1;
    chrono::high_resolution_clock::time_point t2;
    ofstream tablicaFile ("wynikiPomiarowTablicy.txt",ios::out|ios::app); //zrobic zabezpiczeenie zeby za kazdym razem generowal sie nowy plik
    double srednia;
    double srednia2;
    double tablicaSrednich1[iloscWynikow];
    double tablicaSrednich2[iloscWynikow];
    ::srand(time(NULL));
    double tablicaCzasow[iloscOperacji];
    double tablicaCzasow1[iloscOperacji];
    //badanie dodawqania na koniec i odejmowania z konca
    for(int j=0;j<iloscWynikow;j++){
        srednia=0;
        srednia2=0;
        for(int i=0;i<iloscOperacji;i++){
            for(int k=0;k<wielkoscZestawu;k++) tablicaTest.dodajNaKoniec(rand()%1000+1);
            int numb = rand()%1000+1;
            t1 = chrono::high_resolution_clock::now();
            tablicaTest.dodajNaKoniec(numb);
            t2 = chrono::high_resolution_clock::now();
            chrono::duration<double> time_span = std::chrono::duration_cast<chrono::duration<double>>(t2 - t1);
            tablicaCzasow[i] = std::chrono::duration<double>(time_span).count();
            srednia+=tablicaCzasow[i];
            t1 = chrono::high_resolution_clock::now();
            tablicaTest.usunZKonca();
            t2 = chrono::high_resolution_clock::now();
            time_span = std::chrono::duration_cast<chrono::duration<double>>(t2 - t1);
            tablicaCzasow1[i] = std::chrono::duration<double>(time_span).count();
            srednia2+=tablicaCzasow1[i];
            for(int k=0;k<wielkoscZestawu;k++) tablicaTest.usunZKonca();
        }
        tablicaSrednich1[j] = srednia/iloscOperacji;
        tablicaSrednich2[j] = srednia2/iloscOperacji;
    }
    if(tablicaFile.is_open()){
        tablicaFile<<"WLASCIWOSCI: WIELKOSC ZESTAWU: "<< wielkoscZestawu<<" ILOSC OPERACJI: "<<iloscOperacji<<endl;
        tablicaFile<<"DODAWANIE_NA_KONIEC: ";
        for(int i=0;i<iloscWynikow;i++) tablicaFile<<tablicaSrednich1[i]*pow(10,9)<<" ";
        tablicaFile<<endl;
        tablicaFile<<"USUWANIE_Z_KONCA: ";
        for(int i=0;i<iloscWynikow;i++) tablicaFile<<tablicaSrednich2[i]*pow(10,9)<<" ";
        tablicaFile<<endl;
    }
    //badanie dodawania na poczatrke i odjemwonai az koncu
    for(int j=0;j<iloscWynikow;j++){
        srednia=0;
        srednia2=0;
        for(int i=0;i<iloscOperacji;i++){
            for(int k=0;k<wielkoscZestawu;k++) tablicaTest.dodajNaKoniec(rand()%1000+1);
            int numb = rand()%1000+1;
            t1 = chrono::high_resolution_clock::now();
            tablicaTest.dodajNaPoczatek(numb);
            t2 = chrono::high_resolution_clock::now();
            chrono::duration<double> time_span = std::chrono::duration_cast<chrono::duration<double>>(t2 - t1);
            tablicaCzasow[i] = std::chrono::duration<double>(time_span).count();
            srednia+=tablicaCzasow[i];
            t1 = chrono::high_resolution_clock::now();
            tablicaTest.usunZPoczatku();
            t2 = chrono::high_resolution_clock::now();
            time_span = std::chrono::duration_cast<chrono::duration<double>>(t2 - t1);
            tablicaCzasow1[i] = std::chrono::duration<double>(time_span).count();
            srednia2+=tablicaCzasow1[i];
            for(int k=0;k<wielkoscZestawu;k++) tablicaTest.usunZKonca();
        }
        tablicaSrednich1[j] = srednia/iloscOperacji;
        tablicaSrednich2[j] = srednia2/iloscOperacji;
    }
    if(tablicaFile.is_open()){
        tablicaFile<<"DODAWANIE_NA_POCZATEK: ";
        for(int i=0;i<iloscWynikow;i++) tablicaFile<<tablicaSrednich1[i]*pow(10,9)<<" ";
        tablicaFile<<endl;
        tablicaFile<<"USUWANIE_Z_POCZATKU: ";
        for(int i=0;i<iloscWynikow;i++) tablicaFile<<tablicaSrednich2[i]*pow(10,9)<<" ";
        tablicaFile<<endl;
    }
    //badanie dodawania i odejmowania z dowolnego miejsca w polowie
    for(int j=0;j<iloscWynikow;j++){
        srednia=0;
        srednia2=0;
        for(int i=0;i<iloscOperacji;i++){
            for(int k=0;k<wielkoscZestawu;k++) tablicaTest.dodajNaKoniec(rand()%1000+1);
            int numb = rand()%1000+1;
            int indeks = rand()%(wielkoscZestawu/2+(wielkoscZestawu/2 -50));
            t1 = chrono::high_resolution_clock::now();
            tablicaTest.dodajNaDowolneMiejsce(indeks,numb);
            t2 = chrono::high_resolution_clock::now();
            chrono::duration<double> time_span = std::chrono::duration_cast<chrono::duration<double>>(t2 - t1);
            tablicaCzasow[i] = std::chrono::duration<double>(time_span).count();
            srednia+=tablicaCzasow[i];
            t1 = chrono::high_resolution_clock::now();
            tablicaTest.usunZDowolnegoMiejsca(indeks);
            t2 = chrono::high_resolution_clock::now();
            time_span = std::chrono::duration_cast<chrono::duration<double>>(t2 - t1);
            tablicaCzasow1[i] = std::chrono::duration<double>(time_span).count();
            srednia2+=tablicaCzasow1[i];
            for(int k=0;k<wielkoscZestawu;k++) tablicaTest.usunZKonca();
        }
        tablicaSrednich1[j] = srednia/iloscOperacji;
        tablicaSrednich2[j] = srednia2/iloscOperacji;
    }
    if(tablicaFile.is_open()){
        tablicaFile<<"DODAWANIE_NA_DOWOLNE_MIEJSCE: ";
        for(int i=0;i<iloscWynikow;i++) tablicaFile<<tablicaSrednich1[i]*pow(10,9)<<" ";
        tablicaFile<<endl;
        tablicaFile<<"USUWANIE_Z_DOWOLNEGO_MIEJSCA: ";
        for(int i=0;i<iloscWynikow;i++) tablicaFile<<tablicaSrednich2[i]*pow(10,9)<<" ";
        tablicaFile<<endl;
    }
    for(int j=0;j<iloscWynikow;j++){
        srednia=0;
        for(int i=0;i<iloscOperacji;i++){
            for(int k=0;k<wielkoscZestawu;k++) tablicaTest.dodajNaKoniec(rand()%1000+1);
            tablicaTest.table[wielkoscZestawu/2] = 1002;
            t1 = chrono::high_resolution_clock::now();
            tablicaTest.wyszukaj(1002);
            t2 = chrono::high_resolution_clock::now();
            chrono::duration<double> time_span = std::chrono::duration_cast<chrono::duration<double>>(t2 - t1);
            tablicaCzasow[i] = std::chrono::duration<double>(time_span).count();
            srednia+=tablicaCzasow[i];
            for(int k=0;k<wielkoscZestawu;k++) tablicaTest.usunZKonca();
        }
        tablicaSrednich1[j] = srednia/iloscOperacji;
    }
    if(tablicaFile.is_open()){
        tablicaFile<<"Wyszukiwanie: ";
        for(int i=0;i<iloscWynikow;i++) tablicaFile<<tablicaSrednich1[i]*pow(10,9)<<" ";
        tablicaFile<<endl;
        tablicaFile<<endl<<endl;
    }
    cout<<"TESTY NA TABLICY ZAKONCZONE SUKCESEM"<<endl;
}