#include <windows.h>

#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "kernel32.lib")

static CHAR ClassName[] = "MyWinClass";
static CHAR AppName[] = "Dave's Tiny App";

static HINSTANCE hInstance;
static LPSTR CommandLine;

LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);

void __stdcall MainEntry(void)
{
	STARTUPINFO sui;

	hInstance = GetModuleHandle(NULL);
	CommandLine = GetCommandLine();
	
	GetStartupInfo(&sui);
	ExitProcess(WinMain(hInstance, NULL, CommandLine, (sui.dwFlags & STARTF_USESHOWWINDOW)?sui.wShowWindow:SW_SHOWDEFAULT));
}

int __stdcall WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR CmdLine, int CmdShow)
{
	WNDCLASSEX wc;
	MSG	   msg;
	HWND	   hwnd;

	wc.cbSize = sizeof (WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInst;
	wc.hbrBackground = (HBRUSH)(COLOR_3DSHADOW+1);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = ClassName;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	RegisterClassEx(&wc);

	hwnd = CreateWindowEx(0, ClassName, AppName, WS_OVERLAPPEDWINDOW + WS_VISIBLE, 
		CW_USEDEFAULT, CW_USEDEFAULT, 640, 480, NULL, NULL, hInstance, NULL);
		
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	
	return (int) msg.wParam;
}

LRESULT CALLBACK    WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT	ps;
        RECT		rect;
        HDC		hdc;
	
	switch (uMsg)
	{
		case WM_PAINT:
			hdc = BeginPaint(hWnd, &ps);
			SetBkMode(hdc, TRANSPARENT);
			GetClientRect(hWnd, &rect);
			DrawText(hdc, AppName, -1, &rect, DT_SINGLELINE + DT_CENTER + DT_VCENTER);
			EndPaint(hWnd, &ps);
			return 0;
		break;
		
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}