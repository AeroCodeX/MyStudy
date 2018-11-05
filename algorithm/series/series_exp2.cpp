#include "series.h"

long long series_exp2(int n)
{
	long long sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += i * i;
	}
	return sum;
}

long long series_exp2_formla(int n)
{
	return n * (2 * n + 1) / 6 * (n + 1);
}