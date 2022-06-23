#pragma once
#include <SFML/Graphics.hpp>

class ProcessableObject
{
private:
	bool destroyed = false;
public:
	ProcessableObject();
	virtual void process();
	virtual void handleInputs();
	virtual void destroyObject();
};

