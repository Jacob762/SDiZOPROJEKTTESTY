//
// Created by jakub on 3/12/2023.
//

#ifndef SDIZO_KOPIEC_H
#define SDIZO_KOPIEC_H
#include <string>
#include <iostream>
#include <cstdio>
#include <ctime>
#include <ratio>
#include <chrono>

using namespace std;

class kopiec {
private:
    bool start = true;
public:
    kopiec();
    int * temp;
    int rozmiar = 0;
    int* table = NULL;
    void dodaj(int liczba);
    void usunKorzen();
    void pokaz(std::string sp, std::string sn, int v);
    void relocate();
    void sort();
    bool isCorrect();
    void test(int iloscTestow, int wielkoscZestawu,int iloscOperacji);
    void wczytaj(string nazwa);
    void zapisz(string nazwa);

    void menu();

    int wyszukaj(int number);

    int szukaj(int indeks,int number);
};


#endif //SDIZO_KOPIEC_H
