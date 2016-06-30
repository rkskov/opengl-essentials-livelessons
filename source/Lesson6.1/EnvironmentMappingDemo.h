#pragma once

#include "DrawableGameComponent.h"
#include "EnvironmentMappingEffect.h"

namespace Library
{
	class Light;
}

namespace Rendering
{
	class EnvironmentMappingDemo : public Library::DrawableGameComponent
	{
		RTTI_DECLARATIONS(EnvironmentMappingDemo, Library::DrawableGameComponent)

	public:		
		EnvironmentMappingDemo(Library::Game& game, Library::Camera& camera);
		EnvironmentMappingDemo(const EnvironmentMappingDemo&) = delete;
		EnvironmentMappingDemo& operator=(const EnvironmentMappingDemo&) = delete;
		EnvironmentMappingDemo(EnvironmentMappingDemo&&) = delete;
		EnvironmentMappingDemo& operator=(EnvironmentMappingDemo&&) = delete;
		~EnvironmentMappingDemo();

		virtual void Initialize() override;
		virtual void Update(const Library::GameTime& gameTime) override;
		virtual void Draw(const Library::GameTime& gameTime) override;

	private:
		void UpdateAmbientLight(const Library::GameTime& gameTime);
		void UpdateReflectionAmount(const Library::GameTime& gameTime);
		
		glm::mat4 mWorldMatrix;
		glm::vec4 mEnvironmentColor;
		EnvironmentMappingEffect mShaderProgram;
		GLuint mVertexArrayObject;
		GLuint mVertexBuffer;
		GLuint mIndexBuffer;
		std::uint32_t mIndexCount;
		GLuint mColorTexture;
		GLuint mEnvironmentMap;
		std::unique_ptr<Library::Light> mAmbientLight;
		float mReflectionAmount;
		GLuint mColorTextureSampler;
		GLuint mEnvironmentMapSampler;
	};
}
