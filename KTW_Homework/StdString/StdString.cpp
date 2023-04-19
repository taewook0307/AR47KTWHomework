#include <iostream>
#include <vector>

class MyString
{
public:
    MyString(const char* _Text)
    {
        int i = 0;
        while (0 != _Text[i])
        {
            Buffer.push_back(_Text[i]);
            ++i;
        }
    }

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

    size_t find(char _Ch)
    {
        for (size_t i = 0; i < Buffer.size(); i++)
        {
            if (Buffer[i] == _Ch)
            {
                return i;
            }
        }
        return std::string::npos;
    }

    size_t rfind(char _Ch)
    {
        for (size_t i = Buffer.size() - 1; i >= 0; i--)
        {
            if (Buffer[i] == _Ch)
            {
                return i;
            }
        }
        return std::string::npos;
    }

    size_t find_first_not_of(char _Ch)
    {
        for (size_t i = 0; i < Buffer.size(); i++)
        {
            if (Buffer[i] == _Ch)
            {
                continue;
            }
            return i;
        }
    }

    size_t find_last_not_of(char _Ch)
    {
        for (size_t i = Buffer.size() - 1; i >= 0; i--)
        {
            if (Buffer[i] == _Ch)
            {
                continue;
            }
            return i;
        }
    }

    inline void replace(size_t _Start, size_t _End, const char* _Ch)
    {
        int Count = 0;

        while (0 != _Ch[Count])
        {
            ++Count;
        }

        size_t ChangeRange = _End - _Start;
        size_t NewSize = ChangeRange <= Count ? Count : ChangeRange;
        size_t LeftBuffer = Buffer.size() - ChangeRange;

        size_t NewBufferSize = NewSize + LeftBuffer;

        std::vector<char> NewBuffer;

        NewBuffer.reserve(NewBufferSize);

        for (size_t i = 0; i < _Start; i++)
        {
            NewBuffer.push_back(Buffer[i]);
        }
        for (size_t i = 0; i < Count; i++)
        {
            NewBuffer.push_back(_Ch[i]);
        }
        for (size_t i = _End; i < Buffer.size(); i++)
        {
            NewBuffer.push_back(Buffer[i]);
        }

        NewBuffer.push_back(0);

        Buffer = NewBuffer;

        return;
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
        Text.find() : 해당 원소가 앞에서부터 확인하여 몇번 인덱스에 있는지 확인
        Text.rfind() : 해당 원소가 뒤에서부터 확인하여 몇번 인덱스에 있는지 확인
        Text.find_last_not_of() : 해당 원소가 앞에서부터 몇번째까지 있는지 확인
        Text.find_first_of() : 해당 원소가 뒤에서부터 몇번째까지 있는지 확인
        Text.append()*/            // 찾는 값이 없을 경우 string::npos를 반환

        std::cout << "a : " << Text.find('a') << std::endl;
        std::cout << "b : " << Text.find('b') << std::endl;
        std::cout << "c : " << Text.find('c') << std::endl;
        std::cout << "d : " << Text.find('d') << std::endl;
        std::cout << "z : " << Text.find('z') << std::endl;

        size_t Value_R = Text.rfind('c');

        std::cout << "Value_R : " << Value_R << std::endl;

        std::string NumText = "00012333";
        std::string NumText2 = "112509000000";
        std::string NumText3 = "33349899999";
        std::string NumText4 = "9999982811";

        std::cout << "NumText.find_first_not_of('0')의 결과 : " << NumText.find_first_not_of('0') << std::endl;
        std::cout << "NumText.find_first_not_of('1')의 결과 : " << NumText.find_first_not_of('1') << std::endl;
        std::cout << "NumText.find_first_not_of('3')의 결과 : " << NumText.find_first_not_of('3') << std::endl;
        std::cout << "NumText.find_first_not_of('9')의 결과 : " << NumText.find_first_not_of('9') << std::endl << std::endl;
        std::cout << "NumText2.find_first_not_of('0')의 결과 : " << NumText2.find_first_not_of('0') << std::endl;
        std::cout << "NumText2.find_first_not_of('1')의 결과 : " << NumText2.find_first_not_of('1') << std::endl;
        std::cout << "NumText2.find_first_not_of('3')의 결과 : " << NumText2.find_first_not_of('3') << std::endl;
        std::cout << "NumText2.find_first_not_of('9')의 결과 : " << NumText2.find_first_not_of('9') << std::endl << std::endl;
        std::cout << "NumText3.find_first_not_of('0')의 결과 : " << NumText3.find_first_not_of('0') << std::endl;
        std::cout << "NumText3.find_first_not_of('1')의 결과 : " << NumText3.find_first_not_of('1') << std::endl;
        std::cout << "NumText3.find_first_not_of('3')의 결과 : " << NumText3.find_first_not_of('3') << std::endl;
        std::cout << "NumText3.find_first_not_of('9')의 결과 : " << NumText3.find_first_not_of('9') << std::endl << std::endl;
        std::cout << "NumText4.find_first_not_of('0')의 결과 : " << NumText4.find_first_not_of('0') << std::endl;
        std::cout << "NumText4.find_first_not_of('1')의 결과 : " << NumText4.find_first_not_of('1') << std::endl;
        std::cout << "NumText4.find_first_not_of('3')의 결과 : " << NumText4.find_first_not_of('3') << std::endl;
        std::cout << "NumText4.find_first_not_of('9')의 결과 : " << NumText4.find_first_not_of('9') << std::endl << std::endl;

        std::cout << "NumText.find_last_not_of('0')의 결과 : " << NumText.find_last_not_of('0') << std::endl;
        std::cout << "NumText.find_last_not_of('1')의 결과 : " << NumText.find_last_not_of('1') << std::endl;
        std::cout << "NumText.find_last_not_of('3')의 결과 : " << NumText.find_last_not_of('3') << std::endl;
        std::cout << "NumText.find_last_not_of('9')의 결과 : " << NumText.find_last_not_of('9') << std::endl << std::endl;
        std::cout << "NumText2.find_last_not_of('0')의 결과 : " << NumText2.find_last_not_of('0') << std::endl;
        std::cout << "NumText2.find_last_not_of('1')의 결과 : " << NumText2.find_last_not_of('1') << std::endl;
        std::cout << "NumText2.find_last_not_of('3')의 결과 : " << NumText2.find_last_not_of('3') << std::endl;
        std::cout << "NumText2.find_last_not_of('9')의 결과 : " << NumText2.find_last_not_of('9') << std::endl << std::endl;
        std::cout << "NumText3.find_last_not_of('0')의 결과 : " << NumText3.find_last_not_of('0') << std::endl;
        std::cout << "NumText3.find_last_not_of('1')의 결과 : " << NumText3.find_last_not_of('1') << std::endl;
        std::cout << "NumText3.find_last_not_of('3')의 결과 : " << NumText3.find_last_not_of('3') << std::endl;
        std::cout << "NumText3.find_last_not_of('9')의 결과 : " << NumText3.find_last_not_of('9') << std::endl << std::endl;
        std::cout << "NumText4.find_last_not_of('0')의 결과 : " << NumText4.find_last_not_of('0') << std::endl;
        std::cout << "NumText4.find_last_not_of('1')의 결과 : " << NumText4.find_last_not_of('1') << std::endl;
        std::cout << "NumText4.find_last_not_of('3')의 결과 : " << NumText4.find_last_not_of('3') << std::endl;
        std::cout << "NumText4.find_last_not_of('9')의 결과 : " << NumText4.find_last_not_of('9') << std::endl << std::endl;
    }

