#include "divisor.h"

vector<int> divisor_full_scan(int v)
{
	vector<int> ret;
	for (int i = 1; i <= v; i++) {
		if (v%i == 0) ret.push_back(i);
	}
	return ret;
}

