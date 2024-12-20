#include <windows.h>
#include "engine/application/application.hpp"

#ifdef WIN32
// ReSharper disable CppParameterNamesMismatch
int WINAPI wWinMain(HINSTANCE h_instance, HINSTANCE h_prev_instance, PWSTR p_cmd_line, int n_cmd_show)
#else
int main()
#endif
{
	emare::application app;
	app.initialize();
	return app.run();
}