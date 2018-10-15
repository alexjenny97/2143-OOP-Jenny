/**
*  Course: CMPS 2143 - OOP
*
*  Purpose: game of life class
*
*  @author Alex Jenny
*  @version 1.1 01/03/17
*  @github repo: https://github.com/2143-OOP-Jenny
**/

#include <SFML/Graphics.hpp>
#include<string>
#include<iostream>
#include<fstream>
#include "GOL.h"

using namespace std;
using namespace sf;

// game of life cell constructor
golCell::golCell()
{
	Width = 10;
	Height = 10;
	isAlive = false;
	neighborCount = 0;

	//SFML stuff
	Rect.setSize(sf::Vector2f(Width, Height));
	Rect.setFillColor(Color::Black);
	Rect.setOutlineColor(Color::Blue);
	Rect.setOutlineThickness(1);
}

//SFML
void golCell::setCellPos(int x, int y)
{
	Rect.setPosition(x*Width, y*Height);
}

// GOL constructor
gameOfLife::gameOfLife(int row, int col)
{
	Cols = col;
	Rows = row;
	frameCount = 0;
	frameRate = 1;

	//SFML
	Window.create(VideoMode(200, 200), "Game of Life");

	//create array will all cells dead
	World = new golCell*[Rows];
	for (int i = 0; i < Rows; i++)
	{
		World[i] = new golCell[Cols];
		for (int j = 0; j < Cols; j++)
		{
			World[i][j].isAlive = false;
			World[i][j].neighborCount = 0;
		}
	}
} // end of constructor


// initate world by creating gen0 from data
void gameOfLife::initWorld(string *firstState)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (firstState[i][j] == '1') // then it is aliiivvve!!
			{
				World[i][j].isAlive = true;
			}
		}
	}
} // end of init world

// Prints world to game window
void gameOfLife::printWorld()
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << World[i][j].isAlive;
		}
		cout << endl;
	}
}

//Prints world to outfile
void gameOfLife::printWorld(ofstream &out)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			out << World[i][j].isAlive;
		}
		out << endl;
	}
}

//goNextGen	Transitions from current to next generation
void gameOfLife::goNextGen()
{
	// create new matrix
	golCell** temp;
	temp = new golCell*[Rows];

	// actually create temp matrix
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			//get num neighbors set for World
			countNeighbors(i, j);
		}
	}

	// set temp's values
	for (int i = 0; i < Rows; i++)
	{
		temp[i] = new golCell[Cols];
		for (int j = 0; j < Cols; j++)
		{
			temp[i][j].isAlive = World[i][j].isAlive;
			temp[i][j].neighborCount = World[i][j].neighborCount;
		}
	}

	// apply the rules to temp
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			// apply rules to box in new temp arry;
			applyRules(temp, i, j);
		}
	}

	// make temp the new world
	delete World;
	World = temp;
	temp = nullptr;

	// change color of alive cells
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			World[i][j].Rect.setFillColor(Color::Black);
		}
	}
}

// Counts the neighbors for a given cell
void gameOfLife::countNeighbors(int row, int col)
{
	int neighbors = 0;
	if (onWorld(row - 1, col - 1) && World[row - 1][col - 1].isAlive == true)
	{
		neighbors++;
	}

	if (onWorld(row - 1, col) && World[row - 1][col].isAlive == true)
	{
		neighbors++;
	}

	if (onWorld(row - 1, col + 1) && World[row - 1][col + 1].isAlive == true)
	{
		neighbors++;
	}

	if (onWorld(row, col - 1) && World[row][col - 1].isAlive == true)
	{
		neighbors++;
	}

	if (onWorld(row, col + 1) && World[row][col + 1].isAlive == true)
	{
		neighbors++;
	}

	if (onWorld(row + 1, col - 1) && World[row + 1][col - 1].isAlive == true)
	{
		neighbors++;
	}

	if (onWorld(row + 1, col) && World[row + 1][col].isAlive == true)
	{
		neighbors++;
	}

	if (onWorld(row + 1, col + 1) && World[row + 1][col + 1].isAlive == true)
	{
		neighbors++;
	}
	World[row][col].neighborCount = neighbors;
}

// rules of game of life
void gameOfLife::applyRules(golCell **&nextgen, int row, int col) // does nextgen need & since i want it to change?
{
	if (World[row][col].neighborCount < 2) // death by no firends
	{
		nextgen[row][col].isAlive = false;
	}

	else if (World[row][col].neighborCount == 2)
	{
		// do nothing
	}
	else if (World[row][col].neighborCount == 3) // if already alive it does nothing, if dead it comes to life
	{
		nextgen[row][col].isAlive = true;
	}

	else if (World[row][col].neighborCount > 3) // death for all, mwahahaha
	{
		nextgen[row][col].isAlive = false;
	}
}

// determines if a cell is within the matrix
bool gameOfLife::onWorld(int row, int col)
{
	if (row > Rows - 1 || col > Cols - 1 || row < 0 || col < 0)
		return false;
	else
	{
		return true;
	}
}

// SFML puts matrix on screen
void gameOfLife::drawWorld()
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