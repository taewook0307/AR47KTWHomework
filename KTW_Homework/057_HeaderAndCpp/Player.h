#pragma once		// �� cpp ���� ���� ��� �ߺ� ���� (�� �ٸ� cpp ���� �� �ִ� ��� �ߺ��� �ذ� �Ұ�)

// ��� �ߺ��� �����ϴ� �͵� ������ �ð�
// �ִ��� ����� ���� �ʿ��� �͸� include

class Player
{
public:
	Player();
	void Damage(int _Damage);

	// �����Ϸ��� ���� ���Ѵ�.
	void Test();

private:
	int Hp = 100;
	int Att = 10;
};