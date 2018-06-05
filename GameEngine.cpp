/*
 * GameEngine.cpp
 *
 *  Created on: 29 de mai de 2018
 *      Author: Alexandre
 */

#include "SDL2/SDL.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
/*----------------------------*/
#include <iostream>

#include "GameEngine.h"
#include "GameState.h"
#include "Window.h"
#include "Texture.h"

GameEngine::GameEngine()
{
	this->gWindow = NULL;
	this->gRenderer = NULL;
	this->m_running = false;
}


bool create_window(Window* gWindow, SDL_Renderer* gRenderer)
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{	std::cout<<"SDL could not initialize! SDL Error: %s\n"<<SDL_GetError() ;		success = false;	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{	std::cout<<"Warning: Linear texture filtering not enabled!";		}

		//Initialize SDL_mixer
		if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
		{	std::cout<<"SDL_mixer could not initialize! SDL_mixer Error: %s\n"<<Mix_GetError();	 success = false;	}

		//Create window
		if( !gWindow->init() )
		{	std::cout<<"Window could not be created! SDL Error: %s\n"<<SDL_GetError();	success = false;	}
		else
		{
			//Create renderer for window
			gRenderer = gWindow->createRenderer();
			if( gRenderer == NULL )
			{	std::cout<<"Renderer could not be created! SDL Error: %s\n"<<SDL_GetError();		success = false;	}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{	std::cout<<"SDL_image could not initialize! SDL_image Error: %s\n"<<IMG_GetError();		success = false;	}

			}
		}
	}

	return success;
}


void GameEngine::Init()
{
	if(!create_window(this->gWindow, this->gRenderer))
	{
		std::cout<<"ERRO AO ABRIR JANELA";
		return;
	}

	m_running = true;
}

void GameEngine::Cleanup()
{
	// cleanup the all states
	while ( !states.empty() ) {
		states.back()->Cleanup();
		states.pop_back();
	}

	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	gWindow->free();

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

void GameEngine::ChangeState(GameState* state)
{
	// cleanup the current state
	if ( !states.empty() )
	{
		states.back()->Cleanup();
		states.pop_back();
	}

	// store and init the new state
	states.push_back(state);
	states.back()->Init();
}

void GameEngine::PushState(GameState* state)
{
	// pause current state
	if ( !states.empty() )
	{
		states.back()->Pause();
	}

	// store and init the new state
	states.push_back(state);
	states.back()->Init();
}

void GameEngine::PopState()
{
	// cleanup the current state
	if ( !states.empty() ) {
		states.back()->Cleanup();
		states.pop_back();
	}

	// resume previous state
	if ( !states.empty() ) {
		states.back()->Resume();
	}
}


void GameEngine::HandleEvents()
{
	// let the state handle events
//	states.back()->HandleEvents(this);
}

void GameEngine::Update()
{
	// let the state update the game
//	states.back()->Update(this);
}

void GameEngine::Draw()
{
	// let the state draw the screen
//	states.back()->Draw(this);
}



