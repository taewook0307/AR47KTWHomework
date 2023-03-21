/* GlobalValue가 코드 아래 선언되었기 때문에 사용불가
void Test0()
{
	GlobalValue++;
}
*/

// 전역 변수 : 어떠한 지역에도 속하지 않는 변수
// (이름이 있는 함수나 그 외부에 있는 변수)
int GlobalValue = 0;
// 전역변수가 선언된 코드 위치 아래부터 어디서든 사용가능

void Test()
{
	GlobalValue++;
}

int main()
{	// 지역(스코프)의 시작
	int Value = 0;	// 지역 변수
}   // 지역(스코프)의 끝