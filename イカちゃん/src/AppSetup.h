#pragma once
#include "lib\framework.hpp"

// このヘッダをincludeすれば
// 先生のライブラリの機能をどこでも使えるようにしている
// デザインパターン　シングルトン

#define WINDOW_WIDTH		(1024)
#define WINDOW_HEIGHT		(1664)
#define IS_FULL_SCREEN		(false)
#define ENABLE_WINDOW_SIZE	(true)

class App
{
public:
	static AppEnv& Get();

private:
	App();
};