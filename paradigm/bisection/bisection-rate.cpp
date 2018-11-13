#include <stdio.h>
#pragma warning(disable:4996)

int win, lose;
const int MAX = 10000;

int rate(int moreWin)
{
	int total = win + lose + moreWin;
	int totalWin = win + moreWin;
	double winRate = (double) totalWin / (double) total;
	return winRate * 100;
}

int bisection(int s, int e)
{
	//! 마지막 값으로 안된다면, 불가능.
	//! 구간이 올바르지 않다면, 불가능.
	if (rate(e) < 50) return -1;
	if (e <= s) return -1;

	//! 중간을 쪼개 승률을 비교한다.
	int mid = (s + e) / 2;
	int rateMid = rate(mid);
	if (rateMid == 50)
	{
		int ans = mid;
		while (rate(ans) == 50) ans--;
		return ans + 1;
	}
	else if (rateMid > 50) return bisection(s, mid - 1);
	else if (rateMid < 50) return bisection(mid + 1, e);
	return -1;
}

int main()
{
	int moreWin;
	while (1)
	{
		scanf("%d %d", &win, &lose);
		moreWin = bisection(0, MAX);
		printf("%d\n", moreWin);
	}
}