#include "main.h"
#include "Scene.h"

void Scene::Init()
{
	m_stageA.Init();
}

void Scene::Release()
{
	m_stageA.Release();
}

void Scene::Update()
{
	m_stageA.Update();
}

void Scene::Draw2D()
{
	m_stageA.Draw();
}

void Scene::ImGuiUpdate()
{
	ImGui::SetNextWindowPos(ImVec2(20, 20), ImGuiSetCond_Once);
	ImGui::SetNextWindowSize(ImVec2(200, 100), ImGuiSetCond_Once);

	if (ImGui::Begin("Debug Window"))
	{
		ImGui::Text("FPS : %d", APP.m_fps);
	}
	ImGui::End();
}
