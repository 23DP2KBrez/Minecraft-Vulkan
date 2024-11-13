#include "window.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
	case WM_DESTROY:
		PostQuitMessage(0);  
		return 0;

	case WM_CLOSE:
		DestroyWindow(hwnd); 
		return 0;

	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
}
void Window::initialize()
{
	const wchar_t CLASS_NAME[] = L"Minecraft";

	wc.lpfnWndProc = WindowProc;       
	wc.hInstance = hInstance;
	wc.lpszClassName = CLASS_NAME;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW); 
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); 

	RegisterClass(&wc);

	hwnd = CreateWindowEx(
		0, 
		wc.lpszClassName, 
		L"Minecraft", 
		WS_OVERLAPPEDWINDOW, 
		0, 
		0, 
		1920, 1080, 
		nullptr, nullptr, 
		hInstance,
		nullptr);


	if (hwnd == NULL) {
		MessageBox(NULL, L"Window Creation Failed!", L"Error!", MB_ICONEXCLAMATION | MB_OK);
		exit(0);
	}
	ShowWindow(hwnd, SW_SHOW);
}

void Window::update()
{
	MSG msg;
	while (PeekMessage(&msg, hwnd, 0, 0, PM_REMOVE)) 
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		isRunning = msg.message != WM_QUIT;
	}
}