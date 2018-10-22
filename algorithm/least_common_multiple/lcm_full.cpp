#include "lcm.h"

int lcm_full(int a, int b) {
	int ret;

	for (int i = 1; i <= b; i++) {
		for (int j = 1; j <= a; j++) {
			if (a*i == b * j) {
				return a * i;
			}
		}
	}

	// unreachable.
	return -1;
}