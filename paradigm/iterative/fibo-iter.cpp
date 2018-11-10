int fibo_iter(int n)
{
	//! 30 이상은 받지 않는다.
	if (30 <= n) return -1;

	int arr[30] = { 0, 1 };
	for (int i = 2; i <= n; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	return arr[n];
}