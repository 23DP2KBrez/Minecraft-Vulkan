#include "shader.h"
#include <fstream>
#include <vector>
#include <Windows.h>

Shader::Shader(const char* filepath, VkDevice* device, VkShaderStageFlagBits stage)
{
	this->stage = stage;
	this->device = device;

	assemblyPath = filepath;
}

void Shader::create()
{
	std::vector<char> shaderCode;
	std::ifstream file(assemblyPath, std::ios::ate | std::ios::binary);
	if (!file.is_open())
	{
		MessageBox(NULL, L"Shader Creation Failed!\n", L"Error!", MB_ICONEXCLAMATION | MB_OK);
		return;
	}

	size_t fileSize = (size_t)file.tellg();
	shaderCode.resize(fileSize);
	file.seekg(0);
	file.read(shaderCode.data(), fileSize);

	VkShaderModuleCreateInfo createInfo = {};
	createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
	createInfo.codeSize = shaderCode.size();
	createInfo.pCode = reinterpret_cast<const uint32_t*>(shaderCode.data());

	vkCreateShaderModule(*device, &createInfo, nullptr, &shaderModule);

	shaderStageInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
	shaderStageInfo.stage = stage;
	shaderStageInfo.module = shaderModule;
	shaderStageInfo.pName = "main";
}