#include <stdio.h>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

vector<int> order, temp;
int N, n;
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &n);
		
		while (n--)
		{
			temp.push_back(order.back());
			order.pop_back();
		}
		order.push_back(i);
		while (!temp.empty())
		{
			order.push_back(temp.back());
			temp.pop_back();
		}
	}
	for (int v : order) printf("%d ", v);
}