#pragma once

#include <BaseGame.h>

namespace star
{
	class SceneManager;
}

class Game : public star::BaseGame
{
public:
	Game();
	~Game() {}

	void Initialize(int32 window_width, int32 window_height);
		
	void Update(const star::Context& context);
	void Draw();

	void End();
	
private:
	Game(const Game&);
	Game(Game&&);
	Game& operator=(const Game&);
};
