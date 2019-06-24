#pragma once

#include <string>
#include <SDL.h>
#include <SDL_image.h>

class Texture
{
public:
    Texture(std::string fileName);
    ~Texture(void);

    void Draw();
    void Draw(int offsetX, int offSetY);

    SDL_Texture* getTexture();

private:
    SDL_Texture* texture;
};