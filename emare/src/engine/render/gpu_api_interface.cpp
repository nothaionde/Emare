#include "gpu_api_interface.hpp"
#include <src/engine/render/vulkan/vulkan_rendering_api.hpp>

namespace emare
{
	std::unique_ptr<gpu_api> gpu_api::get_gpu_api(const api api)
	{
		// TODO: Need parse api here from command line or smth
		assert(api == vulkan);
		api_ = api;
		return std::make_unique<vulkan_rendering_api>();
	}
}
