#include <stdio.h>
#pragma warning (disable:4996);

int N, M;
int budget[10000], v;
int s, e, mid, upperBound;
int biggest = -1;
long long total = 0;

bool test(int testUpperBound)
{
	long long sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += (budget[i] < testUpperBound ? budget[i] : testUpperBound);
		if (sum > M) return false;
	}
	return true;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &budget[i]);
		if (biggest < budget[i])biggest = budget[i];
		total += budget[i];
	}
	scanf("%d", &M);

	//! 전부 허용할 수 있다면,
	if (total <= M)
	{
		printf("%d", biggest);
		return 0;
	}

	s = 0;
	e = 1000000001;
	while (s < e)
	{
		mid = (s + e) / 2;
		if (test(mid))
		{
			// 예산 한도액을 더 크게 잡을 수 있지 않을까?
			if (!test(mid + 1))
			{
				upperBound = mid;
				break;
			}
			s = mid + 1;
		}
		else
		{
			// 예산 한도액을 더 잡게 잡아야 한다.
			if (test(mid - 1))
			{
				upperBound = mid - 1;
				break;
			}
			e = mid;
		}
	}
	printf("%d\n", upperBound);
}
