#include "prime_number.h"
#include <math.h>

bool eratos_improved[PRIME_MAX + 1];
bool eratos_improved_init = false;


bool* generate_prime_eratos_improved()
{
	if (!eratos_improved_init)
	{
		// 배열 초기화
		// (Eratos_improved) 전부 Prime으로 가정한다.
		memset(eratos_improved, true, sizeof(eratos_improved));
		eratos_improved[0] = false;
		eratos_improved[1] = false;


		// 조건 검사
		// (Eratos_improved) 소수의 배수는 Composite이다.
		// (Eratos_improved) sqrt(n)까지만 조사하면 된다.
		// (Eratos_improved) 소수의 가능성이 있으려면 6i±1 이어야 한다.
		sieve(2, eratos_improved);	// 예외처리
		sieve(3, eratos_improved);	// 예외처리
		int end = sqrt(PRIME_MAX);
		for (int i = 6; i <= end+6; i+=6)
		{
			if (eratos_improved[i - 1]) sieve(i - 1, eratos_improved);
			if (eratos_improved[i + 1]) sieve(i + 1, eratos_improved);
		}
		eratos_improved_init = true;
	}
	return eratos_improved;
}