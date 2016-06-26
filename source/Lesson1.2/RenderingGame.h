#pragma once

#include "Game.h"

namespace Library
{
	class GameTime;
}

namespace Rendering
{
	class RenderingGame final : public Library::Game
	{
		RTTI_DECLARATIONS(RenderingGame, Library::Game)

	public:
		RenderingGame(HINSTANCE instance, const std::wstring& windowTitle);

	protected:
		virtual void Draw(const Library::GameTime& gameTime) override;
	};
}
