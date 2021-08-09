#pragma once

class Graphics;

class Game {
private:
    void gameLoop();

    void draw(Graphics& graphics);

    void update(float elapsedTime);

public:
    Game();

    ~Game();
};

