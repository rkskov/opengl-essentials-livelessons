#include "pch.h"

namespace Library
{
    std::map<TextureType, UINT> ModelMaterial::sTextureTypeMappings;

    ModelMaterial::ModelMaterial(Model& model)
        : mModel(model), mTextures()
    {
        InitializeTextureTypeMappings();
    }

    ModelMaterial::ModelMaterial(Model& model, aiMaterial* material)
        : mModel(model), mTextures()
    {
        InitializeTextureTypeMappings();

        aiString name;
        material->Get(AI_MATKEY_NAME, name);
        mName = name.C_Str();

        for (TextureType textureType = static_cast<TextureType>(0); textureType < TextureType::End; textureType = static_cast<TextureType>((static_cast<int>(textureType) + 1)))
        {
            aiTextureType mappedTextureType = (aiTextureType)sTextureTypeMappings[textureType];

            UINT textureCount = material->GetTextureCount(mappedTextureType);
            if (textureCount > 0)
            {
                std::vector<std::wstring>* textures = new std::vector<std::wstring>();
                mTextures.insert(std::pair<TextureType, std::vector<std::wstring>*>(textureType, textures));

                textures->reserve(textureCount);
                for (UINT textureIndex = 0; textureIndex < textureCount; textureIndex++)
                {
                    aiString path;
                    if (material->GetTexture(mappedTextureType, textureIndex, &path) == AI_SUCCESS)
                    {
                        std::wstring wPath;
                        Utility::ToWideString(path.C_Str(), wPath);

                        textures->push_back(wPath);
                    }
                }
            }
        }
    }

    ModelMaterial::~ModelMaterial()
    {
        for (std::pair<TextureType, std::vector<std::wstring>*> textures : mTextures)
        {
            DeleteObject(textures.second);
        }
    }

    Model& ModelMaterial::GetModel()
    {
        return mModel;
    }

    const std::string& ModelMaterial::Name() const
    {
        return mName;
    }

    const std::map<TextureType, std::vector<std::wstring>*>& ModelMaterial::Textures() const
    {
        return mTextures;
    }

    void ModelMaterial::InitializeTextureTypeMappings()
    {
		if (sTextureTypeMappings.size() != static_cast<int>(TextureType::End))
        {
            sTextureTypeMappings[TextureType::Difffuse] = aiTextureType_DIFFUSE;
            sTextureTypeMappings[TextureType::SpecularMap] = aiTextureType_SPECULAR;
            sTextureTypeMappings[TextureType::Ambient] = aiTextureType_AMBIENT;
            sTextureTypeMappings[TextureType::Heightmap] = aiTextureType_HEIGHT;
            sTextureTypeMappings[TextureType::NormalMap] = aiTextureType_NORMALS;
            sTextureTypeMappings[TextureType::SpecularPowerMap] = aiTextureType_SHININESS;
            sTextureTypeMappings[TextureType::DisplacementMap] = aiTextureType_DISPLACEMENT;
            sTextureTypeMappings[TextureType::LightMap] = aiTextureType_LIGHTMAP;
        }
    }
}