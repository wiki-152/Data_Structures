// Lab 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "C:\Users\wiki8\Desktop\Lab 3\Header.h"

int main()
{
    std::cout << "Hello World!\n";
    cout << "Enter Size : ";
    int size = 0;
    cin>> size;
    int * array = new int[size];

    for (int i = 0; i < size; i++)
    {
        array[i] = 0;
    }

    cout << "Give Input : " << endl;

    for (int i = 0; i < size; i++)
    {
        cin>>array[i];
    }

    cout << "Minimum : " << min(array, size) << endl;
    cout << "Maximum : " << max(array, size) << endl;



}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
