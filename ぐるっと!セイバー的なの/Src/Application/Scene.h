#pragma once
#include "StageA.h"

class Scene
{
public:
	// ‰Šúİ’è
	void Init();
	// ‰ğ•ú
	void Release();
	// XVˆ—
	void Update();
	// •`‰æˆ—
	void Draw2D();
	// GUIˆ—
	void ImGuiUpdate();

private:
	C_StageA m_stageA;

	Scene() {}

public:
	static Scene& GetInstance()
	{
		static Scene instance;
		return instance;
	}
};

#define SCENE Scene::GetInstance()
