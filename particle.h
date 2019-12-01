#pragma once

#include "vec3d.h"
#include "constants.h"


class particle
{
	float mass;
	vec3d velocity;
	vec3d position;
	int max_velocity;

public:
	particle(vec3d center, int min_init_velocity, int max_init_velocity, int _max_velocity);

	void move(vec3d = vec3d(0.0, 0.0, 0.0));

	vec3d get_pos();

	~particle(void);
};