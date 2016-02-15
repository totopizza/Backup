#pragma once
#include "AppSetup.h"

class SceneBase
{
public:
	SceneBase(){}

	virtual ~SceneBase(){}

	virtual void Setup(){}

	virtual void Upate(){}

	virtual void Draw(){}

};