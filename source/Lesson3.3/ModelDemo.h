#pragma once

#include "DrawableGameComponent.h"
#include "BasicEffect.h"

namespace Library
{
	class Mesh;
}

using namespace Library;

namespace Rendering
{
	class ModelDemo final : public DrawableGameComponent
	{
		RTTI_DECLARATIONS(ModelDemo, DrawableGameComponent)

	public:		
		ModelDemo(Game& game, Camera& camera);
		ModelDemo(const ModelDemo&) = delete;
		ModelDemo& operator=(const ModelDemo&) = delete;
		ModelDemo(ModelDemo&&) = delete;
		ModelDemo& operator=(ModelDemo&&) = delete;
		~ModelDemo();

		virtual void Initialize() override;
		virtual void Draw(const GameTime& gameTime) override;

	private:
		enum class VertexAttribute
		{
			Position = 0,
			Color = 1
		};		

		void CreateVertexBuffer(const Mesh& mesh, GLuint& vertexBuffer);

		glm::mat4 mWorldMatrix;
		ShaderProgram mShaderProgram;
		GLuint mVertexArrayObject;
		GLuint mVertexBuffer;
		GLuint mIndexBuffer;
		GLint mWorldViewProjectionLocation;		
		GLuint mIndexCount;
	};
}
