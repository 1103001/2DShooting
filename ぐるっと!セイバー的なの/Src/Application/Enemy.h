#pragma once
#include "Base.h"

class C_Enemy : public C_Base
{
public:
	C_Enemy();
	~C_Enemy();

	void Init(float startAngle);
	void Release();
	void Update(float cameraAngle, float Size);
	void Draw();

private:

	static constexpr float SPAWN_RADIUS = 800.0f; // 外周スポーン距離
	static constexpr float FALL_SPEED   = 5.0f;   // 中心への落下速度(px/frame)

	float EnemySize = 1.0f;
	int EnemyCuttingRange = 32;

};
