#pragma once
#define VK_USE_PLATFORM_WIN32_KHR
#include "vulkanCore/shader.h"
#include "vulkanCore/pipeline.h"
#include "vulkanCore/mesh.h"
#include "vulkan/vulkan.h"
#include "glm/glm.hpp"
#include <vector>

class VulkanCore
{
public:
	VulkanCore(HWND hwnd, HINSTANCE hInstance);

	void initialize();
	void render();
	void cleanup();
private:
	void createInstance();
	void createSurface();
	void createPhysicalDevice();
	void createDevice();
	void createSwapchain();
	void createImageViews();
	void createSemaphores();
	void createRenderPass();
	void createCommandPool();
	void createCommandBuffer();
	void createFences();
	void createFrameBuffers();
	void createDescriptorPool();
	
	void recordCommandBuffer();

	VkImageView MakeImageView(const VkImage& image, VkFormat format);
	void* CreateImage(uint32_t x, uint32_t y, unsigned char imageFormat);

	VkInstance instance;
	VkPhysicalDevice physicalDevice;
	VkDevice device;
	VkQueue graphicsQueue;
	VkSurfaceKHR surface;
	VkQueue presentQueue;
	VkSwapchainKHR swapchain;
	VkImageView swapchainImageViews;
	VkRenderPass renderPass;
	VkImage image;
	VkCommandBuffer commandBuffer;
	VkCommandPool commandPool;
	VkFence fence;

	VkSemaphore graphicsSemaphore;
	VkSemaphore presentSemaphore;

	Pipeline* terrainPipeline;

	std::vector<VkImageView> imageViews;
	std::vector<VkFramebuffer> framebuffers;
	HWND hwnd;
	HINSTANCE hInstance;

	uint32_t graphicsFamily = 0;
	uint32_t presentFamily = 0;

	uint32_t imageIndex = 0;
	uint32_t* imageIndexes = 0;

	glm::vec2 resolution;

	VkDescriptorPool descriptorPool;
	VkWriteDescriptorSet writeDescriptorSet;

	std::vector<Mesh*> meshes;
};