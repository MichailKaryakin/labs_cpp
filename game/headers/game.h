#pragma once

#include "sprite.h"

class Graphics;

class Game {
private:
    void gameLoop();

    void draw(Graphics& graphics);

    void update(float elapsedTime);

    Sprite _player;
public:
    Game();

    ~Game();
};
