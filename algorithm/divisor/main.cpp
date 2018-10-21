
#include <iostream>
#include <chrono>
#include "divisor.h"
using namespace std;

#define TEST 1000

int main() {
	//! �ð������� ���� ��������,
	chrono::system_clock::time_point s, e;
	chrono::duration<double> dt;

	//! ��� �˰����� ���� ��������,
	vector<int> ret;
	int T = TEST;

	//! TESTȸ ��ŭ �ݺ��Ѵ�.
	s = chrono::system_clock::now();
	while (T--) ret = divisor_sqrt_scan_2(1000000000);
	e = chrono::system_clock::now();

	//! ��� �ɸ��ð� ���.
	dt = e - s;
	cout << "dt : " << chrono::duration_cast<chrono::microseconds>(dt).count() / TEST << "micro sec" << endl;
}