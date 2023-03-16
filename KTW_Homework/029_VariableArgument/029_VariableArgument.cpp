#include <iostream>

void VarFunction(...)
{

}

void TestFunction2(int _1, ...)
{

}

int main()
{
    VarFunction(2, 3, 4, 5);

    VarFunction("1", "1", "1", "1", "1");

    VarFunction("1", 1, 2);
}
