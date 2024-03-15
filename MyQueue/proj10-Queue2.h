/**
*  File: proj10-Queue2.h
*  Author: Harrison Hassler
*  Course: CSI 1440
*  Assignment: Project 10
*  Due Date: 05/1/2023
*
*  Date Modified: 04/30/2023
*    - File Created and functions made
*
*/
#ifndef PROJECT10_PROJ10_QUEUE2_H
#define PROJECT10_PROJ10_QUEUE2_H
#include "proj10-MyVector.h"

template <class T>
class Queue2 : public MyVector<T> {
private:
    int front, rear;

public:
    Queue2();
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
Queue2<T>::Queue2(){
    front = 0;
    rear = 0;
}

template <class T>
void Queue2<T>::enqueue(T val){
    if (this->size >= this->capacity){
        this->capacity *= 2;
        T *newData = new T[this->capacity];
        int cIndex = this->front;
        for (int i = 0; i < this->size; i++){
            newData[i] = this->data[cIndex];

            cIndex++;
            if (cIndex >= this->capacity / 2){
                cIndex = 0;
            }
        }
        this->front = 0;
        this->rear = this->size - 1;

        delete [] this->data;
        this->data = newData;
    }

    this->rear++;
    if (this->rear >= this->capacity){
        this->rear = 0;
    }

    this->data[this->rear] = val;
    this->size++;
}

template <class T>
void Queue2<T>::dequeue(T& val){
    if (this->size <= 0){
        throw BADINDEX();
    }

    val = this->data[front];

    this->front++;
    if (this->front >= this->capacity){
        this->front = 0;
    }
    this->size--;
}





#endif //PROJECT10_PROJ10_QUEUE2_H
