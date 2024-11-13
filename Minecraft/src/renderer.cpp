#include "renderer.h"

void Renderer::initialize()
{
	window = new Window();
	window->initialize();

	vulkanCore = new VulkanCore(window->hwnd, window->hInstance);
	vulkanCore->initialize();
}

void Renderer::render()
{
	vulkanCore->render();
	window->update();
}