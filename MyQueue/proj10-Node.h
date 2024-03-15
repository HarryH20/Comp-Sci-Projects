

#ifndef PROJECT10_PROJ10_NODE_H
#define PROJECT10_PROJ10_NODE_H
#include <iostream>
template <class T>
class Node {
public:
    T data;
    Node <T>*next;

    Node( T d ) {
        data = d;
        next = NULL;
    }

    ~Node( ) {
        delete next;
    }
};
#endif //PROJECT10_PROJ10_NODE_H
