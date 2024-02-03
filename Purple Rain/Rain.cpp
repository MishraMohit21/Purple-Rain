#include "Rain.h"

void Rain::initVariable()
{
	this->windowSize = { 1000, 600 };
	this->speed = 1.0f;
	this->dropTimerMax = 10000;
	this->dropTimer = 10000;
	this->Maxdrop = 600;
	this->tick = 0;

}

void Rain::initwindow()
{
	this->window = new sf::RenderWindow(this->windowSize, "Purple Rain", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}

void Rain::pollEvent()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();

		case sf::Event::KeyPressed:
			if (ev.key.code == sf::Keyboard::Escape) {
				this->window->close();
				break;
			}

		default:
			break;
		}
	}
}

void Rain::spawnRain()
{
	this->drop.initDrop(this->windowSize);
	this->Rain_set.push_back(this->drop);
}

Rain::Rain()
{
	this->initVariable();
	this->initwindow();
}

Rain::~Rain()
{
	delete this->window;
}

const bool Rain::running() const
{
	return this->window->isOpen();
}

void Rain::Update()
{

	this->pollEvent();

	this->UpdateRain();

}

void Rain::UpdateRain()
{
	tick++;
	if (this->Rain_set.size() < this->Maxdrop)
	{
		if (this->dropTimer < 0)
		{
			this->spawnRain();
		}
		else
		{
			this->dropTimer -= 5;
		}
	}


	for (int i = 0; i < this->Rain_set.size(); i++)
	{
		this->Rain_set[i].setPosition(this->Rain_set[i].getPosition() + sf::Vector2f(0, this->speed));
		if (this->Rain_set[i].getPosition().y == this->windowSize.height)
		{
			this->Rain_set[i].initDrop(this->windowSize);
		}
	}
}

void Rain::Render()
{

	this->window->clear(sf::Color(230, 230, 250));

	this->RenderRain();

	this->window->display();
}

void Rain::RenderRain()
{
	for (auto& drip : this->Rain_set)
	{
		this->window->draw(drip);
	}
}
