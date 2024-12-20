#include "vulkan_instance.hpp"

namespace emare
{
	vulkan_instance::vulkan_instance()
	{
		vkb::InstanceBuilder builder;
		const auto instance_return = builder.set_app_name("Emare")
		                                    .request_validation_layers(true)
		                                    .require_api_version(1, 2)
		                                    .build();
		if (!instance_return)
		{
			EMARE_LOG_ERROR("Vulkan Instance error: %s", instance_return.error().message().c_str());
		}
		vk_instance_ = instance_return.value();
		vkb_instance_ = instance_return.value();
	}
}
