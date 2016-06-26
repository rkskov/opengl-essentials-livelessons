#include "pch.h"

using namespace Library;
using namespace Rendering;

int WINAPI WinMain(HINSTANCE instance, HINSTANCE previousInstance, LPSTR commandLine, int showCommand)
{
	UNREFERENCED_PARAMETER(instance);
	UNREFERENCED_PARAMETER(previousInstance);
	UNREFERENCED_PARAMETER(commandLine);
	UNREFERENCED_PARAMETER(showCommand);

#if defined(DEBUG) | defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	RenderingGame game(instance, L"OpenGL Essentials");

	try
	{
		game.Run();
	}
	catch (GameException ex)
	{
		MessageBox(game.WindowHandle(), ex.whatw().c_str(), game.WindowTitle().c_str(), MB_ABORTRETRYIGNORE);
	}

	return 0;
}