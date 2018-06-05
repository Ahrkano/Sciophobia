/*
 * Intro.cpp
 *
 *  Created on: 29 de mai de 2018
 *      Author: Alexandre
 */
#include "SDL2/SDL.h"
#include <SDL2/SDL_image.h>
#include "Intro.h"

Intro Intro::m_IntroState;

void Intro::Init()
{
	SDL_Surface* temp = SDL_LoadBMP("intro.bmp");

	bg = SDL_ConvertSurfaceFormat(temp);

	SDL_FreeSurface(temp);

	// create the fader surface like the background with alpha
	fader = SDL_CreateRGBSurface( SDL_SRCALPHA, bg->w, bg->h,
									bg->format->BitsPerPixel,
									bg->format->Rmask, bg->format->Gmask,
									bg->format->Bmask, bg->format->Amask );

		// fill the fader surface with black
	SDL_FillRect (fader, NULL, SDL_MapRGB (bg->format, 0, 0, 0)) ;

		// start off opaque
	alpha = 255;

	SDL_SetAlpha(fader, SDL_SRCALPHA, alpha);

	printf("CIntroState Init\n");
}
