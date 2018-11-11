int fibo_iter_2(int n)
{
	//! 30이상은 받지 않는다.
	if (30 <= n)return -1;

	int fibo[30] = { 0, 1, 1 };
	for (int i = 3; i < 30; i++) fibo[i] = 0;

	for (int i = 1; i < 30; i++)
	{
		for (int j = i + 2; j < 30; j++)
		{
			fibo[j] += fibo[i];
		}
	}
	return fibo[n];
}