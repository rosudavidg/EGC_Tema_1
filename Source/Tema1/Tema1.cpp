#include "Tema1.h"

#include <vector>
#include <iostream>

#include <Core/Engine.h>
#include "Transform2D.h"
#include "Objects2D.h"
#include "GameObject.h"
#include "BallObject.h"
#include "EdgeObject.h"
#include "BarObject.h"
#include "BrickObject.h"
#include "LifeObject.h"
#include "PowerupObject.h"
#include <time.h>

using namespace std;

Tema1::Tema1()
{
}

Tema1::~Tema1()
{
}

void Tema1::createMeshes() {
	// Creare bila
	Mesh* ball = Objects2D::CreateCircle("ball", glm::vec3(0, 0, 0), 10.0f, glm::vec3(1, 1, 1), true);
	AddMeshToList(ball);

	// Creare margine stanga
	Mesh* left_edge = Objects2D::CreateRectangle("left_edge", glm::vec3(0, 100, 0), 20, 620, glm::vec3(1, 0, 0), true);
	AddMeshToList(left_edge);

	// Creare margine dreapta
	Mesh* right_edge = Objects2D::CreateRectangle("right_edge", glm::vec3(1260, 100, 0), 20, 620, glm::vec3(1, 0, 0), true);
	AddMeshToList(right_edge);

	// Creare margine sus
	Mesh* top_edge = Objects2D::CreateRectangle("top_edge", glm::vec3(0, 700, 0), 1280, 20, glm::vec3(1, 0, 0), true);
	AddMeshToList(top_edge);

	// Creare margine jos
	Mesh* bottom_edge = Objects2D::CreateRectangle("bottom_edge", glm::vec3(0, 0, 0), 1280, 20, glm::vec3(1, 0, 0), true);
	AddMeshToList(bottom_edge);

	// Creare bara
	Mesh* bar = Objects2D::CreateRectangle("bar", glm::vec3(0, 0, 0), 200, 20, glm::vec3(0, 0.5, 0.5), true);
	AddMeshToList(bar);

	// Creare obstacole
	Mesh* brick = Objects2D::CreateRectangle("brick", glm::vec3(0, 0, 0), 80, 40, glm::vec3(0, 0.8, 0.5), true);
	AddMeshToList(brick);

	// Creare obiecte viata
	Mesh* life = Objects2D::CreateCircle("life", glm::vec3(0, 0, 0), 10.0f, glm::vec3(1, 1, 1), true);
	AddMeshToList(life);

	// Creare obiect powerups - galben - sticky bar
	Mesh* powerup_1 = Objects2D::CreateSquare("powerup_1", glm::vec3(0, 0, 0), 22, glm::vec3(1, 1, 0), true);
	AddMeshToList(powerup_1);

	// Creare obiect powerups - rosu - bottom edge
	Mesh* powerup_2 = Objects2D::CreateSquare("powerup_2", glm::vec3(0, 0, 0), 22, glm::vec3(1, 0, 0), true);
	AddMeshToList(powerup_2);

	// Creare obiect powerups - alb - 1 viata bonus
	Mesh* powerup_3 = Objects2D::CreateSquare("powerup_3", glm::vec3(0, 0, 0), 22, glm::vec3(1, 1, 1), true);
	AddMeshToList(powerup_3);
}

void Tema1::initGame() {
	lives = 2;
	numBalls = 1;
	gameObjects.clear();
	currentLevel = 0;
}

void Tema1::clearLevel() {
	gameObjects.clear();
}

void Tema1::initNextLevel() {
	currentLevel++;
	lives++;

	powerup1Time = 0;
	powerup2Time = 0;

	if (currentLevel <= 10) {
		std::cout << "Level " << currentLevel << endl;
	}

	if (currentLevel > 10) {
		std::cout << "FELICITARI!" << endl;
	}

	switch (currentLevel) {
		case 1: initLevel1(); break;
		case 2: initLevel2(); break;
		case 3: initLevel3(); break;
		case 4: initLevel4(); break;
		case 5: initLevel5(); break;
		case 6: initLevel6(); break;
		case 7: initLevel7(); break;
		case 8: initLevel8(); break;
		case 9: initLevel9(); break;
		case 10: initLevel10(); break;
		default: initGame(); initLevel1();
	}


}

