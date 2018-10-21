#include <iostream>
using namespace std;

int T;
int from, to;
int len, n;

long long maxWarp(long long cnt) {
	long long half = (cnt + 1) / 2;
	if (cnt % 2) return half * half;
	return half * half + half;
}

int main() {
	cin >> T;
	while (T--) {
		cin >> from >> to;
		len = to - from;
		n = 0;
		while (len > maxWarp(++n));
		cout << n << endl;
	}
	return 0;
}

