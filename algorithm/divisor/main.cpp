
#include <iostream>
#include <chrono>
#include "divisor.h"
using namespace std;

#define TEST 1000

int main() {
	//! 시간측정을 위한 변수선언,
	chrono::system_clock::time_point s, e;
	chrono::duration<double> dt;

	//! 약수 알고리즘을 위한 변수선언,
	vector<int> ret;
	int T = TEST;

	//! TEST회 만큼 반복한다.
	s = chrono::system_clock::now();
	while (T--) ret = divisor_sqrt_scan_2(1000000000);
	e = chrono::system_clock::now();

	//! 평균 걸린시간 출력.
	dt = e - s;
	cout << "dt : " << chrono::duration_cast<chrono::microseconds>(dt).count() / TEST << "micro sec" << endl;
}