#include "RenderingGame.h"
#include "GameException.h"
#include "FirstPersonCamera.h"
#include "ColorHelper.h"
#include "VectorHelper.h"
#include "Grid.h"

#include "WrappingModesDemo.h"

using namespace glm;

namespace Rendering
{
	RTTI_DEFINITIONS(RenderingGame)

	RenderingGame::RenderingGame(HINSTANCE instance, const std::wstring& windowTitle)
		:  Game(instance, windowTitle),
		mCamera(nullptr), mKeyboardHandler(nullptr),
		mWrappingModesDemo(nullptr)
	{
		mDepthStencilBufferEnabled = true;
	}

	void RenderingGame::Initialize()
	{
		mCamera = new FirstPersonCamera(*this);
		mComponents.push_back(mCamera);
		mServices.AddService(Camera::TypeIdClass(), mCamera);

		using namespace std::placeholders;
		mKeyboardHandler = std::bind(&RenderingGame::OnKey, this, _1, _2, _3, _4);
		AddKeyboardHandler(mKeyboardHandler);

		mGrid = new Grid(*this, *mCamera);
		mComponents.push_back(mGrid);

		mWrappingModesDemo = new WrappingModesDemo(*this, *mCamera);
		mComponents.push_back(mWrappingModesDemo);

		Game::Initialize();

		mCamera->SetPosition(0, 5, 10);
	}

	void RenderingGame::Shutdown()
	{
		DeleteObject(mWrappingModesDemo);

		DeleteObject(mGrid);
		RemoveKeyboardHandler(mKeyboardHandler);
		DeleteObject(mCamera);

		Game::Shutdown();
	}

	void RenderingGame::Draw(const GameTime& gameTime)
	{
		static const GLfloat one = 1.0f;

		glClearBufferfv(GL_COLOR, 0, &ColorHelper::CornflowerBlue[0]);
		glClearBufferfv(GL_DEPTH, 0, &one);

		Game::Draw(gameTime);

		glfwSwapBuffers(mWindow);
	}

	void RenderingGame::OnKey(int key, int scancode, int action, int mods)
	{
		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		{
			Exit();
		}
	}
}