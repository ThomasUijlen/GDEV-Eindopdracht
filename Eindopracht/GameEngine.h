#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "ProcessableObject.h"
#include "CollisionBody.h"

class GameEngine
{
private:
	static std::vector<ProcessableObject*> processableObjects;
	static std::vector<CollisionBody*> collisionBodies;

	void handleCollisions();
	void processObjects();

public:
	static sf::RenderWindow renderWindow;
	static Object2D* currentScene;

	~GameEngine();
	void runGame();
	static void createScene(int number);

	static void addProcessableObject(ProcessableObject* object);
	static void removeProcessableObject(ProcessableObject* object);
	static void addCollisionBody(CollisionBody* object);
	static void removeCollisionBody(CollisionBody* object);
	static void clearAllObjects();
};