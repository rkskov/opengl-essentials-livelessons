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
		mDepthStencilBufferEnabled = true;
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

		mGrid = make_shared<Grid>(*this, *mCamera);
		mComponents.push_back(mGrid);

		mDiffuseLightingDemo = make_shared<DiffuseLightingDemo>(*this, *mCamera);
		mComponents.push_back(mDiffuseLightingDemo);

		Game::Initialize();

		mCamera->SetPosition(0, 5, 20);
	}
	
	void RenderingGame::Draw(const GameTime& gameTime)
	{
		static const GLfloat one = 1.0f;

		glClearBufferfv(GL_COLOR, 0, &ColorHelper::CornflowerBlue[0]);
		glClearBufferfv(GL_DEPTH, 0, &one);

		Game::Draw(gameTime);

		glfwSwapBuffers(mWindow);
	}
}