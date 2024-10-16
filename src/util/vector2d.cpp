#include "vector2d.hpp"

Vector2D Vector2D::operator/(const float val) {
	return Vector2D(x / val, y / val);
}
Vector2D Vector2D::operator*(float val)
{
	return Vector2D(x * val, y * val);
}
Vector2D Vector2D::operator-(Vector2D& other)
{
    if (this != &other) {
        this->x -= other.x;
        this->y -= other.y;
        return *this;
    }
}
Vector2D& Vector2D::operator=(Vector2D other)
{
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}

Vector2D& Vector2D::operator+=(Vector2D other)
{
    if (this != &other) {
        x += other.x;
        y += other.y;
    }
    return *this;
}
