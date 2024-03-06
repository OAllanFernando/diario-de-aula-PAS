// snake.hpp

#ifndef COMIDA_HPP
#define COMIDA_HPP

#include <SDL.h>
#include "Object.hpp"

class Comida : public Object {
public:
    Comida();
    void render(SDL_Renderer* renderer);
    void aparecer(int x, int y);

private:

};

#endif