#pragma once
#include "vulkan/vulkan.h"
#include "shader.h"
#include <vector>

class Pipeline
{
public:
	Pipeline(VkDevice* device, VkRenderPass renderPass, std::vector<VkDescriptorSetLayoutBinding> descriptorSetLayout);
	void create();

	VkPipeline getPipeline() { return pipeline; }
	VkPipelineLayout getPipelineLayout() { return layout; }
	VkDescriptorSetLayout getDescriptorLayout() { return descriptorLayout; }
	VkDescriptorSet* getDescriptorSet() { return &descriptorSet; }
private:
	Shader* shader;
	VkDevice* device;

	VkPipelineLayout layout;
	VkPipelineCache cache;
	VkPipeline pipeline;

	VkRenderPass renderPass;

	std::vector<VkDescriptorSetLayoutBinding> descriptorSetLayout;
	VkDescriptorSetLayout descriptorLayout;
	VkDescriptorSet descriptorSet;

	uint32_t pushConstantsSize = 0;
};