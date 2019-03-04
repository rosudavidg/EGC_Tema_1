#pragma once
#include "GameObject.h"

class LifeObject : public GameObject
{
public:
	LifeObject(float posx, float posy, float radius);
	~LifeObject();

	float posx;
	float posy;
	float radius;

	void foo() {
		//LifeObject
	}
};

