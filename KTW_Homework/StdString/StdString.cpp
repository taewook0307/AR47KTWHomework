#include <iostream>
#include <vector>

class MyString
{
public:
    void operator+(const MyString& _Other)
    {
        std::vector<char> NewBuffer;

        NewBuffer.reserve(Buffer.size() + _Other.Buffer.size());

        for (size_t i = 0; i < Buffer.size(); i++)
        {
            NewBuffer.push_back(Buffer[i]);
        }

        for (size_t i = 0; i < _Other.Buffer.size(); i++)
        {
            NewBuffer.push_back(_Other.Buffer[i]);
        }

        Buffer = NewBuffer;
    }

    MyString(const char* _Text)
    {
        int i = 0;
        while (0 != _Text[i])
        {
            Buffer.push_back(_Text[i]);
        }
    }

    int find(char _Ch)
    {
        for (int i = 0; i < Buffer.size(); i++)
        {
            if (Buffer[i] == _Ch)
            {
                return i;
            }
        }
        return static_cast<int>(std::string::npos);
    }

    int rfind(char _Ch)
    {
        for (int i = Buffer.size() - 1; i >= 0; i--)
        {
            if (Buffer[i] == _Ch)
            {
                return i;
            }
        }
        return static_cast<int>(std::string::npos);
    }

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
    //{
    //    // char
    //    std::string Text = "안녕하세요";

    //    std::cout << Text << std::endl;
    //}

    //{
    //    // 기본적으로 비쥬얼 스튜디오의 출력 국가 코드는 미국
    //    // 와이드 바이트는 국가코드에 영향을 받음
    //    
    //    setlocale(LC_ALL, "KOR");       // 국가코드를 바꿔주는 함수

    //    // wchar
    //    std::wstring WText = L"반갑습니다";

    //    std::wcout << WText << std::endl;
    //}

    {
        std::string Text = "abcdefg";

         /*Text.replace()
         Text.find()
         Text.rfind()
         Text.find_last_not_of()
         Text.find_first_of()
         Text.append() */            // 찾는 값이 없을 경우 string::npos를 반환

        std::cout << "a : " << Text.find('a') << std::endl;
        std::cout << "b : " << Text.find('b') << std::endl;
        std::cout << "c : " << Text.find('c') << std::endl;
        std::cout << "d : " << Text.find('d') << std::endl;
        std::cout << "z : " << Text.find('z') << std::endl;

        int Value_R = Text.rfind('k');

        std::cout << "Value_R : " << Value_R << std::endl;
    }
}
