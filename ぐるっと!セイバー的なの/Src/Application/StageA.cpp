#include "StageA.h"

void C_StageA::Init()
{
	cameraAngle  = 0.0f;
	m_spawnTimer = 0;

	m_player = new C_Player();
	m_player->Init();

	m_tower = new C_Tower();
	m_tower->Init(0.0f);
}

void C_StageA::Release()
{
	if (m_player) { m_player->Release(); delete m_player; m_player = nullptr; }
	if (m_tower)  { m_tower->Release();  delete m_tower;  m_tower  = nullptr; }

	for (auto* e : m_enemies)
	{
		e->Release();
		delete e;
	}
	m_enemies.clear();
}

void C_StageA::Update()
{
	// 左右キーでワールドを回転
	if (GetAsyncKeyState(VK_LEFT)  & 0x8000) cameraAngle -= ROT_SPEED;
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000) cameraAngle += ROT_SPEED;

	// 各オブジェクト更新-
	if (m_player) m_player->Update();
	if (m_tower)  m_tower->Update(cameraAngle, 1.0f);

	for (auto* e : m_enemies) e->Update(cameraAngle, 1.0f);

	// 死んだ敵を除去
	for (auto it = m_enemies.begin(); it != m_enemies.end(); )
	{
		if (!(*it)->GetFlg())
		{
			(*it)->Release();
			delete *it;
			it = m_enemies.erase(it);
		}
		else
		{
			++it;
		}
	}


	// スポーン
	m_spawnTimer++;
	if (m_spawnTimer >= SPAWN_INTERVAL)
	{
		m_spawnTimer = 0;
		C_Enemy* e = new C_Enemy();

		// π/2 = 画面の真上
		// cameraAngleを引くことで、カメラがどこを向いていても
		// 常に画面の真上から出てくる
		e->Init(3.14159f / 2.0f - cameraAngle);
		m_enemies.push_back(e);
	}
}

void C_StageA::Draw()
{
	if (m_tower)  m_tower->Draw();
	for (auto* e : m_enemies) e->Draw();
	if (m_player) m_player->Draw();
}
