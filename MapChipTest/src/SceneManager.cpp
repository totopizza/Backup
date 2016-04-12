#include "SceneManager.h"

SceneManager::SceneManager()
{
	scene = new Title();

	sceneType = None_;
}

void SceneManager::Update(AppEnv& env)
{
	ChanageScene();

	if (env.isPushKey(GLFW_KEY_S)){
		sceneType = GameMain_;
	}

	scene->Update();
}

void SceneManager::Draw()
{
	scene->Draw();
}

void SceneManager::ChanageScene()
{
	switch (sceneType)
	{
	case Title_:
		delete scene;
		scene = new Title();
		sceneType = None_;
		break;
	case GameMain_:
		delete scene;
		scene = new GameMain();
		sceneType = None_;
		break;
	case None_:
		break;
	default:
		break;
	}
}

SceneBase *SceneManager::GetScene()
{
	return scene;
}