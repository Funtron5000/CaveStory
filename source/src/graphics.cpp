#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "graphics.h"

Graphics::Graphics(){
    SDL_CreateWindowAndRenderer(640, 480, 0, &this->_window, &this->_renderer);
    SDL_SetWindowTitle(this->_window, "CaveStory");
}

Graphics::~Graphics(){
    SDL_DestroyWindow(this->_window);
    SDL_DestroyRenderer(this->_renderer);
}

//SDL_Surface *G