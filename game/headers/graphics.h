#pragma once

#include <map>
#include <string>

struct SDL_Window;
struct SDL_Renderer;
struct SDL_Surface;
struct SDL_Texture;
struct SDL_Rect;

class Graphics {
private:
    SDL_Window* _window{};
    SDL_Renderer* _renderer{};
    std::map<std::string, SDL_Surface*> _spriteSheets;
public:
    Graphics();

    ~Graphics();

    SDL_Surface* loadImage(const std::string& filePath);

    void blitSurface(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);

    void flip();

    void clear();

    SDL_Renderer* getRenderer() const;
};
