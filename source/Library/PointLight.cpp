#include "PointLight.h"

using namespace glm;

namespace Library
{
	RTTI_DEFINITIONS(PointLight)

	const float PointLight::DefaultRadius = 10.0f;

	PointLight::PointLight(Game& game)
		: Light(game), mPosition(0), mRadius(DefaultRadius)
	{
	}

	PointLight::~PointLight()
	{
	}

	const vec3& PointLight::Position() const
	{
		return mPosition;
	}

	float PointLight::Radius() const
	{
		return mRadius;
	}

	void PointLight::SetPosition(FLOAT x, FLOAT y, FLOAT z)
    {
		mPosition = vec3(x, y, z);
    }

    void PointLight::SetPosition(const vec3& position)
    {
        mPosition = position;
    }

	void PointLight::SetRadius(float value)
	{
		mRadius = value;
	}
}