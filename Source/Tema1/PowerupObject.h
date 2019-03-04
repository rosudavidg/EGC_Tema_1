#pragma once
#include "GameObject.h"

class PowerupObject : public GameObject
{
public:
	PowerupObject(float posx, float posy, float rotation, int type);
	~PowerupObject();

	float posx;
	float posy;
	float rotation;
	long startTime;
	int duration = 20; // seconds

	int type; // 1 - sticky bar
		      // 2 - bottom edge

	void foo() {
		//LifeObject
	}
};

