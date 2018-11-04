#include "padovan_number.h"
#include <string.h>

long long pado_memo[100];
bool pado_init = false;
long long pado_recursion_memoized(int n)
{
	// long long 으로 표현할 수 있는 한계.
	if (161 < n) return -1;

	if (n <= 2) return 1;
	if (!pado_init)
	{
		memset(pado_memo, 0, sizeof(pado_memo));
		pado_init = true;
	}
	if (pado_memo[n] == 0) pado_memo[n] = pado_recursion_memoized(n - 2) + pado_recursion_memoized(n - 3);
	return pado_memo[n];
}

void clear()
{
	pado_init = false;
}