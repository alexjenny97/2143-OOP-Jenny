    /**
     *  Course: CMPS 2143 - OOP
     *  Program: A05/A06
     *
     *  Purpose: Make bouncing clock
     * 
     *  @author Alex Jenny
     *  @github repo: https://github.com/alexjenny97
     */

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <chrono>
#include <string>
#include <vector>
#include <functional>
#include "Group.h"
#include "GameClock.h"

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

// GetStop gets the stop time for a clock
Time GameClock::GetStop()
{
    return stop;
}

// getElapsed increments and decrements depending on the value given
Time GameClock::getElapsed(char ud)
{
    if (keepCounting)
    {
        if (ud == 'u')
        {
            return gameClock.getElapsedTime() + start;
        }
        else if (ud == 'd')
        {
            return start - gameClock.getElapsedTime();
        }
    }
}

// ChangeRect will change the fill color of the rectange and outline color
void GameClock::SetRectFill(sf::Color F)
{
    clockRectangle.setFillColor(F);
}

// SetTectOut sets the rectangle outline color
void GameClock::SetRectOut(Color O)
{
    clockRectangle.setOutlineColor(O);
}

// not used
// /*
// * GameClock constructor -
// * @Params:
// * game_width {int}: width of actual game
// * game_height {int}: height of actual game
// * game_buffer {int}: buffer around outside of game to keep away from edge of window
// */
// GameClock::GameClock(int game_width, int game_height, int game_buffer = 0)
// {
//     gameWidth = game_width;
//     gameHeight = game_height;
//     gameBuffer = game_buffer;

//     if (!font.loadFromFile("gothic.ttf"))
//     {
//         cout << "Error loading font 'arial.ttf'...";
//         exit(0);
//     }

//     textColor = sf::Color(0, 255, 0);
//     backgroundColor = sf::Color(0, 0, 255);
//     clockRectangle.setFillColor(sf::Color(0, 0, 255));
//     fontSize = 24;
//     position = "C";
//     clockBuffer = 10;
//     _init();

//     // Push shapes onto our "Group" vector so we can print them together.
// }

// GameClock constructor
GameClock::GameClock(int game_width, int game_height, int begin, int end, int game_buffer)
{
    gameWidth = game_width;
    gameHeight = game_height;
    gameBuffer = game_buffer;
    start = seconds(begin);
    stop = seconds(end);

    if (!font.loadFromFile("gothic.ttf"))
    {
        cout << "Error loading font 'arial.ttf'...";
        exit(0);
    }

    textColor = sf::Color(0, 255, 0);                  // green
    backgroundColor = sf::Color(255, 0, 0);            // red
    clockRectangle.setFillColor(sf::Color(0, 0, 255)); // blue
    fontSize = 24;
    position = "C"; // center
    clockBuffer = 10;

    _init();
}

// GameClock constructor -
GameClock::GameClock(int game_width, int game_height, int game_buffer, string font_name, sf::Color clock_color, sf::Color clock_rect_color, int font_size, string pos, int clock_buffer, int begin, int end)
{
    start = seconds(begin);
    stop = seconds(end);
    gameWidth = game_width;
    gameHeight = game_height;
    gameBuffer = game_buffer;

    if (!font.loadFromFile(font_name))
    {
        cout << "Error loading font 'arial.ttf'...";
        exit(0);
    }

    textColor = clock_color;
    backgroundColor = clock_rect_color;
    clockRectangle.setFillColor(backgroundColor);
    fontSize = font_size;
    position = pos;
    clockBuffer = clock_buffer;

    _init();
}

/**
* virtual = A virtual function a member function which is declared within base class and is re-defined (Overriden) by derived class.
* function draw:
* draw an SFML object to some window
*/
// void draw(sf::RenderTarget &target, sf::RenderStates states) const
// {
//   for (const auto &drawable : m_drawables)
//   {
//     target.draw(drawable, states);
//   }
// }

// An easy way to position your game clock.
void GameClock::setClockPosition(string p)
{
    sf::Vector2f coord; // var to hold calculated position

    // if p is empty, set p = to default value from class data member
    if (p == "")
    {
        p = position;
    }

    // Top Center
    if (p == "N")
    {
        coord.x = gameWidth / 2;
        coord.y = 0;
    }

    // Top Right
    else if (p == "NE")
    {
        coord.x = gameWidth;
        coord.y = 0;
    }

    // Right Middle
    else if (p == "E")
    {
        coord.x = gameWidth;
        coord.y = gameHeight / 2;
    }

    // Bottom Right
    else if (p == "SE")
    {
        coord.x = gameWidth;
        coord.y = gameHeight;
    }

    // Bottom Center
    else if (p == "S")
    {
        coord.x = gameWidth / 2;
        coord.y = gameHeight;
    }

    // Bottom Left
    else if (p == "SW")
    {
        coord.x = 0;
        coord.y = gameHeight;
    }

    // Left Middle
    else if (p == "W")
    {
        coord.x = 0;
        coord.y = gameHeight / 2;
    }

    // Top Left
    else if (p == "NW")
    {
        coord.x = 0;
        coord.y = 0;
    }

    // Center Middle
    else
    {
        coord.x = gameWidth / 2;
        coord.y = gameHeight / 2;
    }

    _setClockPosition(coord);
}

