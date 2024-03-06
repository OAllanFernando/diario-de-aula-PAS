// Snake.cpp

#include "Snake.hpp"
#include <iostream> 
Snake::Snake() {
   
    length = 1;  
    direction = 0;
    setX(0);
    setY(0);
}

void Snake::handleInput(SDL_Event& event) {
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
        case SDLK_UP:
            // Move up
            setY(getY() - 3);
            break;
        case SDLK_DOWN:
            setY(getY() + 3);
            break;
        case SDLK_LEFT:
            setX(getX() - 3);
            break;
        case SDLK_RIGHT:
            // Move right
            setX(getX() + 3);
            break;
        default:
            break;
        }
    }
}




void Snake::render(SDL_Renderer* renderer) {
    /*std::cout << "Rendering the snake on the screen." << std::endl; */
}