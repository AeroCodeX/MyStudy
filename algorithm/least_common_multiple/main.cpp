
#include <iostream>
#include <chrono>
#include "lcm.h"
using namespace std;

#define TEST 1000000

int main() {
	//! �ð������� ���� ��������,
	chrono::system_clock::time_point s, e;
	chrono::duration<double> dt;

	//! �˰����� ���� ����.
	int ret;

	//! TESTȸ ��ŭ �ݺ��Ѵ�.
	int T = TEST;
	s = chrono::system_clock::now();
	while (T--) ret = lcm_using_gcd(46341, 46340);
	e = chrono::system_clock::now();

	//! ��� �ɸ��ð� ���.
	cout << ret << endl;
	dt = e - s;
	cout << "dt : " << chrono::duration_cast<chrono::nanoseconds>(dt).count() / TEST << endl;
}