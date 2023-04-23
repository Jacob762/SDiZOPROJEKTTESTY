//
// Created by jakub on 3/19/2023.
//

#include <fstream>
#include "listaTesty.h"
#include <cmath>

using namespace std;

listaTesty::listaTesty() {
    list = lista();
}

void listaTesty::test(int wielkoscZestawu,int iloscOperacji,int iloscWynikow) {
    chrono::high_resolution_clock::time_point t1;
    chrono::high_resolution_clock::time_point t2;
    ofstream listaFile ("wynikiPomiarowListy.txt",ios::out|ios::app); //zrobic zabezpiczeenie zeby za kazdym razem generowal sie nowy plik
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
            for(int k=0;k<wielkoscZestawu;k++) list.dodajNaKoniec(new listaElement(rand()%1000+1));
            int numb = rand()%1000+1;
            listaElement* element = new listaElement(numb);
            t1 = chrono::high_resolution_clock::now();
            list.dodajNaKoniec(element);
            t2 = chrono::high_resolution_clock::now();
            chrono::duration<double> time_span = std::chrono::duration_cast<chrono::duration<double>>(t2 - t1);
            tablicaCzasow[i] = std::chrono::duration<double>(time_span).count();
            srednia+=tablicaCzasow[i];
            t1 = chrono::high_resolution_clock::now();
            list.usunZKonca();
            t2 = chrono::high_resolution_clock::now();
            time_span = std::chrono::duration_cast<chrono::duration<double>>(t2 - t1);
            tablicaCzasow1[i] = std::chrono::duration<double>(time_span).count();
            srednia2+=tablicaCzasow1[i];
            for(int k=0;k<wielkoscZestawu;k++) list.usunZKonca();
        }
        tablicaSrednich1[j] = srednia/iloscOperacji;
        tablicaSrednich2[j] = srednia2/iloscOperacji;
    }
    if(listaFile.is_open()){
        listaFile<<"WLASCIWOSCI: WIELKOSC ZESTAWU: "<< wielkoscZestawu<<" ILOSC OPERACJI: "<<iloscOperacji<<endl;
        listaFile<<"DODAWANIE_NA_KONIEC: ";
        for(int i=0;i<iloscWynikow;i++) listaFile<<tablicaSrednich1[i]*pow(10,9)<<" ";
        listaFile<<endl;
        listaFile<<"USUWANIE_Z_KONCA: ";
        for(int i=0;i<iloscWynikow;i++) listaFile<<tablicaSrednich2[i]*pow(10,9)<<" ";
        listaFile<<endl;
    }
    //badanie dodawania na poczatrke i odjemwonai az koncu
    for(int j=0;j<iloscWynikow;j++){
        srednia=0;
        srednia2=0;
        for(int i=0;i<iloscOperacji;i++){
            for(int k=0;k<wielkoscZestawu;k++) list.dodajNaKoniec(new listaElement(rand()%1000+1));
            int numb = rand()%1000+1;
            listaElement* element = new listaElement(numb);
            t1 = chrono::high_resolution_clock::now();
            list.dodajNaPoczatek(element);
            t2 = chrono::high_resolution_clock::now();
            chrono::duration<double> time_span = std::chrono::duration_cast<chrono::duration<double>>(t2 - t1);
            tablicaCzasow[i] = std::chrono::duration<double>(time_span).count();
            srednia+=tablicaCzasow[i];
            t1 = chrono::high_resolution_clock::now();
            list.usunZPoczatku();
            t2 = chrono::high_resolution_clock::now();
            time_span = std::chrono::duration_cast<chrono::duration<double>>(t2 - t1);
            tablicaCzasow1[i] = std::chrono::duration<double>(time_span).count();
            srednia2+=tablicaCzasow1[i];
            for(int k=0;k<wielkoscZestawu;k++) list.usunZKonca();
        }
        tablicaSrednich1[j] = srednia/iloscOperacji;
        tablicaSrednich2[j] = srednia2/iloscOperacji;
    }
    if(listaFile.is_open()){
        listaFile<<"DODAWANIE_NA_POCZATEK: ";
        for(int i=0;i<iloscWynikow;i++) listaFile<<tablicaSrednich1[i]*pow(10,9)<<" ";
        listaFile<<endl;
        listaFile<<"USUWANIE_Z_POCZATKU: ";
        for(int i=0;i<iloscWynikow;i++) listaFile<<tablicaSrednich2[i]*pow(10,9)<<" ";
        listaFile<<endl;
    }
    //badanie dodawania i odejmowania z dowolnego miejsca w polowie
    for(int j=0;j<iloscWynikow;j++){
        srednia=0;
        srednia2=0;
        for(int i=0;i<iloscOperacji;i++){
            for(int k=0;k<wielkoscZestawu;k++) list.dodajNaKoniec(new listaElement(rand()%1000+1));
            int numb = rand()%1000+1;
            int indeks = wielkoscZestawu/2;
            listaElement* element = new listaElement(numb);
            t1 = chrono::high_resolution_clock::now();
            list.dodajWDowolnymMiejscu(indeks,element); //psuje tez, kwestia tego indeksu
            t2 = chrono::high_resolution_clock::now();
            chrono::duration<double> time_span = std::chrono::duration_cast<chrono::duration<double>>(t2 - t1);
            tablicaCzasow[i] = std::chrono::duration<double>(time_span).count();
            srednia+=tablicaCzasow[i];
            t1 = chrono::high_resolution_clock::now();
            list.usunZDowolnegoMiejsca(indeks); //psuje sie bo funkcja zajmuje sie teraz liczbami a nie indeksaMi
            t2 = chrono::high_resolution_clock::now();
            time_span = std::chrono::duration_cast<chrono::duration<double>>(t2 - t1);
            tablicaCzasow1[i] = std::chrono::duration<double>(time_span).count();
            srednia2+=tablicaCzasow1[i];
            for(int k=0;k<wielkoscZestawu;k++) list.usunZKonca();
        }
        tablicaSrednich1[j] = srednia/iloscOperacji;
        tablicaSrednich2[j] = srednia2/iloscOperacji;
    }
    if(listaFile.is_open()){
        listaFile<<"DODAWANIE_NA_DOWOLNE_MIEJSCE: ";
        for(int i=0;i<iloscWynikow;i++) listaFile<<tablicaSrednich1[i]*pow(10,9)<<" ";
        listaFile<<endl;
        listaFile<<"USUWANIE_Z_DOWOLNEGO_MIEJSCA: ";
        for(int i=0;i<iloscWynikow;i++) listaFile<<tablicaSrednich2[i]*pow(10,9)<<" ";
        listaFile<<endl;
    }
    for(int j=0;j<iloscWynikow;j++){
        srednia=0;
        for(int i=0;i<iloscOperacji;i++){
            for(int k=0;k<wielkoscZestawu;k++) list.dodajNaKoniec(new listaElement(rand()%1000+1));
            list.usunZKonca();
            list.dodajWDowolnymMiejscu(wielkoscZestawu/2,new listaElement(1002));
            t1 = chrono::high_resolution_clock::now();
            list.wyszukajElementIndex(1002);
            t2 = chrono::high_resolution_clock::now();
            chrono::duration<double> time_span = std::chrono::duration_cast<chrono::duration<double>>(t2 - t1);
            tablicaCzasow[i] = std::chrono::duration<double>(time_span).count();
            srednia+=tablicaCzasow[i];
            for(int k=0;k<wielkoscZestawu;k++) list.usunZKonca();
        }
        tablicaSrednich1[j] = srednia/iloscOperacji;
    }
    if(listaFile.is_open()){
        listaFile<<"Wyszukiwanie: ";
        for(int i=0;i<iloscWynikow;i++) listaFile<<tablicaSrednich1[i]*pow(10,9)<<" ";
        listaFile<<endl;
        listaFile<<endl<<endl;
    }
    cout<<"TESTY NA LISCIE ZAKONCZONE SUKCESEM"<<endl;
}