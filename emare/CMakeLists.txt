# Find all source files
file(GLOB_RECURSE emare_src 
  "src/*.hpp"
  "src/*.cpp"
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(${PROJECT_NAME} WIN32 ${emare_src})

find_package(Vulkan REQUIRED)
FetchContent_MakeAvailable(glfw)
FetchContent_MakeAvailable(vk-bootstrap)
FetchContent_MakeAvailable(vma)
FetchContent_MakeAvailable(Vulkan)
FetchContent_MakeAvailable(imgui)

include_directories(${Vulkan_INCLUDE_DIR})
message(STATUS "Vulkan_INCLUDE_DIR: ${Vulkan_INCLUDE_DIR}")
link_directories(${Vulkan_INCLUDE_DIR}/../lib)

add_Library(imgui
    ${imgui_SOURCE_DIR}/imgui.cpp
    ${imgui_SOURCE_DIR}/imgui_draw.cpp
    ${imgui_SOURCE_DIR}/imgui_demo.cpp
    ${imgui_SOURCE_DIR}/imgui_tables.cpp
    ${imgui_SOURCE_DIR}/imgui_widgets.cpp
    ${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.cpp
    ${imgui_SOURCE_DIR}/backends/imgui_impl_vulkan.cpp
)
target_include_directories(imgui 
    PUBLIC 
    ${imgui_SOURCE_DIR}
    ${glfw_SOURCE_DIR}/include
)
target_include_directories (${PROJECT_NAME}
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
)


target_link_libraries(${PROJECT_NAME}
    PUBLIC
    glfw
    vk-bootstrap
    Vulkan::Vulkan
    VulkanMemoryAllocator
	imgui
)

if (NOT MINGW)
	target_precompile_headers(${PROJECT_NAME} PRIVATE "src/epch.hpp")
endif()