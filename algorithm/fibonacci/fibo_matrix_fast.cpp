#include "fibonacci.h"
#include <stdio.h>

void multAndSet(long long A[2][2], long long B[2][2]) 
{
	// A * B를 계산한 뒤, A에 대입한다.
	long long T[2][2];
	T[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
	T[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1];
	T[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0];
	T[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1];

	A[0][0] = T[0][0];
	A[0][1] = T[0][1];
	A[1][0] = T[1][0];
	A[1][1] = T[1][1];
}

long long fibo_matrix_fast(int n)
{
	//! long long으로 표현할 수 있는 한계선.
	if (92 < n) return -1;
	if (n <= 1) return n;


	//! ans : 정답행렬
	//! tmp : 중간값 저장 행렬
	//! m   : 피보나치를 계산하기 위한 단위 행렬
	long long ans[2][2] = { 1, 1, 1, 0 };
	long long tmp[2][2] = { 0, 0, 0, 0 };
	long long m[2][2] = { 1, 1, 1, 0 };


	//! n의 최상위 비트를 알아낸다.
	//! n이 int이므로 32비트 만큼 옮겨가며 조사한다.
	int mask = 1;
	for (int i = 0; i < 32; i++)
	{
		if (n & 1 << i) mask = 1 << i;
	}

	//! ans[0][0]은 n+1번째 피보나치 값이다.
	//! n으로 적절히 조정한다.
	n--;

	//! 초기값은 1이다.
	mask >>= 1;

	while (mask != 0)
	{
		//! 왼쪽으로 시프트한다.
		tmp[0][0] = ans[0][0] * ans[0][0] + ans[0][1] * ans[1][0];
		tmp[0][1] = ans[0][0] * ans[0][1] + ans[0][1] * ans[1][1];
		tmp[1][0] = ans[1][0] * ans[0][0] + ans[1][1] * ans[1][0];
		tmp[1][1] = ans[1][0] * ans[0][1] + ans[1][1] * ans[1][1];
		ans[0][0] = tmp[0][0];
		ans[0][1] = tmp[0][1];
		ans[1][0] = tmp[1][0];
		ans[1][1] = tmp[1][1];

		if (n & mask)
		{
			//! 1을 더한다.
			tmp[0][0] = ans[0][0] * m[0][0] + ans[0][1] * m[1][0];
			tmp[0][1] = ans[0][0] * m[0][1] + ans[0][1] * m[1][1];
			tmp[1][0] = ans[1][0] * m[0][0] + ans[1][1] * m[1][0];
			tmp[1][1] = ans[1][0] * m[0][1] + ans[1][1] * m[1][1];
			ans[0][0] = tmp[0][0];
			ans[0][1] = tmp[0][1];
			ans[1][0] = tmp[1][0];
			ans[1][1] = tmp[1][1];
		}
		mask >>= 1;
	}

	return ans[0][0];
}