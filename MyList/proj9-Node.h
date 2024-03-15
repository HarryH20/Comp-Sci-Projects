

#ifndef PROJECT9_PROJ9_NODE_H
#define PROJECT9_PROJ9_NODE_H
template <class T>
class Node {
public:
    T data;
    Node<T> *next;

    Node(T e) {
        data = e;
        next = NULL;
    }
};
#endif //PROJECT9_PROJ9_NODE_H
