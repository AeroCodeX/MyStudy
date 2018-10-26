
#include "prime_number.h"
#include <vector>
#include <algorithm>
using namespace std;

vector<int> primes;
int lastChecked = 1;
bool check_prime_dynamic(int n)
{
	if (n <= 1) return false;
	
	// at first, check out cache.
	if (n <= lastChecked) return find(primes.begin(), primes.end(), n) != primes.end();

	// get next prime number.
	int len;
	bool isPrime;
	for (int i = lastChecked+1; i <= n; i++)
	{
		len = primes.size();
		isPrime = true;
		for(int prime : primes)
		{
			if (i % prime == 0)
			{
				isPrime = false;
				break;
			}
		}
		if(isPrime) primes.push_back(i);
	}
	lastChecked = n;
	return primes.back() == n;
}