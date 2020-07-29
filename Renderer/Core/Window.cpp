#include "Window.h"

#include <thread>

namespace VKR
{
    
    Window::Window(uint32_t width, uint32_t height, const std::string& window_name)
        :height(height), width(width), name(window_name)
    {
        this->CreateWindow();
    }
    
    Window::Window(uint32_t width, uint32_t height, std::string&& window_name)
        :height(height), width(width), name(std::move(window_name))
    {
        this->CreateWindow();
    }
    
    bool Window::IsOpen()
    {
        return this->is_open;
    }
    
    void Window::ShouldClose()
    {
        this->is_open = !glfwWindowShouldClose(window_handle);
    }
    
    void Window::CreateWindow()
    {
        glfwInit();// NOTE(Tiago):  Initializes the GLFW library
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);// NOTE(Tiago): Stops GLFW from creating an OpenGL context
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);// NOTE(Tiago): Tells GLFW the window will not be resizable
        
        // NOTE(Tiago): In order to able to interact with a window from another thread we need to create the window on that thread. Since we want to have window event pools be independent from application framerate, we need to create the window in a thread and use that thread to poll its events.
        std::thread window_thread([this](){
                                      this->window_handle = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr); // NOTE(Tiago): Create the GLFW window
                                      while(this->IsOpen())
                                      {
                                          this->PollEvents();
                                      }
                                  });
        window_thread.detach();
    }
    
    void Window::PollEvents()
    {
        this->ShouldClose();
        glfwPollEvents();
    }
    
}