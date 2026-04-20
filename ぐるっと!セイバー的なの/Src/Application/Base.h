#pragma once

// 回転の中心座標
static constexpr float SCREEN_CX = 0.0f;
static constexpr float SCREEN_CY = -420.0f;

class C_Base
{
public:
	C_Base();
	virtual ~C_Base();

	virtual void Init();
	virtual void Update();
	virtual void Draw();

	Math::Vector2 GetPos()         const { return pos; }
	float         GetWorldAngle()  const { return worldAngle; }
	float         GetWorldRadius() const { return worldRadius; }
	bool          GetFlg()         const { return flg; }
	void          SetFlg(bool f)         { flg = f; }

protected:
	Math::Vector2 pos   = { 0.0f, 0.0f };
	Math::Color   color = { 1.0f, 1.0f, 1.0f, 1.0f };
	Math::Matrix  mat;

	float worldAngle  = 0.0f;
	float worldRadius = 0.0f;
	float moveSpeed   = 0.0f;
	bool  flg         = false;

	KdTexture tex;

	// cameraAngleを受け取ってpos・matを更新する
	void CalcScreenPos(float cameraAngle, float Scale);
};
