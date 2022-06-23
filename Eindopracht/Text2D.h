#pragma once
#include "DrawableObject.h"
#include <string>

class Text2D :
    public DrawableObject
{
private:
    int fontSize = 30;
    sf::Text textObject;
    static sf::Font font;
    static bool fontLoaded;

    void loadFont();
    void updateText();

public:
    std::string text;

    Text2D();
    Text2D(sf::Color c);
    Text2D(Vector2Custom pos);
    Text2D(Vector2Custom pos, sf::Color c);
    Text2D(Vector2Custom pos, std::string t, sf::Color c);
    Text2D(Vector2Custom pos, std::string t, int s, sf::Color c);
    void process();
};

