#pragma once
#include "ProcessableObject.h"
#include "Vector2Custom.h"
#include <vector>
#include <list>

class Object2D :
    public ProcessableObject
{
private:
    std::list<Object2D*> children;

public:
    Vector2Custom position;
    Object2D* parent;
    
    Object2D();
    Object2D(Vector2Custom pos);

    Vector2Custom getGlobalPosition();

    //Parenting
    void setAsParent(Object2D* p);
    void addAsChild(Object2D* c);
    void removeChild(Object2D* c);
    virtual void destroyObject();
};

