#pragma once

#include "DrawableGameComponent.h"
#include "ShaderProgram.h"
#include "Game.h"

namespace Library
{
	class Mesh;
}

using namespace Library;

namespace Rendering
{
	class TexturedModelDemo final : public DrawableGameComponent
	{
		RTTI_DECLARATIONS(TexturedModelDemo, DrawableGameComponent)

	public:		
		TexturedModelDemo(Game& game, Camera& camera);
		TexturedModelDemo(const TexturedModelDemo&) = delete;
		TexturedModelDemo& operator=(const TexturedModelDemo&) = delete;
		TexturedModelDemo(TexturedModelDemo&&) = delete;
		TexturedModelDemo& operator=(TexturedModelDemo&&) = delete;
		~TexturedModelDemo();

		virtual void Initialize() override;
		virtual void Draw(const GameTime& gameTime) override;

	private:
		enum class VertexAttribute
		{
			Position = 0,
			TextureCoordinate = 1
		};		

		void CreateVertexBuffer(const Mesh& mesh, GLuint& vertexBuffer);
		void OnKey(int key, int scancode, int action, int mods);

		glm::mat4 mWorldMatrix;
		Game::KeyboardHandler mKeyboardHandler;
		ShaderProgram mShaderProgram;
		GLuint mVertexArrayObject;
		GLuint mVertexBuffer;
		GLuint mIndexBuffer;
		GLint mWorldViewProjectionLocation;		
		GLuint mIndexCount;
		GLuint mColorTexture;
		GLuint mAltTexture;
		GLuint mActiveTexture;
	};
}
