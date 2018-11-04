#include "padovan_number.h"

long long pado_recursion(int n)
{
	if (n <= 2) return 1;
	return pado_recursion(n - 2) + pado_recursion(n - 3);
}