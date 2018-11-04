#include "fibonacci.h"
#include <string.h>
long long fibo_memo[100];
bool fibo_init = false;
long long fibo_recursion_memoized(int n)
{
	//! long long으로 표현할 수 있는 한계선.
	if (92 < n) return -1;

	if (!fibo_init)
	{
		memset(fibo_memo, 0, sizeof(fibo_memo));
		fibo_init = true;
	}

	if (n == 0)return 0;
	if (n == 1)return 1;
	if (fibo_memo[n] == 0) fibo_memo[n] = fibo_recursion_memoized(n - 1) + fibo_recursion_memoized(n - 2);
	
	return fibo_memo[n];
}

void fibo_recursion_memo_clear()
{
	fibo_init = false;
}
