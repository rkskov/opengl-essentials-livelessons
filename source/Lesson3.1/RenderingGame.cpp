#include "pch.h"

using namespace glm;
using namespace std;
using namespace Library;

namespace Rendering
{
	RTTI_DEFINITIONS(RenderingGame)

	RenderingGame::RenderingGame(HINSTANCE instance, const wstring& windowTitle) :
		Game(instance, windowTitle)
	{
	}

	void RenderingGame::Initialize()
	{
		mCamera = make_shared<FirstPersonCamera>(*this);
		mComponents.push_back(mCamera);
		mServices.AddService(Camera::TypeIdClass(), mCamera.get());

		auto keyboardHandler = [&](int key, int scancode, int action, int mods) {
			UNREFERENCED_PARAMETER(scancode);
			UNREFERENCED_PARAMETER(mods);

			if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
			{
				Exit();
			}
		};
		AddKeyboardHandler(keyboardHandler);

		mColoredTriangleDemo = make_shared<ColoredTriangleDemo>(*this, *mCamera);
		mComponents.push_back(mColoredTriangleDemo);

		Game::Initialize();
	}

	void RenderingGame::Draw(const GameTime& gameTime)
	{
		glClearBufferfv(GL_COLOR, 0, &ColorHelper::CornflowerBlue[0]);

		Game::Draw(gameTime);

		glfwSwapBuffers(mWindow);
	}
}