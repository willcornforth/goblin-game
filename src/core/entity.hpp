#pragma once
#include "raylib.h"
#include "util/vector2d.hpp"
#include "animation.hpp"

enum EntityType : unsigned char {
	TypeEntity,
	TypeParticle
};

class Entity {
public:
	Entity(Vector2D _position) {
		position = _position;
		velocity = velocity;

		type = TypeEntity;
		isDestroyed = false;
		anim = nullptr;
	}

	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Destroy();

	virtual ~Entity() {
		delete anim;
	}

	Vector2D GetPosition() const { return position; };
	void SetPosition(Vector2D newPosition) { position.x = newPosition.x; position.y = newPosition.y; }

	Vector2D GetVelocity() const { return velocity; };
	void SetVelocity(Vector2D newVelocity) { velocity = newVelocity; };

	bool IsDestroyed() const { return isDestroyed; };

	EntityType GetType() const { return type; };

protected:
	Animation* anim;

	bool isDestroyed;
	EntityType type;

	Vector2D position;
	Vector2D velocity;
};