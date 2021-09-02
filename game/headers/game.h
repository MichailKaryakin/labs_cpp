#pragma once

#include "player.h"
#include "level.h"

class Graphics;

/* класс игры
 * скрепляет всю логику игры
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
    Player _player;

    //уровень
    Level _level;
public:
    Game();

    ~Game();
};
