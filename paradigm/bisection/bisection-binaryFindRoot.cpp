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
const Range NullRange(-1, 1); 

// coff[i] : 다항식 요소 중, x^i의 계수
// d       : 다항식의 차수
// [s, e)  : 다항식의 근을 찾을 구간
// limit   : 앞으로 남은 분할 횟수.
Range binaryFindRoot(double coff[], int d, double s, double e, int limit)
{
	// 충분히 반복함.
	if (limit == 0)
	{
		return Range(s, e);
	}

	// s, e, mid에 대하여 함수값을 계산.
	double mid = (s + e) / 2.0;
	double fs = 0, fe = 0, fm = 0;
	for (int i = 0; i < d; i++)
	{
		fs += coff[i] * pow(s, i);
		fe += coff[i] * pow(e, i);
		fm += coff[i] * pow(mid, i);
	}
	printf("%2d ::  (%.10f %.10f), %.10f %.10f\n", limit, s, e, fs, fe);

	// s 또는 e 또는 mid가 정답인 경우.
	if (fs == 0) return Range(s, s + 0.0000001);
	if (fe == 0) return Range(e, e + 0.0000001);
	if (fm == 0) return Range(mid, mid + 0.0000001);


	// 그 외의 경우에는,
	// 구간 양쪽 함수값의 부호가 다를 때 정답.
	// sign of fs (sfs)
	// sign of fe (sfe) 
	// sign of fm (sfm) 
	int sfs = fs < 0 ? -1 : +1;
	int sfe = fe < 0 ? -1 : +1;
	int sfm = fm < 0 ? -1 : +1;

	if (sfs != sfm) return binaryFindRoot(coff, d, s, mid, limit - 1);
	if (sfm != sfe) return binaryFindRoot(coff, d, mid, e, limit - 1);
	
	// 이 구간에 정답은 없다.
	return NullRange;
}

int main()
{
	double coff[4] = { -4, 2, 2.8, 0.5 };
	Range ans = binaryFindRoot(coff, 4, -100, +100, 50);
	const char* equ = (ans.s == ans.e) ? "equal" : "not equal";
	printf("결과 : %3.10f %3.10f %s", ans.s, ans.e, equ );
	while (1);
}