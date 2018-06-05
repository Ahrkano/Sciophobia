/*
 * GameState.h
 *
 *  Created on: 29 de mai de 2018
 *      Author: Alexandre
 */

#ifndef SRC_GAMESTATE_H_
#define SRC_GAMESTATE_H_

#include "GameEngine.h"

class GameState
{
public:
  virtual void Init() = 0;
  virtual void Cleanup() = 0;

  virtual void Pause() = 0;
  virtual void Resume() = 0;

  virtual void HandleEvents(GameEngine* game) = 0;
  virtual void Update(GameEngine* game) = 0;
  virtual void Draw(GameEngine* game) = 0;

  void ChangeState(GameEngine* game, GameState* state)
  {	game->ChangeState(state);	}

  virtual ~GameState() {}

protected:
  GameState() { }
};

#endif /* SRC_GAMESTATE_H_ */
