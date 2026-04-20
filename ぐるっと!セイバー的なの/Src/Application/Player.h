#pragma once
#include "Base.h"

class C_Player : public C_Base
{
public:
	C_Player();
	~C_Player();

	void Init();
	void Release();
	void Update();   // Player‚ÍƒJƒƒ‰‚ÉˆË‘¶‚µ‚È‚¢ií‚É’†‰›ŒÅ’èj
	void Draw();

private:

	float PlayerSize = 1.0f;
	int PlayerCuttingRange = 32;

};
