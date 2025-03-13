#ifndef __WINDOW__
    #define __WINDOW__

#include "WindowDisplay.hpp"

#include <cstddef>
#include <string>

namespace WindowManager
{
    class Window : public WindowDisplay {
        public:
            Window();
            Window(std::size_t width, std::size_t height, const std::string &winName);
            void begin();
            void setNewWidth(std::size_t width);
            void setNewHeight(std::size_t height);
            void setNewSize(std::size_t width, std::size_t height);
            bool isOpen() const;
            bool runContinue();
            ~Window();
        private:
            std::size_t _width;
            std::size_t _height;
            std::string _winName;
            bool _open;
            bool _resize;
    };
}

#endif
