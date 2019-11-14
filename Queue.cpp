//
// Created by Benjamin Raiford on 11/14/19.
//

#include "Queue.h"

//Default Constructor
Queue::Queue() {
    head = nullptr;
    tail = nullptr;
}

//Adds a new node to the tail of the list
void Queue::enqueue_tail(const Data &d) {
    Node* newTail = new Node(d);
    if(head == nullptr){
        head = newTail;
        tail = newTail;
    }
    else{
        tail->next = newTail;
        tail = newTail;
    }
}
//Removes a node from the head, returns false if list is empty
bool Queue::dequeue_head() {
    // if not an empty list
    if (head != nullptr) {
        // save location of where head points
        Node *curr = head;
        // head points to next node
        head = head->next;
        // delete node where head originally pointed
        delete curr;
    }
    else{
        return false;
    }
}


