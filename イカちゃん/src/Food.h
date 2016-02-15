#pragma once
#include "AppSetup.h"

#include "Utility.h"

class Food
{
public:

	void Setup();
	// ObjectDataŒ^‚ğ‰Šú‰»‚·‚éŠÖ”
	void DataInit();

	void IntInit();

	void BoolInit();

	void Update();

	void Draw();
	// intŒ^createTimerİ’è(•b)
	void SetCreateTimer(int _Value);
	// boolŒ^isCreateİ’è
	void SetIsCreate(bool _TrueOrFalse);

	void IsCrick(bool _isCrick);
	// ‚¢‚Â¶¬‚·‚é‚©‚ğ”»’f‚µ‚Ä‚¢‚éŠÖ”
	void Create();

	ObjectData GetData();

	bool GetIsCreate();

private:
	Texture image;

	ObjectData data;

	Random random;

	int createTimer;

	bool isCreate;

	bool isCrick;


};