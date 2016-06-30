#pragma once

#include "DrawableGameComponent.h"
#include "TransparencyMappingEffect.h"

namespace Library
{
	class Light;
	class DirectionalLight;
	class ProxyModel;
}

namespace Rendering
{
	class TransparencyMappingDemo final : public Library::DrawableGameComponent
	{
		RTTI_DECLARATIONS(TransparencyMappingDemo, Library::DrawableGameComponent)

	public:
		TransparencyMappingDemo(Library::Game& game, Library::Camera& camera);
		TransparencyMappingDemo(const TransparencyMappingDemo&) = delete;
		TransparencyMappingDemo& operator=(const TransparencyMappingDemo&) = delete;
		TransparencyMappingDemo(TransparencyMappingDemo&&) = delete;
		TransparencyMappingDemo& operator=(TransparencyMappingDemo&&) = delete;
		~TransparencyMappingDemo();

		virtual void Initialize() override;
		virtual void Update(const Library::GameTime& gameTime) override;
		virtual void Draw(const Library::GameTime& gameTime) override;

	private:
		void UpdateAmbientLight(const Library::GameTime& gameTime);
		void UpdateDirectionalLight(const Library::GameTime& gameTime);
		void UpdateSpecularLight(const Library::GameTime& gameTime);

		static const glm::vec2 LightRotationRate;
		static const float LightModulationRate;

		glm::mat4 mWorldMatrix;
		glm::vec4 mSpecularColor;
		glm::vec4 mFogColor;
		TransparencyMappingEffect mShaderProgram;
		GLuint mVertexArrayObject;
		GLuint mVertexBuffer;
		GLuint mIndexBuffer;		
		std::uint32_t mIndexCount;
		GLuint mColorTexture;
		std::unique_ptr<Library::Light> mAmbientLight;
		std::unique_ptr<Library::DirectionalLight> mDirectionalLight;
		std::unique_ptr<Library::ProxyModel> mProxyModel;
		float mSpecularPower;		
		float mFogStart;
		float mFogRange;
		GLuint mAlphaMap;
		GLuint mTrilinearSampler;
	};
}
