#pragma once

int lcm_full(int a, int b);
int lcm_alternative(int a, int b);
int lcm_using_gcd(int a, int b);

int gcd_euclidean_iterative(int a, int b) {
	if (a == b) return a;
	if (b == 0) return a;

	int temp;
	if (a < b) {
		// swap.
		temp = a;
		a = b;
		b = temp;
	}

	while (b != 0) {
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}