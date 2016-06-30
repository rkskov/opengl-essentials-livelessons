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

	private:
		std::shared_ptr<Library::FirstPersonCamera> mCamera;
		std::shared_ptr<Library::Grid> mGrid;
		std::shared_ptr<PointLightDemo> mPointLightDemo;
	};
}
