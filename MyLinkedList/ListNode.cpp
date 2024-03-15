#include "ListNode.h"
ListNode* insert(ListNode *ptr, string val){
    ListNode* newNode = new ListNode{val,ptr};
    return newNode;


}

void insert( ListNode **ptr, string val ){
    *ptr = new ListNode{val,*ptr};
}


ListNode *remove( ListNode *ptr ){
    if (ptr == nullptr) {
        return nullptr;
    }
    ListNode* next = ptr->next;
    delete ptr;
    return next;
}



void remove(ListNode** ptr){
    if (*ptr != nullptr) {
        ListNode* nodeToRemove = *ptr;
        *ptr = (*ptr)->next;
        delete nodeToRemove;
    }
}

void printForward(ostream &out, ListNode *ptr){
    if (ptr == nullptr) {
        return;
    }
    out << ptr->data << endl;
    printForward(out, ptr->next);
}



void printReverse(ostream &out, ListNode *ptr){
    if (ptr == nullptr) {
        return;
    }
    printReverse(out, ptr->next);
    out << ptr->data << endl;
}






