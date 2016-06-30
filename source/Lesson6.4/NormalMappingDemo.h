#pragma once

#include "DrawableGameComponent.h"
#include "NormalMappingEffect.h"
#include "FogEffect.h"
#include "Game.h"

namespace Library
{
	class Light;
	class DirectionalLight;
	class ProxyModel;
}

namespace Rendering
{
	class NormalMappingDemo final : public Library::DrawableGameComponent
	{
		RTTI_DECLARATIONS(NormalMappingDemo, Library::DrawableGameComponent)

	public:		
		NormalMappingDemo(Library::Game& game, Library::Camera& camera);
		NormalMappingDemo(const NormalMappingDemo&) = delete;
		NormalMappingDemo& operator=(const NormalMappingDemo&) = delete;
		NormalMappingDemo(NormalMappingDemo&&) = delete;
		NormalMappingDemo& operator=(NormalMappingDemo&&) = delete;
		~NormalMappingDemo();

		virtual void Initialize() override;
		virtual void Update(const Library::GameTime& gameTime) override;
		virtual void Draw(const Library::GameTime& gameTime) override;

	private:
		void UpdateAmbientLight(const Library::GameTime& gameTime);
		void UpdateDirectionalLight(const Library::GameTime& gameTime);
		void UpdateSpecularLight(const Library::GameTime& gameTime);
		void OnKey(int key, int scancode, int action, int mods);

		static const glm::vec2 LightRotationRate;
		static const float LightModulationRate;

		glm::mat4 mWorldMatrix;
		glm::vec4 mSpecularColor;
		glm::vec4 mFogColor;
		NormalMappingEffect mNormalMappingEffect;
		FogEffect mFogEffect;
		GLuint mNormalMappingVAO;
		GLuint mFogVAO;
		GLuint mNormalMappingVertexBuffer;
		GLuint mFogVertexBuffer;
		GLuint mIndexBuffer;		
		std::uint32_t mIndexCount;
		GLuint mColorTexture;
		std::unique_ptr<Library::Light> mAmbientLight;
		std::unique_ptr<Library::DirectionalLight> mDirectionalLight;
		std::unique_ptr<Library::ProxyModel> mProxyModel;
		float mSpecularPower;
		float mFogStart;
		float mFogRange;
		GLuint mNormalMap;
		GLuint mTrilinearSampler;		
		Library::Game::KeyboardHandler mKeyboardHandler;
		bool mShowNormalMapping;
	};
}
