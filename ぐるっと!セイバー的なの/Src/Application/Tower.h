#pragma once
#include "Base.h"

class C_Tower : public C_Base
{
public:

	C_Tower();
	~C_Tower();

	void Init(float startAngle);
	void Release();
	void Update(float cameraAngle,float Size);
	void Draw();

private:

	float TowerSize = 12.0f;
	int TowerCuttingRange = 32;

};
