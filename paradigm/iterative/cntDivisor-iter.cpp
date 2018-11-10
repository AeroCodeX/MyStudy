int cntDivisor(int n)
{
	// 정답이 담길 배열을 선언하고 초기화한다.
	int cnt[100];
	for (int i = 0; i < 100; i++)cnt[i] = 0;

	// i*? = K 이면, i는 K의 약수이다.
	for (int i = 1; i < 100; i++)
	{
		for (int j = 1; i*j < 100; j++)
		{
			cnt[i*j]++;
		}
	}
	return cnt[n];
}