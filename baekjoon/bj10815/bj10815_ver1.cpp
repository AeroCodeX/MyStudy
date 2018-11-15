#include <stdio.h>
#include <algorithm>
#pragma warning (disable:4996);
using namespace std;

int N, M;
int s, e, mid, v;
int arr[500000];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	sort(&arr[0], &arr[N]);
	
	scanf("%d", &M);
	while (M--)
	{
		scanf("%d", &v);
		s = 0;
		e = N;
		while (true)
		{
			if (e <= s)
			{
				printf("0 ");
				break;
			}
			mid = (s + e) / 2;
			if (arr[mid] == v)
			{
				printf("1 ");
				break;
			}
			else if (arr[mid] > v)
			{
				e = mid;
			}
			else if (arr[mid] < v)
			{
				s = mid + 1;
			}
		}
	}
}
