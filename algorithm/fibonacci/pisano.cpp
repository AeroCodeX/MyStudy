#include "fibonacci.h"

long long pisano(long long mod)
{
	if (mod < 0) return -1;
	if (mod == 1) return 1;
	
	long long beginPart[3] = { 0, 1, 1 };
	long long queue[3] = { 1, 1 };
	int p = 0;
	int q = 5;
	long long cnt = 0;

	while (p != 3)
	{
		queue[q % 3] = (queue[(q - 1) % 3] + queue[(q - 2) % 3]) % mod;
		cnt++;
		queue[q % 3] == beginPart[p] ? p++ : p = 0;
		if (++q >= 6)q = 3;
	}
	return cnt;
}