#include "C:\Users\wiki8\Desktop\Task 04\Task 04.h"

using namespace std;

template<typename T1, typename T2, typename T3>
inline Store<T1, T2, T3>::Store()
{
	counterInt = 0;
	counterDouble = 0;
	counterChar = 0;

	for (int i = 0; i < 10; i++)
	{
		arrayInt[i] = 0;
		arrayDouble[i] = 0;
		arrayChar[i] = 0;
	}
}



template<typename T1, typename T2, typename T3>
inline void Store<T1, T2, T3>::add(T1 a)
{
	if (counterInt < 10)
	{
		arrayInt[counterInt] = a;
		counterInt++;
	}
}

template<typename T1, typename T2, typename T3>
inline void Store<T1, T2, T3>::add(T2 a)
{
	if (counterDouble < 10)
	{
		arrayDouble[counterDouble] = a;
		counterDouble++;
	}
}

template<typename T1, typename T2, typename T3>
inline void Store<T1, T2, T3>::add(T3 a)
{
	if (counterChar < 10)
	{
		arrayChar[counterChar] = a;
		counterChar++;
	}
}

template<typename T1, typename T2, typename T3>
inline void Store<T1, T2, T3>::display()
{
	for (int i = 0; i < counterInt; i++)
	{
		cout << arrayInt[i] << endl;
	}

	cout << "Double";
	for (int i = 0; i < counterDouble; i++)
	{
		cout << arrayDouble[i] << endl;
	}
	

	cout << "Char ";
	for (int i = 0; i < counterChar; i++)
	{
		cout << arrayChar[i] << endl ;
	}

}

template<typename T1, typename T2, typename T3>
inline void Store<T1, T2, T3>::input()
{
	T1 a;

	for (int i = 0; i < 30; i++)
	{
		cin >> a;

		if (typeid (a) == typeid(int))
		{
			add(a);
		}
		else if (typeid(a) == typeid(double))
		{
			add(a);
		}
		else if (typeid(a) == typeid(char))
		{
			add(a);
		}
	}


}
