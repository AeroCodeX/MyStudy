#include "prime_number.h"

bool brute[PRIME_MAX + 1];
bool brute_init = false;


bool* generate_prime_brute()
{
	if (!brute_init)
	{
		// 배열 초기화
		// (Brute) 전부 Prime으로 가정한다.
		memset(brute, true, sizeof(brute));
		brute[0] = false;
		brute[1] = false;


		// 조건 검사
		// (Brute) 구간[2, N)의 수로 나눠지면 Composite이다.
		for (int i = 2; i <= PRIME_MAX; i++)
		{
			for (int j = 2; j < i; j++)
			{
				if (i%j == 0)
				{
					brute[i] = false;
					goto outerBreak;
				}
			}
		outerBreak:
			;
		}
		brute_init = true;
	}
	return brute;
}