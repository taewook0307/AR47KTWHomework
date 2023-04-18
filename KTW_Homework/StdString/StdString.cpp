#include <iostream>
#include <vector>

class MyString
{
private:
    std::vector<char> Buffer;
};

int main()
{
    // 문자가 사용되는 대표적 예시
    // 파일 입출력
    // 파일 경로를 표현할 때

    // 인코딩 : 멀티바이트, 와이드 바이트
    // 1바이트 인코딩 : 아스키 or ANSI

    // 1~2바이트 멀티 바이트 인코딩 <= 특정 한 국가의 문자정도는 표현이 가능
    // 2바이트 와이드 바이트
    // 2바이트 인코딩까지는 국가별로 달라지는 매칭형식

    // 3바이트 문자형 및 4바이트 문자형 : UTF 인코딩 시리즈들

    // wchar_t : 모든 문자가 2바이트

    // std::string은 vector 형태의 자료구조
    {
        // char
        std::string Text = "안녕하세요";

        std::cout << Text << std::endl;
    }

    {
        // 기본적으로 비쥬얼 스튜디오의 출력 국가 코드는 미국
        // 와이드 바이트는 국가코드에 영향을 받음
        
        setlocale(LC_ALL, "KOR");       // 국가코드를 바꿔주는 함수

        // wchar
        std::wstring WText = L"반갑습니다";

        std::wcout << WText << std::endl;
    }

    {
        std::string Text = "안녕하세요";

        // Text.replace()
        // Text.find()
        // Text.rfind()
        // Text.find_last_not_of()
        // Text.find_first_of()
        // Text.append()
        // 

    }
}
