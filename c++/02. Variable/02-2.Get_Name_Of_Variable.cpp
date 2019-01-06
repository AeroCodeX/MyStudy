#include <cstdio>
#define GetVariableName(var) #var // Result type is "const char*"
using namespace std;

int main() {
    int foo = 1;
    printf("%s %d", GetVariableName(foo), foo);

    return 0;
}