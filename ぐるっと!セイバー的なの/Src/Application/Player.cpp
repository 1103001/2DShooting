#include "Player.h"

C_Player::C_Player() {}
C_Player::~C_Player() { tex.Release(); }

void C_Player::Init()
{
	C_Base::Init();
	tex.Load("Texture/Player.png");
	// Player‚Íí‚É‰æ–Ê’†‰›ŒÅ’è
	worldRadius = 0.0f;
	flg         = true;
}

void C_Player::Release()
{
	tex.Release();
}

void C_Player::Update()
{
	if (!flg) return;

	// Player‚Íí‚É‰æ–Ê’†‰›‚É•`‰æ
	pos = { SCREEN_CX, SCREEN_CY };
	mat = Math::Matrix::CreateTranslation(pos.x, pos.y + 195, 0.0f);

	// Œã‚ÅƒVƒ‡ƒbƒgˆ—‚È‚Ç‚ğ‚±‚±‚É’Ç‰Á
}

void C_Player::Draw()
{
	if (!flg) return;
	SHADER.m_spriteShader.SetMatrix(mat);
	SHADER.m_spriteShader.DrawTex(&tex, Math::Rectangle{ 0, 0, PlayerCuttingRange, PlayerCuttingRange }, 1.0f);
}
