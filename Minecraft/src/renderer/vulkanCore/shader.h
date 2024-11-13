#pragma once
#include "vulkan/vulkan.h"
#include <string>

class Shader
{
public:
	Shader() = default;
	Shader(const char* filepath, VkDevice* device, VkShaderStageFlagBits stage);
	void create();

	VkShaderModule* getShaderModule() { return &shaderModule; }
	VkPipelineShaderStageCreateInfo shaderStageInfo;
private:
	VkShaderStageFlagBits stage;
	VkShaderModule shaderModule;
	VkDevice* device;

	const char* assemblyPath;
};