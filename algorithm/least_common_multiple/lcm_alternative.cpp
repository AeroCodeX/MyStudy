#include "lcm.h"

int lcm_alternative(int a, int b) {
	int ret;
	int x = a;
	int y = b;

	while (true) {
		if (x == y) {
			ret = x;
			break;
		}
		if (x < y) x += a;
		else y += b;
	}
	return ret;
}