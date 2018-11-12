#include <stdio.h>
#include <math.h>

struct Range
{
	Range(double s, double e)
	{
		this->s = s;
		this->e = e;
	}
	double s;
	double e;
};
const Range NullRange(0, 0); 

// coff[i] : 다항식 요소 중, x^i의 계수
// d       : 다항식의 차수
// [s, e)  : 다항식의 지역최대(최소)가 포함된다고 추측되는 구간.
// limit   : 앞으로 남은 분할 횟수.
Range triFindLocal(double coff[], int d, double s, double e, int limit)
{
	// 충분히 반복함.
	if (limit == 0) return Range(s, e);

	// 구간을 3개로 쪼개고, 
	// 각 경계값의 함수값과 그 차이를 계산한다.
	double x[4] = { s, (2 * s + e) / 3, (s + 2 * e) / 3, e };
	double fx[4] = { 0, 0, 0, 0 };
	double dx[3];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < d; j++)
		{
			fx[i] += (coff[j] * pow(x[i], j));
		}
		if (i != 0) dx[i - 1] = fx[i] - fx[i - 1];
	}

	// 함수의 증가, 감소를 판단한다.
	bool isInc[3];
	for (int i = 0; i < 3; i++) isInc[i] = dx[i] > 0;

	// 순증가, 순감소가 변화되는 구간의 합이 정답을 포함하는 구간이다.
	if (isInc[0] ^ isInc[1])
	{
		// 정답 구간은 1, 2번째 구간 안에 있다.
		return triFindLocal(coff, d, s, (s + 2 * e) / 3, limit - 1);
	}
	else
	{
		// 정답 구간은 2, 3번째 구간 안에 있다.
		return triFindLocal(coff, d, (2 * s + e) / 3, e, limit - 1);
	}
}

int main()
{
	double coff[4] = { -4, 2, 2.8, 0.5 };
	Range ans = triFindLocal(coff, 4, -5, -1, 100);
	const char* equ = (ans.s == ans.e) ? "equal" : "not equal";
	printf("결과 : %3.10f %3.10f %s", ans.s, ans.e, equ );
	while (1);
}