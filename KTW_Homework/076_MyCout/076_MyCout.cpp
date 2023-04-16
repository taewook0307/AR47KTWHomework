#include <iostream>

class MyEndl
{
};

class MyCout
{
public:
    void operator<<(const MyEndl& _Value)
    {
        printf_s("\n");
    }

    MyCout& operator<<(const char* _Text)
    {
        printf_s(_Text);

        return *this;
    }
};

namespace std
{
    MyEndl MEndl;
    MyCout MCout;
}


int main()
{
    std::MCout.operator<<("Hello World!").operator<<(std::MEndl);

    std::cout.operator<<("Hello World!").operator<<(std::endl);

    // std::cout << "Hello World!\n";
}