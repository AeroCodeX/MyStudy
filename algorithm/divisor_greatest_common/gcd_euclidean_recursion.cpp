#include "gcd.h"
using namespace std;

int gcd_euclidean_recursion(int a, int b) {
	if (a == b) return a;
	if (b == 0) return a;

	if (a < b) return gcd_euclidean_recursion(b, a);
	if (a > b) return gcd_euclidean_recursion(b, a%b);

	// unreachable.
	return -1;
}