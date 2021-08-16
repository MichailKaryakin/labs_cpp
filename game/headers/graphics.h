#pragma once

#include <map>
#include <string>

struct SDL_Window;
struct SDL_Renderer;
struct SDL_Surface;
struct SDL_Texture;
struct SDL_Rect;

/*
 * класс, работающий с графикой игры
 */

class Graphics {
private:
    SDL_Window* _window{};
    SDL_Renderer* _renderer{};
    //все спрайтшиты, использующиеся игрой
    std::map<std::string, SDL_Surface*> _spriteSheets;
public:
    Graphics();

    ~Graphics();

    //загрузка спрайтшита в карту
    SDL_Surface* loadImage(const std::string& filePath);

    //загрузка текстуры на определённое место экрана
    void blitSurface(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);

    //отображение всего на экран
    void flip();

    //очистка экрана
    void clear();

    //возврат рендерера
    SDL_Renderer* getRenderer() const;
};
