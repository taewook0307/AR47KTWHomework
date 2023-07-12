// 091_String_view.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Player {

};

// 레퍼런스를 붙이는 이유 => 복사 비용을 져렴하게 하기 위해서 : 속력
// const 를 붙이는 이유 => 함수안에 니가 넣어준 인자가 변형되지 않을 것이라는 의도를 표현 : 의도
void Function(const Player& _Data)
{

}

void StringFunction(const std::string& Value)
{
	// std::string을 통해 넘겨줄 경우 힙 메모리에서 동적할당이 일어나게 됨
}

void StringPtrFunction(const char* Value)
{

}


int main()
{
	StringFunction("aaaaaaaaaa");
}