#pragma once

#include "animatedsprite.h"
#include "globals.h"

class Graphics;

class Player : public AnimatedSprite {
public:
    Player();

    Player(Graphics& graphics, float x, float y);

    void draw(Graphics& graphics);

    void update(float elapsedTime);

    //двигает игрока влево по -dx
    void moveLeft();

    //двигает игрока вправо по dx
    void moveRight();

    //останавливает движение игрока
    void stopMoving();

    virtual void animationDone(std::string currentAnimation);

    virtual void setupAnimations();

private:
    float _dx, _dy;
    Direction _facing;
};

