/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Juan Carlos
 *
 * Created on September 14, 2019, 5:35 PM
 */

#include <cstdlib>
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
    cout << "Hola mundo ..." << endl;
    cout<<"No me corre.....nel es un problema de MingW"<<endl;
    cout<<"Me estan dando ganas de bailar un piche cumbion bien loco.."<<endl;
    cout << endl;

    return 0;
}

