#include "series.h"

long long series_exp3(int n)
{
	long long sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += i * i*i;
	}
	return sum;
}

long long series_exp3_formla(int n)
{
	long long k = n * (n + 1) / 2;
	return k * k;
}