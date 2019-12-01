#include <cmath>
#include "vec3d.h"

//--------Constructors
//Contructor for vector class given (x, y, z)(null vector by default)
vec3d::vec3d(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

//Constructor to initialize a vector with a vector and magnitude (the new vector will share the direction of given vector)
vec3d::vec3d(vec3d vec, float mag)
{
	vec.normalize();
	if (mag == 0)
		throw "invalid vector";
	x = mag * vec.x;
	y = mag * vec.y;
	z = mag * vec.z;
}


//---------Basic arithmetic operations
//addition
vec3d vec3d :: operator+(const vec3d& vec) const
{
	return vec3d(x + vec.x, y + vec.y, z + vec.z);
}

//Subtraction
vec3d vec3d :: operator-(const vec3d& vec) const
{
	return vec3d(x - vec.x, y - vec.y, z - vec.z);
}

//--------Scalar operations
//Multiplication
vec3d vec3d :: operator*(float val) const
{
	return vec3d(x * val, y * val, z * val);
}

//Scalar division
vec3d vec3d :: operator/(float val) const
{
	return vec3d(x / val, y / val, z / val);
}

//--------Other operations
//to return magnitude of vector
float vec3d::mag() const
{
	return sqrt(x * x + y * y + z * z);
}

//to return unit vector in the direction of vector
vec3d vec3d::unit() const
{
	float m = mag();
	return vec3d(x / m, y / m, z / m);
}

//to normalize the vector
void vec3d::normalize()
{
	float m = mag();
	if (m == 0)
		throw "invalid vector";
	x = x / m;
	y = y / m;
	z = z / m;
}
