#include "padovan_number.h"

long long pado_pisano(long long mod)
{
	if (mod <= 1) return 1;

	long long beginPart[3] = { 1, 1, 1 };
	long long queue[4] = { 1, 1, 1 };
	int idx = 7; // [4, 8)
	int p = 0;
	long long cnt = 0;

	while (p != 3)
	{
		queue[idx % 4] = queue[(idx - 2) % 4] % mod + queue[(idx - 3) % 4] % mod;
		queue[idx % 4] %= mod;
		cnt++;
		queue[idx % 4] == beginPart[p] ? p++ : p = 0;
		if (++idx >= 8)idx = 4;
	}
	return cnt;
}