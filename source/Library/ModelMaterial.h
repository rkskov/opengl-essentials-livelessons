#pragma once

#include <string>
#include <map>
#include <vector>

struct aiMaterial;

namespace Library
{
    enum class TextureType
    {
        Difffuse = 0,
        SpecularMap,
        Ambient,
        Emissive,
        Heightmap,
        NormalMap,
        SpecularPowerMap,
        DisplacementMap,
        LightMap,
        End
    };

    class ModelMaterial final
    {
        friend class Model;

    public:
        ModelMaterial(Model& model);
        ~ModelMaterial();

        Model& GetModel();
        const std::string& Name() const;
        const std::map<TextureType, std::vector<std::wstring>*>& Textures() const;

    private:		
        static void InitializeTextureTypeMappings();
        static std::map<TextureType, UINT> sTextureTypeMappings;

        ModelMaterial(Model& model, aiMaterial* material);
        ModelMaterial(const ModelMaterial& rhs);
        ModelMaterial& operator=(const ModelMaterial& rhs);

        Model& mModel;
        std::string mName;
        std::map<TextureType, std::vector<std::wstring>*> mTextures;		
    };
}