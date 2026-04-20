#include "Tower.h"

C_Tower::C_Tower() {}
C_Tower::~C_Tower() { tex.Release(); }

void C_Tower::Init(float startAngle)
{
	C_Base::Init();
	tex.Load("Texture/Tower.png");
	worldAngle = startAngle;
	worldRadius = 0.0f;  // •ê‘D‚Í‰æ–Ê’†‰›ŒÅ’è
	moveSpeed   = 0.0f;
	flg         = true;
}

void C_Tower::Release()
{
	tex.Release();
}

void C_Tower::Update(float cameraAngle,float Scale)
{
	if (!flg) return;

	Scale = TowerSize;

	CalcScreenPos(cameraAngle,Scale);
}

void C_Tower::Draw()
{
	if (!flg) return;
	SHADER.m_spriteShader.SetMatrix(mat);
	SHADER.m_spriteShader.DrawTex(&tex, Math::Rectangle{ 0, 0, TowerCuttingRange, TowerCuttingRange }, 1.0f);
}