void Tema1::initLevel1() {
	gameObjects.push_back(new BallObject(540, 60, 10, 5));
	
	gameObjects.push_back(new EdgeObject(0, 100, 20, 620));
	gameObjects.push_back(new EdgeObject(1260, 100, 20, 620));
	gameObjects.push_back(new EdgeObject(0, 700, 1280, 20));

	gameObjects.push_back(new BarObject(540, 20, 200, 20, false));

	gameObjects.push_back(new BrickObject(600, 340, 80, 40, 0.1, 1));

	for (int i = 0; i < lives - 1; i++) {
		gameObjects.push_back(new LifeObject(10 + 30 * i, 50, 10));
	}
}

void Tema1::initLevel2() {
	gameObjects.push_back(new BallObject(540, 60, 10, 5));

	gameObjects.push_back(new EdgeObject(0, 100, 20, 620));
	gameObjects.push_back(new EdgeObject(1260, 100, 20, 620));
	gameObjects.push_back(new EdgeObject(0, 700, 1280, 20));

	gameObjects.push_back(new BarObject(540, 20, 200, 20, false));

	for (int i = 2; i < 4; i++) {
		for (int j = 4; j < 6; j++) {
			gameObjects.push_back(new BrickObject(60 + 120 * j, 600 - 70 * i, 80, 40, 0.1, 1));
		}
	}

	for (int i = 0; i < lives - 1; i++) {
		gameObjects.push_back(new LifeObject(10 + 30 * i, 50, 10));
	}
}

void Tema1::initLevel3() {
	gameObjects.push_back(new BallObject(540, 60, 10, 5));

	gameObjects.push_back(new EdgeObject(0, 100, 20, 620));
	gameObjects.push_back(new EdgeObject(1260, 100, 20, 620));
	gameObjects.push_back(new EdgeObject(0, 700, 1280, 20));

	gameObjects.push_back(new BarObject(540, 20, 200, 20, false));

	for (int i = 1; i < 4; i++) {
		for (int j = 3; j < 7; j++) {
			gameObjects.push_back(new BrickObject(60 + 120 * j, 600 - 70 * i, 80, 40, 0.1, 1));
		}
	}

	for (int i = 0; i < lives - 1; i++) {
		gameObjects.push_back(new LifeObject(10 + 30 * i, 50, 10));
	}
}

void Tema1::initLevel4() {
	gameObjects.push_back(new BallObject(540, 60, 10, 10));

	gameObjects.push_back(new EdgeObject(0, 100, 20, 620));
	gameObjects.push_back(new EdgeObject(1260, 100, 20, 620));
	gameObjects.push_back(new EdgeObject(0, 700, 1280, 20));

	gameObjects.push_back(new BarObject(540, 20, 200, 20, false));

	gameObjects.push_back(new BrickObject(600, 340, 80, 40, 0.1, 2));

	for (int i = 0; i < lives - 1; i++) {
		gameObjects.push_back(new LifeObject(10 + 30 * i, 50, 10));
	}
}

void Tema1::initLevel5() {
	gameObjects.push_back(new BallObject(540, 60, 10, 10));

	gameObjects.push_back(new EdgeObject(0, 100, 20, 620));
	gameObjects.push_back(new EdgeObject(1260, 100, 20, 620));
	gameObjects.push_back(new EdgeObject(0, 700, 1280, 20));

	gameObjects.push_back(new BarObject(540, 20, 200, 20, false));

	for (int i = 2; i < 4; i++) {
		for (int j = 4; j < 6; j++) {
			gameObjects.push_back(new BrickObject(60 + 120 * j, 600 - 70 * i, 80, 40, 0.1, 2));
		}
	}

	for (int i = 0; i < lives - 1; i++) {
		gameObjects.push_back(new LifeObject(10 + 30 * i, 50, 10));
	}
}

