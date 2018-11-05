#include "series.h"

long long series_arth(int a0, int d, int n)
{
	long long sum = 0;
	long long an = a0 - d;
	for (int i = 0; i < n; i++)
	{
		an += d;
		sum += an;
	}
	return sum;
}

long long series_arth_formla(int a0, int d, int n)
{
	long long an = a0 + d * (n - 1);
	return n * (a0 + an) / 2;
}