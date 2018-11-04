#include "fibonacci.h"
#include <string.h>
long long fibo_iterative_queue(int n)
{
	//! long long���� ǥ���� �� �ִ� �Ѱ輱.
	if (92 < n) return -1;
	if (n == 0) return 0;
	if (n == 1) return 1;

	long long queue[3] = { 1, 1 };

	//! idx�� ������ ���� �ʵ��� ������ [3, 6) ���� �����Ѵ�.
	int idx = 5;
	while (n--)
	{
		queue[idx % 3] = (queue[(idx - 1) % 3] + queue[(idx - 2) % 3]);
		if (++idx >= 6) idx = 3;
	}
	return queue[idx % 3];
}