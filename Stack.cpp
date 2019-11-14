//
// Created by Benjamin Raiford on 11/13/19.
//

#include "Stack.h"

//Default constructor
Stack::Stack() {
    head = nullptr;
}

//Deletes from the head, returns false if list is empty
bool Stack::pop_head() {
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
//Adds a new node to the head of the list
void Stack::push_head(const Data& d) {
    Node* newHead = new Node(d);
    if(head == nullptr){
        head = newHead;
    }
    else{
        newHead->next = head;
        head = newHead;
    };
}
