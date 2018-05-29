/*
 * GameEngine.h
 *
 *  Created on: 29 de mai de 2018
 *      Author: Alexandre
 */

#ifndef SRC_GAMEENGINE_H_
#define SRC_GAMEENGINE_H_

#include "SDL2/SDL.h"
#include <vector>
#include "Window.h"

class GameState;

class GameEngine
{
private:
	// the stack of states
	std::vector<GameState*> states;

	bool m_running;

public:
	void Init();
	void Cleanup();

	void ChangeState(GameState* state);
	void PushState(GameState* state);
	void PopState();

	void HandleEvents();
	void Update();
	void Draw();

	bool Running() { return m_running; }
	void Quit() { m_running = false; }

	Window* gWindow;
	SDL_Renderer* gRenderer;

	GameEngine();

};

#endif /* SRC_GAMEENGINE_H_ */
