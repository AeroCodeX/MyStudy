#include "padovan_number.h"

long long pado_iterative(int n)
{
	if (n <= 2) return 1;
	long long pado[100] = { 1, 1, 1 };
	for (int i = 3; i <= n; i++)
	{
		pado[i] = pado[i - 2] + pado[i - 3];
	}
	return pado[n];
}