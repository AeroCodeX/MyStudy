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
	bool *map;
	int T = TEST;

	//! Repeat {TEST} times.
	s = chrono::system_clock::now();
	while (T--)
	{
		map = generate_prime_eratos_improved();
	}
	e = chrono::system_clock::now();

	//! Print out dt.
	dt = e - s;
	cout << "dt : " << chrono::duration_cast<chrono::milliseconds>(dt).count() / TEST << endl;
	
	// wait...
	while (1);
}