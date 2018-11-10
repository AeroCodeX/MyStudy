int cntDivisor(int n)
{
	// 기저사항
	if (n == 1) return 1;

	// n의 약수 하나를 구한다.
	for (int i = 2; i <= n; i++)
	{
		if (n%i == 0)
		{
			// 약수를 1개 찾았고,
			// 나머지 약수는 또 다른 자신에게 넘긴다.
			return 1 + cntDivisor(n / i);
		}
	}

	// 도달할 수 없는 영역
	return -987654321;
}