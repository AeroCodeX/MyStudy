#ifndef __CHRONO_TIMER__
#define __CHRONO_TIMER__
#include <chrono>
using namespace std;
class Timer{
private:
	chrono::system_clock::time_point s;
	chrono::system_clock::time_point e;
public:
	void start() { s = chrono::system_clock::now(); }
	void end  () { e = chrono::system_clock::now(); }
	double result() { return chrono::duration<double>(e - s).count(); }
};
#endif