void Tema1::initLevel6() {
	gameObjects.push_back(new BallObject(540, 60, 10, 10));

	gameObjects.push_back(new EdgeObject(0, 100, 20, 620));
	gameObjects.push_back(new EdgeObject(1260, 100, 20, 620));
	gameObjects.push_back(new EdgeObject(0, 700, 1280, 20));

	gameObjects.push_back(new BarObject(540, 20, 200, 20, false));

	for (int i = 1; i < 4; i++) {
		for (int j = 3; j < 7; j++) {
			gameObjects.push_back(new BrickObject(60 + 120 * j, 600 - 70 * i, 80, 40, 0.1, 2));
		}
	}

	for (int i = 0; i < lives - 1; i++) {
		gameObjects.push_back(new LifeObject(10 + 30 * i, 50, 10));
	}
}

void Tema1::initLevel7() {
	gameObjects.push_back(new BallObject(540, 60, 10, 10));

	gameObjects.push_back(new EdgeObject(0, 100, 20, 620));
	gameObjects.push_back(new EdgeObject(1260, 100, 20, 620));
	gameObjects.push_back(new EdgeObject(0, 700, 1280, 20));

	gameObjects.push_back(new BarObject(540, 20, 200, 20, false));

	for (int i = 0; i < 5; i++) {
		for (int j = 3; j < 7; j++) {
			gameObjects.push_back(new BrickObject(60 + 120 * j, 600 - 70 * i, 80, 40, 0.1, 2));
		}
	}

	for (int i = 0; i < lives - 1; i++) {
		gameObjects.push_back(new LifeObject(10 + 30 * i, 50, 10));
	}
}

void Tema1::initLevel8() {
	gameObjects.push_back(new BallObject(540, 60, 10, 10));

	gameObjects.push_back(new EdgeObject(0, 100, 20, 620));
	gameObjects.push_back(new EdgeObject(1260, 100, 20, 620));
	gameObjects.push_back(new EdgeObject(0, 700, 1280, 20));

	gameObjects.push_back(new BarObject(540, 20, 200, 20, false));

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			gameObjects.push_back(new BrickObject(60 + 120 * j, 600 - 70 * i, 80, 40, 0.1, 2));
		}
	}

	for (int i = 0; i < lives - 1; i++) {
		gameObjects.push_back(new LifeObject(10 + 30 * i, 50, 10));
	}
}

void Tema1::initLevel9() {
	gameObjects.push_back(new BallObject(540, 60, 10, 10));

	gameObjects.push_back(new EdgeObject(0, 100, 20, 620));
	gameObjects.push_back(new EdgeObject(1260, 100, 20, 620));
	gameObjects.push_back(new EdgeObject(0, 700, 1280, 20));

	gameObjects.push_back(new BarObject(540, 20, 200, 20, false));

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 10; j++) {
			gameObjects.push_back(new BrickObject(60 + 120 * j, 600 - 70 * i, 80, 40, 0.1, 2));
		}
	}

	for (int i = 0; i < lives - 1; i++) {
		gameObjects.push_back(new LifeObject(10 + 30 * i, 50, 10));
	}
}

void Tema1::initLevel10() {
	gameObjects.push_back(new BallObject(540, 60, 10, 15));

	gameObjects.push_back(new EdgeObject(0, 100, 20, 620));
	gameObjects.push_back(new EdgeObject(1260, 100, 20, 620));
	gameObjects.push_back(new EdgeObject(0, 700, 1280, 20));

	gameObjects.push_back(new BarObject(540, 20, 200, 20, false));

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 10; j++) {
			gameObjects.push_back(new BrickObject(60 + 120 * j, 600 - 70 * i, 80, 40, 0.1, 3));
		}
	}

	for (int i = 0; i < lives - 1; i++) {
		gameObjects.push_back(new LifeObject(10 + 30 * i, 50, 10));
	}
}

void Tema1::renderEdges() {
	modelMatrix = glm::mat3(1);
	RenderMesh2D(meshes["left_edge"], shaders["VertexColor"], modelMatrix);
	RenderMesh2D(meshes["right_edge"], shaders["VertexColor"], modelMatrix);
	RenderMesh2D(meshes["top_edge"], shaders["VertexColor"], modelMatrix);

	if (time(NULL) < powerup2Time) {
		RenderMesh2D(meshes["bottom_edge"], shaders["VertexColor"], modelMatrix);
	}

}

