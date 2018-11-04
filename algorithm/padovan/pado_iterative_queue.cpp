#include "padovan_number.h"

long long pado_iterative_queue(int n)
{
	// long long 으로 표현할 수 있는 한계.
	if (161 < n) return -1;

	if (n <= 2) return 1;
	
	long long queue[4] = { 1, 1, 1 };
	int idx = 7; // [4, 8)
	while (0 <= n--)
	{
		queue[idx % 4] = queue[(idx - 2) % 4] + queue[(idx - 3) % 4];
		if (++idx >= 8)idx = 4;
	}
	return queue[idx % 4];
}