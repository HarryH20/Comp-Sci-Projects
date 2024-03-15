/**
*  File: proj10-MyList.h
*  Author: Harrison Hassler
*  Course: CSI 1440
*  Assignment: Project 10
*  Due Date: 05/1/2023
*
*  Date Modified: 04/30/2023
*    - File Created and functions made
*
*/



#ifndef PROJECT10_PROJ10_MYLIST_H
#define PROJECT10_PROJ10_MYLIST_H
#include "proj10-ContainerIfc.h"
#include "proj10-Node.h"



template <class T>
class MyList : public ContainerIfc <T> {
public:
    /**
     * MyList()
     *
     * class constructor
     *
     * Parameters: none
     *
     * Output:
     *      return: none
     *      reference parameters: none
     *      stream: none
     */
    MyList();

    /**
     * ~MyList()
     *
     * class destructor
     *
     * Parameters: none
     *
     * Output:
     *      return: none
     *      reference parameters: none
     *      stream: none
     */
    ~MyList();

    /**
     * MyList(const MyList&)
     *
     * class copy constructor
     *
     * Parameters:
     *   - that:  a const MyList object
     *
     * Output:
     *      return: none
     *      reference parameters: that
     *      stream: none
     */
    MyList(const MyList&);

    /**
     * equals operator
     *
     * overload assignment operator
     *
     * Parameters:
     *   - other:  a const MyList object
     *
     * Output:
     *      return: MyList object
     *      reference parameters: that
     *      stream: none
     */
    MyList <T>& operator = (const MyList&);

    /**
     * pushFront(T)
     *
     * store data element n in a new Node and adds the Node to the front of a
     * data structure
     *
     * Parameters:
     *   - other:  a T variable
     *
     * Output:
     *      return: MyList object by reference
     *      reference parameters: none
     *      stream: none
     */
    MyList <T>& pushFront(T);

    /**
     * pushback
     *
     * store data element n in a new Node and adds the Node to the rear
     * of a data structure
     *
     * Parameters:
     *   - a:  a T variable
     *
     * Output:
     *      return: MyList object by reference
     *      reference parameters: none
     *      stream: none
     */
    MyList <T>& pushBack(T);

    /**
     * popFront
     *
     * removes a data element from the front of the data structure
     *
     * Parameters:
     *   - a:  a T variable
     *
     * Output:
     *      return: MyList object by reference
     *      reference parameters: e
     *      stream: none
     */
    MyList <T>& popFront(T&);

    /**
     * popBack
     *
     * removes a data element from the rear of the data structure
     *
     * Parameters:
     *   - a:  a T variable
     *
     * Output:
     *      return: MyList object by reference
     *      reference parameters: e
     *      stream: none
     */
    MyList <T>& popBack(T&);

    /**
     * getSize()
     *
     * returns the number of Nodes currently in the linked MyList
     *
     * Parameters: none
     *
     * Output:
     *      return: int
     *      reference parameters: e
     *      stream: none
     */
    int getSize();

    /**
    * isEmpty()
    *
    * returns true if there are any linked nodes in the list
    *
    * Parameters: none
    *
    * Output:
    *      return: int
    *      reference parameters: none
    *      stream: none
    */
    bool isEmpty();

    /**
     * front()
     *
     * returns a copy of the first data item in the linked list
     *
     * Parameters: none
     *
     * Output:
     *      return: T
     *      reference parameters: none
     *      stream: none
     */
    T front();

    /**
     * back()
     *
     * returns a copy of the last data item in the linked list
     *
     * Parameters: none
     *
     * Output:
     *      return: T
     *      reference parameters: none
     *      stream: none
     */
    T back();

    /**
     * operator []
     *
     * returns a copy of the first data item in the linked list
     *
     * Parameters:
     *   ndx:  the index of what node to access
     *
     * Output:
     *      return: T reference
     *      reference parameters: none
     *      stream: none
     */
    T& operator [](int);

    /**
    * erase()
    *
    * removes all nodes from MyList
    *
    * Parameters:
    *   ndx:  the index of what node to access
    *
    * Output:
    *      return: T reference
    *      reference parameters: none
    *      stream: none
    */
    void erase();

private:
    Node<T> *head;
    Node<T> *tail;
};



