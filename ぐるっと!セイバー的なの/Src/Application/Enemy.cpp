#include "Enemy.h"

C_Enemy::C_Enemy() {}
C_Enemy::~C_Enemy() { tex.Release(); }

void C_Enemy::Init(float startAngle)
{
	C_Base::Init();
	tex.Load("Texture/Enemy.png");
	worldAngle  = startAngle;
	worldRadius = SPAWN_RADIUS; // 外周からスタート
	flg         = true;

	CalcScreenPos(0.0f, 1.0f);
}

void C_Enemy::Release()
{
	tex.Release();
}

void C_Enemy::Update(float cameraAngle,float Size)
{
	if (!flg) return;

	worldRadius -= FALL_SPEED;

	// 母船(中心付近)に到達したら消える
	if (worldRadius <= 200.0f)
	{
		flg = false;
		return;
	}

	Size = 1.0f;

	CalcScreenPos(cameraAngle,Size);
}

void C_Enemy::Draw()
{
	if (!flg) return;
	SHADER.m_spriteShader.SetMatrix(mat);
	SHADER.m_spriteShader.DrawTex(&tex, Math::Rectangle{ 0, 0, EnemyCuttingRange, EnemyCuttingRange }, 1.0f);
}
