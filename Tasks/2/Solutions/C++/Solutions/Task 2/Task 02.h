#pragma once

#include <iostream>

using namespace std;

// --------------------------------------- Task 2 ---------------------------------------
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

template <typename T>
T smaller(T a, T b , T c)
{
    if (a < b && a < c)
    {
		return a;
	}
    if (b < a && b < c)
    {
		return b;
	}
    else
    {
		return c;
	}
}