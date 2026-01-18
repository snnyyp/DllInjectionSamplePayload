#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#ifdef MSGBOX
const DWORD MSGBOX_DELAY = 5 * 1000;
#endif

int WINAPI MessageBoxTimeoutW(IN HWND hWnd, IN LPCWSTR lpText, IN LPCWSTR lpCaption, IN UINT uType,
                              IN WORD wLanguageId,IN DWORD dwMilliseconds);

BOOL APIENTRY DllMain(HMODULE hModule,
                      DWORD ul_reason_for_call,
                      LPVOID lpReserved
)
{
	if (ul_reason_for_call == DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(hModule);

#ifdef MSGBOX
		MessageBoxW(0, L"Process attached.", L"Dll Injection Sample Payload V1",
		            MB_OK | MB_ICONINFORMATION | MB_SYSTEMMODAL);
#else
		OutputDebugStringW(L"Dll Injection Sample Payload V1: Process attached.");
#endif
	}
	else if (ul_reason_for_call == DLL_PROCESS_DETACH)
	{
#ifdef MSGBOX
		MessageBoxTimeoutW(0, L"Process detached.", L"Dll Injection Sample Payload V1",
		                   MB_OK | MB_ICONINFORMATION | MB_SYSTEMMODAL,
		                   0, MSGBOX_DELAY);
#else
		OutputDebugStringW(L"Dll Injection Sample Payload V1: Process detached.");
#endif
	}

	return TRUE;
}
