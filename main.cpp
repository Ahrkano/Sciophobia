#include "SDL2/SDL.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
/*----------------------------*/
#include <cstdio>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <math.h>
#include <sstream>
/*----------------------------*/
#include "Window.h"
#include "Texture.h"
#include "TTimer.h"
#include "GameState.h"
#include "GameEngine.h"

//always put these arguments to the main function
//to avoid SDL_win32_main.c|| undefined reference to `SDL_main'|

int main(int argv, char** args)
{
	GameEngine Game;
	Game.Init();
	return 0;
}
