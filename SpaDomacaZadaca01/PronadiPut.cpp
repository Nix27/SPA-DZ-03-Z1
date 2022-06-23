#include "PronadiPut.h"
#include<ctime>

PronadiPut::PronadiPut(sf::RenderWindow* window)
{
	this->window = window;
}

void PronadiPut::KreirajMapu()
{
	srand(time(nullptr));
	pocetna.x = rnd_pozicija(0, 39);
	pocetna.y = rnd_pozicija(0, 59);
	ciljna.x = rnd_pozicija(0, 39);
	ciljna.y = rnd_pozicija(0, 59);

	for (unsigned i = 0; i < 40; i++)
	{
		for (unsigned j = 0; j < 60; j++)
		{
			polje.setSize(sf::Vector2f(20.f, 15.f));
			PostaviPocetnoStanje(i, j, polje);
			polje.setPosition(x, y);
			this->window->draw(polje);
			polja[i][j] = polje;
			x += 20;
		}
		
		y += 15;
		x = 0;
	}

	PronadiNajboljiPut();
}

int PronadiPut::rnd_pozicija(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

void PronadiPut::PostaviPocetnoStanje(int i, int j, sf::RectangleShape& polje)
{
	if ((i == pocetna.x && j == pocetna.y) || (i == ciljna.x && j == ciljna.y))
	{
		polje.setFillColor(sf::Color::Green);
	}
	else {
		polje.setFillColor(sf::Color::Black);
	}
}

void PronadiPut::PronadiNajboljiPut()
{
	int j = pocetna.y;
	int i = pocetna.x;

	if (j < ciljna.y)
	{
		while (j != ciljna.y)
		{
			polja[i][j].setFillColor(sf::Color::Red);
			j++;
		}
	}
	else {
		while (j != ciljna.y)
		{
			polja[i][j].setFillColor(sf::Color::Red);
			j--;
		}
	}

	if (i < ciljna.x)
	{
		while (i != ciljna.x)
		{
			polja[i][j].setFillColor(sf::Color::Red);
			i++;
		}
	}
	else {
		while (i != ciljna.x)
		{
			polja[i][j].setFillColor(sf::Color::Red);
			i--;
		}
	}

	polja[pocetna.x][pocetna.y].setFillColor(sf::Color::Green);
}

void PronadiPut::iscrtaj()
{
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 60; j++)
		{
			this->window->draw(polja[i][j]);
		}
	}
}
