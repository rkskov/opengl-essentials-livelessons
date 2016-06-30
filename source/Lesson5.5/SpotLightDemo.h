#pragma once

#include "DrawableGameComponent.h"
#include "SpotLightEffect.h"

namespace Library
{
	class Light;
	class SpotLight;
	class ProxyModel;
}

namespace Rendering
{
	class SpotLightDemo final : public Library::DrawableGameComponent
	{
		RTTI_DECLARATIONS(SpotLightDemo, Library::DrawableGameComponent)

	public:		
		SpotLightDemo(Library::Game& game, Library::Camera& camera);
		SpotLightDemo(const SpotLightDemo&) = delete;
		SpotLightDemo& operator=(const SpotLightDemo&) = delete;
		SpotLightDemo(SpotLightDemo&&) = delete;
		SpotLightDemo& operator=(SpotLightDemo&&) = delete;
		~SpotLightDemo();

		virtual void Initialize() override;
		virtual void Update(const Library::GameTime& gameTime) override;
		virtual void Draw(const Library::GameTime& gameTime) override;

	private:
		void UpdateAmbientLight(const Library::GameTime& gameTime);
		void UpdateSpotLight(const Library::GameTime& gameTime);
		void UpdateSpecularLight(const Library::GameTime& gameTime);

		static const float LightModulationRate;
		static const float LightMovementRate;
		static const glm::vec2 LightRotationRate;

		glm::mat4 mWorldMatrix;
		glm::vec4 mSpecularColor;
		SpotLightEffect mShaderProgram;
		GLuint mVertexArrayObject;
		GLuint mVertexBuffer;
		GLuint mIndexBuffer;		
		std::uint32_t mIndexCount;
		GLuint mColorTexture;
		std::unique_ptr<Library::Light> mAmbientLight;
		std::unique_ptr<Library::SpotLight> mSpotLight;		
		std::unique_ptr<Library::ProxyModel> mProxyModel;
		float mSpecularPower;
	};
}
