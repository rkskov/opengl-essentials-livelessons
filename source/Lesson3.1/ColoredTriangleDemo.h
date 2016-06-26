#pragma once

#include "DrawableGameComponent.h"
#include "ShaderProgram.h"

using namespace Library;

namespace Rendering
{
	class ColoredTriangleDemo final : public DrawableGameComponent
	{
		RTTI_DECLARATIONS(ColoredTriangleDemo, DrawableGameComponent)

	public:		
		ColoredTriangleDemo(Game& game, Camera& camera);
		ColoredTriangleDemo(const ColoredTriangleDemo&) = delete;
		ColoredTriangleDemo& operator=(const ColoredTriangleDemo&) = delete;
		ColoredTriangleDemo(ColoredTriangleDemo&&) = delete;
		ColoredTriangleDemo& operator=(ColoredTriangleDemo&&) = delete;
		~ColoredTriangleDemo();

		virtual void Initialize() override;
		virtual void Draw(const GameTime& gameTime) override;

	private:
		enum class VertexAttribute
		{
			Position = 0,
			Color = 1
		};

		ShaderProgram mShaderProgram;
		GLuint mVertexArrayObject;
		GLuint mVertexBuffer;
	};
}
