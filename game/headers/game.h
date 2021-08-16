#pragma once

#include "sprite.h"

class Graphics;

/*
 * класс игры, скрепляющий всю её логику
 */

class Game {
private:
    //игровой цикл, выполняющийся каждый кадр
    void gameLoop();

    //вывод кадра
    void draw(Graphics& graphics);

    //обновление кадра
    void update(float elapsedTime);

    //спрайт персонажа
    Sprite _player;
public:
    Game();

    ~Game();
};
