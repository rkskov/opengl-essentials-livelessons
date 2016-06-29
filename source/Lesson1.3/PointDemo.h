#pragma once

#include "DrawableGameComponent.h"
#include "GL/glcorearb.h"

namespace Rendering
{
	class PointDemo final : public Library::DrawableGameComponent
	{
		RTTI_DECLARATIONS(PointDemo, Library::DrawableGameComponent)

	public:		
		PointDemo(Library::Game& game, Library::Camera& camera);
		PointDemo(const PointDemo&) = delete;
		PointDemo& operator=(const PointDemo&) = delete;
		PointDemo(PointDemo&&) = delete;
		PointDemo& operator=(PointDemo&&) = delete;
		~PointDemo();

		virtual void Initialize() override;
		virtual void Draw(const Library::GameTime& gameTime) override;

	private:
		GLuint mShaderProgram;
		GLuint mVertexArrayObject;
	};
}
