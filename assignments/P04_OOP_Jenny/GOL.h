/**
*  Course: CMPS 2143 - OOP
*
*  Purpose: Create and keep track of frame count
*
*  @author Alex Jenny
*  @version 1.1 01/03/17
*  @github repo: https://github.com/2143-OOP-Jenny
*/

#include <SFML/Graphics.hpp>
#include<string>

using namespace std;
using namespace sf;

/**
 *  game of life cell struct
 */
struct golCell
{
	bool isAlive;
	int neighborCount;

	/**
	 *  game of life cell constructor
	 */
	golCell();

	//SFML stuff
	RectangleShape Rect;
	int Width;
	int Height;
	void setCellPos(int x, int y);
};

/**
 *  Game of life class
 */
class gameOfLife
{
private:
	//int Cols	Number of cols in world
	int Cols;
	//int Rows	Number of rows in world
	int Rows;
	//int frameCount	Total times game loop did loop
	int frameCount;
	//int FrameRate	Allow user to slow down animation
	int frameRate;
	// 2D array of 0 or 1
	golCell** World;

/**
 *  applies rules to each cell, called by goNextGen
 *
 *  @param {golCell**, int, int} nextgen, row, col : the next matrix, rows, cols
 */
	void applyRules(golCell **&nextgen, int row, int col);

/**
 *  onWorld	determines if a cell is within the matrix, called by goNextGen
 *
 *  @param {int, int} row, col : rows, cols
 *  @return {bool} : On the world is true
 */
	bool onWorld(int row, int col);

	//SFML
	RenderWindow Window;

public:
/**
 *  GOL constructor
 */
	gameOfLife(int row, int col);

/**
*   initate world by creating gen0 from data
 *
 *  @param {string*} firstState: initial values for World
 */
	void initWorld(string *firstState);

/**
*   Prints world to game window
 */
	void printWorld();

/**
*   Prints world to outfile
 */
	void printWorld(ofstream &out);

/**
*  	Transitions from current to next generation
 */
	void goNextGen();

/**
*   Counts the neighbors for a given cell
 *
 *  @param {int, int} row, col : rows, cols
 */
	void countNeighbors(int row, int col);

	//SFML
	void drawWorld();
};

