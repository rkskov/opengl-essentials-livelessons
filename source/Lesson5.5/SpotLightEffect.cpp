#include "pch.h"

using namespace glm;
using namespace std;
using namespace Library;

namespace Rendering
{
    RTTI_DEFINITIONS(SpotLightEffect)	

    SpotLightEffect::SpotLightEffect() :
		ShaderProgram(),
		SHADER_VARIABLE_INITIALIZATION(WorldViewProjection), SHADER_VARIABLE_INITIALIZATION(World),
		SHADER_VARIABLE_INITIALIZATION(AmbientColor), SHADER_VARIABLE_INITIALIZATION(LightColor),
		SHADER_VARIABLE_INITIALIZATION(LightPosition), SHADER_VARIABLE_INITIALIZATION(LightRadius),
		SHADER_VARIABLE_INITIALIZATION(CameraPosition), SHADER_VARIABLE_INITIALIZATION(LightLookAt),
		SHADER_VARIABLE_INITIALIZATION(SpecularColor), SHADER_VARIABLE_INITIALIZATION(SpecularPower),
		SHADER_VARIABLE_INITIALIZATION(SpotLightInnerAngle), SHADER_VARIABLE_INITIALIZATION(SpotLightOuterAngle)
    {
    }

    SHADER_VARIABLE_DEFINITION(SpotLightEffect, WorldViewProjection)
	SHADER_VARIABLE_DEFINITION(SpotLightEffect, World)
	SHADER_VARIABLE_DEFINITION(SpotLightEffect, AmbientColor)
	SHADER_VARIABLE_DEFINITION(SpotLightEffect, LightColor)
	SHADER_VARIABLE_DEFINITION(SpotLightEffect, LightPosition)
	SHADER_VARIABLE_DEFINITION(SpotLightEffect, LightRadius)
	SHADER_VARIABLE_DEFINITION(SpotLightEffect, LightLookAt)
	SHADER_VARIABLE_DEFINITION(SpotLightEffect, CameraPosition)
	SHADER_VARIABLE_DEFINITION(SpotLightEffect, SpecularColor)
	SHADER_VARIABLE_DEFINITION(SpotLightEffect, SpecularPower)
	SHADER_VARIABLE_DEFINITION(SpotLightEffect, SpotLightInnerAngle)
	SHADER_VARIABLE_DEFINITION(SpotLightEffect, SpotLightOuterAngle)

	void SpotLightEffect::Initialize(GLuint vertexArrayObject)
    {
        ShaderProgram::Initialize(vertexArrayObject);

        SHADER_VARIABLE_INSTANTIATE(WorldViewProjection)
		SHADER_VARIABLE_INSTANTIATE(World)
		SHADER_VARIABLE_INSTANTIATE(AmbientColor)
		SHADER_VARIABLE_INSTANTIATE(LightColor)
		SHADER_VARIABLE_INSTANTIATE(LightPosition)
		SHADER_VARIABLE_INSTANTIATE(LightRadius)
		SHADER_VARIABLE_INSTANTIATE(LightLookAt)
		SHADER_VARIABLE_INSTANTIATE(CameraPosition)
		SHADER_VARIABLE_INSTANTIATE(SpecularColor)
		SHADER_VARIABLE_INSTANTIATE(SpecularPower)
		SHADER_VARIABLE_INSTANTIATE(SpotLightInnerAngle)
		SHADER_VARIABLE_INSTANTIATE(SpotLightOuterAngle)

		glVertexAttribPointer(static_cast<GLuint>(VertexAttribute::Position), 4, GL_FLOAT, GL_FALSE, sizeof(VertexPositionTextureNormal), (void*)offsetof(VertexPositionTextureNormal, Position));
		glEnableVertexAttribArray(static_cast<GLuint>(VertexAttribute::Position));

		glVertexAttribPointer(static_cast<GLuint>(VertexAttribute::TextureCoordinate), 2, GL_FLOAT, GL_FALSE, sizeof(VertexPositionTextureNormal), (void*)offsetof(VertexPositionTextureNormal, TextureCoordinates));
		glEnableVertexAttribArray(static_cast<GLuint>(VertexAttribute::TextureCoordinate));

		glVertexAttribPointer(static_cast<GLuint>(VertexAttribute::Normal), 3, GL_FLOAT, GL_FALSE, sizeof(VertexPositionTextureNormal), (void*)offsetof(VertexPositionTextureNormal, Normal));
		glEnableVertexAttribArray(static_cast<GLuint>(VertexAttribute::Normal));
    }

	void SpotLightEffect::CreateVertexBuffer(const Mesh& mesh, GLuint& vertexBuffer) const
	{
		const vector<vec3>& sourceVertices = mesh.Vertices();

		vector<VertexPositionTextureNormal> vertices;
		vertices.reserve(sourceVertices.size());

		vector<vec3>* textureCoordinates = mesh.TextureCoordinates().at(0);
		assert(textureCoordinates->size() == sourceVertices.size());

		const vector<vec3>& normals = mesh.Normals();
		assert(normals.size() == sourceVertices.size());

		for (size_t i = 0; i < sourceVertices.size(); i++)
		{
			const vec3& position = sourceVertices.at(i);
			const vec2& uv = static_cast<vec2>(textureCoordinates->at(i));
			const vec3& normal = normals.at(i);
			vertices.push_back(VertexPositionTextureNormal(vec4(position.x, position.y, position.z, 1.0f), uv, normal));
		}

		CreateVertexBuffer(&vertices[0], vertices.size(), vertexBuffer);
	}

	void SpotLightEffect::CreateVertexBuffer(VertexPositionTextureNormal* vertices, uint32_t vertexCount, GLuint& vertexBuffer) const
	{
		glGenBuffers(1, &vertexBuffer);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
		glBufferData(GL_ARRAY_BUFFER, VertexSize() * vertexCount, &vertices[0], GL_STATIC_DRAW);
	}

    uint32_t SpotLightEffect::VertexSize() const
    {
        return sizeof(VertexPositionTextureNormal);
    }
}