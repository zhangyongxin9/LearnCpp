// Test01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
 
int numberOf1(int n)
{
	int count=0;
	unsigned int flag = 1;
	while ( flag)
	{
		if (n & flag)
			++count;
		flag = flag << 1;
	}
	return count;
}

int main()
{
	int number;
	cout << "input number:" << endl;
	cin >> number;

	cout << "number of 1 is:" << numberOf1(number) << endl;
	getchar();
	return 0;
}

