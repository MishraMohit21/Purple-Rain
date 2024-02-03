#include <iostream>
#include <ctime>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>



class Drop : public sf::RectangleShape
{
	float x, y, z;
	float width, height;
	float scale;

	sf::Color purple = { 138, 43, 226 };

	double mapValue(double value, double inputMin, double inputMax, double outputMin, double outputMax);

public:

	void initDrop(sf::VideoMode vm);
};
