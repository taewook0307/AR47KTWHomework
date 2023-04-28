#include <iostream>

void Function(int _Value = 50)
{
    std::cout << _Value << std::endl;
}

// 주의해야할 점
// 디폴트 인자는 무조건 인자의 가장 오른쪽부터 만들 수 있음

// 함수 오버로딩 시 호출할 때 어느것을 호출 해야하는지 애매해짐
void Function(int _Value, int _Test = 50)
{
    std::cout << _Value << std::endl;
    std::cout << _Test << std::endl;
}

int main()
{
    Function();     // 자동으로 _Value의 값에 50이 대입됨
    Function();
    Function();
    Function();
    Function();
    Function(20, 10);
    // Function(20); => _Value만 가지고 있는 Fucntion을 호출할지 _Value와 _Test를 가진 Function을 호출할지 알 수 없음
}