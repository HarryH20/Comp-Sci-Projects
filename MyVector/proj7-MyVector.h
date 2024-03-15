/* file: proj7-MyVector.h
 * author: Harrison Hassler
 * course: CSI 1440
 * assignment: Project 7
 * due date: 4/3/2023
 * date modified: 3/29/2023
 *     -file created
 * date modified: 3/30/2023
 *     -file finished and code written
 */

#ifndef PROJECT7_PROJ7_MYVECTOR_H
#define PROJECT7_PROJ7_MYVECTOR_H
#include "proj7-ContainerIfc.h"

template <class T>
class MyVector : public ContainerIfc<T> {
public:
    /*
     *MyVector
     *
     *This function is the default constructor
     *
     *Parameters:
     *    none
     *
     *Output:
     *    return: none
     *    reference parameters: none
     *    stream: none
     */
    MyVector ();

    /*
     *~MyVector
     *
     *This function is the destructor
     *
     *Parameters:
     *    none
     *
     *Output:
     *    return: none
     *    reference parameters: none
     *    stream: none
     */
    ~MyVector ();

    /*
     *MyVector
     *
     *This function is the copy constructor
     *
     *Parameters:
     *    that: const MyVector reference
     *
     *Output:
     *    return: none
     *    reference parameters: that
     *    stream: none
     */
    MyVector (const MyVector&);

    /*
     *operator =
     *
     *This function overloads the assignment operator
     *
     *Parameters:
     *    that: const MyVector reference
     *
     *Output:
     *    return: a reference to itself
     *    reference parameters: that
     *    stream: none
     */
    MyVector<T>& operator = (const MyVector&);

    /*
     *pushFront
     *
     *This function adds data element a to the front of the vector
     *
     *Parameters:
     *    a: type T
     *
     *Output:
     *    return: a reference to self
     *    reference parameters: none
     *    stream: none
     */
    MyVector<T>& pushFront(T);

    /*
     *pushBack
     *
     *This function stores data element a in the end of the vector
     *
     *Parameters:
     *    a: type T
     *
     *Output:
     *    return: a reference to self
     *    reference parameters: none
     *    stream: none
     */
    MyVector<T>& pushBack(T);

    /*
     *popFront
     *
     *This function removes a data element from the front of the data structure
     *
     *Parameters:
     *    a: reference to type T
     *
     *Output:
     *    return: a reference to self
     *    reference parameters: a
     *    stream: none
     */
    MyVector<T>& popFront(T&);

    /*
     *popBack
     *
     *This function removes a data element from the end of the data structure
     *
     *Parameters:
     *    a: reference to type T
     *
     *Output:
     *    return: a reference to self
     *    reference parameters: a
     *    stream: none
     */
    MyVector<T>& popBack(T&);

    /*
     *front
     *
     *This function returns a copy of the first data item in the MyVector
     *
     *Parameters:
     *    none
     *
     *Output:
     *    return: a copy of the object at the beginning of the array
     *    reference parameters: none
     *    stream: none
     */
    T  front();

    /*
     *back
     *
     *This function returns a copy of the last data item in MyVector
     *
     *Parameters:
     *    none
     *
     *Output:
     *    return: a copy of the object at the end of the array
     *    reference parameters: none
     *    stream: none
     */
    T  back();

    /*
     *operator []
     *
     *This function returns a reference to data element index in MyVector
     *
     *Parameters:
     *    index: integer
     *
     *Output:
     *    return: a reference to the object stored at offset of index within data
     *    reference parameters: none
     *    stream: none
     */
    T&  operator [](int);

    /*
     *getSize
     *
     *This function returns the number of elements currently in the MyVector
     *
     *Parameters:
     *    none
     *
     *Output:
     *    return: an integer value representing the number of elements in the list
     *    reference parameters: none
     *    stream: none
     */
    int getSize();

    /*
     *isEmpty
     *
     *This function returns state information about the list
     *
     *Parameters:
     *    none
     *
     *Output:
     *    return: true if the MyVector is empty false otherwise
     *    reference parameters: none
     *    stream: none
     */
    bool isEmpty();

