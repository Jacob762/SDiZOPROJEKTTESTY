//
// Created by jakub on 3/13/2023.
//

#ifndef SDIZO_RBTREE_H
#define SDIZO_RBTREE_H
#include <string>
#include "../Tablica/tablica.h"

using namespace std;
class RBTree {
public:
    struct RBTNode{
        RBTNode* up;
        RBTNode* left;
        RBTNode* right;
        int data;
        char color;
    };
    std::string cr, cl, cp;
    RBTNode straznik;
    RBTNode* root = NULL;
    RBTree();
    void dodaj(int liczba);


    void printRBT(std::string sp, std::string sn, RBTNode *p);

    void rotacjaWLewo(RBTNode *node);

    void rotacjaWPrawo(RBTNode *node);

    RBTNode* wyszukaj(int liczba);

    void zapisz(string nazwa, string sp, string sn, RBTNode * p );

    void wczytaj(string nazwa);

    void print2DUtil(RBTNode *root, int space);

    void print2D(RBTNode *root);

    void printData(RBTNode *rote);

    bool usun(RBTNode *node);

    RBTNode *nastepnik(RBTNode *node);

    RBTNode *wskazBrata(RBTNode *node);

    void menu();
};


#endif //SDIZO_RBTREE_H
