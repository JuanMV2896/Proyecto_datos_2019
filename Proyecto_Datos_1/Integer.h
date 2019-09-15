/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Integer.h
 * Author: Juan Carlos
 *
 * Created on September 14, 2019, 6:53 PM
 */

#ifndef INTEGER_H
#define INTEGER_H

#include"lista.h"
#include"stack.h"

#define ZERO 0
#define ONE 1

using namespace std;
class Integer {
public:
    Integer();
    Integer(const Integer& orig);
    virtual ~Integer();
    virtual Integer* sumar(Integer*);
    virtual Integer* restar(Integer*);
    virtual Integer* division(Integer*);
    virtual Integer* multiplicacion(Integer*);
    virtual Integer& operator==(const Integer&);
    virtual Integer& operator*(const Integer&);
    virtual Integer& operator/(const Integer&);
    virtual Integer& operator+(const Integer&);
    virtual Integer& operator-(const Integer&);
    virtual Integer& operator=(const Integer&);
    virtual Integer& operator+=(const Integer&);
    virtual Integer& operator-=(const Integer&);
    virtual Integer& operator*=(const Integer&);
    virtual Integer& operator/=(const Integer&);
    virtual Integer& operator!=(const Integer&);
    virtual Integer& operator<(const Integer&);
    virtual Integer& operator<=(const Integer&);
    virtual Integer& operator>(const Integer&);
    virtual Integer& operator>=(const Integer&);
    virtual Integer& operator<<(const Integer&);
    virtual long* parse(string);
    virtual int* parse(string);
    
private:
    lista* _lista;
    stack* _stack;
};

#endif /* INTEGER_H */

