#include "padovan_number.h"
#include <stdio.h>
long long bino(int n, int r);

long long pado_bino(int n)
{
	// long long 으로 표현할 수 있는 한계.
	if (161 < n) return -1;

	// bino 오버플로우 한계
	if (154 < n) return -1;

	if (n <= 2) return 1;
	long long ret = 0;
	for (int i = 0; i <= n + 2; i += 2)
	{
		if (i / 2 < n + 2 - i) continue;
		ret += bino(i / 2, (n + 2) - i);
	}
	return ret;
}

long long bino(int n, int r)
{
	if (n < r || n < 0 || r < 0) return 0;
	if (r == 0 || n == r) return 1;

	return bino(n - 1, r - 1) * n / r;
}