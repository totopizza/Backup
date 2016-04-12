#pragma once
#include "lib\framework.hpp"
#include "Utility.h"

#include "SceneBase.h"
#include "Title.h"
#include "GameMain.h"

class SceneManager
{
private:
	SceneBase* scene;

public:

	SceneManager();

	void Update(AppEnv& env);

	void Draw();

	void ChanageScene();

	SceneBase *GetScene();
};