template <class T>
MyList<T>::MyList(){
    this->head = nullptr;
    this->tail = nullptr;

}

template <class T>
MyList<T>::~MyList(){
    this->erase();
}

template <class T>
MyList<T>::MyList(const MyList& other) {
    if (other.head != nullptr) {
        this->head = new Node<T>(other.head->data);
        Node<T>* temp = other.head->next;
        Node<T>* curr = this->head;
        while (temp != nullptr) {
            curr->next = new Node<T>(temp->data);
            curr = curr->next;
            temp = temp->next;
        }
        this->tail = curr;
    }
    else {
        this->head = nullptr;
        this->tail = nullptr;
    }
}


template <class T>
MyList<T>& MyList<T>::operator=(const MyList& that) {
    if (this != &that) {
        if (that.head != nullptr) {
            this->head = new Node<T>(that.head->data);
            Node<T>* temp = that.head->next;
            Node<T>* curr = this->head;
            while (temp != nullptr) {
                curr->next = new Node<T>(temp->data);
                curr = curr->next;
                temp = temp->next;
            }
            this->tail = curr;
        }
        else {
            this->head = nullptr;
            this->tail = nullptr;
        }
    }
    return *this;
}

template <class T>
MyList<T>& MyList<T>::pushFront(T a){
    if(this->isEmpty()){
        this->head = new Node<T>(a);
        this->tail = this->head;
    }
    else{
        Node<T>* temp = this->head;
        this->head = new Node<T>(a);
        this->head->next = temp;
    }

    return *this;
}

template <class T>
MyList<T>& MyList<T>::pushBack(T a){
    if(this->isEmpty()){
        this->head = new Node<T>(a);
        this->tail = this->head;
    }
    else{
        this->tail->next = new Node<T>(a);
        this->tail = this->tail->next;
    }
    return *this;
}

template <class T>
MyList<T>& MyList<T>::popFront(T& a){
    if(this->isEmpty()){
        throw BADINDEX();
    }
    else {
        Node<T> *temp = this->head;
        a = this->head->data;
        this->head = temp->next;
        temp->next = nullptr;
        delete temp;
    }

    if(this->isEmpty()){
        this->tail = this->head;
    }
    return *this;

}

template <class T>
MyList<T>& MyList<T>::popBack(T& a){
    if (this->isEmpty()) {
        throw BADINDEX();
    }
    else if (this->head->next == nullptr){
        a = this->head->data;

        delete this->head;
        this->head = nullptr;
        this->tail = nullptr;
    }
    else{
        Node<T> *temp = this->head;
        while (temp->next->next != nullptr){
            temp = temp->next;
        }
        a = temp->next->data;
        this->tail = temp;

        delete temp->next;
        temp->next = nullptr;
    }

    return *this;
}

template <class T>
int MyList<T>::getSize(){
    int count = 0;
    Node<T>* temp = this->head;
    while(temp != nullptr){
        temp = temp->next;
        count++;
    }
    return count;
}

template <class T>
bool MyList<T>::isEmpty() {
    return this->head == nullptr;
}

template <class T>
T MyList<T>::front(){
    if (this->isEmpty()){
        throw BADINDEX();
    }
    else {
        return this->head->data;
    }
}

template <class T>
T MyList<T>::back(){
    if(this->isEmpty()){
        throw BADINDEX();
    }
    else{
        return this->tail->data;
    }
}

template <class T>
T& MyList<T>::operator [] (int index){
    if (index >= this->getSize() || index < 0){
        throw BADINDEX();
    }
    Node<T> *temp = this->head;
    for (int i = 0; i < index; i++){
        temp = temp->next;
    }
    return temp->data;
}

template <class T>
void MyList<T>::erase(){
    if(this->head != nullptr){
        while(this->head != nullptr){
            Node<T> *temp = this->head;
            this->head = this->head->next;
            delete temp;
        }
        this->tail = this->head;
    }
}



#endif //PROJECT10_PROJ10_MYLIST_H
