#include "fibonacci.h"
#include <string.h>
long long fibo_iterative_queue(int n)
{
	//! long long으로 표현할 수 있는 한계선.
	if (92 < n) return -1;
	if (n == 0) return 0;
	if (n == 1) return 1;

	long long queue[3] = { 1, 1 };

	//! idx가 음수가 되지 않도록 범위를 [3, 6) 으로 제한한다.
	int idx = 5;
	while (n--)
	{
		queue[idx % 3] = (queue[(idx - 1) % 3] + queue[(idx - 2) % 3]);
		if (++idx >= 6) idx = 3;
	}
	return queue[idx % 3];
}