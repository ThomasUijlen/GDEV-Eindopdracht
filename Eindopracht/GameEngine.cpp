#include "GameEngine.h"
#include <algorithm>
#include "Player.h"
#include "EnemySpawner.h"
#include "Text2D.h"
#include "LevelCounter.h"
#include <iostream>
#include <windows.h>
#include "KeyTrigger.h"

using namespace std;
using namespace sf;


vector<ProcessableObject*> GameEngine::processableObjects;
vector<CollisionBody*> GameEngine::collisionBodies;
RenderWindow GameEngine::renderWindow;
Object2D* GameEngine::currentScene;


void GameEngine::runGame() {
	renderWindow.create(VideoMode(1000, 1000), "Game");
	renderWindow.setFramerateLimit(60);

	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE);

	createScene(1);

	Event event;
	while (renderWindow.isOpen()) {
		while (renderWindow.pollEvent(event)) {
			switch (event.type)
			{
			case Event::Closed:
				renderWindow.close();
				break;
			case Event::KeyPressed:
				switch (event.key.code) {
				case Keyboard::Escape:
					renderWindow.close();
					break;
				}
			}
		}


		handleCollisions();
		processObjects();
	}
}

void GameEngine::addProcessableObject(ProcessableObject* object) {
	processableObjects.push_back(object);
}

void GameEngine::removeProcessableObject(ProcessableObject* object) {
	processableObjects.erase(remove(processableObjects.begin(), processableObjects.end(), object), processableObjects.end());
}

void GameEngine::addCollisionBody(CollisionBody* object) {
	collisionBodies.push_back(object);
}

void GameEngine::removeCollisionBody(CollisionBody* object) {
	collisionBodies.erase(remove(collisionBodies.begin(), collisionBodies.end(), object), collisionBodies.end());
}

void GameEngine::handleCollisions()
{
	for (CollisionBody* object : collisionBodies) {
		object->clearColliders();
	}

	for (CollisionBody* object1 : collisionBodies) {
		for (CollisionBody* object2 : collisionBodies) {
			if (object1 == object2) continue;

			object1->collisionCheck(object2);
		}
	}
}

void GameEngine::processObjects()
{
	renderWindow.clear();
	for (int i = 0; i < processableObjects.size(); i++) {
		ProcessableObject* object = processableObjects[i];
		object->handleInputs();
		object->process();
	}
	renderWindow.display();
}

void GameEngine::createScene(int number) {
	clearAllObjects();
	currentScene = new Object2D();

	switch (number)
	{
	case 1:
	{
		//Create game scene
		currentScene->addAsChild(new Player(Vector2Custom(500, 800), Vector2Custom(150, 50), 0.5f, sf::Color(0, 255, 0, 255)));
		currentScene->addAsChild(new EnemySpawner(Vector2Custom(), 120));
		currentScene->addAsChild(new LevelCounter());
		LevelCounter::resetCounter();
	}
		break;
	case 2:
	{
		//Create end screen
		currentScene->addAsChild(new Text2D(Vector2Custom(GameEngine::renderWindow.getSize().x / 2, GameEngine::renderWindow.getSize().y / 2.5), "Game Over!", 50, sf::Color(0, 255, 0, 255)));
		currentScene->addAsChild(new Text2D(Vector2Custom(GameEngine::renderWindow.getSize().x / 2, GameEngine::renderWindow.getSize().y / 2), "Score: " + to_string(LevelCounter::score), sf::Color(0, 255, 0, 255)));
		currentScene->addAsChild(new Text2D(Vector2Custom(GameEngine::renderWindow.getSize().x / 2, GameEngine::renderWindow.getSize().y / 1.8), "Press R to restart", sf::Color(0, 255, 0, 255)));

		//Set up a one-time trigger to reset the game
		new KeyTrigger(
			[] {return sf::Keyboard::isKeyPressed(sf::Keyboard::R); },
			[] {GameEngine::createScene(1); }
		);
	}
		break;
	}
}

GameEngine::~GameEngine()
{
	clearAllObjects();
}

void GameEngine::clearAllObjects() {
	while (processableObjects.size() > 0) {
		ProcessableObject* object = processableObjects.back();
		processableObjects.pop_back();
		if (object == nullptr) continue;
		object->destroyObject();
	}
}