#pragma once
#include "AppSetup.h"

#include "Utility.h"

class Food
{
public:

	void Setup();
	// ObjectData�^������������֐�
	void DataInit();

	void IntInit();

	void BoolInit();

	void Update();

	void Draw();
	// int�^createTimer�ݒ�(�b)
	void SetCreateTimer(int _Value);
	// bool�^isCreate�ݒ�
	void SetIsCreate(bool _TrueOrFalse);

	void IsCrick(bool _isCrick);
	// ���������邩�𔻒f���Ă���֐�
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