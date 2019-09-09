/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Stack.h
 * Author: sebas
 *
 * Created on 9 de septiembre de 2019, 03:50 PM
 */

#ifndef STACK_H
#define STACK_H

// <editor-fold defaultstate="collapsed" desc="CLASS LINK">
//==============================================================================
//                                CLASS LINK
//==============================================================================

template <class T>
class Link {
public:
    Link();
    //    Link(T& info, Link<T>* next);
    Link(T info, Link<T>* next);
    Link(T& info);
    T* getInfo();
    T getValor();
    Link<T>* getNext();
    void setNext(Link<T>* next);
    T& operator<(const T&);
    void operator=(const T&);
    T& operator>(const T&);
    bool operator==(const T&);
    T& operator>=(const T&);
    T& operator<=(const T&);
    T& operator+(const T&);
private:
    T _valor;
    T* info;
    Link<T>* next;
};

template <class T>
T Link<T>::getValor() {
    return _valor;
}

template <class T>
Link<T>::Link() {
    this->info = NULL;
    this->next = NULL;
}

template <class T>
T& Link<T>::operator+(const T& x) {
    return *info + x;
}

template <class T>
T& Link<T>::operator>=(const T& x) {
    if (info >= x)
        return info;
    return x;
}

template <class T>
T& Link<T>::operator<=(const T& x) {
    if (info <= x)
        return info;
    return x;
}

template <class T>
bool Link<T>::operator==(const T& x) {
    return info == x;
}

template <class T>
T& Link<T>::operator>(const T& x) {
    if (info > x)
        return info;
    return x;
}

template <class T>
T& Link<T>::operator<(const T& x) {
    if (info < x)
        return info;
    return x;
}

template <class T>
void Link<T>::operator=(const T& x) {
    *this->info = x;
}

//template <class T>
//Link<T>::Link(T& info, Link<T>* next) {
//    this->info = &info;
//    this->next = next;
//}

template <class T>
Link<T>::Link(T info, Link<T>* next) {
    this->_valor = info;
    this->next = next;
}

template <class T>
Link<T>::Link(T& _info) {
    this->info = &_info;
}

template <class T>
T* Link<T>::getInfo() {
    return info;
}

template <class T>
Link<T>* Link<T>::getNext() {
    return next;
}

template <class T>
void Link<T>::setNext(Link<T>* _next) {
    this->next = _next;
}
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="CLASS STACK">
template <class T>
class Stack {
public:
    Stack();
    Stack(T&);
    ~Stack();
    bool isEmpty()const;
    int count()const;
    T* top()const;
    T verTop()const;
    void push(T x);
    T pop();
    T suma();
private:
    int _count;
    Link<T>* first;
    Link<T>* last;
    void add_first(T);
    void add_last(T&);
    T remove_first();
};

template <class T>
Stack<T>::Stack() {
    _count = 0;
    first = NULL;
    last = NULL;
}

template <class T>
Stack<T>::Stack(T& x) {
    _count = 1;
    this->first = new Link<T>(x);
    last = first;
}

template <class T>
Stack<T>::~Stack() {

}

template <class T>
bool Stack<T>::isEmpty() const {
    return first == NULL;
}

template <class T>
int Stack<T>::count() const {
    return _count;
}

template <class T>
T* Stack<T>::top() const {
    return isEmpty() ? NULL : first->getInfo();
}

template <class T>
T Stack<T>::verTop() const {
    return isEmpty() ? NULL : first->getValor();
}

template <class T>
void Stack<T>::push(T x) {
    add_first(x);
}

template <class T>
T Stack<T>::pop() {
    return remove_first();
}

template <class T>
void Stack<T>::add_first(T x) {
    first = new Link<T>(x, first);
    if (!last) {
        last = first;
    }
    _count++;
}

template <class T>
T Stack<T>::remove_first() {
    T r;
    if (!isEmpty()) {
        r = first->getValor();
        first = first->getNext();
        if (!first) {
            last = NULL;
        }
        _count--;
    }
    return r;
}

template <class T>
T Stack<T>::suma() {
    if (_count != 0)
        return pop() + suma();
    return 0;
}
// </editor-fold>

#endif /* STACK_H */

