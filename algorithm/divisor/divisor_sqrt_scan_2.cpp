#include "divisor.h"

vector<int> divisor_sqrt_scan_2(int n) {
	vector<int> ret;
	int down = n;
	for (int i = 1; i <= n; i++) {
		if (down == i) break;
		if (n%i == 0) {
			ret.push_back(i);
			ret.push_back(n / i);
			down = n / i;
		}
	}
	return ret;
}

