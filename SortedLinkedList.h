//
// Created by Benjamin Raiford on 11/14/19.
//

#ifndef PROJECT7_SORTEDLINKEDLIST_H
#define PROJECT7_SORTEDLINKEDLIST_H

#include "LinkedList.h"


class SortedLinkedList : public LinkedList{
    public:
        void insertSorted(const Data& d);
};


#endif //PROJECT7_SORTEDLINKEDLIST_H
