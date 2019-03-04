#include "BallObject.h"

BallObject::BallObject(float posx, float posy, float radius, float speed)
{
	this->posx = posx;
	this->posy = posy;
	this->radius = radius;
	this->moving = false;

	this->speed = speed;

	this->speedx = 0;
	this->speedy = speed;
}


BallObject::~BallObject()
{
}


