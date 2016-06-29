#pragma once

#include "DrawableGameComponent.h"
#include "ShaderProgram.h"
#include "Game.h"

namespace Library
{
	class VertexPositionTexture;
}

namespace Rendering
{
	class WrappingModesDemo final : public Library::DrawableGameComponent
	{
		RTTI_DECLARATIONS(WrappingModesDemo, Library::DrawableGameComponent)

	public:		
		WrappingModesDemo(Library::Game& game, Library::Camera& camera);
		WrappingModesDemo(const WrappingModesDemo&) = delete;
		WrappingModesDemo& operator=(const WrappingModesDemo&) = delete;
		WrappingModesDemo(WrappingModesDemo&&) = delete;
		WrappingModesDemo& operator=(WrappingModesDemo&&) = delete;
		~WrappingModesDemo();

		virtual void Initialize() override;
		virtual void Draw(const Library::GameTime& gameTime) override;

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

		void CreateVertexBuffer(Library::VertexPositionTexture* vertices, std::uint32_t vertexCount, GLuint& vertexBuffer);
		void CreateIndexBuffer(std::uint32_t* indices, std::uint32_t indexCount, GLuint& indexBuffer);
		void OnKey(int key, int scancode, int action, int mods);

		glm::mat4 mWorldMatrix;
		std::vector<GLuint> mTextureSamplers;
		std::map<WrappingMode, GLuint> mTextureSamplersByWrappingMode;
		Library::ShaderProgram mShaderProgram;
		GLuint mVertexArrayObject;
		GLuint mVertexBuffer;
		GLuint mIndexBuffer;
		GLint mWorldViewProjectionLocation;		
		std::uint32_t mIndexCount;
		GLuint mColorTexture;		
		WrappingMode mActiveWrappingMode;
		Library::Game::KeyboardHandler mKeyboardHandler;
	};
}
