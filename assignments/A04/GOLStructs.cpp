# Program creates functions for the Game Of Life (Conway) game

#include <SFML/Graphics.hpp>
using namespace sf;



struct golCell 
{
	bool isAlive;
	int neighborCount;
	RectangleShape Rect;
	int Width;
	int Height;

	golCell() {
		Width = 10;
		Height = 10;
		Rect.setSize(sf::Vector2f(Width, Height));
		Rect.setFillColor(Color::Green);
		Rect.setOutlineColor(Color::Black);
		Rect.setOutlineThickness(1);
	}

	void setCellPos(int x, int y) {
		Rect.setPosition(x*Width, y*Height);
	}

};

struct gameOfLife
{
	//int Cols	Number of cols in world
	int Cols;

	//int Rows	Number of rows in world
	int Rows;

	//int frameCount	Total times game loop did loop
	int frameCount;

	//int FrameRate	Allow user to slow down animation
	int frameRate;

	RenderWindow Window;
	golCell** World;

	// GOL constructor
	gameOfLife(int width, int height) {
		Cols = width;
		Rows = height;
		frameCount = 0;
		frameRate = 1;
		Window.create(VideoMode(Cols, Rows), "Game of Life");

		//golCell** gameBoard	2D game world of golCells
		World = new golCell*[height];

		for (int i = 0; i<height; i++) {
			World[i] = new golCell[width];
			for (int j = 0; j<width; j++) {
				World[i][j].setCellPos(i, j);
			}
		}
	}

	void drawWorld() 
	{
		if (frameCount % frameRate == 0)
		{
			Window.clear();
			for (int i = 0; i < Rows; i++) {
				for (int j = 0; j < Cols; j++) {
					Window.draw(World[i][j].Rect);
				}
			}
			Window.display();
		}
	}
};

