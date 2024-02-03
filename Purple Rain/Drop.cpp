
#include "Drop.h"

double Drop::mapValue(double value, double inputMin, double inputMax, double outputMin, double outputMax)
{
	return (value - inputMin) * (outputMax - outputMin) / (inputMax - inputMin) + outputMin;
}

void Drop::initDrop(sf::VideoMode vm)
{
	x = rand() % vm.width;
	y = 0; //rand() % vm.height;
	z = rand() % vm.width;

	scale = mapValue(z, 0, vm.width, 0.6f, 1.1f);

	this->setPosition(this->x, this->y);
	this->setFillColor(this->purple);
	this->setSize(sf::Vector2f(4.0f, 40.0f));
	this->setScale(scale, scale);
}
