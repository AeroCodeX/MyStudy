#include <vector>
using namespace std;

int main()
{
	vector<int> divisor;
	int N = 1000000000;
	for (int i = 1; i <= N; i++)
	{
		if (N % i == 0) divisor.push_back(i);
	}
}
