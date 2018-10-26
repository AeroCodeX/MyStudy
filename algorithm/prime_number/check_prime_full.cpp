#include "prime_number.h"

bool check_prime_full(int n)
{
	if (n == 1) return false;

	bool ret = true;
	for (int i = 2; i < n; i++)
	{
		if (n%i == 0)
		{
			ret = false;
			break;
		}
	}
	return ret;
}