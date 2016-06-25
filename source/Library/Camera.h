#pragma once

#include "GameComponent.h"
#include "glm/glm.hpp"

namespace Library
{
	class Game;
	class GameTime;

	class Camera : public GameComponent
	{
		RTTI_DECLARATIONS(Camera, GameComponent)

	public:
		Camera(Game& game);
		Camera(Game& game, float fieldOfView, float aspectRatio, float nearPlaneDistance, float farPlaneDistance);
		Camera(const Camera&) = delete;
		Camera& operator=(const Camera&) = delete;
		Camera(Camera&&) = delete;
		Camera& operator=(Camera&&) = delete;
		virtual ~Camera() = default;

		const glm::vec3& Position() const;
		const glm::vec3& Direction() const;
		const glm::vec3& Up() const;
		const glm::vec3& Right() const;

		float AspectRatio() const;
		float FieldOfView() const;
		float NearPlaneDistance() const;
		float FarPlaneDistance() const;

		const glm::mat4& ViewMatrix() const;
		const glm::mat4& ProjectionMatrix() const;
		glm::mat4 ViewProjectionMatrix() const;

		virtual void SetPosition(float x, float y, float z);
		virtual void SetPosition(const glm::vec3& position);

		virtual void Reset();
		virtual void Initialize() override;
		virtual void Update(const GameTime& gameTime) override;
		virtual void UpdateViewMatrix();
		virtual void UpdateProjectionMatrix();
		virtual void ApplyRotation(const glm::mat4& transform);

		static const float DefaultFieldOfView;
		static const float DefaultNearPlaneDistance;
		static const float DefaultFarPlaneDistance;

	protected:
		float mFieldOfView;
		float mAspectRatio;
		float mNearPlaneDistance;
		float mFarPlaneDistance;

		glm::vec3 mPosition;
		glm::vec3 mDirection;
		glm::vec3 mUp;
		glm::vec3 mRight;

		glm::mat4 mViewMatrix;
		glm::mat4 mProjectionMatrix;
	};
}

