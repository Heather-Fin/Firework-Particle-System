#include "fireworks.h"
#include <GL/glut.h>
#include <math.h>
#include <random>

fireworks::fireworks() {

	// Random seed
	// Initialize Mersenne Twister pseudo-random number generator
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(-75, 75);
	center = vec3d(dis(gen), dis(gen), 0);

	// Create a random lifespan
	uniform_int_distribution<> randy_life(65, 85);
	life_span = 0.1;
	life_span_increment = float(randy_life(gen)) / 100000;

	// Pick random color for the firework
	uniform_int_distribution<> randy_color(0, 100);
	color_red = float(randy_color(gen)) / 100;
	color_green = float(randy_color(gen)) / 100;
	color_blue = float(randy_color(gen)) / 100;

	// Picks random min and max init velocities with only a range of 40
	// Allows the fireworks to be different sizes
	uniform_int_distribution<> randy_vel(60, 120);
	min_init_velocity = randy_vel(gen); // range 60-120
	max_init_velocity = min_init_velocity + 40; // range 100-160
	max_velocity = max_init_velocity + 40; // range 140 - 200

	// creates a particles vector
	for (int i = 0; i < NUMBER_OF_PARTICLES; i++)
	{
		particle temp(center, min_init_velocity, max_init_velocity, max_velocity);
		particles.push_back(temp);
	}
}


// moves the particles and then draws them
void fireworks::draw()
{
	life_span += life_span_increment;

	vector<particle>::iterator it;
	for (it = particles.begin(); it != particles.end(); it++)
	{
		// moves particle
		vec3d force = vec3d((center - it->get_pos()), FORCE_MAG);
		it->move(force);

		// get particle position after moving
		vec3d pos = it->get_pos();

		// set color for drawing the particle
		glColor4f(color_red, color_green, color_blue, 1);

		// draws particle
		glBegin(GL_POINTS);
		glVertex3f(pos.x, pos.y, pos.z);
		glEnd();
	}
}

// gets the current lifespan
float fireworks::get_life_span()
{
	return life_span;
}

fireworks::~fireworks(void)
{

}