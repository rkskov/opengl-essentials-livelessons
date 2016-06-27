#pragma once

#include "DrawableGameComponent.h"
#include "BlinnPhongEffect.h"

namespace Library
{
	class Light;
	class DirectionalLight;
	class ProxyModel;
}

namespace Rendering
{
	class BlinnPhongDemo final : public Library::DrawableGameComponent
	{
		RTTI_DECLARATIONS(BlinnPhongDemo, Library::DrawableGameComponent)

	public:		
		BlinnPhongDemo(Library::Game& game, Library::Camera& camera);
		BlinnPhongDemo(const BlinnPhongDemo&) = delete;
		BlinnPhongDemo& operator=(const BlinnPhongDemo&) = delete;
		BlinnPhongDemo(BlinnPhongDemo&&) = delete;
		BlinnPhongDemo& operator=(BlinnPhongDemo&&) = delete;
		~BlinnPhongDemo();

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
		BlinnPhongEffect mShaderProgram;
		GLuint mVertexArrayObject;
		GLuint mVertexBuffer;
		GLuint mIndexBuffer;
		GLuint mIndexCount;
		GLuint mColorTexture;
		Library::Light* mAmbientLight;
		Library::DirectionalLight* mDirectionalLight;		
		float mSpecularPower;
		Library::ProxyModel* mProxyModel;
	};
}
