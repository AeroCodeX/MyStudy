#include <stdio.h>
#pragma warning(disable:4996)

int A, B, C, D;
int P, M, N;
int period1, period2;
int cnt_p = 0, cnt_m = 0, cnt_n = 0;

int main()
{
	scanf("%d %d %d %d", &A, &B, &C, &D);
	scanf("%d %d %d", &P, &M, &N);

	period1 = A + B; 
	period2 = C + D; 

	if (P%period1 != 0 && P%period1 <= A)cnt_p++;
	if (P%period2 != 0 && P%period2 <= C)cnt_p++;
	if (M%period1 != 0 && M%period1 <= A)cnt_m++;
	if (M%period2 != 0 && M%period2 <= C)cnt_m++;
	if (N%period1 != 0 && N%period1 <= A)cnt_n++;
	if (N%period2 != 0 && N%period2 <= C)cnt_n++;
	printf("%d\n%d\n%d", cnt_p, cnt_m, cnt_n);
}