void Tema1::renderBar(BarObject* bar) {
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(bar->posx, bar->posy);
	RenderMesh2D(meshes["bar"], shaders["VertexColor"], modelMatrix);
}

void Tema1::renderBall(BallObject* ball) {
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(ball->posx, ball->posy);
	modelMatrix *= Transform2D::Scale(ball->radius / 10, ball->radius / 10);
	RenderMesh2D(meshes["ball"], shaders["VertexColor"], modelMatrix);
}

void Tema1::renderBrick(BrickObject* brick) {
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(brick->posx, brick->posy);
	modelMatrix *= Transform2D::Translate(brick->width / 2, brick->height / 2);
	modelMatrix *= Transform2D::Scale(brick->scale, brick->scale);
	modelMatrix *= Transform2D::Translate(-brick->width / 2, -brick->height / 2);
	RenderMesh2D(meshes["brick"], shaders["VertexColor"], modelMatrix);
}

void Tema1::renderLife(LifeObject* life) {
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(life->posx, life->posy);
	RenderMesh2D(meshes["life"], shaders["VertexColor"], modelMatrix);
}

void Tema1::Init()
{
	glm::ivec2 resolution = window->GetResolution();
	auto camera = GetSceneCamera();
	camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
	camera->SetPosition(glm::vec3(0, 0, 50));
	camera->SetRotation(glm::vec3(0, 0, 0));
	camera->Update();
	GetCameraInput()->SetActive(false);

	// Creare meshes
	createMeshes();
	initGame();
	initNextLevel();
}

void Tema1::FrameStart()
{
	// clears the color buffer (using the previously set color) and depth buffer
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::ivec2 resolution = window->GetResolution();
	// sets the screen area where to draw
	glViewport(0, 0, resolution.x, resolution.y);
}

