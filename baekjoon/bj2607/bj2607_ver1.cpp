#include <stdio.h>
#include <string.h>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

int T, cnt = 0;
char word[11];
char origin[128], compare[128];
vector<int> diff;

void disassemble(char *w, char *table)
{
	memset(table, 0, sizeof(origin));
	int len = -1;
	while (w[++len] != '\0') table[w[len]]++;
}
bool isSimillar()
{
	if (diff.size() != 0)diff.clear();

	// 2개 이상 차이나면 가망없음.
	for (int i = 'A'; i <= 'Z'; i++)
	{
		if (origin[i] - compare[i] <= -2) return false;
		if (origin[i] - compare[i] >=  2) return false;
		if (origin[i] != compare[i]) diff.push_back(i);
	}
	if (diff.size() >= 3) return false;
	else if (diff.size() == 2)
	{
		return (origin[diff[0]] + origin[diff[1]]) == (compare[diff[0]] + compare[diff[1]]);
	}
	return true;
}


int main()
{

	scanf("%d", &T);

	// get first word.
	scanf("%s", word);
	disassemble(word, origin);
	T--;
	while (T--)
	{
		scanf("%s", word);
		disassemble(word, compare);
		if (isSimillar()) cnt++;
	}
	printf("%d", cnt);
	while (1);
}