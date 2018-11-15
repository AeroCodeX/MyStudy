#include <stdio.h>
#include <algorithm>
#pragma warning (disable:4996);
using namespace std;

int N, tree[1000000], M, H = 0;
int tallest = -1;
int s, e, mid;

bool test(int h)
{
	long long sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += (tree[i] < h ? 0 : tree[i] - h);
		if (sum >= M) return true;
	}
	return false;
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) 
	{
		scanf("%d", &tree[i]);
		if (tallest < tree[i]) tallest = tree[i];
	}

	//! 처음으로 식을 만족하지 않는 H를 구한다.
	//! 답은 H + 1 이다.
	s = 0;
	e = tallest + 1;
	while (s < e)
	{
		mid = (s + e) / 2;
		if (test(mid))
		{
			// 답은 오른쪽 구간에 있다.
			if (!test(mid + 1))
			{
				H = mid;
				break;
			}
			s = mid;
		}
		else
		{
			// 답은 왼쪽 구간에 있다.
			if (test(mid - 1))
			{
				H = mid - 1;
				break;
			}
			e = mid;
		}
	}
	printf("%d", H);
}
