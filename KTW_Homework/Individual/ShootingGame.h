#pragma once

class Player;
class Bullet;
class ShootingGame
{
public:
	static const int BulletCount = 10;

	static void GameSetting();
	static void GameStart();

private:
	static Player NewPlayer;
	static Bullet ArrBullet[BulletCount];
};

