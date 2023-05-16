#include <iostream>

class Test
{
public:
    explicit Test(int Value)
    {

    }

    void TestFunction()
    {
        std::cout << "Test Function" << std::endl;
    }
};

int main()
{
    // Test NewTest = 10;           explicit이 걸어져 있어 약식으로 생성자를 호출하지 못 함
    Test NewTest = Test(10);

    NewTest.TestFunction();
}