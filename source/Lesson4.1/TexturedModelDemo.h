#pragma once

#include "DrawableGameComponent.h"
#include "ShaderProgram.h"
#include "Game.h"

namespace Library
{
	class Mesh;
}

namespace Rendering
{
	class TexturedModelDemo final : public Library::DrawableGameComponent
	{
		RTTI_DECLARATIONS(TexturedModelDemo, Library::DrawableGameComponent)

	public:		
		TexturedModelDemo(Library::Game& game, Library::Camera& camera);
		TexturedModelDemo(const TexturedModelDemo&) = delete;
		TexturedModelDemo& operator=(const TexturedModelDemo&) = delete;
		TexturedModelDemo(TexturedModelDemo&&) = delete;
		TexturedModelDemo& operator=(TexturedModelDemo&&) = delete;
		~TexturedModelDemo();

		virtual void Initialize() override;
		virtual void Draw(const Library::GameTime& gameTime) override;

	private:
		enum class VertexAttribute
		{
			Position = 0,
			TextureCoordinate = 1
		};		

		void CreateVertexBuffer(const Library::Mesh& mesh, GLuint& vertexBuffer);
		void OnKey(int key, int scancode, int action, int mods);

		glm::mat4 mWorldMatrix;
		Library::Game::KeyboardHandler mKeyboardHandler;
		Library::ShaderProgram mShaderProgram;
		GLuint mVertexArrayObject;
		GLuint mVertexBuffer;
		GLuint mIndexBuffer;
		GLint mWorldViewProjectionLocation;		
		std::uint32_t mIndexCount;
		GLuint mColorTexture;
		GLuint mAltTexture;
		GLuint mActiveTexture;
	};
}
