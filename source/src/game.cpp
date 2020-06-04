#include <SDL2/SDL.h>

#include "game.h"
#include "graphics.h"
#include "input.h"

/* Game Class
*  Holds all information for the main game loop
*/

namespace{
    const int FPS = 50;
    const int MAX_FRAME_TIME = 5 * 1000 / FPS;
}

Game::Game(){
    SDL_Init(SDL_INIT_EVERYTHING); //initialize SDL with all options
    this->gameLoop(); //call the game loop
}

Game::~Game(){

}

int LAST_UPDATE_TIME = SDL_GetTicks();
//main game loop
void Game::gameLoop(){
    Graphics graphics;
    Input input;
    SDL_Event event; //contains the SDL events that happened in the frame

    while(true){
        input.beginNewFrame();
        if(SDL_PollEvent(&event)){
            if(event.type == SDL_KEYDOWN){
                if(event.key.repeat == 0){
                    input.keyDownEvent(event);
                }
            }
            else if(event.type == SDL_KEYUP){
                input.keyUpEvent(event);
            }
            else if(event.type == SDL_QUIT){
                return;
            }
        }
        if(input.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true){
            return;
        }

        //track frame-time
        const int CURRENT_TIME_MS = SDL_GetTicks();
        int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
        //keeps the framerate at or below the declared fps
        this->update(std::min(ELAPSED_TIME_MS,MAX_FRAME_TIME));
        LAST_UPDATE_TIME = CURRENT_TIME_MS;
    };
}

void Game::draw(Graphics &graphics){

}

void Game::update(float elapsedTime){

}