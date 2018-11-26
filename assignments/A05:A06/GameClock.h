#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <chrono>
#include <string>
#include <vector>
#include <functional>
#include "Group.h"

using namespace std;
using namespace sf;

/**
 * Class GameClock:
 * Public:
 *    // Default constructor needs window width/height. 
 *    GameClock(int game_width, int game_height, int game_buffer = 0);
 * 
 *    // Overloaded constructor needs a lot!
 *    GameClock(int game_width, int game_height, int game_buffer, string font_name, 
 *              sf::Color clock_color, sf::Color clock_rect_color, int font_size, string pos, int clock_buffer);
 * 
 *    // Tells class where to print clock, expects a cardinal direction.
 *    void setClockPosition(string p = ""); 
 * 
 *    // Tells class where to print clock, expects a coordinate
 *    void setClockPosition(sf::Vector2f coord); 
 * Private:
 *    // Initializes a lot of things. Each constructor calls init for the common lines of code to run.
 *    void _init(); 
 * 
 *    // Public setClockPositionsd turn around and call this one. The string version calculates a coord based
 *    // cardinal directions, then calls this one. 
 *    void _setClockPosition(sf::Vector2f coord);
 */
class GameClock : public Group
{
  private:
    Vector2f dir;
    sf::Font font;       // clocks font
    int fontSize;        // size of font in pixels
    string position;     // N,NE,E,SE,S,SW,W,NW, C [N = top center, NE = top right, E = far right vertically centered, ..., C = centered ]
    sf::Text text;       // var to hold clock digits
    sf::Clock gameClock; // SFML clock type
    // sf::Time startTime;
    sf::Time elapsedTime;              // SFML time type
    sf::Color textColor;               // Color of clock text
    sf::Color backgroundColor;         // Color behind clock
    sf::Vector2f clockCoord;           // Locations to print clock
    sf::RectangleShape clockRectangle; // Rectangle representing clock back.
    int clockBuffer;                   // Padding around clock digits (size of rectangle)
    int gameBuffer;                    // Padding around game border (if any);
    int gameWidth;                     // Actual width of game window
    int gameHeight;
    Time start;
    Time stop;
    bool keepCounting;
    // Actual height of game window

    /**
 * Private: init
 *    Called from the constructors to reduce repeat code.
 * @Params: 
 *   p {string} : position where N,NE,E,SE,S,SW,W,NW, C [N = top center, NE = top right, E = far right vertically centered, ..., C = centered ]
 * @returns:
 *   void
*/
    void _init();

    /**
* sets position of clock
* @Params:
*   coord {sf::Vector2f} : x,y position
* @returns:
*   void
*/
    void _setClockPosition(sf::Vector2f coord);

  public:
    /*
* GetStop gets the stop time for a clock
* 
* @return {Time}: the time the clock should stop 
*/
    Time GetStop();

    /*
* getElapsed increments and decrements depending on the value given
* 
* @param {char} ud : u if the clock should increment (up)
* @return {Time} : the current time of the clock
*/
    Time getElapsed(char ud);

    /*
* SetRectFill will change the fill color of the rectange  
*
* @param {Color} F: New fill color
*/
    void SetRectFill(sf::Color C);

    /*
* SetTectOut sets the rectangle outline color
* 
* @param {Color} O : the new outline color
*/
    void SetRectOut(Color O);

    // not used
    // GameClock(int game_width, int game_height, int game_buffer = 0);

    /*
* GameClock constructor
* 
* @param {int, int, int, int, int} game_width, game_height, begin, end, game_buffer : window width, window height, time to begin at, time to end at, buffer
*/
    GameClock(int game_width, int game_height, int begin, int end, int game_buffer);

    /**
* GameClock constructor - 
*
* @Params:
* game_width {int}: width of actual game
* game_height {int}: height of actual game
* game_buffer {int}: buffer around outside of game to keep away from edge of window
* font_name {string}: name of font (or path and name)
* clock_color {sf::Color}: color of clock digits
* clock_rect_color {sf::Color}: color of clock background
* font_size {int}: size of clock font
* pos {string}: location of clock (N,NE,S,....,etc.)
* clock_buffer {int} : padding between digits and background rectangle edges
* begin {int} : time for clock to start at
* end {int} : time for clock to stop at
*/
    GameClock(int game_width, int game_height, int game_buffer, string font_name, sf::Color clock_color, sf::Color clock_rect_color, int font_size, string pos, int clock_buffer, int begin, int end);

    /**
* Public: setClockPosition
* An easy way to position your game clock. 
* @Params: 
* p {string} : position where N,NE,E,SE,S,SW,W,NW, C [N = top center, NE = top right, E = far right vertically centered, ..., C = centered ]
*/
    void setClockPosition(string p = "");

    /* 
* sets position of clock
* @param {Vector2f} coord : coordinates to place clock
*/
    void setClockPosition(sf::Vector2f coord);

    /*
* sets outline color of clock
*
* @param {Color} C : new outline color
*/
    void setOutline(sf::Color C);

    /*
* Moves the clock
*
* @param {Window} w: the window
*/
    void movePlace(Window &w);

    /*
* starts the clock
*/
    void startClock();

    /*
* gets text of clock and updates text
* @return {Text} : the time of the clock
*/
    Text getSeconds();

    /*
* gets the elapsed time
*/
    Time getEllapsedTime();

    /*
    * gets direction/speed of clock
    * @param{int, int} x,y : desired chnge is x and y when moved
    */
    void SetSpeed(int x, int y);

    /*
   * sets text color
   * * @param{Color} C: new text color
   */
    void SetFontColor(Color C);

    /*
    * sets text size
    * @param{int} size: new size
    */
    void SetFontSize(int size);

    /*
    * sets outline color of clock
    * @param{Color} C: new color
    */
    void SetOutline(Color C);

    /*
* tell clock to stop or continue counting
* @param{bool} c: true if continue
*/
    void SetCounting(bool c);

    /*
* is clock counting?
* @return{bool} : true if counting
*/
    bool CountCheck();
};