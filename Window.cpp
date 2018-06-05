/*
 * Window.cpp
 *
 *  Created on: 07/12/2014
 *      Author: Monge
 */


#include "SDL2/SDL.h"
#include "Window.h"

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;


Window::Window()
{
    //Initialize non-existant window
    mWindow = NULL;
    mMouseFocus = false;
    mKeyboardFocus = false;
    mFullScreen = false;
    mMinimized = false;
    mWidth = 0;
    mHeight = 0;
}

Window::~Window()
{/*EMPTY*/}

SDL_Renderer* Window::createRenderer()
{
    return SDL_CreateRenderer( mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
}

bool Window::init()
{
    //Create window
    mWindow = SDL_CreateWindow( "Sciophobia v1.0", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE );
    if( mWindow != NULL )
    {
        mMouseFocus = true;
        mKeyboardFocus = true;
        mWidth = SCREEN_WIDTH;
        mHeight = SCREEN_HEIGHT;
    }

    return mWindow != NULL;
}

void Window::handleEvent( SDL_Event& e, SDL_Renderer* gRenderer )
{
    //Window event occured
    if( e.type == SDL_WINDOWEVENT )
    {
        switch( e.window.event )
                {
                    //Get new dimensions and repaint on window size change
                    case SDL_WINDOWEVENT_SIZE_CHANGED:
                    mWidth = e.window.data1;
                    mHeight = e.window.data2;
                    SDL_RenderPresent( gRenderer );
                    break;

                    //Repaint on exposure
                    case SDL_WINDOWEVENT_EXPOSED:
                    SDL_RenderPresent( gRenderer );
                    break;

                    //Mouse entered window
                     case SDL_WINDOWEVENT_ENTER:
                    	 mMouseFocus = true;
                    	 //0 = hide, 1 = visible
                    	 SDL_ShowCursor(0);
                     break;

                     //Mouse left window
                     case SDL_WINDOWEVENT_LEAVE:
                    	 mMouseFocus = false;
                     break;

                     //Window has keyboard focus
                     case SDL_WINDOWEVENT_FOCUS_GAINED:
                    	 mKeyboardFocus = true;
                     break;

                     //Window lost keyboard focus
                     case SDL_WINDOWEVENT_FOCUS_LOST:
                    	 mKeyboardFocus = false;
                     break;

                     //Window minimized
                     case SDL_WINDOWEVENT_MINIMIZED:
                    	 mMinimized = true;
                     break;

                     //Window maxized
                     case SDL_WINDOWEVENT_MAXIMIZED:
                    	 mMinimized = false;
                     break;

                     //Window restored
                     case SDL_WINDOWEVENT_RESTORED:
                    	 mMinimized = false;
                     break;
                 }

    }

    //Enter exit full screen on return key
    else if( e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_F12 )
    {
    	if( mFullScreen )
        {
    		SDL_SetWindowFullscreen( mWindow, SDL_FALSE );
            mFullScreen = false;
        }
        else
        {
        	SDL_SetWindowFullscreen( mWindow, SDL_TRUE );
            mFullScreen = true;
            mMinimized = false;
        }
    }
}

void Window::free()
{
	if( mWindow != NULL )
	{
		SDL_DestroyWindow( mWindow );
	}

	mMouseFocus = false;
	mKeyboardFocus = false;
	mWidth = 0;
	mHeight = 0;
}

int Window::getWidth() const
{
	return mWidth;
}

int Window::getHeight() const
{
	return mHeight;
}

bool Window::hasMouseFocus()
{
	return mMouseFocus;
}

bool Window::hasKeyboardFocus()
{
	return mKeyboardFocus;
}

bool Window::isMinimized()
{
	return mMinimized;
}


