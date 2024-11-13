#pragma once
#include "renderer/vulkanCore.h"
#include "renderer/window.h"

class Renderer 
{
public:
	void initialize();
	void render();

	bool isRunning() { return window->isRunning; }

private:
	VulkanCore* vulkanCore;
	Window* window;
};