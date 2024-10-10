#pragma once
#include "raylib.h"
#include "util/vector2d.hpp"

class Entity {
public:
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Destroy() = 0;

	virtual ~Entity() = default;

	Vector2D GetPosition() const { return position; };
	void SetPosition(Vector2 newPosition) { position.x = newPosition.x; position.y = newPosition.y; }

	Vector2D GetVelocity() const { return velocity; };
	void SetVelocity(Vector2D newVelocity) { velocity = newVelocity; };

protected:
	Vector2D position;
	Vector2D velocity;
};