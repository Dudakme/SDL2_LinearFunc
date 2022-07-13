#include <SDL.h>
#include <cstdio>
#include <utility>
#include <cmath>
using namespace std;




int main(int argc, char** argv)
{
    int height = 800;
    int width = 800;
    SDL_Window* win = SDL_CreateWindow("Hello World", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    SDL_Renderer* renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);

    int a[] = { 3, 2, 5, 1, 0, 4 };
    int n = sizeof a / sizeof a[0];

    bool running = true;

    int m=1;
    int b=1;
    bool isDown = false;

    // y=mx+b
    while (running)
    {
        SDL_Event event;
        while( SDL_PollEvent(&event) )
        {
            if (event.type == SDL_QUIT)
                running = false;
        }


        SDL_Delay(50);

        
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 1);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 24, 24, 24, 1);

        for (double x = 1; x < 1000;) {
            double y = m*x+b;

            SDL_RenderDrawPoint(renderer, floor(x), floor(y));
            printf("%f \n", x);
            printf("%f \n", y);

            x+=0.2;
        }


        int* pointer = &m;
        
        if ( *pointer == 200 )   {isDown = true;} else if ( *pointer == 1 ) {  isDown = false; }

        if (isDown) {
            *pointer-=1;
        } else {
            *pointer+=1;
        }
        
        SDL_RenderPresent( renderer );

    }

    SDL_Quit();
    return 1;
}