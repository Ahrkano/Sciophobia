/*
 * Intro.h
 *
 *  Created on: 29 de mai de 2018
 *      Author: Alexandre
 */

#ifndef SRC_INTRO_H_
#define SRC_INTRO_H_

#include "Texture.h"
#include "GameState.h"

class Intro : public GameState
{
public:

	void Init();
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(GameEngine* game);
	void Update(GameEngine* game);
	void Draw(GameEngine* game);

protected:
	Intro()
	{
		this->bg = NULL;
		this->fader = NULL;
		this->alpha = 0;
	}
	virtual ~Intro(){};

private:
	static Intro m_IntroState;

	SDL_Surface* bg;
	SDL_Surface* fader;
	int alpha;

};

#endif /* SRC_INTRO_H_ */
