#pragma once

#include "DrawableGameComponent.h"
#include "ShaderProgram.h"
#include "VertexDeclarations.h"
#include "Game.h"

namespace Library
{
	class Mesh;
}

using namespace Library;

namespace Rendering
{
	class WrappingModesDemo final : public DrawableGameComponent
	{
		RTTI_DECLARATIONS(WrappingModesDemo, DrawableGameComponent)

	public:		
		WrappingModesDemo(Game& game, Camera& camera);
		WrappingModesDemo(const WrappingModesDemo&) = delete;
		WrappingModesDemo& operator=(const WrappingModesDemo&) = delete;
		WrappingModesDemo(WrappingModesDemo&&) = delete;
		WrappingModesDemo& operator=(WrappingModesDemo&&) = delete;
		~WrappingModesDemo();

		virtual void Initialize() override;
		virtual void Draw(const GameTime& gameTime) override;

	private:
		enum class VertexAttribute
		{
			Position = 0,
			TextureCoordinate = 1
		};

		enum class WrappingMode
		{
			Repeat = 0,
			MirroredRepeat,
			ClampToEdge,
			ClampToBorder,
			End
		};

		void CreateVertexBuffer(VertexPositionTexture* vertices, GLuint vertexCount, GLuint& vertexBuffer);
		void CreateIndexBuffer(std::uint32_t* indices, GLuint indexCount, GLuint& indexBuffer);
		void OnKey(int key, int scancode, int action, int mods);

		glm::mat4 mWorldMatrix;
		std::vector<GLuint> mTextureSamplers;
		std::map<WrappingMode, GLuint> mTextureSamplersByWrappingMode;
		ShaderProgram mShaderProgram;
		GLuint mVertexArrayObject;
		GLuint mVertexBuffer;
		GLuint mIndexBuffer;
		GLint mWorldViewProjectionLocation;		
		GLuint mIndexCount;
		GLuint mColorTexture;		
		WrappingMode mActiveWrappingMode;
		Game::KeyboardHandler mKeyboardHandler;
	};
}
