#include <cstdio>
#include <string>
using namespace std;

int main() {
    long long w = 36762444129608L;
    string s = (const char*)&w;
    printf("%s\n", s.data());
}

