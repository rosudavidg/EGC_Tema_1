#pragma once

#include <Component/SimpleScene.h>
#include <string>
#include <Core/Engine.h>
#include "GameObject.h"
#include "BarObject.h"
#include "BallObject.h"
#include "BrickObject.h"
#include "LifeObject.h"
#include "PowerupObject.h"


class Tema1 : public SimpleScene
{
public:
	Tema1();
	~Tema1();

	void Init() override;


private:
	void FrameStart() override;
	void Update(float deltaTimeSeconds) override;
	void FrameEnd() override;

	void OnInputUpdate(float deltaTime, int mods) override;
	void OnKeyPress(int key, int mods) override;
	void OnKeyRelease(int key, int mods) override;
	void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
	void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
	void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
	void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
	void OnWindowResize(int width, int height) override;

	void initGame();

	void clearLevel();

	void initLevel1();
	void initLevel2();
	void initLevel3();
	void initLevel4();
	void initLevel5();
	void initLevel6();
	void initLevel7();
	void initLevel8();
	void initLevel9();
	void initLevel10();


	void checkCollision(BallObject* ball);
	void checkBallOutside(BallObject* ball);
	void updateObjects();
	void checkLevelClear();
	void createMeshes();
	void renderEdges();
	void renderPowerups();
	void renderBar(BarObject* bar);
	void renderBall(BallObject* bar);
	void renderBrick(BrickObject* brick);
	void renderLife(LifeObject* life);
	void initNextLevel();

protected:
	glm::mat3 modelMatrix;
	glm::mat3 copyOfMatrix;
	std::vector<std::string> objectNames;
	std::vector<std::string> staticObjectNames;

	float mymouseX = 0;
	float mymouseY = 0;

	int lives;
	int numBalls;
	float ballSpeed;
	int currentLevel;

	time_t powerup1Time = 0;
	time_t powerup2Time = 0;

	std::vector<GameObject*> gameObjects;
	std::vector<PowerupObject*> powerupObjects;
};
