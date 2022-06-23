#include "Text2D.h"
#include "GameEngine.h"

sf::Font Text2D::font;
bool Text2D::fontLoaded = false;

Text2D::Text2D() : DrawableObject()
{
	loadFont();
}

Text2D::Text2D(sf::Color c) : DrawableObject(c)
{
	loadFont();
}

Text2D::Text2D(Vector2Custom pos) : DrawableObject(pos)
{
	loadFont();
}

Text2D::Text2D(Vector2Custom pos, sf::Color c) : DrawableObject(pos, c)
{
	loadFont();
}

Text2D::Text2D(Vector2Custom pos, std::string t, sf::Color c) : DrawableObject(pos, c)
{
	text = t;
	loadFont();
}

Text2D::Text2D(Vector2Custom pos, std::string t, int s, sf::Color c) : DrawableObject(pos, c)
{
	text = t;
	fontSize = s;
	loadFont();
}

void Text2D::process() {
	updateText();
	GameEngine::renderWindow.draw(textObject);
}

void Text2D::updateText()
{
	textObject.setFont(font);
	textObject.setString(text);
	textObject.setCharacterSize(fontSize);
	textObject.setFillColor(color);

	Vector2Custom globalPosition = getGlobalPosition();
	sf::FloatRect bounds = textObject.getLocalBounds();
	textObject.setPosition(sf::Vector2f(globalPosition.x- bounds.width/2, globalPosition.y));
}

void Text2D::loadFont() {
	if (fontLoaded) return;

	fontLoaded = true;
	font.loadFromFile("Roboto-Regular.ttf");
}