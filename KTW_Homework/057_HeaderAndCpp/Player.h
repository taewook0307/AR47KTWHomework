#pragma once		// 한 cpp 파일 내의 헤더 중복 제거 (단 다른 cpp 파일 내 있는 헤더 중복은 해결 불가)

// 헤더 중복을 제거하는 것도 컴파일 시간
// 최대한 헤더는 정말 필요한 것만 include

class Player
{
public:
	Player();
	void Damage(int _Damage);

	// 컴파일러가 빌드 안한다.
	void Test();

private:
	int Hp = 100;
	int Att = 10;
};