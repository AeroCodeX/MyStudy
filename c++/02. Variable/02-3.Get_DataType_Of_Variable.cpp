#include <cstdio>
#include <typeinfo>
using namespace std;

int main() {
    int foo = 1;
    const char* typeName = typeid(foo).name();
    printf("%s %d", typeName, foo);

    return 0;
}