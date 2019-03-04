#pragma once
#include "GameObject.h"

class EdgeObject : public GameObject
{
public:
	EdgeObject(float posx, float posy, float width, float height);
	~EdgeObject();

	float posx;
	float posy;
	float width;
	float height;
	

	void foo() {
		//EdgeObject
	}
};

