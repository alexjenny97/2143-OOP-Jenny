/**
*  Course: CMPS 2143 - OOP
*
*  Purpose: Create and keep track of frame count
*
*  @author Alex Jenny
*  @version 1.1 01/03/17
*  @github repo: https://github.com/2143-OOP-Jenny
*/

//Methods
//Type	Method	Description
//Primary
//printWorld	Prints world to game window
//goNextGen	Transitions from current to next generation
//Helper
//countNeighbors	Counts the neighbors for a given cell
//onWorld	determines if a cell is within the matrix
//

// Member	Description
//int FrameCount	Total times game loop did loop
//int FrameRate	Allow user to slow down animation
//int Rows	Number of rows in world
//int Cols	Number of cols in world
//golCell** gameBoard	2D game world of golCells

#include "GOL.cpp"
#include <SFML/Graphics.hpp>

using namespace sf;



int main() {
	Clock tickToc;
	
	gameOfLife Gol(200, 200);

	while (Gol.Window.isOpen())
	{
		

		Time Now = tickToc.getElapsedTime();
		Gol.frameCount++; // update frame count
		Gol.frameRate = 10;
	
		Event event;
		while (!(Gol.frameCount % 95) && Gol.Window.pollEvent(event))
		{
			Gol.drawWorld();
			if (event.type == Event::Closed)
				Gol.Window.close();
		}


	}

	return 0;
}

