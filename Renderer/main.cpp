#define GLFW_INCLUDE_VULKAN
#include <glfw/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#include <iostream>
#include <stdexcept>
#include <cstdlib>

#include "Core/Window.h"

using namespace VKR;

int main()
{    
    Window window = {800,600,"Something"};
    Window window2 = {800,600,"Something"};
    
    while(window.IsOpen())
    {
    }
    
    return 0;
}