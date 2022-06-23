#pragma once
#include "ProcessableObject.h"
#include <functional>

class KeyTrigger :
    public ProcessableObject
{
private:
    std::function<bool()> trigger;
    std::function<void()> action;


public:
    KeyTrigger(std::function<bool()> t, std::function<void()> a);
    void handleInputs();
};

