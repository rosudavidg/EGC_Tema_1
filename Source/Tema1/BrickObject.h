#pragma once
#include "GameObject.h"

class BrickObject : public GameObject
{
public:
	BrickObject(float posx, float posy, float width, float height, float scaleSpeed, int lives);
	~BrickObject();

	float posx;
	float posy;
	float width;
	float height;
	float scaleSpeed;
	float scale;
	bool hit;
	int lives;


	void foo() {
		//EdgeObject
	}
};

