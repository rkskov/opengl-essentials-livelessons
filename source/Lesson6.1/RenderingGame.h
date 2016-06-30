#pragma once

#include "Game.h"

namespace Library
{
	class GameTime;
	class FirstPersonCamera;
	class Grid;
	class Skybox;
}

namespace Rendering
{
	class EnvironmentMappingDemo;

	class RenderingGame final : public Library::Game
	{
		RTTI_DECLARATIONS(RenderingGame, Library::Game)

	public:
		RenderingGame(HINSTANCE instance, const std::wstring& windowTitle);

	protected:
		virtual void Initialize() override;
		virtual void Draw(const Library::GameTime& gameTime) override;
		virtual void Shutdown() override;

	private:
		void OnKey(int key, int scancode, int action, int mods);

		std::shared_ptr<Library::FirstPersonCamera> mCamera;
		KeyboardHandler mKeyboardHandler;
		std::shared_ptr<Library::Grid> mGrid;
		std::shared_ptr<Library::Skybox> mSkybox;

		std::shared_ptr<EnvironmentMappingDemo> mEnvironmentMappingDemo;
	};
}
