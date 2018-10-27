#include "prime_number.h"
#include <math.h>

bool eratos_improved[PRIME_MAX + 1];
bool eratos_improved_init = false;


bool* generate_prime_eratos_improved()
{
	if (!eratos_improved_init)
	{
		// �迭 �ʱ�ȭ
		// (Eratos_improved) ���� Prime���� �����Ѵ�.
		memset(eratos_improved, true, sizeof(eratos_improved));
		eratos_improved[0] = false;
		eratos_improved[1] = false;


		// ���� �˻�
		// (Eratos_improved) �Ҽ��� ����� Composite�̴�.
		// (Eratos_improved) �Ҽ��� ����� Composite�̴�.
		// (Eratos_improved) �Ҽ��� ���ɼ��� �������� 6i��1 �̾�� �Ѵ�.
		sieve(2, eratos_improved);	// ����ó��
		sieve(3, eratos_improved);	// ����ó��
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