#include "Base.h"
#include <cmath>

C_Base::C_Base() {}

C_Base::~C_Base()
{
	tex.Release();
}

void C_Base::Init()
{
	pos         = { 0.0f, 0.0f };
	color       = { 1.0f, 1.0f, 1.0f, 1.0f };
	worldAngle  = 0.0f;
	worldRadius = 0.0f;
	moveSpeed   = 0.0f;
	flg         = false;
}

void C_Base::Update() {}
void C_Base::Draw()   {}

void C_Base::CalcScreenPos(float cameraAngle, float Scale)
{
	float a = worldAngle + cameraAngle;
	// 画面中央を原点として計算
	pos.x = SCREEN_CX + cosf(a) * worldRadius;
	pos.y = SCREEN_CY + sinf(a) * worldRadius;

	// 中心方向を向く角度を計算（中心 - 自分の位置 の方向）
	float dirX = SCREEN_CX - pos.x;
	float dirY = SCREEN_CY - pos.y;
	float facingAngle = atan2f(dirY, dirX);

	// 角度込みの行列を作成
	Math::Matrix trans = Math::Matrix::CreateTranslation(pos.x, pos.y, 0.0f);
	Math::Matrix rotate = Math::Matrix::CreateRotationZ(facingAngle);
	Math::Matrix scale = Math::Matrix::CreateScale(Scale, Scale, 1.0f);
	mat = scale * rotate * trans;
}
