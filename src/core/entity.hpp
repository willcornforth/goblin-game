#pragma once
#include "raylib.h"

class Entity {
public:
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Destroy() = 0;

	virtual ~Entity() = default;

	Vector2 GetPosition() const { return position; };
	void SetPosition(Vector2 newPosition) { position.x = newPosition.x; position.y = newPosition.y; }

	float GetSpeed() const { return speed; };
	void SetSpeed(float newSpeed) { speed = newSpeed; };

protected:
	Vector2 position;
	float speed;
};