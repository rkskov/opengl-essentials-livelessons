#include "pch.h"

using namespace std;
using namespace Library;

namespace Rendering
{
	RTTI_DEFINITIONS(RenderingGame)

	RenderingGame::RenderingGame(HINSTANCE instance, const wstring& windowTitle) :
		Game(instance, windowTitle),
		mCamera(nullptr), mKeyboardHandler(nullptr), mPointDemo(nullptr)
	{
	}

	void RenderingGame::Initialize()
	{
		mCamera = new FirstPersonCamera(*this);
		mComponents.push_back(mCamera);
		mServices.AddService(Camera::TypeIdClass(), mCamera);

		using namespace std::placeholders;
		mKeyboardHandler = bind(&RenderingGame::OnKey, this, _1, _2, _3, _4);
		AddKeyboardHandler(mKeyboardHandler);

		mPointDemo = new PointDemo(*this, *mCamera);
		mComponents.push_back(mPointDemo);

		Game::Initialize();
	}

	void RenderingGame::Shutdown()
	{
		DeleteObject(mPointDemo);

		RemoveKeyboardHandler(mKeyboardHandler);
		DeleteObject(mCamera);

		Game::Shutdown();
	}

	void RenderingGame::Draw(const GameTime& gameTime)
	{
		glClearBufferfv(GL_COLOR, 0, &ColorHelper::CornflowerBlue[0]);

		Game::Draw(gameTime);

		glfwSwapBuffers(mWindow);
	}

	void RenderingGame::OnKey(int key, int scancode, int action, int mods)
	{
		UNREFERENCED_PARAMETER(scancode);
		UNREFERENCED_PARAMETER(mods);

		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		{
			Exit();
		}
	}
}