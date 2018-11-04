#include "fibonacci.h"
const long long M[2][2] = { {1, 1}, {1, 0} };
long long fibo_matrix(int n)
{
	//! long long으로 표현할 수 있는 한계선.
	if (92 < n) return -1;

	if (n == 0) return 0;
	if (n == 1) return 1;
	long long ret[2][2] = { {1, 1}, {1, 0} };
	long long tmp[2][2];
	for (int i = 0; i < n - 2; i++)
	{
		tmp[0][0] = ret[0][0];
		tmp[0][1] = ret[0][1];
		tmp[1][0] = ret[1][0];
		tmp[1][1] = ret[1][1];

		ret[0][0] = tmp[0][0] * M[0][0] + tmp[0][1] * M[1][0];
		ret[0][1] = tmp[0][0] * M[0][1] + tmp[0][1] * M[1][1];
		ret[1][0] = tmp[1][0] * M[0][0] + tmp[1][1] * M[1][0];
		ret[1][1] = tmp[1][0] * M[0][1] + tmp[1][1] * M[1][1];
	}
	return ret[0][0];
}