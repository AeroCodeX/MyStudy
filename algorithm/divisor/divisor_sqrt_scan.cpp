#include "divisor.h"

vector<int> divisor_sqrt_scan(int n) {
	vector<int> ret;
	int sqrt = 0;
	while (sqrt * sqrt < n)
	{
		sqrt++;
	}
	for (int i = 1; i <= sqrt; i++) {
		if (n%i == 0) {
			ret.push_back(i);
			ret.push_back(n / i);
		}
	}
	return ret;
}

