#pragma once
#ifndef _WINDOW_H_
#define _WINDOW_H_
#include<iostream>
#include<math.h>
#include"SFML/Graphics.hpp"
#define row (17)
#define column (20)
class window {
private:
	sf::RenderWindow* Window;
	sf::Event* event;
	sf::Vector2f tileSize;
public:
    window()
    {
	Window = new sf::RenderWindow(sf::VideoMode(800, 800), "Astar");
	event = new sf::Event();
	//Window->setFramerateLimit(60);

	//initialization
	tileSize = { (float)Window->getView().getSize().x / column, (float)Window->getView().getSize().y / row };
    }
	~window() {
		Window->close();
	}
	void drawMap(int input_map[row][column])
	{
		for (int y = 0; y < row; y++)
		{
			for (int x = 0; x < column; x++)
			{
				sf::RectangleShape tile(tileSize);
				tile.setPosition(x * tileSize.x, y * tileSize.y);
				tile.setOutlineThickness(1.0f);
				tile.setOutlineColor(sf::Color::Black);

				//we need to check by [y][x] to draw correctly because of array structure
				if (input_map[y][x] == 1)
				{
					//if map[y][x] is blockade, make it black
					tile.setFillColor(sf::Color::Black);
					tile.setOutlineColor(sf::Color::White);
				}
				if (input_map[y][x] == 5)
				{
					tile.setFillColor(sf::Color::Green);
					tile.setOutlineColor(sf::Color::White);
				}
				if (input_map[y][x] == 6)
				{

					tile.setFillColor(sf::Color::Red);
					tile.setOutlineColor(sf::Color::White);
				}
				if (input_map[y][x] == 3)
				{

					tile.setFillColor(sf::Color::Yellow);
					tile.setOutlineColor(sf::Color::White);
				}
				if (input_map[y][x] == 7)
				{
					tile.setFillColor(sf::Color::Blue);
					tile.setOutlineColor(sf::Color::White);
				}

				Window->draw(tile);
			}
		}
	}
	sf::RenderWindow* getWindowHandle() { return Window; }
	sf::Event* getEventHandle() { return event; }

};
#endif //!_WINDOW_H_