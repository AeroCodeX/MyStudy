int fibo_recursion(int n)
{
	//! 30 이상은 받지 않는다.
	if (30 <= n) return -1;

	//! 기저사항
	if (n == 0) return 0;
	if (n == 1) return 1;

	return fibo_recursion(n - 1) + fibo_recursion(n - 2);
}