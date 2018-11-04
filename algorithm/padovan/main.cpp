#include <iostream>
#include <chrono>
#include "padovan_number.h"
using namespace std;

#define TEST 1
#define stop while(1);

int main() {
	//! Variable for dt.
	chrono::system_clock::time_point s, e;
	chrono::duration<double> dt;

	//! Variable for algolithm.
	long long ret;
	int T = TEST;

	//! Repeat {TEST} times.
	s = chrono::system_clock::now();
	while (T--)
	{
		for (int i = 85; i<120; i++)
		{
			printf("%d %lld \n", i, pado_iterative_queue(i));
		}
	}
	// printf("%lld\n", ret);
	e = chrono::system_clock::now();

	//! Print out dt.
	dt = e - s;
	cout << "dt : " << chrono::duration_cast<chrono::nanoseconds>(dt).count() / TEST << endl;

	stop
}