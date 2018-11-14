#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;

#define MAX_X +1000L
#define MIN_X -1000L
#define NULL_RANGE _null_range

struct Range
{
	Range(double s, double e)
	{
		this->s = s;
		this->e = e;
	}
	double s;
	double e;

	bool operator == (const Range other)
	{
		if (this->s != other.s) return false;
		if (this->e != other.e) return false;
		return true;
	}

	bool operator != (const Range other)
	{
		return !(*this == other);
	}
};
const Range _null_range(MIN_X, MIN_X);
const double DELTA = 0.000000000001; // 충분히 작은 값.


double f(vector<double> coff, double x);		//! 계수가 coff인 다항함수의 함숫값 f(x)를 구한다.
vector<Range> solve(vector<double> coff);		//! 계수가 coff인 다항함수의 해를 구한다.
vector<double> derivatize(vector<double> coff);	//! 계수가 coff인 다항함수를 미분한다. 
Range bisection(vector<double> coff, double s, double e);
double average(Range r);	// 구간의 중앙값을 반환한다.


// 주어진 구간의 중앙값을 반환한다.
double average(Range r)
{
	double aver = (r.s + r.e) / 2.0;
	return aver;
}


//! 계수가 coff인 다항함수의 함숫값 f(x)를 구한다.
double f(vector<double> coff, double x)
{
	double fx = 0;
	for (unsigned int i = 0; i < coff.size(); i++)
	{
		fx += coff[i] * pow(x, i);
	}
	return fx;
}


//! 계수가 coff인 다항함수를 미분한다. 
vector<double> derivatize(vector<double> coff)
{
	vector<double> derivated;
	for (unsigned int i = 1; i < coff.size(); i++)
	{
		derivated.push_back(coff[i] * i);
	}
	return derivated;
}


//! 계수가 coff인 다항함수에서
//! 열린구간 (s, e) 사이에 있는 해의 범위를 추측한다.
Range bisection(vector<double> coff, double s, double e)
{
	int limit = 100;
	double mid, fx_mid, fx_s, fx_e;

	//! 구간 (s, e)에 0이 없다면 패스.
	fx_s = f(coff, s);
	fx_e = f(coff, e);
	if (fx_s < 0 && fx_e < 0) return NULL_RANGE;
	if (fx_s > 0 && fx_e > 0) return NULL_RANGE;

	//! 일정횟수만 반복한다.
	while (limit--)
	{
		mid = (s + e) / 2;
		fx_s = f(coff, s);
		fx_e = f(coff, e);
		fx_mid = f(coff, mid);

		if (fx_mid == 0)
		{
			return Range(mid - DELTA, mid + DELTA);
		}
		else if (fx_mid > 0)
		{
			if (fx_s < 0) { e = mid; }
			else if (fx_e < 0) { s = mid; }
		}
		else if (fx_mid < 0)
		{
			if (fx_s > 0) { e = mid; }
			else if (fx_e > 0) { s = mid; }
		}
	}
	return Range(s, e);
}


//! 계수가 coff인 다항함수의 해를 구한다.
vector<Range> solve(vector<double> coff)
{
	//! 일차 이하의 간단한 방정식은 그냥 푼다.
	vector<Range> roots;
	if (coff.size() <= 1)
	{
		//! 올바르지 않거나 상수함수일 경우에는 무시한다.
		return roots;
	}
	if (coff.size() == 2)
	{
		//! 일차함수
		double root = -coff[0] / coff[1];
		roots.emplace_back(root - DELTA, root + DELTA);
		return roots;
	}


	//! 이차 이상의 복잡한 방정식은 미분을 사용한다.
	//! (1) 먼저, 전체구간을 단조성을 만족하는 부분구간으로 나눈다.
	vector<double> derivated = derivatize(coff);
	vector<Range>  local_pos = solve(derivated);
	vector<Range> monotonic;
	if (local_pos.size() == 0)
	{
		monotonic.emplace_back(MIN_X, MAX_X);
	}
	else
	{
		monotonic.emplace_back(MIN_X, average(local_pos[0]));
		for (unsigned int i = 0; i < local_pos.size() - 1; i++)
		{
			monotonic.emplace_back(average(local_pos[i]), average(local_pos[i + 1]));
		}
		monotonic.emplace_back(average(local_pos[local_pos.size() - 1]), MAX_X);
	}

	//! (2) 각 부분구간에 대해 이분법을 적용한다.
	for (Range r : monotonic)
	{
		roots.push_back(bisection(coff, r.s, r.e));
	}
	return roots;
}


int main()
{
	//! y = (2x^4) + (-3x^3) + (-2.4x^2) + (5x^1) + (-1.7x^0);
	//! coff[i] == x^i의 계수.
	vector<double> coff, derv;
	coff = { -1.7, 5, -2.4, -3, 2 };

	vector<Range> roots = solve(coff);
	for (Range r : roots)
	{
		//! 허수해가 있을경우 NULL_RANGE 조건에서 필터링된다.
		if (r != NULL_RANGE) printf("%.4f\n", average(r));
	}
	printf("DONE!");
}