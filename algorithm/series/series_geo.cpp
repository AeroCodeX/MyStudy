#include "series.h"

long long series_geo(int a0, int r, int n)
{
	long long sum = a0;
	long long an = a0;
	for (int i = 1; i < n; i++)
	{
		an *= r;
		sum += an;
	}
	return sum;
}

long long series_geo_formla(int a0, int r, int n)
{
	long long r_power_n = r;
	for (int i = 1; i < n; i++) r_power_n *= r;
	return a0 * (r_power_n - 1) / (r - 1);
}