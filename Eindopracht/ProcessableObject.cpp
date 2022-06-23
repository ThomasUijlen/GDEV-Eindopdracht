#include<vector>
#include "ProcessableObject.h"
#include "GameEngine.h"
#include <iostream>

ProcessableObject::ProcessableObject()
{
	auto* self = this;
	GameEngine::addProcessableObject(self);
}

void ProcessableObject::process() {

}

void ProcessableObject::handleInputs()
{

}

void ProcessableObject::destroyObject()
{
	if (destroyed) return;
	destroyed = true;

	auto* self = this;
	GameEngine::removeProcessableObject(self);

	delete self;
}

