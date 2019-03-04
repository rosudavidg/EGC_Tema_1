#include "BarObject.h"

BarObject::BarObject(float posx, float posy, float width, float height, bool sticky)
{
	this->posx = posx;
	this->posy = posy;
	this->height = height;
	this->width = width;
	this->sticky = sticky;
}


BarObject::~BarObject()
{
}


