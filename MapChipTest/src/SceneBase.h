#pragma once
#include "lib\framework.hpp"

class SceneBase
{
public:

	virtual ~SceneBase(){}

	virtual void Update(){}

	virtual void Draw(){}
};