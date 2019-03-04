#pragma once
#include "GameObject.h"

class BallObject : public GameObject
{
public:
	BallObject(float posx, float posy, float radius, float speed);
	~BallObject();

	float posx;
	float posy;
	float radius;
	
	bool moving;

	float speed;

	float speedx;
	float speedy;


	void foo() {
		//BallObject
	}
};

