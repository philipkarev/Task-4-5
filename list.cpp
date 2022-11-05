#include "list.h"

List::List() {

    Size = 0;
    head = nullptr;
}

List::~List() {

    clear();
}

void List::push_back(int data) {

    if (head == nullptr) {
        head = new Node(data);
    } else {
        Node *cur = this -> head;
        while (cur -> pNext != nullptr)
            cur = cur -> pNext;
        cur -> pNext = new Node(data);
    }

    ++Size;
}

int& List::operator[](const int index) {

    int count = 0;

    Node* cur = this->head;

    int i = 0;
    while (cur != nullptr) {

        if (count == index) {
            return cur->data;
            ++i;
        }

        cur = cur->pNext;
        ++count;
    }

    return cur->data; // чтобы компилятор не ругался
}

void List::pop_front() {

    Node* tmp = head;

    head = head->pNext;

    delete tmp;

    Size--;
}

void List::clear() {

    while (Size) {
        pop_front();
    }
}

void List::push_front(int data) {

    head = new Node(data, head);
    ++Size;
}