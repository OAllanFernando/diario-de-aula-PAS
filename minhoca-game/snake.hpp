// snake.hpp

#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <SDL.h>
#include "Object.hpp"

class Snake : public Object {
public:
    Snake();
    void handleInput(SDL_Event& event); 
    void render(SDL_Renderer* renderer); 


private:
    int length; 
    int direction; 
};

#endif