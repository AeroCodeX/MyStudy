#include "lcm.h"

int lcm_using_gcd(int a, int b) {
	int gcd = gcd_euclidean_iterative(a, b);
	return (a / gcd)*b;
}