    {
        MyString MyText = MyString("abcdefg");

        // find : 해당 원소가 앞에서부터 확인하여 몇번 인덱스에 있는지 확인
        std::cout << "a : " << MyText.find('a') << std::endl;
        std::cout << "b : " << MyText.find('b') << std::endl;
        std::cout << "c : " << MyText.find('c') << std::endl;
        std::cout << "d : " << MyText.find('d') << std::endl;
        std::cout << "z : " << MyText.find('z') << std::endl;

        // rfind : 해당 원소가 뒤에서부터 확인하여 몇번 인덱스에 있는지 확인
        size_t Value_R = MyText.rfind('c');

        std::cout << "Value_R : " << Value_R << std::endl;

        MyString NumText = MyString("00012333");
        MyString NumText2 = MyString("112509000000");
        MyString NumText3 = MyString("33349899999");
        MyString NumText4 = MyString("9999982811");

        // find_first_not_of : 해당 원소가 앞에서부터 몇번째까지 있는지 확인
        std::cout << "NumText.find_first_not_of('0')의 결과 : " << NumText.find_first_not_of('0') << std::endl;
        std::cout << "NumText.find_first_not_of('1')의 결과 : " << NumText.find_first_not_of('1') << std::endl;
        std::cout << "NumText.find_first_not_of('3')의 결과 : " << NumText.find_first_not_of('3') << std::endl;
        std::cout << "NumText.find_first_not_of('9')의 결과 : " << NumText.find_first_not_of('9') << std::endl << std::endl;
        std::cout << "NumText2.find_first_not_of('0')의 결과 : " << NumText2.find_first_not_of('0') << std::endl;
        std::cout << "NumText2.find_first_not_of('1')의 결과 : " << NumText2.find_first_not_of('1') << std::endl;
        std::cout << "NumText2.find_first_not_of('3')의 결과 : " << NumText2.find_first_not_of('3') << std::endl;
        std::cout << "NumText2.find_first_not_of('9')의 결과 : " << NumText2.find_first_not_of('9') << std::endl << std::endl;
        std::cout << "NumText3.find_first_not_of('0')의 결과 : " << NumText3.find_first_not_of('0') << std::endl;
        std::cout << "NumText3.find_first_not_of('1')의 결과 : " << NumText3.find_first_not_of('1') << std::endl;
        std::cout << "NumText3.find_first_not_of('3')의 결과 : " << NumText3.find_first_not_of('3') << std::endl;
        std::cout << "NumText3.find_first_not_of('9')의 결과 : " << NumText3.find_first_not_of('9') << std::endl << std::endl;
        std::cout << "NumText4.find_first_not_of('0')의 결과 : " << NumText4.find_first_not_of('0') << std::endl;
        std::cout << "NumText4.find_first_not_of('1')의 결과 : " << NumText4.find_first_not_of('1') << std::endl;
        std::cout << "NumText4.find_first_not_of('3')의 결과 : " << NumText4.find_first_not_of('3') << std::endl;
        std::cout << "NumText4.find_first_not_of('9')의 결과 : " << NumText4.find_first_not_of('9') << std::endl << std::endl;

        // find_first_not_of : 해당 원소가 뒤에서부터 몇번째까지 있는지 확인
        std::cout << "NumText.find_last_not_of('0')의 결과 : " << NumText.find_last_not_of('0') << std::endl;
        std::cout << "NumText.find_last_not_of('1')의 결과 : " << NumText.find_last_not_of('1') << std::endl;
        std::cout << "NumText.find_last_not_of('3')의 결과 : " << NumText.find_last_not_of('3') << std::endl;
        std::cout << "NumText.find_last_not_of('9')의 결과 : " << NumText.find_last_not_of('9') << std::endl << std::endl;
        std::cout << "NumText2.find_last_not_of('0')의 결과 : " << NumText2.find_last_not_of('0') << std::endl;
        std::cout << "NumText2.find_last_not_of('1')의 결과 : " << NumText2.find_last_not_of('1') << std::endl;
        std::cout << "NumText2.find_last_not_of('3')의 결과 : " << NumText2.find_last_not_of('3') << std::endl;
        std::cout << "NumText2.find_last_not_of('9')의 결과 : " << NumText2.find_last_not_of('9') << std::endl << std::endl;
        std::cout << "NumText3.find_last_not_of('0')의 결과 : " << NumText3.find_last_not_of('0') << std::endl;
        std::cout << "NumText3.find_last_not_of('1')의 결과 : " << NumText3.find_last_not_of('1') << std::endl;
        std::cout << "NumText3.find_last_not_of('3')의 결과 : " << NumText3.find_last_not_of('3') << std::endl;
        std::cout << "NumText3.find_last_not_of('9')의 결과 : " << NumText3.find_last_not_of('9') << std::endl << std::endl;
        std::cout << "NumText4.find_last_not_of('0')의 결과 : " << NumText4.find_last_not_of('0') << std::endl;
        std::cout << "NumText4.find_last_not_of('1')의 결과 : " << NumText4.find_last_not_of('1') << std::endl;
        std::cout << "NumText4.find_last_not_of('3')의 결과 : " << NumText4.find_last_not_of('3') << std::endl;
        std::cout << "NumText4.find_last_not_of('9')의 결과 : " << NumText4.find_last_not_of('9') << std::endl << std::endl;
    }

    {
        std::string Text = "Hello World";
        Text.replace(0, 3, "GoodBye");

        std::cout << "Text : " << Text << std::endl;

        MyString MyText = MyString("Hello World");

        MyText.replace(0, 3, "GoodBye");

        int a = 0;
    }
}
