// Snake.cpp

#include "Comida.hpp"
#include <iostream> 
Comida::Comida() {
    setX(50);
    setY(50);
}

void Comida::aparecer(int x, int y) {
    std::cout << "Aparecendo a comida na tela." << std::endl;
    int newX = x + (x * 1.03);
    int newY = y + (y * 1.07);
    setX(newX);
    setY(newY);
}


void Comida::render(SDL_Renderer* renderer) {
  /*std::cout << "Rendering the snake on the screen." << std::endl;*/  
}

