#include "fibonacci.h"
long long fibo_recursion(int n)
{	//! long long으로 표현할 수 있는 한계선.
	if (92 < n) return -1;

	if (n == 0)return 0;
	if (n == 1)return 1;
	return fibo_recursion(n - 1) + fibo_recursion(n - 2);
}