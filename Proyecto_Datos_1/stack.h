
#ifndef STACK_H
#define STACK_H

#include <exception>
#include <iostream>
#include <sstream>
#include "objetoBase.h"
using namespace std;

#define MAX_ELEMENTS 20

template <class T>
class stack : public objetoBase{
public:
    stack(int = MAX_ELEMENTS);
    stack(const stack<T>&);
    virtual ~stack();
    stack<T>& operator=(const stack<T>&);

    virtual int is_empty() const;
    virtual int max_size() const;
    virtual int count() const;
    virtual T top() const;

    virtual void push(T);
    virtual T pop();

    virtual string toString() const;

private:
    int _n;
    T* _v;
    int _k;
};

template <class T>
stack<T>::stack(int n) : _n(n), _v(new T[n]), _k(0) {
}

template <class T>
stack<T>::stack(const stack<T> &s) : _n(s._n), _v(new T[s._n]), _k(0) {
    for (int i = 0; i < s._k; i++) {
        _v[_k++] = s._v[i];
    }
}

template <class T>
stack<T>::~stack() {
    if (_v != NULL) {
        delete _v;
    }
}

template <class T>
stack<T>& stack<T>::operator=(const stack<T> &s) {
    if (this != &s) {
        if (_v != NULL) {
            delete _v;
        }

        _n = s._n;
        _v = new T[s._n];
        _k = 0;

        for (int i = 0; i < s._k; i++) {
            _v[_k++] = s._v[i];
        }
    }
    return *this;
}

template <class T>
int stack<T>::is_empty() const {
    return count() == 0;
}

template <class T>
int stack<T>::max_size() const {
    return _n;
}

template <class T>
int stack<T>::count() const {
    return _k;
}

template <class T>
T stack<T>::top() const {
    if (!is_empty()) {
        return _v[_k - 1];
    } else {
        throw exception();
    }
}

template <class T>
void stack<T>::push(T x) {
    if (_k < _n) {
        _v[_k++] = x;
    } else {
        throw exception();
    }
}

template <class T>
T stack<T>::pop() {
    if (!is_empty()) {
        return _v[--_k];
    } else {
        throw exception();
    }
}

template <class T>
string stack<T>::toString() const {
    stringstream r;
    r << "[";
    for (int i = 0; i < _k; i++) {
        r << _v[i];
        if (i < (_k - 1)) {
            r << ", ";
        }
    }
    r << "]";
    return r.str();
}

#endif /* STACK_H */
