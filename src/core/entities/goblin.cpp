#include "goblin.hpp"

void Goblin::Update()
{
	// Calculate direction of target actor, then get the unit vector of the
	// direction to give the acceleration vector the actor should use.
	if (target != nullptr) {
		Vector2D newAcceleration = (target->GetPosition() - position).Normalise();
		acceleration = newAcceleration;
	}

	Actor::Update();
}