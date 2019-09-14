/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: sebas y juan
 *
 * Created on 9 de septiembre de 2019, 03:47 PM
 */

#include <cstdlib>
#include <iostream>
#include "stack.h"

using namespace std;

/* 
 * 
 */
int main(int argc, char** argv) {
#if defined(_WIN32) || defined(_WIN64)
    system("cls");
    system("chcp 65001");
    cout << endl;
#endif

    stack<int>* s0 = new stack<int>();

    s0->push(15);
    s0->push(34);
    s0->push(7);
    s0->push(5);
    s0->push(3);
    s0->push(8);
    s0->push(23);
    s0->push(12);
    cout << "s0: " << s0->toString() << endl;
    cout << endl;
    
    return 0;
}

