#pragma once
#include "AppSetup.h"
#include <memory>

#include "Character.h"

#include "BabySquid.h"
#include "DrilSquid.h"

class CharacterManager
{
public:

	void Setup();

	void Update();

private:
	std::shared_ptr<Character> charaBase;


};