// sets position of clock
void GameClock::setClockPosition(sf::Vector2f coord)
{
    _setClockPosition(coord);
}

// sets outline color of clock
void GameClock::setOutline(sf::Color C)
{
    clockRectangle.setOutlineColor(C);
}

// Moves the clock
void GameClock::movePlace(Window &w)
{
    if (keepCounting)

    { //if clock is going off the side of the window change direction
        if (clockRectangle.getPosition().x + (.5 * clockRectangle.getSize().x) >= gameWidth || clockRectangle.getPosition().x - (.5 * clockRectangle.getSize().x) <= 0)
        {

            dir.x *= -1;
        }

        // if clock is going off top/bottom of window change direction
        if (clockRectangle.getPosition().y + (.9 * clockRectangle.getSize().y) >= gameHeight || clockRectangle.getPosition().y - (.9 * clockRectangle.getSize().y) <= 0)
        {

            dir.y *= -1;
        }

        // move rectangle and text
        clockRectangle.move(dir.x, dir.y);
        text.move(dir.x, dir.y);
    }
    else
    {
    }
}

// starts the clock
void GameClock::startClock()
{
    gameClock.restart();
}

// gets text of clock and updates text
Text GameClock::getSeconds()
{
    string time = "";
    int seconds;

    if (stop > start) // go up (increment)
    {
        seconds = gameClock.getElapsedTime().asSeconds() + start.asSeconds();
    }

    else // go down
    {
        seconds = start.asSeconds() - gameClock.getElapsedTime().asSeconds();
    }

    time = to_string(seconds);
    text.setString(time);
    return text;
}

// gets the elapsed time
Time GameClock::getEllapsedTime()
{
    return gameClock.getElapsedTime();
}

// Called from the constructors to reduce repeat code.
void GameClock::_init()
{
    // direction clock will move
    dir.x = 1;
    dir.y = 1;
    clockRectangle.setOutlineThickness(2);
    // select the font
    text.setFont(font); // font is a sf::Font

    // set the string to display
    text.setString("0");

    // set the character size
    text.setCharacterSize(fontSize); // in pixels, not points!

    // set the color
    text.setFillColor(textColor);

    // set the text style
    //text.setStyle(sf::Text::Bold | sf::Text::Underlined);

    text.setStyle(sf::Text::Bold);
    //text.setPosition(sf::Vector2f(WIDTH / 2.0f, HEIGHT / 2.0f));
    //clockRectangle.setFillColor(backgroundColor);

    setClockPosition();
    //backgroundColor = sf::Color(0,0,255);

    elapsedTime = sf::Time::Zero;
    keepCounting = true;

    push_back(clockRectangle);
    push_back(text);
}

/**
* Private: _setClockPosition
* After x,y is found for clock position, this method will make adjustments based on the "game buffer" and "clock buffer"
* @Params:
* coord {sf::Vector2f} : x,y position
*/
void GameClock::_setClockPosition(sf::Vector2f coord)
{
    float textWidth = text.getLocalBounds().width;
    float textHeight = text.getLocalBounds().height;

    coord.x += gameBuffer;
    coord.y += gameBuffer;

    sf::Vector2f origin(textWidth / 2.0f, textHeight / 2.0f);

    text.setOrigin(origin);
    text.setPosition(coord);

    sf::FloatRect textRect = text.getLocalBounds();
    // clockRectangle.setSize(sf::Vector2f(100, 100));
    clockRectangle.setSize(sf::Vector2f(5 * textWidth, 3 * textHeight));
    clockRectangle.setOrigin(sf::Vector2f(origin.x + textWidth + clockBuffer, origin.y - textHeight + clockBuffer));
    clockRectangle.setPosition(coord);
}

/*
    gets direction/speed of clock
    */
void GameClock::SetSpeed(int x, int y)
{
    dir.x = x;
    dir.y = y;
}

// set font color
void GameClock::SetFontColor(Color C)
{
    text.setFillColor(C);
}

// set text size
void GameClock::SetFontSize(int size)
{
    text.setCharacterSize(size);
}

 

// set outline color
void GameClock::SetOutline(Color C)
{
    clockRectangle.setOutlineColor(C);
}

// manually tell clock if it should count
void GameClock::SetCounting(bool c)
{
    keepCounting = c;
}

// is clock counting?
bool GameClock::CountCheck()
{
    return keepCounting;
}
