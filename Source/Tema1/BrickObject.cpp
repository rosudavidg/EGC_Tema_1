#include "BrickObject.h"

BrickObject::BrickObject(float posx, float posy, float width, float height, float scaleSpeed, int lives)
{
	this->posx = posx;
	this->posy = posy;
	this->height = height;
	this->width = width;
	this->scaleSpeed = scaleSpeed;
	this->hit = false;
	this->scale = 1;
	this->lives = lives;
}


BrickObject::~BrickObject()
{
}


