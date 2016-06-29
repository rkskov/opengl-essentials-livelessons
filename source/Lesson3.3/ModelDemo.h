#pragma once

#include "DrawableGameComponent.h"
#include "BasicEffect.h"

namespace Library
{
	class Mesh;
}
namespace Rendering
{
	class ModelDemo final : public Library::DrawableGameComponent
	{
		RTTI_DECLARATIONS(ModelDemo, Library::DrawableGameComponent)

	public:		
		ModelDemo(Library::Game& game, Library::Camera& camera);
		ModelDemo(const ModelDemo&) = delete;
		ModelDemo& operator=(const ModelDemo&) = delete;
		ModelDemo(ModelDemo&&) = delete;
		ModelDemo& operator=(ModelDemo&&) = delete;
		~ModelDemo();

		virtual void Initialize() override;
		virtual void Draw(const Library::GameTime& gameTime) override;

	private:
		enum class VertexAttribute
		{
			Position = 0,
			Color = 1
		};		

		void CreateVertexBuffer(const Library::Mesh& mesh, GLuint& vertexBuffer);

		glm::mat4 mWorldMatrix;
		Library::ShaderProgram mShaderProgram;
		GLuint mVertexArrayObject;
		GLuint mVertexBuffer;
		GLuint mIndexBuffer;
		GLint mWorldViewProjectionLocation;		
		std::uint32_t mIndexCount;
	};
}
