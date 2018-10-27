#include <stdio.h>
#include <string.h>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

bool map[101][101];
bool chk[101]; // [1, i]를 경유한 경로체크를 완료함.
vector<int> linked;
int  computerN, networkN, cnt = 0;

int main()
{
	memset(map, 0, sizeof(map));
	memset(chk, 0, sizeof(chk));
	
	scanf("%d %d", &computerN, &networkN);
	for (int i = 0; i < networkN; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		map[a][b] = true;
		map[b][a] = true;
	}

	linked.emplace_back(1);
	while (!linked.empty())
	{
		int node = linked.back();
		linked.pop_back();
		if (chk[node]) continue;
		for (int i = 1; i <= computerN; i++)
		{
			if (map[node][i])
			{
				map[1][i] = true;
				if (!chk[i]) linked.push_back(i);
			}
		}
		chk[node] = true;
	}
	for (int i = 2; i <= computerN; i++) if (map[1][i])cnt++;
	printf("%d", cnt);
}