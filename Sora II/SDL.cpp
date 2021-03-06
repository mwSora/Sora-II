#include "SDL.h"
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include "Globals.h"

Lilac::SDL::SDL()
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);

	this->create_window();
	this->create_mixer();
	this->create_ttf();
}

void Lilac::SDL::create_window()
{
	SDL_DisplayMode dm;
	SDL_GetCurrentDisplayMode(0, &dm);

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2");
	SDL_SetHint(SDL_HINT_RENDER_DRIVER, "direct3d");
	SDL_SetHint(SDL_HINT_RENDER_VSYNC, "0");

	this->window = SDL_CreateWindow("PROJECT SORA II", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, dm.w, dm.h, SDL_WINDOW_BORDERLESS);
	this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	this->windowSize.x = dm.w;
	this->windowSize.y = dm.h;

	this->workspaceSize.x = 1920;
	this->workspaceSize.y = 1080;

	SDL_ShowCursor(false);
}

void Lilac::SDL::create_mixer()
{
	Mix_Init(MIX_InitFlags::MIX_INIT_OGG);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
}

void Lilac::SDL::create_ttf()
{
	TTF_Init();
}

void Lilac::SDL::destroy()
{
	SDL_DestroyRenderer(this->renderer);
	SDL_DestroyWindow(this->window);

	TTF_Quit();
	Mix_CloseAudio();
	Mix_Quit();
	SDL_Quit();
}
