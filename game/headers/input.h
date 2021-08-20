#pragma once

#include <SDL.h>
#include <map>

/* класс ввода
 * работает с пользовательским вводом
 */

class Input {
private:
    //удерживаемые в данный момент клавиши
    std::map<SDL_Scancode, bool> _heldKeys;
    //нажатые в данный момент клавиши
    std::map<SDL_Scancode, bool> _pressedKeys;
    //отпущенные в данный момент клавиши
    std::map<SDL_Scancode, bool> _releasedKeys;
public:
    void beginNewFrame();

    void keyUpEvent(const SDL_Event& event);

    void keyDownEvent(const SDL_Event& event);

    bool wasKeyPressed(SDL_Scancode key);

    bool wasKeyReleased(SDL_Scancode key);

    bool isKeyHeld(SDL_Scancode key);
};
