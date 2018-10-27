#include "prime_number.h"

bool brute[PRIME_MAX + 1];
bool brute_init = false;


bool* generate_prime_brute()
{
	if (!brute_init)
	{
		// �迭 �ʱ�ȭ
		// (Brute) ���� Prime���� �����Ѵ�.
		memset(brute, true, sizeof(brute));
		brute[0] = false;
		brute[1] = false;


		// ���� �˻�
		// (Brute) ����[2, N)�� ���� �������� Composite�̴�.
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