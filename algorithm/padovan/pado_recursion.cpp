#include "padovan_number.h"

long long pado_recursion(int n)
{
	// long long ���� ǥ���� �� �ִ� �Ѱ�.
	if (161 < n) return -1;

	if (n <= 2) return 1;
	return pado_recursion(n - 2) + pado_recursion(n - 3);
}