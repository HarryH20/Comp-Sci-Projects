

#ifndef LAB8_LISTNODE_H
#define LAB8_LISTNODE_H
#include <iostream>
#include <string>

using namespace std;

struct ListNode {
    string data;
    ListNode *next;
};

ListNode *insert(ListNode *ptr, string val);
void insert(ListNode **ptr, string val);
ListNode *remove(ListNode *ptr);
void remove(ListNode** ptr);
void printForward(ostream &out, ListNode *ptr);
void printReverse(ostream &out, ListNode *ptr);
#endif //LAB8_LISTNODE_H
