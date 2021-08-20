#pragma once

#include "sprite.h"
#include "globals.h"

#include <map>
#include <string>
#include <vector>

class Graphics;

/* класс анимированного спрайта
 * содержит логику анимированного спрайта
 */

class AnimatedSprite : public Sprite {
private:
    std::map<std::string, std::vector<SDL_Rect>> _animations;
    std::map<std::string, Vector2> _offsets;
    int _frameIndex{};
    double _timeElapsed{};
    bool _visible{};
protected:
    double _timeToUpdate{};
    bool _currentAnimationOnce{};
    std::string _currentAnimation;

    //добавляет анимацию в карту анимаций
    void addAnimation(int frames, int x, int y, std::string name, int width, int height, Vector2 offset);

    //сбрасывает все анимации, ассоциирующиеся со спрайтом
    void resetAnimations();

    //останавливает текущую анимацию
    void stopAnimation();

    //меняет видимость анимированного спрайта
    void setVisible(bool visible);

    //логика, выполняющаяся по завершении анимации
    virtual void animationDone(std::string currentAnimation) = 0;

    //необходимая функция, устанавливающая все анимации для спрайта
    virtual void setupAnimations() = 0;
public:
    AnimatedSprite(Graphics& graphics, const std::string& filepath, int sourceX, int sourceY, int width, int height,
                   float posX, float posY, float timeToUpdate);

    AnimatedSprite();

    //проигывает желаемую анимацию, если она уже не проигрывается
    void playAnimation(std::string animation, bool once = false);

    //обновляет анимированный спрайт (таймер)
    void update(int elapsedTime);

    //выводит спрайт на экран
    void draw(Graphics& graphics, int x, int y);
};