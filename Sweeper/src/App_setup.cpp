#include "App_setup.h"

AppEnv& App::get()
{
	// �E�B���h�E�̐ݒ�
	static AppEnv s_env(WINDOW_WIDTH, WINDOW_HEIGHT,
		IS_FULL_SCREEN, ENABLE_WINDOW_SIZE);

	return s_env;

}