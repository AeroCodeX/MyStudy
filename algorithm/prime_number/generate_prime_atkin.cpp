#include "prime_number.h"

bool atkin[PRIME_MAX + 1];
bool atkin_init = false;


bool* generate_prime_atkin()
{
	if (!atkin_init)
	{
		// �迭 �ʱ�ȭ
		// (Atkin) ���� Composite�� �����Ѵ�.
		memset(atkin, false, sizeof(atkin));


		// ���� �˻�
		// (Atkin) �� ���ǿ� ���������� ������Ų��.
		int n;
		for (int x = 1; x * x < PRIME_MAX; x++) {
			for (int y = 1; y * y < PRIME_MAX; y++) {
				// Flip  n = 4x^2 + y^2.
				// When  r is {1, 13, 37, 49} OR {17, 29, 41, 53}
				n = (4 * x * x) + (y * y);
				if (n <= PRIME_MAX && (n % 12 == 1 || n % 12 == 5))
					atkin[n] ^= true;

				// Flip  n = 3x^2 + y^2.
				// When  r is {7, 19, 31, 43}
				n = (3 * x * x) + (y * y);
				if (n <= PRIME_MAX && n % 12 == 7)
					atkin[n] ^= true;

				// Flip  n = 3x^2 - y^2.
				// When  r is {11, 23, 47, 59}
				n = (3 * x * x) - (y * y);
				if (x > y && n <= PRIME_MAX && n % 12 == 11)
					atkin[n] ^= true;

				// Ignore it.
				// When  r is something else.
			}
		}
		// (Atkin) �Ҽ��� ������ Composite�̴�.
		for (int r = 5; r * r <= PRIME_MAX; r++) {
			if (atkin[r]) {
				for (int i = r * r; i <= PRIME_MAX; i += r * r)
					atkin[i] = false;
			}
		}
		// (Atkin) ���߿� 5������ ���� ��������� �����Ѵ�.
		atkin[0] = atkin[1] = atkin[4] = false;
		atkin[2] = atkin[3] = atkin[5] = true;

		atkin_init = true;
	}
	return atkin;
}
