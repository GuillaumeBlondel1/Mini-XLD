#include "Window.hpp"
#include "Error.hpp"

#include <iostream>

int main()
{
    WindowManager::Window window(1920, 1080, "Mini XL-Deploy");

    try {
        window.begin();
    } catch (WindowManager::WindowError &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    while (window.runContinue()) {
        window.setDraw();
        window.clear();
        window.setDraw();
    }
    return 0;
}
