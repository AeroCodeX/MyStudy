
#include <iostream>
#include <chrono>
#include "prime_number.h"
using namespace std;

#define TEST 1

int main() {
	//! Variable for dt.
	chrono::system_clock::time_point s, e;
	chrono::duration<double> dt;

	//! Variable for algolithm.
	bool ret;
	int T = TEST;

	//! Repeat {TEST} times.
	s = chrono::system_clock::now();
	while (T--)
	{
		for (int i = 1; i <= 200000; i++)
		{
			ret = check_prime_full(i);
		}
	}
	e = chrono::system_clock::now();

	//! Print out dt.
	dt = e - s;
	cout << "dt : " << chrono::duration_cast<chrono::milliseconds>(dt).count() / TEST << endl;
	
	// wait...
	while (1);
}