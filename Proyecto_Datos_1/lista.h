#ifndef LISTA_H
#define LISTA_H

#include <iomanip>
#include "coleccion.h"


template <class T> class lista;
template <class T> class nodo;

template <class T>
class lista : public coleccion<T> {
public:
    lista();
    lista(const lista<T>&);
    virtual ~lista();
    lista<T>& operator=(const lista<T>&);

    virtual int numElementos() const;

    virtual void agregar(T*);
    virtual void insertar(T*, int = -1);

    virtual T* extraer(int);
    virtual T* extraerUltimo();

    virtual T* recuperar(int) const;

    virtual iterador<T>* obtenerIterador() const;

private:
    int _n;
    nodo<T>* _primero;
    nodo<T>* _ultimo;
};

template <class T>
class nodo : public objetoBase {
public:
    nodo(T*, nodo<T>* = NULL);
    virtual ~nodo();

    virtual T* obtenerInfo() const;
    virtual nodo<T>* obtenerSiguiente() const;
    virtual void establecerSiguiente(nodo<T>* = NULL);

    virtual std::string toString() const;

private:
    T* _info;
    nodo<T>* _siguiente;
};

template <class T>
class iteradorLista : public iterador<T> {
public:
    iteradorLista(nodo<T>*);

    virtual void reiniciar();
    virtual bool masElementos() const;
    virtual T* proximoElemento();

private:
    nodo<T>* _primero;
    nodo<T>* _actual;
};

template <class T>
lista<T>::lista()
: coleccion<T>(), _n(0), _primero(NULL), _ultimo(NULL) {
}

template <class T>
lista<T>::lista(const lista<T> &otra)
: coleccion<T>(), _n(0), _primero(NULL), _ultimo(NULL) {
    nodo<T>* cursor = otra._primero;
    while (cursor != NULL) {
        nodo<T>* nuevo = new nodo<T>(cursor->obtenerInfo());
        if (_primero == NULL) {
            _primero = _ultimo = nuevo;
        } else {
            _ultimo->establecerSiguiente(nuevo);
            _ultimo = nuevo;
        }
        _n++;
        cursor = cursor->obtenerSiguiente();
    }
}

template <class T>
lista<T>::~lista() {
    this->extraerTodos();
}

template <class T>
lista<T>& lista<T>::operator=(const lista<T> &otra) {
    if (this != &otra) {
        this->extraerTodos();

        _n = 0;
        _primero = _ultimo = NULL;

        nodo<T>* cursor = otra._primero;
        while (cursor != NULL) {
            nodo<T>* nuevo = new nodo<T>(cursor->obtenerInfo());
            if (_primero == NULL) {
                _primero = _ultimo = nuevo;
            } else {
                _ultimo->establecerSiguiente(nuevo);
                _ultimo = nuevo;
            }
            _n++;
            cursor = cursor->obtenerSiguiente();
        }
    }
    return *this;
}

template <class T>
int lista<T>::numElementos() const {
    return _n;
}

template <class T>
void lista<T>::agregar(T* info) {
    nodo<T>* nuevo = new nodo<T>(info);
    if (_primero == NULL) {
        _primero = _ultimo = nuevo;
    } else {
        _ultimo->establecerSiguiente(nuevo);
        _ultimo = nuevo;
    }
    _n++;
}

template <class T>
void lista<T>::insertar(T* info, int posicion) {
    if ((posicion < 0) || (posicion >= numElementos())) {
        agregar(info);
    } else if (posicion == 0) {
        _primero = new nodo<T>(info, _primero);
        if (_primero->obtenerSiguiente() == NULL) {
            _ultimo = _primero;
        }
        _n++;
    } else {
        nodo<T>* cursor = _primero;
        int i = 1;
        while (i < posicion) {
            cursor = cursor->obtenerSiguiente();
            i++;
        }
        cursor->establecerSiguiente(new nodo<T>(info, cursor->obtenerSiguiente()));
        if (cursor->obtenerSiguiente() == NULL) {
            _ultimo = cursor;
        }
        _n++;
    }
}

template <class T>
T* lista<T>::extraer(int posicion) {
    T* r = NULL;
    if (numElementos() > 0) {
        if (posicion == 0) {
            r = _primero->obtenerInfo();
            nodo<T>* tmp = _primero;
            _primero = _primero->obtenerSiguiente();
            delete tmp;
        } else {
            nodo<T>* cursor = _primero;
            int i = 0;
            while (i < (posicion - 1)) {
                cursor = cursor->obtenerSiguiente();
                i++;
            }
            r = cursor->obtenerSiguiente()->obtenerInfo();
            nodo<T>* tmp = cursor->obtenerSiguiente();
            cursor->establecerSiguiente(cursor->obtenerSiguiente()->obtenerSiguiente());
            delete tmp;
            if (cursor->obtenerSiguiente() == NULL) {
                _ultimo = cursor;
            }
        }
        _n--;
    }
    return r;
}

template <class T>
T* lista<T>::extraerUltimo() {
    T* r = NULL;
    if (_primero != NULL) {
        if (_primero == _ultimo) {
            r = _ultimo->obtenerInfo();
            delete(_ultimo);
            _primero = _ultimo = NULL;
        } else {
            nodo<T>* cursor = _primero;
            while (cursor->obtenerSiguiente() != _ultimo) {
                cursor = cursor->obtenerSiguiente();
            }
            r = cursor->obtenerSiguiente()->obtenerInfo();
            delete(_ultimo);
            cursor->establecerSiguiente();
            _ultimo = cursor;
        }
        _n--;
    }

    return r;
}

template <class T>
T* lista<T>::recuperar(int i) const {
    T* r = NULL;
    if (i < _n) {
        nodo<T>* cursor = _primero;
        int p = 0;
        while (p < i) {
            cursor = cursor->obtenerSiguiente();
            p++;
        }
        r = cursor->obtenerInfo();
    }
    return r;
}

template <class T>
iterador<T>* lista<T>::obtenerIterador() const {
    return new iteradorLista<T>(_primero);
}

template <class T>
nodo<T>::nodo(T* info, nodo<T>* siguiente) :
_info(info), _siguiente(siguiente) {
}

template <class T>
nodo<T>::~nodo() {
}

template <class T>
T* nodo<T>::obtenerInfo() const {
    return _info;
}

template <class T>
nodo<T>* nodo<T>::obtenerSiguiente() const {
    return _siguiente;
}

template <class T>
void nodo<T>::establecerSiguiente(nodo<T>* siguiente) {
    _siguiente = siguiente;
}

template <class T>
string nodo<T>::toString() const {
    std::stringstream r;
    r << "{";
    r << *_info << ", " << std::hex << _siguiente;
    r << "}";
    return r.str();
}

template <class T>
iteradorLista<T>::iteradorLista(nodo<T>* primero) : _primero(primero), _actual(primero) {
}

template <class T>
void iteradorLista<T>::reiniciar() {
    _actual = _primero;
}

template <class T>
bool iteradorLista<T>::masElementos() const {
    return _actual != NULL;
}

template <class T>
T* iteradorLista<T>::proximoElemento() {
    T* r = NULL;
    if (masElementos()) {
        r = _actual->obtenerInfo();
        _actual = _actual->obtenerSiguiente();
    }
    return r;
}



#endif /* LISTA_H */