
#include <iostream>
#include <chrono>
#include "lcm.h"
using namespace std;

#define TEST 1000000

int main() {
	//! 시간측정을 위한 변수선언,
	chrono::system_clock::time_point s, e;
	chrono::duration<double> dt;

	//! 알고리즘을 위한 변수.
	int ret;

	//! TEST회 만큼 반복한다.
	int T = TEST;
	s = chrono::system_clock::now();
	while (T--) ret = lcm_using_gcd(46341, 46340);
	e = chrono::system_clock::now();

	//! 평균 걸린시간 출력.
	cout << ret << endl;
	dt = e - s;
	cout << "dt : " << chrono::duration_cast<chrono::nanoseconds>(dt).count() / TEST << endl;
}