    /*
     *erase
     *
     *This function erases a vector
     *
     *Parameters:
     *    none
     *
     *Output:
     *    return: void
     *    reference parameters: none
     *    stream: none
     */
    void erase();

private:
    T  *data;
    int size;
    int capacity;

    /*
     *grow
     *
     *This function increases the capacity of data by doubling the previous
     *value and allocating the memory for data
     *
     *Parameters:
     *    none
     *
     *Output:
     *    return: void
     *    reference parameters: none
     *    stream: none
     */
    void grow();

    /*
     *shiftRight
     *
     *This function shifts all values in the array one space to the right
     *
     *Parameters:
     *    none
     *
     *Output:
     *    return: void
     *    reference parameters: none
     *    stream: none
     */
    void shiftRight();

    /*
     *shiftLeft
     *
     *This function shifts all values in the array one space to the left
     *
     *Parameters:
     *    none
     *
     *Output:
     *    return: void
     *    reference parameters: none
     *    stream: none
     */
    void shiftLeft();
};
template <class T>
MyVector<T>::MyVector(){
    this->size = 0;
    this->capacity = 10;
    this->data = new T[this->capacity];

}

template <class T>
MyVector<T>::~MyVector(){
    delete[] this->data;
}

template <class T>
MyVector<T>::MyVector(const MyVector& that) {
    this->size = that.size;
    this->capacity = that.capacity;
    this->data = new T[this->capacity];
    for(int i = 0; i < this->size; i++){
        this->data[i] = that.data[i];
    }
}

template <class T>
MyVector<T>& MyVector<T>::operator=(const MyVector& that) {
    if(this != &that){
        delete[] this->data;
        this->size = that.size;
        this->capacity = that.capacity;
        this->data = new T[this->capacity];
        for(int i = 0; i < this->size; i++){
            this->data[i] = that.data[i];
        }

    }
    return *this;
}

template <class T>
void MyVector<T>::grow(){
    this->capacity *= 2;
    T* temp = this->data;
    this->data = new T[this->capacity];
    for(int i = 0; i < this->size; i++){
        this->data[i] = temp[i];
    }
    delete[] temp;
}

template <class T>
void MyVector<T>::shiftRight(){
    for(int i = this->size; i > 0; i--){
        this->data[i] = this->data[i-1];
    }
}

template <class T>
void MyVector<T>::shiftLeft(){
    for(int i = 0; i < this->size-1; i++){
        this->data[i] = this->data[i +1];
    }
}

template <class T>
MyVector<T>& MyVector<T>::pushFront(T a) {
    if(this->size == this->capacity){
        this->grow();
    }
    this->shiftRight();
    this->data[0] = a;
    this->size++;

    return *this;
}

template <class T>
MyVector<T>& MyVector<T>::pushBack(T a) {
    if(this->size == this->capacity){
        this->grow();
    }
    this->data[this->size] = a;
    this->size++;
}

template <class T>
MyVector<T>& MyVector<T>::popFront(T &a) {
    if(this->isEmpty()){
        throw(BADINDEX());
    }
    a = this->data[0];
    this->shiftLeft();
    this->size--;
    return *this;

}

template <class T>
MyVector<T>& MyVector<T>::popBack(T &a) {
    if(this->isEmpty()){
        throw(BADINDEX());
    }
    this->size--;
    a = this->data[this->size];
    return *this;

}

template <class T>
int MyVector<T>::getSize() {
    return this->size;
}
template <class T>
bool MyVector<T>::isEmpty() {
    bool empty = true;
    if (this->size > 0){
        empty = false;
    }
    return empty;

}

template <class T>
void MyVector<T>::erase() {
    delete[] this->data;
    this->size = 0;
    this->capacity = 10;
    this->data = new T[this->capacity];
}

template <class T>
T MyVector<T>::front() {
    if(this->isEmpty()){
        throw(BADINDEX());
    }
    return this->data[0];
}

template <class T>
T MyVector<T>::back() {
    if(this->isEmpty()){
        throw(BADINDEX());
    }
    return this->data[this->size-1];
}

template <class T>
T& MyVector<T>::operator[] (int index){
    if(index >= this->size || index < 0){
        throw(BADINDEX());
    }
    return this->data[index];
}

#endif //PROJECT7_PROJ7_MYVECTOR_H
