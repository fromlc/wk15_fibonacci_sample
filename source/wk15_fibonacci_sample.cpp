//------------------------------------------------------------------------------
// Example 4: Fibonacci Series using Recursion
//
// Fibonacci series: 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89
// 
// Each number is the sum of the previous two
//		n = (n-1) + (n-2)
//
// Author: https://www.geeksforgeeks.org/c-program-for-n-th-fibonacci-number/
//------------------------------------------------------------------------------
#include <iostream>

//------------------------------------------------------------------------------
// using symbols
//------------------------------------------------------------------------------
using std::cin;
using std::cout;
using std::string;

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------
int fib(int n);		// recursive function
int getFib(int n);	// set up Fibonacci recursion

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {
	//--------------------------------------------------------------------------
	// Example 4: recursive Fibonacci sequence
	// 
	//		1, 1, 2, 3, 5, 8, 13, 21, 34, ...
	//		starts with 1, 1, then n = n-1 * n-2
	// 
	// argument n is which number in the series to return
	//--------------------------------------------------------------------------

	cout << "\nn=6, fib(n)=" << getFib(6) << '\n';

	return 0;
}


// This is C code! It drops right in to a C++ program :)
#include<stdio.h>	// printf()
int fib(int n) {

	if (n <= 1)
		return n;
	return fib(n - 1) + fib(n - 2);
}

// this used to be main(), now it sets up the recursive call
int getFib(int n) {

	//int n = 9;
	//printf("%d", fib(n));
	int fibResult = fib(n);

	// wait for a keystroke
	printf("Any key to continue..");
	char ch = getchar();

	return fibResult;
}
