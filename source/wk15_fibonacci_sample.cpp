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
#include <array>

//------------------------------------------------------------------------------
// using symbols
//------------------------------------------------------------------------------
using std::cin;
using std::cout;
using std::string;
using std::array;

//------------------------------------------------------------------------------
// constants
//------------------------------------------------------------------------------
constexpr int FIBSEQ_LIMIT = 40;

//------------------------------------------------------------------------------
// globals
//------------------------------------------------------------------------------
// storage for pre-calculated Fibonacci numbers
namespace g {
	array<size_t, FIBSEQ_LIMIT + 1> aFib { 0 };
}

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------
size_t fib(size_t n);		// recursive function

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

	size_t n;
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
size_t fib(size_t n) {

	if (n <= 1)
		return n;

	// is this efficient code?
	//return fib(n - 1) + fib(n - 2);

	return (g::aFib[n] = fib(n - 1) + fib(n - 2));
}
