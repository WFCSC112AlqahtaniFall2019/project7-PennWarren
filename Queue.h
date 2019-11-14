//
// Created by Benjamin Raiford on 11/14/19.
//

#ifndef PROJECT7_QUEUE_H
#define PROJECT7_QUEUE_H

#include "LinkedList.h"

class Queue : public LinkedList {
    public:
        //Constructor
        Queue();

        //Functions
        void enqueue_tail(const Data& d);
        bool dequeue_head();

    private:
        Node* tail;

};


#endif //PROJECT7_QUEUE_H
