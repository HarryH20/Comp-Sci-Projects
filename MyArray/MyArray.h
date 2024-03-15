

#ifndef LAB6_MYARRAY_H
#define LAB6_MYARRAY_H
#include "ContainerIfc.h"
#include <sstream>



template <class T>
class MyArray : public ContainerIfc<T> {
private:
    T *data;
    int capacity, size;

public:
    ~MyArray();
    MyArray();
    MyArray(const MyArray<T>&);
    MyArray &operator = (const MyArray<T> &);
    MyArray<T>& pushBack(T);
    MyArray<T>& popBack(T&);
    int getSize();
    bool isEmpty();
    T& operator[](int);
    string toString();

};

// notice the T used in the name of the class not the name of the function
template <class T>
MyArray<T>::MyArray(){
    this->capacity = 5;
    this->size = 0;
    this->data = new T[this->capacity];
}

template <class T>
MyArray<T>::~MyArray(){
    delete[] this->data;
}

template <class T>
MyArray<T>::MyArray(const MyArray<T>& that){
    this->size = that.size;
    this->capacity = that.capacity;
    this->data = new T[that.capacity];
    for(int i = 0; i < this->size; i++){
        this->data[i] = that.data[i];
    }
}

template <class T>
MyArray<T>& MyArray<T>::operator = (const MyArray& that){
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
MyArray<T>& MyArray<T>:: pushBack(T val){
    if(this->size == this->capacity){
        this->capacity += 5;
        T* newData = new T[this->capacity];
        for(int i = 0; i < this->size; i++){
            newData[i] = this->data[i];
        }
        delete[] this->data;
        this->data = newData;
    }
    this->data[this->size] = val;
    this->size++;
    return *this;
}

template <class T>
MyArray<T>& MyArray<T>:: popBack(T& val){
    try {
        if (this->size == 0) {
            throw BADINDEX();
        }

        val = this->data[this->size - 1];
        this->size--;
        if (this->capacity > 5 && static_cast<double>(this->size) / static_cast<double>(this->capacity) < 0.25) {
            this->capacity -= 5;
            T *newData = new T[this->capacity];
            for (int i = 0; i < this->size; i++) {
                newData[i] = this->data[i];
            }
            delete[] this->data;
            this->data = newData;
        }
    }

    return *this;
}

template <class T>
int MyArray<T>::getSize(){
    return this->size;
}

template <class T>
bool MyArray<T>::isEmpty(){
    bool out = false;
    if(this->size == 0){
        out = true;
    }
    return out;
}

template <class T>
T& MyArray<T>::operator[](int i){
        if(i > this->size || i < 0){
            throw BADINDEX();
        }
        return this->data[i];




}

template <class T>
string MyArray<T>::toString(){
    ostringstream out;
    out << this->size << endl;
    out << this->capacity << endl;
    for(int i = 0; i < this->size; i++){
        out << this->data[i]<< '\t';
    }
    out << endl;
    return out.str();
}


#endif //LAB6_MYARRAY_H
