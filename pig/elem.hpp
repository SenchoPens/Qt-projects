#ifndef ELEM_HPP
#define ELEM_HPP

template <class T>
class Elem {
private:
    T value;
    Elem<T> *next;

public:
    Elem(T _value, Elem<T> *_next);
    Elem<T> *getNext();
    void setNext(Elem *_next);
    T *getValue();
};

template <class T>
Elem<T>::Elem(T _value, Elem<T> *_next) {
    value = _value;
    next = _next;
}

template <class T>
Elem<T> *Elem<T>::getNext() {
    return next;
}

template <class T>
void Elem<T>::setNext(Elem *_next) {
    next = _next;
}

template <class T>
T *Elem<T>::getValue() {
    return value;
}

#endif // ELEM_HPP
