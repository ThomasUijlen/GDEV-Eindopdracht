#include "Object2D.h"
#include <iostream>

using namespace std;

Object2D::Object2D() : ProcessableObject()
{
	position = Vector2Custom();
}

Object2D::Object2D(Vector2Custom pos) : ProcessableObject()
{
	position = pos;
}

Vector2Custom Object2D::getGlobalPosition()
{
	if (parent != nullptr) {
		Vector2Custom parentPosition = parent->getGlobalPosition();
		return parentPosition + position;
	}
	else {
		return position;
	}
}

void Object2D::setAsParent(Object2D* p)
{
	parent = p;
	auto* self = this;
	p->addAsChild(self);
}

void Object2D::addAsChild(Object2D* c)
{
	children.push_back(c);
	auto* self = this;
	c->parent = self;
}

void Object2D::removeChild(Object2D* c)
{
	children.remove(c);
}

void Object2D::destroyObject()
{
	ProcessableObject::destroyObject();
	auto* self = this;
	if (parent != NULL) parent->removeChild(self);

	while(children.size() > 0) {
		Object2D* child = children.front();
		children.pop_front();
		if (child == nullptr) continue;
		child->destroyObject();
	}
}
