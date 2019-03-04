#pragma once
#include "GameObject.h"

class BarObject : public GameObject
{
public:
	BarObject(float posx, float posy, float width, float height, bool sticky);
	~BarObject();

	float posx;
	float posy;
	float width;
	float height;
	bool sticky;


	void foo() {
		//EdgeObject
	}
};

