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
	class FilteringModesDemo final : public Library::DrawableGameComponent
	{
		RTTI_DECLARATIONS(FilteringModesDemo, Library::DrawableGameComponent)

	public:		
		FilteringModesDemo(Library::Game& game, Library::Camera& camera);
		FilteringModesDemo(const FilteringModesDemo&) = delete;
		FilteringModesDemo& operator=(const FilteringModesDemo&) = delete;
		FilteringModesDemo(FilteringModesDemo&&) = delete;
		FilteringModesDemo& operator=(FilteringModesDemo&&) = delete;
		~FilteringModesDemo();

		virtual void Initialize() override;
		virtual void Draw(const Library::GameTime& gameTime) override;

	private:
		enum class VertexAttribute
		{
			Position = 0,
			TextureCoordinate = 1
		};

		enum class FilteringMode
		{
			Point = 0,
			Linear,
			PointMipMapPoint,
			LinearMipMapPoint,
			PointMipMapLinear,
			TriLinear,
			End
		};

		static const std::string FilteringModeNames[];		

		void CreateVertexBuffer(Library::VertexPositionTexture* vertices, std::uint32_t vertexCount, GLuint& vertexBuffer);
		void CreateIndexBuffer(std::uint32_t* indices, std::uint32_t indexCount, GLuint& indexBuffer);
		void OnKey(int key, int scancode, int action, int mods);
		void OutputFilteringMode();

		glm::mat4 mWorldMatrix;
		std::vector<GLuint> mTextureSamplers;
		std::map<FilteringMode, GLuint> mTextureSamplersByFilteringMode;
		Library::ShaderProgram mShaderProgram;
		GLuint mVertexArrayObject;
		GLuint mVertexBuffer;
		GLuint mIndexBuffer;
		GLint mWorldViewProjectionLocation;
		std::uint32_t mIndexCount;
		GLuint mColorTexture;
		FilteringMode mActiveFilteringMode;
		Library::Game::KeyboardHandler mKeyboardHandler;
	};
}
