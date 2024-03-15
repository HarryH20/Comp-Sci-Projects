/**
*  File: proj10-Queue3.h
*  Author: Harrison Hassler
*  Course: CSI 1440
*  Assignment: Project 10
*  Due Date: 05/1/2023
*
*  Date Modified: 04/30/2023
*    - File Created and functions made
*
*/
#ifndef PROJECT10_PROJ10_QUEUE3_H
#define PROJECT10_PROJ10_QUEUE3_H
#include "proj10-MyList.h"

template <class T>
class Queue3 : public MyList<T> {
public:
    /**
     * enqueue(T)
     *
     * pushes a value to the back of the list
     *
     * Parameters: T
     *
     * Output:
     *      return: none
     *      reference parameters: none
     *      stream: none
     */
    void enqueue( T );

    /**
    * dequeue(T)
    *
    * removes a value from the front of the list
    *
    * Parameters: T&
    *
    * Output:
    *      return: none
    *      reference parameters: T& val
    *      stream: none
    */
    void dequeue( T& ); // throws BADINDEX
};

template <class T>
void Queue3<T>::enqueue(T val){
    this->pushBack(val);
}

template <class T>
void Queue3<T>::dequeue(T& val) {
    this->popFront(val);
}
#endif //PROJECT10_PROJ10_QUEUE3_H
