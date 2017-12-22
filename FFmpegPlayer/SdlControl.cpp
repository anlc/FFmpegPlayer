#include "stdafx.h"

extern "C" {
#include "include\SDL.h"
}
//show bmp picture
int play(const char *title, const char *filepath) {

	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	SDL_Surface *surface = NULL;
	SDL_Texture *texture = NULL;
	int ret;

	int width = 500;
	int height = 600;

	ret = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);
	if (ret == -1) {
		printf("SDL_Init failed %s", SDL_GetError());
	}
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	if (window == NULL) {
		printf("SDL_CreateWindow failed  %s", SDL_GetError());
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL) {
		printf("SDL_CreateRenderer failed  %s", SDL_GetError());
	}
	surface = SDL_LoadBMP(filepath);
	if (surface == NULL) {
		printf("SDL_LoadBMP failed: %s", SDL_GetError());
	}
	texture = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_FreeSurface(surface);
	SDL_RenderClear(renderer);

	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
	SDL_Delay(3000);

	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();
	return 0;
}