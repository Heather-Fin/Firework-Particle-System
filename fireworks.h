#pragma once

#include <vector>
#include "particle.h"

class fireworks
{
	vector<particle> particles;
	vec3d center;
	float life_span;
	float life_span_increment;

	float color_red;
	float color_green;
	float color_blue;

	int min_init_velocity;
	int max_init_velocity;
	int max_velocity;


public:

	fireworks();

	void draw();

	float get_life_span();

	~fireworks(void);
};

