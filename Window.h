/*
 * Window.h
 *
 *  Created on: 07/12/2014
 *      Author: Monge
 */

#ifndef WINDOW_H_
#define WINDOW_H_

class Window
{
	    private:
        //Window data
        SDL_Window* mWindow;

        //Window dimensions
        int mWidth;
        int mHeight;

        //Window focus
        bool mMouseFocus;
        bool mKeyboardFocus;
        bool mFullScreen;
        bool mMinimized;

	    public:

        //Intializes internals
        Window();

        ~Window();

        //Creates window
        bool init();

        //Creates renderer from internal window
        SDL_Renderer* createRenderer();

        //Handles window events
        void handleEvent( SDL_Event& e, SDL_Renderer* gRenderer );

        //Deallocates internals
        void free();

        //Window dimensions
        int getWidth() const;
        int getHeight() const;

        //Window focii
        bool hasMouseFocus();
        bool hasKeyboardFocus();
        bool isMinimized();

};



#endif /* WINDOW_H_ */
