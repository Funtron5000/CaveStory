#pragma once
#include <map>
#include <string>

/* Grahpics Class
** Holds all information for making graphics
*/

struct SDL_Window;
struct SDL_Renderer;
struct SDL_Rect;

class Graphics{
public:
    Graphics();
    ~Graphics();

    // Loads image into the _spritesheets map if it doesn't already exist
    // As a result, each image will only ever be loaded once
    // Returns image from map regardless if it had been just loaded or not
    SDL_Surface *loadImage(const std::string & filePath);

    // Draws a texture to a certain part of the screen
    void blitSurface(SDL_Texture *source, SDL_Rect *sourceRectangle, SDL_Rect *destinationRectangle);

    // Renders everything to the screen ?flips the framebuffer up to screen?
    void flip();

    // Clears the screen
    void clear();

    // Returns the renderer for use elsewhere
    SDL_Renderer *getRenderer() const;
private:
    SDL_Window *_window;
    SDL_Renderer *_renderer;

    std::map<std::string, SDL_Surface*> _spriteSheets;
};
