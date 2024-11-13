#pragma once
#include <vector>
#include "vulkan/vulkan.h"

class Mesh
{
public:

	Mesh(VkDevice device, VkPhysicalDevice physDevice, std::vector<float> vertices);
	~Mesh();
	void create();
	void bind(VkCommandBuffer commandBuffer);
	void draw(VkCommandBuffer commandBuffer);
	VkBuffer vertexBuffer;
	std::vector<float> vertices;

	VkDeviceMemory vertexBufferMemory;
	VkPhysicalDevice physDevice;
	VkDevice device;
private:

};
