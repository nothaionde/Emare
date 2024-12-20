#pragma once
#include "VkBootstrap.h"

namespace emare
{
	class vulkan_instance
	{
	public:
		vulkan_instance();

		VkInstance get_vk_instance() const
		{
			return vk_instance_;
		}

		vkb::Instance get_vkb_instance() const
		{
			return  vkb_instance_;
		}
	private:
		VkInstance vk_instance_;
		vkb::Instance vkb_instance_;
	};
}
