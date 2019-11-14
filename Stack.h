//
// Created by Benjamin Raiford on 11/13/19.
//

#ifndef PROJECT7_STACK_H
#define PROJECT7_STACK_H

#include "LinkedList.h"

class Stack : public LinkedList {
public:
    //Constructor
    Stack();

    //Functions
    void push_head(const Data& d);
    bool pop_head();
};


#endif //PROJECT7_STACK_H
