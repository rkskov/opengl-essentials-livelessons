#pragma once

#include "DrawableGameComponent.h"
#include "PointLightEffect.h"

namespace Library
{
	class Light;
	class PointLight;
	class ProxyModel;
}

namespace Rendering
{
	class PointLightDemo final : public Library::DrawableGameComponent
	{
		RTTI_DECLARATIONS(PointLightDemo, DrawableGameComponent)

	public:		
		PointLightDemo(Library::Game& game, Library::Camera& camera);
		PointLightDemo(const PointLightDemo&) = delete;
		PointLightDemo& operator=(const PointLightDemo&) = delete;
		PointLightDemo(PointLightDemo&&) = delete;
		PointLightDemo& operator=(PointLightDemo&&) = delete;
		~PointLightDemo();

		virtual void Initialize() override;
		virtual void Update(const Library::GameTime& gameTime) override;
		virtual void Draw(const Library::GameTime& gameTime) override;

	private:
		void UpdateAmbientLight(const Library::GameTime& gameTime);
		void UpdatePointLight(const Library::GameTime& gameTime);
		void UpdateSpecularLight(const Library::GameTime& gameTime);

		static const float LightModulationRate;
		static const float LightMovementRate;
		static const float RadiusModulationRate;

		glm::mat4 mWorldMatrix;
		glm::vec4 mSpecularColor;
		PointLightEffect mShaderProgram;
		GLuint mVertexArrayObject;
		GLuint mVertexBuffer;
		GLuint mIndexBuffer;		
		std::uint32_t mIndexCount;
		GLuint mColorTexture;
		std::unique_ptr<Library::Light> mAmbientLight;
		std::unique_ptr<Library::PointLight> mPointLight;
		std::unique_ptr<Library::ProxyModel> mProxyModel;
		float mSpecularPower;
	};
}
