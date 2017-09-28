#include "main.h"

int main()
{
	command_app_initialize->execute();
	return 0;
}

int _stdcall WinMain(void* ci, void* pi, char* cmd, int sw)
{
	return main();
}