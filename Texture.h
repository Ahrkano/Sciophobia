/*
 * Texture.h
 *
 *  Created on: 07/12/2014
 *      Author: Monge
 */

#ifndef TEXTURE_H_
#define TEXTURE_H_


#include <cstdio>
#include <iostream>
#include <SDL2/SDL_ttf.h>

class Texture
{
		private:
		//The actual hardware texture
		SDL_Texture* mTexture;

		//Image dimensions
		int mWidth;
		int mHeight;


		public:
		//Initializes variables
		Texture();

		//Deallocates memory
		~Texture();

		//Loads image at specified path
		bool loadFromFile( std::string path, SDL_Renderer* gRenderer );

		//Deallocates texture
		void free();

        //Set blending
        void setBlendMode( SDL_BlendMode blending );

        //Set alpha modulation
        void setAlpha( Uint8 alpha );

		//Renders texture at given point
		void render( int x, int y, SDL_Renderer* gRenderer );

	    //Renders part of texture at given point
	    void render( int x, int y, SDL_Renderer* gRenderer, SDL_Rect* clip);

		//Gets image dimensions
		int getWidth();
		int getHeight();

		SDL_Texture* getTexture() const;

		//Creates image from font string
		bool loadFromRenderedText( std::string textureText, SDL_Color textColor, TTF_Font* gFont, SDL_Renderer* gRenderer );
};


#endif /* TEXTURE_H_ */
