#include "graphics.h"
#include <SDL.h>
#include <SDL_image.h>

Graphics::Graphics() {
    SDL_CreateWindowAndRenderer(640, 480, 0, &this->_window, &this->_renderer);
    SDL_SetWindowTitle(this->_window, "cave runner");
}

Graphics::~Graphics() {
    SDL_DestroyWindow(this->_window);
}

SDL_Surface* Graphics::loadImage(const std::string& filePath) {

}

void Graphics::blitSurface(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle) {

}

void Graphics::flip() {

}

void Graphics::clear() {

}

SDL_Renderer* Graphics::getRenderer() const {

}
