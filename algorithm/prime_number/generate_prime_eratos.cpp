#include "prime_number.h"

bool eratos[PRIME_MAX + 1];
bool eratos_init = false;


bool* generate_prime_eratos()
{
	if (!eratos_init)
	{
		// 배열 초기화
		// (Eratos) 전부 Prime으로 가정한다.
		memset(eratos, true, sizeof(eratos));
		eratos[0] = false;
		eratos[1] = false;


		// 조건 검사
		// (Eratos) 소수의 배수는 Composite이다.
		for (int i = 2; i < PRIME_MAX + 1; i++)
		{
			if (!eratos[i]) continue;
			sieve(i, eratos);
		}
		eratos_init = true;
	}
	return eratos;
}