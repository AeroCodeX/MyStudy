#include <stdio.h>
#include <algorithm>
#pragma warning (disable:4996);
using namespace std;

int N, M;
int arr[500000];

int idx(int n, bool left)
{
	int s, e, mid, ans = -1;
	s = 0;
	e = N;
	while (s < e)
	{
		mid = (s + e) / 2;
		if (arr[mid] == n)
		{
			//! mid가 값을 관통했을 때,
			if (left)
			{
				// 가장 좌측에 있는 값 구하기.
				// mid가 왼쪽 끝에 있을 가능성을 생각한다.
				if (mid == 0)
				{
					ans = mid;
					break;
				}
				if (arr[mid - 1] == n) e = mid;
				else
				{
					ans = mid;
					break;
				}
			}
			else
			{
				// 가장 우측에 있는 값 구하기.
				// mid가 끝에 있을 가능성을 생각한다.
				if (mid == N - 1)
				{
					ans = mid;
					break;
				}
				if (arr[mid + 1] == n) s = mid + 1;
				else
				{
					ans = mid;
					break;
				}
			}
		}
		else if (arr[mid] < n) s = mid + 1;
		else if (arr[mid] > n) e = mid;
	}
	return ans;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
	sort(&arr[0], &arr[N]);

	scanf("%d", &M);
	int left, right, v;
	while (M--)
	{
		scanf("%d", &v);
		left = idx(v, true);
		right = idx(v, false);
		if (left == -1 || right == -1) printf("0 ");
		else printf("%d ", right - left + 1);
	}
}
