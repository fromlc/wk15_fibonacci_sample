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
// constants
//------------------------------------------------------------------------------
constexpr int FIBSEQ_LIMIT = 45;

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------
int fib(int n);		// recursive function

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {
	//--------------------------------------------------------------------------
	// Example 4: recursive Fibonacci sequence
	// 
	//		1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
	//		starts with 1, 1, then n = n-1 * n-2
	// 
	// argument n is which number in the series to return
	//--------------------------------------------------------------------------
	cout << "\nFibonacci sequence\n";
	cout << "1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...\n\n";

	int n;
	while (true) {

		// limit sequence number to prevent stack overflow
		cout << "Enter a Fibonacci sequence number <= "
			<< FIBSEQ_LIMIT << " (0 quits) : ";
		cin >> n;
		if (!n) {
			break;
		}

		if (n > FIBSEQ_LIMIT) {
			cout << "Too big\n";
			continue;
		}

		cout << "\nn=" << n << " fib(n)=" << fib(n) << '\n';
	}

	cout << "\nGoodbye!\n\n";

	return 0;
}

//------------------------------------------------------------------------------
// recursive Fibonacci number calculator
// given int n, return nth Fibonacci number
//------------------------------------------------------------------------------
int fib(int n) {

	if (n <= 1)
		return n;

	// is this efficient code?
	return fib(n - 1) + fib(n - 2);
}

