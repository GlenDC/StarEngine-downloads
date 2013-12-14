#include "Game.h"

#include <Context.h>
#include <StarEngine.h>
#include <Helpers/Helpers.h>
#include <Graphics/GraphicsManager.h>
#include <Graphics/Scalesystem.h>
#include <Assets/FontManager.h>
#include <Sound/AudioManager.h>
#include <Scenes/SceneManager.h>
#include <Graphics/SpriteAnimationManager.h>
#include <Assets/FontManager.h>
#include <Graphics/UI/UICursor.h>
#include <Input/InputManager.h>
#include <Scenes/SplashScreen.h>

#include "scenes/ExampleScene.h"

Game::Game()
	: star::BaseGame()
{
	star::StarEngine::GetInstance();
}

void Game::Initialize(int32 window_width, int32 window_height)
{
	star::ScaleSystem::GetInstance()->SetWorkingResolution(640, 480);
	star::StarEngine::GetInstance()->Initialize(window_width, window_height);

	auto emptyScene = new ExampleScene(_T("ExampleScene"));
	star::SceneManager::GetInstance()->AddScene(emptyScene);

	auto splashScene = new star::SplashScreen(_T("SplashScene"), emptyScene->GetName());
	star::SceneManager::GetInstance()->AddScene(splashScene);
	
	star::SceneManager::GetInstance()->SetActiveScene(splashScene->GetName());

	star::Logger::GetInstance()->Log(star::LogLevel::Info, _T("Scenes Set and Done."));
}

void Game::Update(const star::Context& context)
{
	star::StarEngine::GetInstance()->Update(context);
}

void Game::Draw()
{
	star::StarEngine::GetInstance()->Draw();
}

void Game::End()
{
	star::Logger::GetInstance()->Log(star::LogLevel::Info, _T("Game ends."));
	star::StarEngine::GetInstance()->End();
}
