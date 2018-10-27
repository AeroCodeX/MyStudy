#include "prime_number.h"

bool wheel[PRIME_MAX + 1];
bool wheel_init = false;
/*
 * Print out p as many times as it divides n.
 * Return the quotient of n by the highest power of p dividing n.
 */
int checkdivisor(int n, int p) {
	while (n % p == 0) n /= p;
	return n;
}

// Wheel for eliminating more composite numbers.
const int PERIOD = 7;
const int WHEEL235[PERIOD] = { 4, 2, 4, 2, 4, 6, 2 };

/*
 * Print the prime divisors of n.
 * The algorithm is trial division with 2-3-5 wheel factorization.
 */
bool check_prime_wheel(int n) {
	if (!wheel_init)
	{

	}
	if (n > 1) {
		// Check 2, 3, and 5 individually
		n = checkdivisor(n, 2);
		n = checkdivisor(n, 3);
		n = checkdivisor(n, 5);
		// Start at the next potential prime divisor, 7.
		int p = 7;
		int i = 0;
		while (n > 1) {
			// If p^2 > n, then n is the last remaining prime divisor.
			if (p * p > n) {
				std::cout << n << std::endl;
				return;
			}
			// Check if p is a prime divisor.
			n = checkdivisor(n, p);
			// Increment p based on the wheel.
			p += WHEEL235[i++ % PERIOD];
		}
	}
}