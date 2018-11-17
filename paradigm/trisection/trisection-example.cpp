#include <stdio.h>
#include <math.h>

double f(double x)
{
	double lnx = log(x);
	return 1.5 * x * (1 - log(x));
}

double trisection(double s, double e)
{
	int limit = 100;
	double m1, m2;
	double fm1, fm2;

	while (limit--)
	{
		//! 주어진 구간을 삼등분하는 점을 정의한다.
		m1 = (2 * s + e) / 3;
		m2 = (s + 2 * e) / 3;

		//! 해당 점의 함숫값을 구한다.
		fm1 = f(m1);
		fm2 = f(m2);

		//! 최대값이 없는 구간을 배제한다.
		if (fm1 < fm2) s = m1;
		if (fm2 < fm1) e = m2;
	}
	//! 구간의 중점을 반환한다.
	return (s + e) / 2;
}

int main()
{
	printf("%f", trisection(0, 100));
}