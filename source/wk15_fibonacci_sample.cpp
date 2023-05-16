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
#include <array>
#include <iostream>
#include <stdexcept>

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
constexpr int FIBSEQ_LIMIT = 10000;

//------------------------------------------------------------------------------
// globals
//------------------------------------------------------------------------------
// storage for pre-calculated Fibonacci numbers
namespace g {
	array<unsigned long long, FIBSEQ_LIMIT + 1> aFib { 0 };
}

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------
unsigned long long fib(size_t n);		// recursive function

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
		cout << "\nEnter a Fibonacci sequence number <= "
			<< FIBSEQ_LIMIT << " (0 quits) : ";
		cin >> n;
		if (!n) {
			break;
		}

		if (n > FIBSEQ_LIMIT) {
			cout << "Too big\n";
			continue;
		}

		try {
			cout << "n=" << n << " fib(n)=" << fib(n) << '\n';
		}
		catch (std::overflow_error& e) {
			cout << "\noverflow on n=" << n << '\n';
			cout << e.what() << '\n';
		}
		catch (std::underflow_error& e) {
			cout << "\nunderflow on n=" << n << '\n';
			cout << e.what() << '\n';
		}
		catch (std::runtime_error& e) {
			cout << "\nruntime error on n=" << n << '\n';
			cout << e.what() << '\n';
		}
		catch (std::range_error& e) {
			cout << "\nrange error on n=" << n << '\n';
			cout << e.what() << '\n';
		}
		catch (std::exception& e) {
			cout << "\nexception on n=" << n << '\n';
			cout << e.what() << '\n';
		}
		catch (...) {
			cout << "\ncrashed on n=" << n << '\n';
		}
	}

	cout << "\nGoodbye!\n\n";

	return 0;
}

//------------------------------------------------------------------------------
// recursive Fibonacci number calculator
// given int n, return nth Fibonacci number
//------------------------------------------------------------------------------
unsigned long long fib(size_t n) {

	if (n <= 1)
		return n;

	// is this efficient code?
	//return fib(n - 1) + fib(n - 2);

	if (g::aFib[n] != 0) {
		return g::aFib[n];
	}

	unsigned long long nthFib = fib(n - 1) + fib(n - 2);
	g::aFib[n] = nthFib;

	return nthFib;
}
