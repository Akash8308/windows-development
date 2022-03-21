#include <Windows.h>

BOOL WINAPI DllMain(HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved)
{
	//Code

	switch (dwReason)
	{

	case DLL_PROCESS_ATTACH:
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		break;

	default:
		break;

	}

	return TRUE;


}


extern "C" __declspec(dllexport) int MakeCube(int num)
{
	//Code

	int cube = num * num * num;

	return cube;

}

