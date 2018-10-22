#include "gcd.h"
using namespace std;

int gcd_full_scan(int a, int b) {
	int gcd = 1;
	int minNumber = a < b ? a : b;

	for (int i = 1; i <= minNumber; i++) {
		if (a%i == 0 && b%i == 0) gcd = i;
	}
	return gcd;
}