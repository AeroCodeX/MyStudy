#include "prime_number.h"

bool eratos[PRIME_MAX + 1];
bool eratos_init = false;


bool* generate_prime_eratos()
{
	if (!eratos_init)
	{
		// �迭 �ʱ�ȭ
		// (Eratos) ���� Prime���� �����Ѵ�.
		memset(eratos, true, sizeof(eratos));
		eratos[0] = false;
		eratos[1] = false;


		// ���� �˻�
		// (Eratos) �Ҽ��� ����� Composite�̴�.
		for (int i = 2; i < PRIME_MAX + 1; i++)
		{
			if (!eratos[i]) continue;
			sieve(i, eratos);
		}
		eratos_init = true;
	}
	return eratos;
}