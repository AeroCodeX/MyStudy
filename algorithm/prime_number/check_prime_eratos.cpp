#include <stdio.h>
#define ERATOS_MAX 200000

bool eratos[ERATOS_MAX+1];
bool eratos_init = false;
bool check_prime_eratos(int n)
{
	if (!eratos_init)
	{
		for (int i = 0; i < ERATOS_MAX + 1; i++) eratos[i] = true;
		eratos[0] = false;
		eratos[1] = false;

		for (int i = 2; i < ERATOS_MAX + 1; i++)
		{
			if (!eratos[i]) continue;
			for (int k = 0; i*k <= ERATOS_MAX; k++)
			{
				eratos[i*k] = false;
			}
		}

		eratos_init = true;
	}
	return eratos[n];
}