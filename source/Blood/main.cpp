#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
#include <tchar.h>
#include <WinUser.h>
#include "main.h"
#include "CELLWinApp.h"

using namespace Blood;



int CALLBACK WinMain(
					__in HINSTANCE hInstance
					,__in_opt HINSTANCE hPrevInstance
					,__in_opt LPSTR IpCmdLine
					,__in int nShowCmd
					)
{
	CELLWINApp winApp;
	winApp.create("ÎÒµÄ´°¿Ú",400,300);
	winApp.main(0, 0);

	return 0;
}