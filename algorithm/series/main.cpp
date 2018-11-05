
#include <iostream>
#include <chrono>
#include "series.h"
using namespace std;

#define stop while(1);
#define TEST 1000000

int main() 
{
	//! 시간측정을 위한 변수선언,
	chrono::system_clock::time_point s, e;
	chrono::duration<double> dt;

	//! 알고리즘을 위한 변수선언,
	int T = TEST;
	long long ret;

	//! TEST회 만큼 반복한다.
	s = chrono::system_clock::now();
	while (T--)
	{
		ret = series_exp3(10000);
	}
	e = chrono::system_clock::now();
	cout << ret << endl;

	//! 평균 걸린시간 출력.
	dt = e - s;
	cout << "dt : " << chrono::duration_cast<chrono::nanoseconds>(dt).count() / TEST << endl;

	stop

}