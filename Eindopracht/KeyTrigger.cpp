#include "KeyTrigger.h"

KeyTrigger::KeyTrigger(std::function<bool()> t, std::function<void()> a) : ProcessableObject() {
	trigger = t;
	action = a;
}

void KeyTrigger::handleInputs()
{
	if (trigger()) {
		action();
		destroyObject();
	}
}
