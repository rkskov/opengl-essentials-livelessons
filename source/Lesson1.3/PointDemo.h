#pragma once

#include "DrawableGameComponent.h"
#include "GL/glcorearb.h"

using namespace Library;

namespace Rendering
{
	class PointDemo : public DrawableGameComponent
	{
		RTTI_DECLARATIONS(PointDemo, DrawableGameComponent)

	public:		
		PointDemo(Game& game, Camera& camera);
		PointDemo();
		PointDemo(const PointDemo&) = delete;
		PointDemo& operator=(const PointDemo&) = delete;
		PointDemo(PointDemo&&) = delete;
		PointDemo& operator=(PointDemo&&) = delete;
		~PointDemo();

		virtual void Initialize() override;
		virtual void Draw(const GameTime& gameTime) override;

	private:
		GLuint mShaderProgram;
		GLuint mVertexArrayObject;
	};
}
