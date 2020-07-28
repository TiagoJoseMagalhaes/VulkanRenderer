#include "Window.h"

namespace VKR
{
    
    Window::Window(uint32_t height, uint32_t width, const std::string& window_name)
        :height(height), width(width), name(window_name)
    {
        
    }
    
    Window::Window(uint32_t height, uin32_t width, std::string&& window_name)
    {
        
    }
    
}