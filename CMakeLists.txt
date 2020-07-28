cmake_minimum_required(VERSION 3.14)

project(VK_Renderer VERSION 0.0.1)

find_package(Vulkan REQUIRED)
add_subdirectory(ThirdParty/glfw)
add_subdirectory(ThirdParty/glm)

# MSVC Configurations
set(warnings "/W4 /WX /EHsc")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd26812")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP /nologo /Oi")

file(GLOB_RECURSE  SRCS
        "Renderer/*.cpp"
        "Renderer/*.hpp"
	    "Renderer/*.h")

add_compile_definitions(WIN32_LEAN_AND_MEAN)

add_executable(${CMAKE_PROJECT_NAME} Renderer/main.cpp ${SRCS})

target_precompile_headers(${CMAKE_PROJECT_NAME} PUBLIC Engine/Core/Core.hpp PUBLIC
												PUBLIC Engine/Core/Platform/platform.hpp
												PUBLIC Engine/Core/Renderer/renderer.hpp
												PUBLIC Engine/Core/Common/common.hpp)


set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY CXX_STANDARD 17)

target_link_libraries(${PROJECT_NAME} Vulkan::Vulkan)
target_link_libraries(${PROJECT_NAME} glm)
target_link_libraries(${PROJECT_NAME} glfw)