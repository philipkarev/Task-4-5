#ifndef TOKENAIZER_LIST_H
#define TOKENAIZER_LIST_H

#include <iostream>
#include <fstream>

#include <cstring>
#include <string>

//#include <list>
//#include <iterator>
//#include <vector>

using namespace std;

class List {
public:
    List();
    ~List();

    void push_back(int data);
    int get_size() {return Size;}
    int& operator[](const int index);
    void pop_front();
    void clear();
    void push_front(int data);
    void pop_back();

    friend class tokenaizer;
private:
    class Node {
    public:
        Node* pNext;
        int data;

        Node(int data = 0, Node* pNext = nullptr) {

            this -> pNext = pNext;
            this -> data = data;
        }
    };
    int Size;
    Node *head;
};

#endif // TOKENAIZER_LIST_H