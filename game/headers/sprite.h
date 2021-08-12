#pragma once

#include <string>

#include <SDL.h>
class Graphics;

class Sprite {
private:
    SDL_Rect _sourceRect{};
    SDL_Texture* _spriteSheet{};

    float _x{}, _y{};
public:
    Sprite();

    Sprite(Graphics& graphics, const std::string& filepath, int sourceX, int sourceY, int width, int height, float posX,
           float posY);

    virtual ~Sprite();

    virtual void update();

    void draw(Graphics& graphics, int x, int y);
};
