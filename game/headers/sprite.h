#pragma once

#include <string>

#include <SDL.h>

class Graphics;

/* класс спрайта
 * работает с информацией о конкретном спрайте
 */

class Sprite {
protected:
    //место спрайта на спрайтшите
    SDL_Rect _sourceRect{};
    //спрайтшит
    SDL_Texture* _spriteSheet{};
    //точка на экране
    float _x{}, _y{};
public:
    Sprite();

    Sprite(Graphics& graphics, const std::string& filepath, int sourceX, int sourceY, int width, int height, float posX,
           float posY);

    virtual ~Sprite();

    virtual void update();

    //загрузка спрайта на рендерер
    virtual void draw(Graphics& graphics, int x, int y);
};
