#pragma once
#include "Drop.h"

class Rain
{

	sf::RenderWindow* window;
	sf::Event ev;
	sf::VideoMode windowSize;

	std::vector<Drop> Rain_set;
	Drop drop;
	float speed;
	unsigned Maxdrop;
	float dropTimerMax;
	float dropTimer;
	long long tick;

	void initVariable();
	void initwindow();
	void pollEvent();

	void spawnRain();

public:

	Rain();
	~Rain();

	const bool running() const;

	void Update();
	void UpdateRain();

	void Render();
	void RenderRain();
};

