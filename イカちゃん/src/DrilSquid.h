#pragma once
#include "AppSetup.h"

#include "BabySquid.h"

class DrilSquid : public BabySquid
{
public:

	void Setup();

	void DataInit();

	void Update();

	void Draw();

	void SetIsActive(bool _TrueOrFalse);

	bool GetIsActive();

private:
	ObjectData data;

	Texture image;

};