void Tema1::checkCollision(BallObject* ball) {

	for (int i = 0; i < gameObjects.size(); i++) {
		GameObject* obj = gameObjects.at(i);

		// MINGE - PERETE
		if (EdgeObject* v = dynamic_cast<EdgeObject*>(obj)) {

			// atinge latura de jos
			if (ball->posx + ball->radius >= v->posx && ball->posx - ball->radius <= v->posx + v->width) {
				if (ball->posy + ball->radius - v->posy <= ball->speed && ball->posy + ball->radius - v->posy >= 0) {
					ball->speedy = -ball->speedy;
				}
			}

			// atinge latura din stanga
			if (ball->posy + ball->radius >= v->posy && ball->posy - ball->radius <= v->posy + v->height) {
				if ((ball->posx + ball->radius) - v->posx <= ball->speed && (ball->posx + ball->radius) - v->posx >= 0) {
					ball->speedx = -ball->speedx;
				}
			}

			// atinge latura din dreapta
			if (ball->posy + ball->radius >= v->posy && ball->posy - ball->radius <= v->posy + v->height) {
				if (v->posx + v->width - (ball->posx - ball->radius) <= ball->speed && v->posx + v->width - (ball->posx - ball->radius) >= 0) {
					ball->speedx = -ball->speedx;
				}
			}

			// atinge latura de sus
			if (ball->posx + ball->radius >= v->posx && ball->posx - ball->radius <= v->posx + v->width) {
				if (v->posy + v->height - (ball->posy - ball->radius) <= ball->speed && v->posy + v->height - (ball->posy - ball->radius) >= 0) {
					ball->speedy = -ball->speedy;
				}
			}
		}

		
		if (BarObject* v = dynamic_cast<BarObject*>(obj)) {
			
			// MINGE - BARA
			// atinge latura de sus
			if (ball->posx + ball->radius >= v->posx && ball->posx - ball->radius <= v->posx + v->width) {
				if (v->posy + v->height - (ball->posy - ball->radius) <= ball->speed && v->posy + v->height - (ball->posy - ball->radius) >= 0) {

					if (!v->sticky) {
						float dist = ((ball->posx - v->posx) - v->width / 2) / 100;
						if (dist > 1) {
							dist = 1;
						}
						if (dist < -1) {
							dist = -1;
						}
						float angle = acos(dist);

						ball->speedx = ball->speed * cos(angle);
						ball->speedy = ball->speed * sin(angle);
					}
					else {
						ball->speedx = 0;
						ball->speedy = ball->speed;
						ball->moving = false;
						ball->posy = 50 + ball->radius;
					}
				}
			}

			// POWERUP - BARA
			for (int j = 0; j < powerupObjects.size(); j++) {
				PowerupObject* p = powerupObjects.at(j);
				if (p->posx >= v->posx && p->posx <= v->posx + v->width) {
					if (v->posy + v->height - p->posy <= 5 && v->posy + v->height - p->posy>= 0) {
						
						if (p->type == 1) {
							powerup1Time = time(NULL) + p->duration;
							powerupObjects.erase(powerupObjects.begin() + j);
							v->sticky = true;
							j--;
						}
						else if (p->type == 2) {
							powerup2Time = time(NULL) + p->duration;
							powerupObjects.erase(powerupObjects.begin() + j);
							gameObjects.push_back(new EdgeObject(0, 0, 1280, 20));
						}
						else if (p->type == 3) {
							powerupObjects.erase(powerupObjects.begin() + j);
							lives++;
							gameObjects.push_back(new LifeObject(10 + 30 * (lives - 2), 50, 10));
						}

					}
				}
			}
		}

		// MINGE - CARAMIDA
		if (BrickObject* v = dynamic_cast<BrickObject*>(obj)) {
			if (v->lives != 0) {
				bool remove = false;

				// atinge latura de jos
				if (ball->posx + ball->radius >= v->posx && ball->posx - ball->radius <= v->posx + v->width) {
					if (ball->posy + ball->radius - v->posy <= ball->speed && ball->posy + ball->radius - v->posy >= 0) {
						ball->speedy = -ball->speedy;
						remove = true;
					}
				}

				// atinge latura din stanga
				if (ball->posy + ball->radius >= v->posy && ball->posy - ball->radius <= v->posy + v->height) {
					if ((ball->posx + ball->radius) - v->posx <= ball->speed && (ball->posx + ball->radius) - v->posx >= 0) {
						ball->speedx = -ball->speedx;
						remove = true;
					}
				}

				// atinge latura din dreapta
				if (ball->posy + ball->radius >= v->posy && ball->posy - ball->radius <= v->posy + v->height) {
					if (v->posx + v->width - (ball->posx - ball->radius) <= ball->speed && v->posx + v->width - (ball->posx - ball->radius) >= 0) {
						ball->speedx = -ball->speedx;
						remove = true;
					}
				}

				// atinge latura de sus
				if (ball->posx + ball->radius >= v->posx && ball->posx - ball->radius <= v->posx + v->width) {
					if (v->posy + v->height - (ball->posy - ball->radius) <= ball->speed && v->posy + v->height - (ball->posy - ball->radius) >= 0) {
						ball->speedy = -ball->speedy;
						remove = true;
					}
				}

				if (remove) {
					v->lives--;

					if (v->lives == 0) {
						int randomNumber = rand() % 100;

						if (randomNumber < 5) {
							powerupObjects.push_back(new PowerupObject(v->width / 2 + v->posx, v->height / 2 + v->posy, 0, 1));
						}
						else if (randomNumber < 10) {
							powerupObjects.push_back(new PowerupObject(v->width / 2 + v->posx, v->height / 2 + v->posy, 0, 2));
						}
						else if (randomNumber < 15) {
							powerupObjects.push_back(new PowerupObject(v->width / 2 + v->posx, v->height / 2 + v->posy, 0, 3));
						}
					}
				}
			}
		}
	}
}

void Tema1::checkBallOutside(BallObject* ball) {
	if (ball->posx > 1280 || ball->posx < 0 || ball->posy > 720 || ball->posy < 0) {
		ball->moving = false;
		ball->speedx = 0;
		ball->speedy = ball->speed;
		ball->posy = 50 + ball->radius;

		lives--;

		if (lives != 0) {
			for (int i = gameObjects.size() - 1; i >= 0; i--) {
				GameObject* obj = gameObjects.at(i);

				if (LifeObject* v = dynamic_cast<LifeObject*>(obj)) {
					gameObjects.erase(gameObjects.begin() + i);
					break;
				}
			}
		}
		else {
			initGame();
			initLevel1();
		}
	}
}

