#include "cs50.h"
#include <stdio.h>
#include <SDL2/SDL.h>

void show_image(const char *image_path);

int main(void) 
{
    int x = get_int("x: ");
    int y = get_int("y: ");

    if (x < y)
    {
        printf("x is less than y\n");
    }
    else if (x > y)
    {
        printf("x is greater than y\n");
        show_image("/Users/mauriciolopez/Documents/c/holamauro/img Small.png");
    }
    else
    {
        printf("x is equal to y\n");
    }
    return 0;
}

void show_image(const char *image_path)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) 
    {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return;
    }

    SDL_Window *win = SDL_CreateWindow("Image", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    if (win == NULL) 
    {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return;
    }

    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == NULL) 
    {
        SDL_DestroyWindow(win);
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_Quit();
        return;
    }

    SDL_Surface *bmp = SDL_LoadBMP(image_path);
    if (bmp == NULL) 
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        printf("SDL_LoadBMP Error: %s\n", SDL_GetError());
        SDL_Quit();
        return;
    }

    SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, bmp);
    SDL_FreeSurface(bmp);
    if (tex == NULL) 
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        printf("SDL_CreateTextureFromSurface Error: %s\n", SDL_GetError());
        SDL_Quit();
        return;
    }

    SDL_RenderClear(ren);
    SDL_RenderCopy(ren, tex, NULL, NULL);
    SDL_RenderPresent(ren);

    SDL_Delay(2000);

    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}