#pragma once
#include "entity.hpp"
#include "../animations/actor_animation.hpp"

class Actor : public Entity {
public:
	Actor(Vector2D _position, SpriteSheet* spriteSheet) : Entity(_position) {
		anim = new ActorAnimation(spriteSheet);
	};
	~Actor() { Entity::~Entity(); };

	virtual void Update() override;
	virtual void Render() override;

	Vector2D GetAcceleration() const { return acceleration; };
	void SetAcceleration(Vector2D newAcceleration) { acceleration = newAcceleration; };

	float GetMaxSpeed() const { return maxSpeed; };
	void SetMaxSpeed(float newMaxSpeed) { maxSpeed = newMaxSpeed; };

	float GetAccelerationRate() const { return accelerationRate; };
	void SetAccelerationRate(float newAccelerationRate) { accelerationRate = newAccelerationRate; };

	float GetDecelerationRate() const { return decelerationRate; };
	void SetDecelerationRate(float newDecelerationRate) { decelerationRate = newDecelerationRate; };

protected:
	Vector2D acceleration = { 0.f, 0.f };

	float maxSpeed = 200.0f;
	float accelerationRate = 500.0f;
	float decelerationRate = 1000.0f;
};