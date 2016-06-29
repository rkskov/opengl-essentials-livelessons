#pragma once

#include "DrawableGameComponent.h"
#include "ShaderProgram.h"

namespace Rendering
{
	class CubeDemo final : public Library::DrawableGameComponent
	{
		RTTI_DECLARATIONS(CubeDemo, Library::DrawableGameComponent)

	public:		
		CubeDemo(Library::Game& game, Library::Camera& camera);
		CubeDemo(const CubeDemo&) = delete;
		CubeDemo& operator=(const CubeDemo&) = delete;
		CubeDemo(CubeDemo&&) = delete;
		CubeDemo& operator=(CubeDemo&&) = delete;
		~CubeDemo();

		virtual void Initialize() override;
		virtual void Update(const Library::GameTime& gameTime) override;
		virtual void Draw(const Library::GameTime& gameTime) override;

	private:
		enum class VertexAttribute
		{
			Position = 0,
			Color = 1
		};

		static const GLfloat RotationRate;

		glm::mat4 mWorldMatrix;
		Library::ShaderProgram mShaderProgram;
		GLuint mVertexArrayObject;
		GLuint mVertexBuffer;
		GLuint mIndexBuffer;
		GLint mWorldViewProjectionLocation;
		std::uint32_t mIndexCount;
	};
}
