#pragma once

#include "DrawableGameComponent.h"
#include "ShaderProgram.h"

using namespace Library;

namespace Rendering
{
	class CubeDemo : public DrawableGameComponent
	{
		RTTI_DECLARATIONS(CubeDemo, DrawableGameComponent)

	public:		
		CubeDemo(Game& game, Camera& camera);
		CubeDemo(const CubeDemo&) = delete;
		CubeDemo& operator=(const CubeDemo&) = delete;
		CubeDemo(CubeDemo&&) = delete;
		CubeDemo& operator=(CubeDemo&&) = delete;
		~CubeDemo();

		virtual void Initialize() override;
		virtual void Update(const GameTime& gameTime) override;
		virtual void Draw(const GameTime& gameTime) override;

	private:
		enum class VertexAttribute
		{
			Position = 0,
			Color = 1
		};

		static const GLfloat RotationRate;

		glm::mat4 mWorldMatrix;
		ShaderProgram mShaderProgram;
		GLuint mVertexArrayObject;
		GLuint mVertexBuffer;
		GLuint mIndexBuffer;
		GLint mWorldViewProjectionLocation;		
	};
}
