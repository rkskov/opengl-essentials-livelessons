#pragma once

#include "DrawableGameComponent.h"
#include "ShaderProgram.h"

namespace Library
{
	class Mesh;
	class Light;
	class DirectionalLight;
	class ProxyModel;
}

namespace Rendering
{
	class DiffuseLightingDemo final : public Library::DrawableGameComponent
	{
		RTTI_DECLARATIONS(DiffuseLightingDemo, Library::DrawableGameComponent)

	public:		
		DiffuseLightingDemo(Library::Game& game, Library::Camera& camera);
		DiffuseLightingDemo(const DiffuseLightingDemo&) = delete;
		DiffuseLightingDemo& operator=(const DiffuseLightingDemo&) = delete;
		DiffuseLightingDemo(DiffuseLightingDemo&&) = delete;
		DiffuseLightingDemo& operator=(DiffuseLightingDemo&&) = delete;
		~DiffuseLightingDemo();

		virtual void Initialize() override;
		virtual void Update(const Library::GameTime& gameTime) override;
		virtual void Draw(const Library::GameTime& gameTime) override;

	private:
		enum class VertexAttribute
		{
			Position = 0,
			TextureCoordinate = 1,
			Normal = 2
		};	

		void CreateVertexBuffer(const Library::Mesh& mesh, GLuint& vertexBuffer);
		void UpdateAmbientLight(const Library::GameTime& gameTime);
		void UpdateDirectionalLight(const Library::GameTime& gameTime);

		static const glm::vec2 LightRotationRate;

		glm::mat4 mWorldMatrix;
		Library::ShaderProgram mShaderProgram;
		GLuint mVertexArrayObject;
		GLuint mVertexBuffer;
		GLuint mIndexBuffer;
		GLint mWorldViewProjectionLocation;
		GLint mWorldLocation;
		GLint mAmbientColorLocation;
		GLint mLightColorLocation;
		GLint mLightDirectionLocation;		
		std::uint32_t mIndexCount;
		GLuint mColorTexture;
		std::unique_ptr<Library::Light> mAmbientLight;
		std::unique_ptr<Library::DirectionalLight> mDirectionalLight;
		std::unique_ptr<Library::ProxyModel> mProxyModel;
	};
}
