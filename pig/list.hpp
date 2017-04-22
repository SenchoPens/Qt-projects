#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include "elem.hpp"
#include "iter.hpp"

template <class T>
class List {
private:
    Elem<T> *head;
    Iter<T> *iter;

public:
    List();
    void append(T _element);
    T at(int _id);
};

template <class T>
List<T>::List() {
    head = nullptr;
    iter = nullptr;
}

template <class T>
void List<T>::append(T _element) {
    std::cout << "adding element";
    if (head == nullptr) {
        std::cout << "reached start";
        head = new Elem<T>(_element, nullptr);;
        iter = new Iter<T>(head);
        return;
    }
    Elem<T> *elem = new Elem<T>(_element, iter->getPrev());
    iter->getElem()->setNext(elem);
    iter->iterNext();
}

template <class T>
T List<T>::at(int _id) {
    Iter<T> *index_iter = new Iter<T>(head);
    for (int i = 0; i < _id; i++) {
        index_iter->iterNext();
    }
    return index_iter->value();
}

#endif // LIST_HPP
