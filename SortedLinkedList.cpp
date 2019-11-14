//
// Created by Benjamin Raiford on 11/14/19.
//

#include "SortedLinkedList.h"

void SortedLinkedList::insertSorted(const Data &d) {
    //Create a new node
    Node *newNode = new Node(d);
    //if list is empty
    if (head == nullptr) {
        head = newNode;
    }
    //if list is NOT empty
    else{
        //create a "dummy" head
        Node *dummyHead = new Node(d);
        dummyHead->next = head;

        //create a marker
        Node *endSorted;
        endSorted = dummyHead;

        //find correct location
        while (endSorted->next != nullptr && endSorted->next->data < newNode->data)
            endSorted = endSorted->next;

        //insert node
        newNode->next = endSorted->next;
        endSorted->next = newNode;

        //delete "dummy" head and make the first value in the list head
        head = dummyHead->next;
        dummyHead->next = nullptr;
        delete dummyHead;
    }
}