void Tema1::checkLevelClear() {
	bool goToNextLevel = true;
	for (int i = 0; i < gameObjects.size(); i++) {
		GameObject* obj = gameObjects.at(i);

		if (BrickObject* v = dynamic_cast<BrickObject*>(obj)) {
			goToNextLevel = false;
			break;
		}
	}

	if (goToNextLevel) {
		clearLevel();
		initNextLevel();
	}
}

void Tema1::renderPowerups() {
	for (int i = 0; i < powerupObjects.size(); i++) {
		PowerupObject* v = powerupObjects.at(i);

		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D::Translate(v->posx, v->posy);
		modelMatrix *= Transform2D::Translate(11, 11);
		modelMatrix *= Transform2D::Rotate(v->rotation);
		modelMatrix *= Transform2D::Translate(-11, -11);

		if (v->type == 1) {
			RenderMesh2D(meshes["powerup_1"], shaders["VertexColor"], modelMatrix);
		}
		else if (v->type == 2) {
			RenderMesh2D(meshes["powerup_2"], shaders["VertexColor"], modelMatrix);
		}
		else if (v->type == 3) {
			RenderMesh2D(meshes["powerup_3"], shaders["VertexColor"], modelMatrix);
		}
	}
}

void Tema1::updateObjects() {
	renderEdges();
	renderPowerups();

	for (int i = 0; i < gameObjects.size(); i++) {

		GameObject* obj = gameObjects.at(i);

		if (BarObject* v = dynamic_cast<BarObject*>(obj)) {
			v->posx = mymouseX - 100;
			renderBar(v);

			if (time(NULL) >= powerup1Time) {
				v->sticky = false;
			}
		}

		if (BallObject* v = dynamic_cast<BallObject*>(obj)) {
			if (!v->moving) {
				v->posx = mymouseX;
			}
			else {
				v->posx += v->speedx;
				v->posy += v->speedy;
			}

			renderBall(v);
		}

		if (BrickObject* v = dynamic_cast<BrickObject*>(obj)) {
			if (v->lives == 0) {
				v->scale -= v->scaleSpeed;
			}

			renderBrick(v);

			if (v->scale <= 0) {
				gameObjects.erase(gameObjects.begin() + i);
				i--;
			}
		}

		if (LifeObject* v = dynamic_cast<LifeObject*>(obj)) {
			renderLife(v);
		}

		if (EdgeObject* v = dynamic_cast<EdgeObject*>(obj)) {
			if (time(NULL) > powerup2Time) {
				if (v->posy == 0) {
					gameObjects.erase(gameObjects.begin() + i);
					i--;
				}
			}
		}
	}

	for (int i = 0; i < powerupObjects.size(); i++) {
		powerupObjects.at(i)->rotation += 0.1;
		powerupObjects.at(i)->posy -= 2;
	}
}

// resolution: 1280 x 720
// edge: 20 x 620
void Tema1::Update(float deltaTimeSeconds)
{
	BallObject *ball = nullptr;

	// Gasire bila
	for (int i = 0; i < gameObjects.size(); i++) {
		GameObject* obj = gameObjects.at(i);
		if (BallObject* v = dynamic_cast<BallObject*>(obj)) {
			ball = v;
		}
	}

	updateObjects();

	checkCollision(ball);

	checkBallOutside(ball);

	checkLevelClear();
}

void Tema1::FrameEnd()
{
}

void Tema1::OnInputUpdate(float deltaTime, int mods)
{
}

void Tema1::OnKeyPress(int key, int mods)
{
}

void Tema1::OnKeyRelease(int key, int mods)
{
}

void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
	mymouseX = mouseX;
}

void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
	for (int i = 0; i < gameObjects.size(); i++) {

		GameObject* obj = gameObjects.at(i);

		if (BallObject* v = dynamic_cast<BallObject*>(obj)) {
			v->moving = true;
		}
	}
}

void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
}

void Tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}

void Tema1::OnWindowResize(int width, int height)
{
}
