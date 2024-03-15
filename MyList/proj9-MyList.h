/**
*  File: proj9-MyList.h
*  Author: Harrison Hassler
*  Course: CSI 1440
*  Assignment: Project 9
*  Due Date: 04/24/2023
*
*  Date Modified: 04/11/2023
*    - File Created and functions made
*
*/

#ifndef PROJECT9_PROJ9_MYLIST_H
#define PROJECT9_PROJ9_MYLIST_H
#include "proj9-ContainerIfc.h"
#include "proj9-Node.h"

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

protected:
    Node<T> *head;
};

template <class T>
MyList<T>::MyList(){
    this->head = nullptr;
}

template <class T>
MyList<T>::~MyList(){
    Node<T>* currNode;
    while(this->head != nullptr){
        currNode = this->head->next;
        delete this->head;
        this->head = currNode;
    }
}

template <class T>
MyList<T>::MyList(const MyList& other){
    this->head = nullptr;
    if(other.head != nullptr){
        this->head = new Node<T>(other.head->data);
        Node<T>* currNode = this->head;
        Node<T>* temp = other.head->next;
        while(temp != nullptr){
            currNode->next = new Node<T>(temp->data);
            currNode = currNode->next;
            temp = temp->next;
        }
    }
}

template <class T>
MyList<T>& MyList<T>::operator =(const MyList& other){
    if(this != &other){
        this->head = nullptr;
        if(other.head != nullptr){
            this->head = new Node<T>(other.head->data);
            Node<T>* currNode = this->head;
            Node<T>* temp = other.head->next;
            while(temp!= nullptr){
                currNode->next = new Node<T>(temp->data);
                currNode = currNode->next;
                temp = temp->next;
            }

        }
        return *this;
    }
}

template <class T>
MyList<T>& MyList<T>::pushFront(T t) {
    if(this->head == nullptr){
        this->head = new Node<T>(t);
    }
    else{
        Node<T>* newNode = new Node<T>(t);
        newNode->next = this->head;
        this->head = newNode;

    }
    return *this;
}

template<class T>
MyList<T>& MyList<T>::pushBack(T t){
    if(this->head == nullptr){
        this->head = new Node<T>(t);
    }
    else{
        Node<T> *temp = this->head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = new Node<T>(t);
    }
    return *this;
}

template<class T>
MyList<T>& MyList<T>::popFront(T& t){
    if(this->head == nullptr){
        throw BADINDEX();
    }
    else{
        t = this->head->data;
        Node<T>* temp = this->head;
        this->head = this->head->next;
        delete temp;
    }
    return *this;
}

template <class T>
MyList<T>& MyList<T>::popBack(T &t){
    if(this->head == nullptr){
        throw BADINDEX();
    }

    else if(this->head->next == nullptr){
        t = this->head->data;
        delete this->head;
        this->head = nullptr;

    }
    else{
        Node<T>*temp = this->head;
        while(temp->next->next != nullptr){
            temp = temp->next;
        }
        t = temp->next->data;
        delete temp->next;
        temp->next = nullptr;


    }
    return *this;

}

template <class T>
int MyList<T>::getSize(){
    Node<T>* temp = this->head;
    int count = 0;
    while(temp != nullptr){
        count++;
        temp = temp->next;
    }
    return count;
}

template <class T>
bool MyList<T>::isEmpty(){
    return(this->head == nullptr);
}


template <class T>
T MyList<T>::front(){
    if(this->head == nullptr){
        throw BADINDEX();
    }
    else{
        return this->head->data;
    }
}

template <class T>
T MyList<T>::back(){
    if(this->head == nullptr){
        throw BADINDEX();
    }
    else{
        Node<T>*temp = this->head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        return temp->data;
    }
}

template <class T>
void MyList<T>::erase(){
    while(this->head != nullptr){
        Node<T>* temp = this->head;
        this->head = temp->next;
        delete temp;


    }
}

template <class T>
T& MyList<T>::operator[](int ndx){
    if(ndx >= this->getSize() || ndx < 0){
        throw BADINDEX();
    }
    else{
        Node<T>*temp = this->head;
        for(int i = 0; i < ndx; i++){
            temp = temp->next;
        }
        return temp->data;
    }

}


#endif //PROJECT9_PROJ9_MYLIST_H
