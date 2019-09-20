/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Integer.cpp
 * Author: Juan Carlos
 * 
 * Created on September 14, 2019, 6:53 PM
 */

#include "Integer.h"

Integer::Integer() {
}

Integer::Integer(lista* l, stack* s) {
    _lista = l;
    _stack = s;
}

void Integer::setlista(lista* l){
    _lista = l;
}
lista* Integer::getlista(){
    return _lista;
}
void Integer::setsatck(stack* s){
    _stack = s;
}
stack* Integer::getsatck(){
    return _stack;
}

Integer::Integer(const Integer& orig) {
}

Integer::~Integer() {
}

