/* date = July 29th 2020 0:21 am */
#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>
#include <memory>

namespace VKR
{
    
    struct Window
    {
        std::string name = "";
        uint32_t height;
        uint32_t width;
        GLFWwindow* window_handle = nullptr;
        
        public:
        Window(uint32_t height, uint32_t width, const std::string& window_name);
        Window(uint32_t height, uint32_t widht, std::string&& window_name); 
        
        private:
        void CreateWindow();
    }
    
}