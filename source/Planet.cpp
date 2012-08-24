/*
 * Copyright © 2012 Fabian Schuiki
 */

#include "Planet.h"
#include "PerlinElevation.h"


Planet::Planet() : radius(6.371e6)
{
	//Initialize some elevation provider.
	elevation = new PerlinElevation;
	
	//Initialize the root chunk which covers the entire planet.
	rootChunk.planet = this;
	rootChunk.p0 = -180;
	rootChunk.p1 = 180;
	rootChunk.t0 = -90;
	rootChunk.t1 = 90;
	rootChunk.init();
}

Planet::~Planet()
{
}

void Planet::updateDetail(Camera &camera)
{
	if ((camera_pos - camera.pos).length2() < 1e-6) return;
	camera_pos = camera.pos;
	
	rootChunk.updateDetail(camera);
}

void Planet::draw()
{
	/*for (int t = 0; t < 18; t++)
		for (int p = 0; p < 36; p++)
			chunks[p][t].draw();*/
	rootChunk.draw();
}