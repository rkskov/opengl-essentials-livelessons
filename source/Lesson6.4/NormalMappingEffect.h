#pragma once

#include "ShaderProgram.h"
#include "VertexDeclarations.h"

namespace Rendering
{
	class NormalMappingEffect final : public Library::ShaderProgram
    {
		RTTI_DECLARATIONS(NormalMappingEffect, Library::ShaderProgram)

        SHADER_VARIABLE_DECLARATION(WorldViewProjection)
		SHADER_VARIABLE_DECLARATION(World)
		SHADER_VARIABLE_DECLARATION(AmbientColor)
		SHADER_VARIABLE_DECLARATION(LightColor)
		SHADER_VARIABLE_DECLARATION(LightDirection)
		SHADER_VARIABLE_DECLARATION(CameraPosition)
		SHADER_VARIABLE_DECLARATION(SpecularColor)
		SHADER_VARIABLE_DECLARATION(SpecularPower)
		SHADER_VARIABLE_DECLARATION(FogColor)
		SHADER_VARIABLE_DECLARATION(FogStart)
		SHADER_VARIABLE_DECLARATION(FogRange)

    public:
        NormalMappingEffect();

		virtual void Initialize(GLuint vertexArrayObject) override;
		virtual void CreateVertexBuffer(const Library::Mesh& mesh, GLuint& vertexBuffer) const override;
		void CreateVertexBuffer(Library::VertexPositionTextureNormalTangentBinormal* vertices, std::uint32_t vertexCount, GLuint& vertexBuffer) const;
		virtual std::uint32_t VertexSize() const override;

	private:
		enum VertexAttribute
		{
			Position = 0,
			TextureCoordinate = 1,
			Normal = 2,
			Tangent = 3,
			Binormal = 4
		};
    };
}