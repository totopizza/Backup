#pragma once
#include "AppSetup.h"

#include "Utility.h"

class Food
{
public:

	void Setup();
	// ObjectData型を初期化する関数
	void DataInit();

	void IntInit();

	void BoolInit();

	void Update();

	void Draw();
	// int型createTimer設定(秒)
	void SetCreateTimer(int _Value);
	// bool型isCreate設定
	void SetIsCreate(bool _TrueOrFalse);

	void IsCrick(bool _isCrick);
	// いつ生成するかを判断している関数
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