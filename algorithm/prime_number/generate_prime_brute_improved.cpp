
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

		// �迭 �ʱ�ȭ
		// (Dynamic) ���� Prime���� �����Ѵ�.
		memset(dynamic, true, sizeof(dynamic));
		dynamic[0] = false;
		dynamic[1] = false;


		// ���� �˻�
		//! (Dynamic) ���ݱ��� �߰ߵ� �Ҽ��� �������� Composite�̴�.
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
