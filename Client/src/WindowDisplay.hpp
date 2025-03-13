#ifndef __WINDOWDISPLAY__
    #define __WINDOWDISPLAY__

#include <raylib.h>

namespace WindowManager
{
    class WindowDisplay {
        public:
            WindowDisplay();
            ~WindowDisplay() = default;
            void setDraw();
            void setColor(const Color &newColor);
            void clear();
        private:
            bool _drawing;
            Color _backColor;
    };
}

#endif
