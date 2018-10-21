#include <iostream>
using namespace std;

int T;
int from, to;
long long len, sum, top, ret;

int main() {
	cin >> T;
	while (T--) {
		cin >> from >> to;
		len = to - from;
		sum = top = 0;
		while (true) {
			if (len <= sum + top) {
				ret = top * 2 - 1;
				break;
			}
			if (len <= sum + top + top) {
				ret = top * 2;
				break;
			}
			sum += top + top;
			top++;
		}
		cout << ret << endl;
	}
}