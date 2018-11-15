#include <stdio.h>
#pragma warning (disable:4996);

int K, N;
int len[10000], v;
long long s, e, mid, ans = -1;

bool test(long long deli)
{
	long long total = 0;
	for (int i = 0; i < K; i++)
	{
		total += (len[i] / deli);
		if (total >= N) return true;
	}
	return false;
}

int main()
{
	scanf("%d %d", &K, &N);
	for (int i = 0; i < K; i++)
	{
		scanf("%d", &len[i]);
	}

	s = 0;
	e = 2147483648;
	while (s < e)
	{
		mid = (s + e) / 2;
		if (test(mid))
		{
			// 더 길게 자를 수 있지 않을까?
			if (!test(mid + 1))
			{
				ans = mid;
				break;
			}
			s = mid + 1;
		}
		else
		{
			// 더 잘게 잘라야 한다.
			if (test(mid - 1))
			{
				ans = mid - 1;
				break;
			}
			e = mid;
		}
	}
	printf("%lld", ans);
}
