#include "gcd.h"
using namespace std;

int gcd_full_scan_reverse(int a, int b) {
	int gcd = 1;
	int minNumber = a < b ? a : b;

	for (int i = minNumber; 0 < i; i--) {
		if (a%i == 0 && b%i == 0) {
			gcd = i;
			break;
		}
	}
	return gcd;
}