#ifndef NODE_H
#define NODE_H


template<typename T>
class Node {
public:
    T value;
    Node *left;
    Node *right;
    Node(T val) : value(val), left(nullptr), right(nullptr){}
};



#endif //NODE_H