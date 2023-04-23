//
// Created by Jakub Klawon on 05/04/2023.
//

#ifndef SDIZO_RBTREETESTY_H
#define SDIZO_RBTREETESTY_H
#include "RBTree.h"

namespace std {

    class RBTreeTesty {
    private:
        RBTree* tree;
    public:
        RBTreeTesty();
        void rbtTesty(int wielkoscZestawu, int iloscOperacji, int iloscWynikow);

    };

} // std

#endif //SDIZO_RBTREETESTY_H
