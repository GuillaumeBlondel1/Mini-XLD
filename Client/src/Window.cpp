#include "Window.hpp"
#include "Error.hpp"

#include <raylib.h>

WindowManager::Window::Window() : _width(0), _height(0), _open(false), _resize(false) {}

WindowManager::Window::Window(std::size_t width, std::size_t height, const std::string &winName) :
    _width(width), _height(height), _winName(winName), _open(false), _resize(false) {}

void WindowManager::Window::begin()
{
    if (_width == 0 || _height == 0) {
        throw WindowManager::WindowError(WindowManager::windowErrorsList.find(2)->second);
    }
    InitWindow((int)_width, (int)_height, _winName.c_str());
    if (!IsWindowReady()) {
        throw WindowManager::WindowError(WindowManager::windowErrorsList.find(1)->second);
    }
    _open = true;
}

void WindowManager::Window::setNewWidth(std::size_t width)
{
    _width = width;
    _resize = true;
}

void WindowManager::Window::setNewHeight(std::size_t height)
{
    _height = height;
    _resize = true;
}

void WindowManager::Window::setNewSize(std::size_t width, std::size_t height)
{
    _width = width;
    _height = height;
    _resize = true;
}

bool WindowManager::Window::isOpen() const
{
    return _open;
}

bool WindowManager::Window::runContinue()
{
    if (WindowShouldClose()) {
        return false;
    }
    return true;
}

WindowManager::Window::~Window()
{
    CloseWindow();
    _open = false;
}
