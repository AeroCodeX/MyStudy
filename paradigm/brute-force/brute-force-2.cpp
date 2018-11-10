#include <vector>
using namespace std;

int main()
{
	vector<int> divisor;
	int N = 50;
	int sqrt = 1000000000;
	while (sqrt*sqrt < N) sqrt++;
	for (int i = 1; i <= sqrt; i++)
	{
		if (N % i == 0)
		{
			divisor.push_back(i);
		}
	}
}