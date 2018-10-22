
#include <iostream>
#include <chrono>
#include "gcd.h"
using namespace std;

#define TEST 1000000

int main() {
	//! �ð������� ���� ��������,
	chrono::system_clock::time_point s, e;
	chrono::duration<double> dt;

	//! ��� �˰����� ���� ��������,
	int T = TEST;
	int ret;

	//! TESTȸ ��ŭ �ݺ��Ѵ�.
	s = chrono::system_clock::now();
	while (T--) ret = gcd_euclidean_iterative(1000000000, 876543210);
	e = chrono::system_clock::now();
	cout << ret << endl;

	//! ��� �ɸ��ð� ���.
	dt = e - s;
	cout << "dt : " << chrono::duration_cast<chrono::milliseconds>(dt).count() / TEST << endl;
}