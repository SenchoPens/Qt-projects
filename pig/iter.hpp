#ifndef ITER_HPP
#define ITER_HPP

#include <elem.hpp>

template <class T>
class Iter {
private:
    Elem<T> *next;
    Elem<T> *elem;
    Elem<T> *prev;

    bool isEnd();
    bool isStart();

public:
    Iter(Elem<T> *_elem);
    void iterNext();
    void del();
    Elem<T> *getElem();
    Elem<T> *getNext();
    Elem<T> *getPrev();
    T *value();
};

template <class T>
Elem<T> *Iter<T>::getElem() {
    return elem;
}
template <class T>
Elem<T> *Iter<T>::getNext() {
    return next;
}
template <class T>
Elem<T> *Iter<T>::getPrev() {
    return prev;
}

template <class T>
Iter<T>::Iter(Elem<T> *_elem) {
    elem = _elem;
    next = elem->getNext();
    prev = nullptr;
}

template <class T>
bool Iter<T>::isEnd() {
    if (next == nullptr) {
        return true;
    }
    return false;
}

template <class T>
bool Iter<T>::isStart() {
    if (next == nullptr) {
        return true;
    }
    return false;
}

template <class T>
void Iter<T>::iterNext() {
    if (isStart()) {
        return;
    }
    prev = elem;
    elem = elem->getNext();
    next = elem->getNext();
}

template <class T>
void Iter<T>::del() {
    if (not isStart()) {
        prev->setNext(next);
    }
    delete elem;
    elem = next;
}

template <class T>
T *Iter<T>::value() {
    return elem->getValue();
}

#endif // ITER_HPP
