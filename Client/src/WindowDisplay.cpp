/*
** EPITECH PROJECT, 2025
** Client
** File description:
** WindowDisplay
*/

#include "WindowDisplay.hpp"

WindowManager::WindowDisplay::WindowDisplay() :
    _drawing(false), _backColor((Color){ 255, 255, 255, 255 }) {}

void WindowManager::WindowDisplay::setDraw()
{
    if (!_drawing) {
        BeginDrawing();
        _drawing = true;
        return;
    }
    EndDrawing();
    _drawing = false;
}

void WindowManager::WindowDisplay::setColor(const Color &newColor)
{
    _backColor = newColor;
}

void WindowManager::WindowDisplay::clear()
{
    if (_drawing) {
        ClearBackground(_backColor);
    }
}
