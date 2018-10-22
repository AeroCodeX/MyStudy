#include "gcd.h"
using namespace std;

int multi_gcd_euclidean(vector<int> list) {
	if (list.size() == 0) return -1;

	int gcd = list[0];
	int len = list.size();
	for (int i = 1; i < len; i++) {
		gcd = gcd_euclidean_iterative(gcd, list[i]);
	}
	return gcd;
}