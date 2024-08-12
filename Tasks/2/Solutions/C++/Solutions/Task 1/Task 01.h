#pragma once

#include <iostream>

using namespace std;

// --------------------------------------- Task 1 ---------------------------------------
template <typename T>
T smaller(T a, T b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

//template <class T>
//class A
//{
//private:
//    T a;
//public:
//    A(T a);
//    
//    void setA(T a);
//
//    T getA();
//};
//
