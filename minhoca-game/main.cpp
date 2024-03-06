#include "Game.hpp"
#include "Object.hpp"
#include "Snake.hpp"
#include "Comida.hpp"
#include <SDL.h>

int main(int argc, char* argv[]) {
    Game* game = new Game("Minhoca Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

    Snake snake;
    Comida comidinha;

    snake.setY(100);
    snake.setX(200);

    snake.setHealth(100);
    snake.setSpeed(5);
    snake.setSize(10);

    comidinha.setSize(10);
    comidinha.aparecer(50, 58);

    while (game->running()) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                game->isRunning = false;
            }
            else if (event.type == SDL_KEYDOWN) {
                snake.handleInput(event);
            }
        }

        // Check for collision
        SDL_Rect snakeRect;
        snakeRect.x = snake.getX();
        snakeRect.y = snake.getY();
        snakeRect.h = snake.getSize();
        snakeRect.w = snake.getSize() + 15;

        SDL_Rect comidinhaRect;
        comidinhaRect.x = comidinha.getX();
        comidinhaRect.y = comidinha.getY();
        comidinhaRect.h = comidinha.getSize();
        comidinhaRect.w = comidinha.getSize() + 12;

        if (SDL_HasIntersection(&snakeRect, &comidinhaRect)) {
            comidinha.aparecer(snake.getX(), snake.getY());
        }

        SDL_SetRenderDrawColor(game->renderer, 50, 50, 255, 255);
        SDL_RenderClear(game->renderer);

        SDL_SetRenderDrawColor(game->renderer, 0, 255, 10, 255);
        SDL_RenderFillRect(game->renderer, &snakeRect);

        SDL_SetRenderDrawColor(game->renderer, 230, 59, 10, 255);
        SDL_RenderFillRect(game->renderer, &comidinhaRect);

        // Renderiza os objetos depois de limpar 
        snake.render(game->renderer);
        comidinha.render(game->renderer);

        SDL_RenderPresent(game->renderer);
    }

    delete game;

    return 0;
}