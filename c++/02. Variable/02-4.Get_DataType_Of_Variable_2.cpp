#include <cstdio>
#include <typeinfo>
#define GetVariableName(var) #var // Result type is "const char*"
using namespace std;

template <typename Any>
const char* GetVariableType(Any var)
{
    if(typeid(var) == typeid(int))
    {
        return "int";
    }
    else if(typeid(var) == typeid(int*))
    {
        return "int*";
    }
    else
    {
        return nullptr;
    }
}


int main() {
    int  integer = 1;
    int* p_integer = &integer;
    printf("type of {%9s} is %s \n", GetVariableName(integer), GetVariableType(integer));
    printf("type of {%9s} is %s \n", GetVariableName(p_integer), GetVariableType(p_integer));
}

