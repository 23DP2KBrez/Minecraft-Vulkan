#pragma once
#include <Windows.h>

class Window
{
public:
	Window() = default;

	void initialize();
	void update();
	HWND hwnd;
	WNDCLASS wc;
	HINSTANCE hInstance;

	bool isRunning = true;
private:
};