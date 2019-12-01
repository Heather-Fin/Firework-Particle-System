#pragma once
#include <iostream>

using namespace std;


//class for 3 dimentional vectors
//make sure u add checks for null vector and other corner cases throw (char*) exceptions if required

class vec3d
{
public:
	//x,y,z components
	float x, y, z;

	//--------Constructors
	//Contructor for vector class given (x, y, z)(null vector by default)
	vec3d(float = 0, float = 0, float = 0);

	//Constructor to initialize a vector with a vector and magnitude (the new vector will share the direction of given vector)
	vec3d(vec3d, float);

	//---------Basic arithmetic operations
	//addition
	vec3d operator+(const vec3d&) const;

	//Subtraction
	vec3d operator-(const vec3d&) const;

	//--------Scalar operations
	//Multiplication
	vec3d operator*(float) const;

	//Scalar division
	vec3d operator/(float) const;

	//--------Other operations
	//to return magnitude of vector
	float mag() const;

	//to return unit vector in the direction of vector
	vec3d unit() const;

	//to normalize the vector
	void normalize();
};