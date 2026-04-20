#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Tower.h"

class C_StageA
{
public:
	void Init();
	void Release();
	void Update();
	void Draw();

private:
	float cameraAngle = 0.0f;
	static constexpr float ROT_SPEED      = 0.05f; // 回転速度
	static constexpr int   SPAWN_INTERVAL = 20;   // スポーン間隔

	C_Player* m_player = nullptr;
	C_Tower*  m_tower  = nullptr;
	std::vector<C_Enemy*> m_enemies;

	int m_spawnTimer = 0;
};
