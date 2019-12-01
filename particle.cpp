#include <Windows.h>
#include <gl/glut.h>

#include "particle.h"


particle::particle(vec3d center, int min_init_velocity, int max_init_velocity, int _max_velocity) {
	mass = rand() % (MAX_MASS - MIN_MASS) + MIN_MASS;
	velocity = vec3d(vec3d(1 - 2 * rand() / float(RAND_MAX), 1 - 2 * rand() / float(RAND_MAX), 1 - 2 * rand() / float(RAND_MAX)), rand() % (max_init_velocity - min_init_velocity) + min_init_velocity);
	position = vec3d((1 - 2 * rand() / float(RAND_MAX)) + center.x, (1 - 2 * rand() / float(RAND_MAX)) + center.y, 0);
	max_velocity = _max_velocity;
}

// advances the position of the particle
void particle::move(vec3d force)
{
	// acceleration
	vec3d acc = force / mass;

	// velocity
	velocity = velocity + acc * (DELTA / 1000.0);

	// cap velocity out at the max
	if (velocity.mag() >= max_velocity)
		velocity = vec3d(velocity.unit(), max_velocity);

	// changes position
	position = position + velocity * (DELTA / 1000.0);

}

// gets the current position
vec3d particle::get_pos()
{
	return position;
}

particle::~particle(void) {
}