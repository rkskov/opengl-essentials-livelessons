#include "pch.h"

using namespace glm;
using namespace std;
using namespace Library;

namespace Rendering
{
    RTTI_DEFINITIONS(NormalMappingEffect)	

    NormalMappingEffect::NormalMappingEffect() :
		SHADER_VARIABLE_INITIALIZATION(WorldViewProjection), SHADER_VARIABLE_INITIALIZATION(World),
		SHADER_VARIABLE_INITIALIZATION(AmbientColor), SHADER_VARIABLE_INITIALIZATION(LightColor),
		SHADER_VARIABLE_INITIALIZATION(LightDirection), SHADER_VARIABLE_INITIALIZATION(CameraPosition),
		SHADER_VARIABLE_INITIALIZATION(SpecularColor), SHADER_VARIABLE_INITIALIZATION(SpecularPower),
		SHADER_VARIABLE_INITIALIZATION(FogColor), SHADER_VARIABLE_INITIALIZATION(FogStart),
		SHADER_VARIABLE_INITIALIZATION(FogRange)
    {
    }

    SHADER_VARIABLE_DEFINITION(NormalMappingEffect, WorldViewProjection)
	SHADER_VARIABLE_DEFINITION(NormalMappingEffect, World)
	SHADER_VARIABLE_DEFINITION(NormalMappingEffect, AmbientColor)
	SHADER_VARIABLE_DEFINITION(NormalMappingEffect, LightColor)
	SHADER_VARIABLE_DEFINITION(NormalMappingEffect, LightDirection)
	SHADER_VARIABLE_DEFINITION(NormalMappingEffect, CameraPosition)
	SHADER_VARIABLE_DEFINITION(NormalMappingEffect, SpecularColor)
	SHADER_VARIABLE_DEFINITION(NormalMappingEffect, SpecularPower)
	SHADER_VARIABLE_DEFINITION(NormalMappingEffect, FogColor)
	SHADER_VARIABLE_DEFINITION(NormalMappingEffect, FogStart)
	SHADER_VARIABLE_DEFINITION(NormalMappingEffect, FogRange)

	void NormalMappingEffect::Initialize(GLuint vertexArrayObject)
    {
        ShaderProgram::Initialize(vertexArrayObject);

        SHADER_VARIABLE_INSTANTIATE(WorldViewProjection)
		SHADER_VARIABLE_INSTANTIATE(World)
		SHADER_VARIABLE_INSTANTIATE(AmbientColor)
		SHADER_VARIABLE_INSTANTIATE(LightColor)
		SHADER_VARIABLE_INSTANTIATE(LightDirection)
		SHADER_VARIABLE_INSTANTIATE(CameraPosition)
		SHADER_VARIABLE_INSTANTIATE(SpecularColor)
		SHADER_VARIABLE_INSTANTIATE(SpecularPower)
		SHADER_VARIABLE_INSTANTIATE(FogColor)
		SHADER_VARIABLE_INSTANTIATE(FogStart)
		SHADER_VARIABLE_INSTANTIATE(FogRange)

		glVertexAttribPointer(static_cast<GLuint>(VertexAttribute::Position), 4, GL_FLOAT, GL_FALSE, sizeof(VertexPositionTextureNormalTangentBinormal), (void*)offsetof(VertexPositionTextureNormalTangentBinormal, Position));
		glEnableVertexAttribArray(static_cast<GLuint>(VertexAttribute::Position));

		glVertexAttribPointer(static_cast<GLuint>(VertexAttribute::TextureCoordinate), 2, GL_FLOAT, GL_FALSE, sizeof(VertexPositionTextureNormalTangentBinormal), (void*)offsetof(VertexPositionTextureNormalTangentBinormal, TextureCoordinates));
		glEnableVertexAttribArray(static_cast<GLuint>(VertexAttribute::TextureCoordinate));

		glVertexAttribPointer(static_cast<GLuint>(VertexAttribute::Normal), 3, GL_FLOAT, GL_FALSE, sizeof(VertexPositionTextureNormalTangentBinormal), (void*)offsetof(VertexPositionTextureNormalTangentBinormal, Normal));
		glEnableVertexAttribArray(static_cast<GLuint>(VertexAttribute::Normal));

		glVertexAttribPointer(static_cast<GLuint>(VertexAttribute::Tangent), 3, GL_FLOAT, GL_FALSE, sizeof(VertexPositionTextureNormalTangentBinormal), (void*)offsetof(VertexPositionTextureNormalTangentBinormal, Tangent));
		glEnableVertexAttribArray(static_cast<GLuint>(VertexAttribute::Tangent));

		glVertexAttribPointer(static_cast<GLuint>(VertexAttribute::Binormal), 3, GL_FLOAT, GL_FALSE, sizeof(VertexPositionTextureNormalTangentBinormal), (void*)offsetof(VertexPositionTextureNormalTangentBinormal, Binormal));
		glEnableVertexAttribArray(static_cast<GLuint>(VertexAttribute::Binormal));
    }

	void NormalMappingEffect::CreateVertexBuffer(const Mesh& mesh, GLuint& vertexBuffer) const
	{
		const vector<vec3>& sourceVertices = mesh.Vertices();

		vector<VertexPositionTextureNormalTangentBinormal> vertices;
		vertices.reserve(sourceVertices.size());

		vector<vec3>* textureCoordinates = mesh.TextureCoordinates().at(0);
		assert(textureCoordinates->size() == sourceVertices.size());

		const vector<vec3>& normals = mesh.Normals();
		assert(normals.size() == sourceVertices.size());

		const vector<vec3>& tangents = mesh.Tangents();
		assert(tangents.size() == sourceVertices.size());

		const vector<vec3>& binormals = mesh.BiNormals();
		assert(binormals.size() == sourceVertices.size());

		for (size_t i = 0; i < sourceVertices.size(); i++)
		{
			const vec3& position = sourceVertices.at(i);
			const vec2& uv = static_cast<vec2>(textureCoordinates->at(i));
			const vec3& normal = normals.at(i);
			const vec3& tangent = tangents.at(i);
			const vec3& binormal = binormals.at(i);
			vertices.push_back(VertexPositionTextureNormalTangentBinormal(vec4(position.x, position.y, position.z, 1.0f), uv, normal, tangent, binormal));
		}

		CreateVertexBuffer(&vertices[0], vertices.size(), vertexBuffer);
	}

	void NormalMappingEffect::CreateVertexBuffer(VertexPositionTextureNormalTangentBinormal* vertices, uint32_t vertexCount, GLuint& vertexBuffer) const
	{
		glGenBuffers(1, &vertexBuffer);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
		glBufferData(GL_ARRAY_BUFFER, VertexSize() * vertexCount, &vertices[0], GL_STATIC_DRAW);
	}

    uint32_t NormalMappingEffect::VertexSize() const
    {
        return sizeof(VertexPositionTextureNormalTangentBinormal);
    }
}