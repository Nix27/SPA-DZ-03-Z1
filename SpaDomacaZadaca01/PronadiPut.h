#pragma once
#include <SFML/Graphics.hpp>

struct Tocka
{
	int x = 0, y = 0;
};

class PronadiPut
{
private:
	sf::RenderWindow* window;
	sf::RectangleShape polje;
	float x = 0, y = 0;
	sf::RectangleShape polja[40][60];
	Tocka pocetna;
	Tocka ciljna;
	int rnd_pozicija(int min, int max);
	void PostaviPocetnoStanje(int i, int j, sf::RectangleShape& polje);
	void PronadiNajboljiPut();
public:
	PronadiPut(sf::RenderWindow* window);
	void KreirajMapu();
	void iscrtaj();
};

