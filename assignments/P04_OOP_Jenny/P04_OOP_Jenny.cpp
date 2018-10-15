/**
*  Course: CMPS 2143 - OOP
*
*  Purpose: Will rum game of life for a number of generations (given in command line)
*
*  @author Alex Jenny
*  @version 1.1 01/03/17
*  @github repo: https://github.com/2143-OOP-Jenny
*/


#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include <iostream>
#include "GOL.h"

using namespace sf;
using namespace std;



int main(int argC, char **argV )
//will have 1st param is the filename to be read in. 
// 2nd param is the number of generations to be run.
	// 3rd param is the filename to write your output to.

{
	// used for frame count
	Clock tickToc;

	int gens = atoi(argV[2]); // need num gens to be int

	// data comes from command line
	ifstream infile;
	ofstream outfile;
	infile.open(argV[1]); 
	outfile.open(argV[3]);
	outfile << "Alex Jenny \n2143 OOP \nProgram 4\n\n";

	int row;
	int col;
	infile >> row >> col; // these values do not need to be in the line array
	
	// create 2D matrix of numbers by creating 1D matrix of strings
	string *line = new string[row];

	// read in and store inputfile data
	for(int i = 0; i < row; i ++)
	{
		infile >> line[i];
	
	}

	// create GOL
	gameOfLife Gol(row, col);

	Gol.initWorld(line); // creates generation 0

	// print matrix since SFML is supa slow
	for (int i = 0; i < gens; i++)
	{
		Gol.goNextGen();
	}
	Gol.printWorld(outfile);
	
	// runs SFML
	//// while open and not to desired generation do stuff
	//int i = 0;
	//while (Gol.Window.isOpen())
	//{
	//	Time Now = tickToc.getElapsedTime();
	//	Gol.frameCount++; // update frame count
	//	Gol.frameRate = 10;

	//	Event event;
	//	while (!(Gol.frameCount % 95) && Gol.Window.pollEvent(event))
	//	{
	//		Gol.drawWorld();
	//		Gol.goNextGen();
	//		if (event.type == Event::Closed || i == 3)
	//			Gol.Window.close();
	//		i++;
	//	}


	//}


	system("pause");
	return 0;
}

