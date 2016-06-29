#pragma once

#include "ShaderProgram.h"
#include "VertexDeclarations.h"

namespace Rendering
{
	class EnvironmentMappingEffect : public Library::ShaderProgram
    {
		RTTI_DECLARATIONS(EnvironmentMappingEffect, ShaderProgram)

        SHADER_VARIABLE_DECLARATION(WorldViewProjection)
		SHADER_VARIABLE_DECLARATION(World)
		SHADER_VARIABLE_DECLARATION(AmbientColor)
		SHADER_VARIABLE_DECLARATION(EnvironmentColor)
		SHADER_VARIABLE_DECLARATION(ReflectionAmount)
		SHADER_VARIABLE_DECLARATION(CameraPosition)

    public:
        EnvironmentMappingEffect();

		virtual void Initialize(GLuint vertexArrayObject) override;
		virtual void CreateVertexBuffer(const Library::Mesh& mesh, GLuint& vertexBuffer) const override;
		void CreateVertexBuffer(Library::VertexPositionTextureNormal* vertices, std::uint32_t vertexCount, GLuint& vertexBuffer) const;
		virtual std::uint32_t VertexSize() const override;

	private:
		enum class VertexAttribute
		{
			Position = 0,
			TextureCoordinate = 1,
			Normal = 2
		};
    };
}