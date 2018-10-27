#include "prime_number.h"
#include <vector>
using namespace std;

bool dynamic[PRIME_MAX + 1];
bool dynamic_init = false;


bool* generate_prime_brute_improved()
{
	if (!dynamic_init)
	{
		vector<int> primes;

		// 배열 초기화
		// (Dynamic) 전부 Prime으로 가정한다.
		memset(dynamic, true, sizeof(dynamic));
		dynamic[0] = false;
		dynamic[1] = false;


		// 조건 검사
		//! (Dynamic) 지금까지 발견된 소수로 나눠지면 Composite이다.
		for (int i = 2; i <= PRIME_MAX; i++)
		{
			for (int prime : primes)
			{
				if (i%prime == 0)
				{
					dynamic[i] = false;
					goto outerBreak;
				}
			}
			primes.push_back(i);
		outerBreak:
			;
		}
		dynamic_init = true;
	}
	return dynamic;
}
