#pragma once

#include "Game.h"

namespace Library
{
	class GameTime;
	class FirstPersonCamera;
	class Grid;
}

namespace Rendering
{
	class PointLightDemo;

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

		Library::FirstPersonCamera* mCamera;
		KeyboardHandler mKeyboardHandler;
		Library::Grid* mGrid;

		PointLightDemo* mPointLightDemo;
	};
}
