#pragma once

#include "DrawableGameComponent.h"
#include "FogEffect.h"

namespace Library
{
	class Light;
	class DirectionalLight;
	class ProxyModel;
}

namespace Rendering
{
	class FogDemo : public Library::DrawableGameComponent
	{
		RTTI_DECLARATIONS(FogDemo, Library::DrawableGameComponent)

	public:
		FogDemo(Library::Game& game, Library::Camera& camera);
		FogDemo(const FogDemo&) = delete;
		FogDemo& operator=(const FogDemo&) = delete;
		FogDemo(FogDemo&&) = delete;
		FogDemo& operator=(FogDemo&&) = delete;
		~FogDemo();

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
		FogEffect mShaderProgram;
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
	};
}
