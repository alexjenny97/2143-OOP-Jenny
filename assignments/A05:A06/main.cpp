  /**
     *  Course: CMPS 2143 - OOP
     *  Program: A05/a06
     *
     *  Purpose: Create bouncing clock
     * 
     *  @author Alex Jenny
     *  @github repo: https://github.com/alexjenny97
     */

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Tile.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <chrono>
#include <string>
#include <vector>
#include <functional>
#include "Group.h"
#include "GameClock.cpp"

using namespace std;
using namespace sf;

#define WIDTH 500
#define HEIGHT 300
// #define CELLWIDTH 50.0  // used for minesweeper
// #define CELLHEIGHT 50.0  // used for ms
#define HEADER 60

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML Smiley!");

    // Tile smiley(128,128,"./smiley.png");
    // smiley.setPosition(sf::Vector2f(100.0, 100.0));
    // smiley.setSize(64,64);
    ///smiley.setOrigin(64.0,64.0);

    // crete clocks, set colors and speeds
    GameClock gangstaClock(WIDTH, HEIGHT, 20, 0, 0);
    gangstaClock.startClock();
    gangstaClock.SetRectFill(Color(2, 4, 66));
    gangstaClock.setOutline(Color(0, 90, 255));
    gangstaClock.SetFontColor(Color(255, 0, 0));

    GameClock tuPacClock(WIDTH, HEIGHT, 0, 29, 0);
    tuPacClock.setClockPosition();
    tuPacClock.SetRectFill(Color(80, 29, 4));
    tuPacClock.setOutline(Color(6, 200, 1));

    tuPacClock.SetSpeed(3, 3);
    tuPacClock.startClock();

    GameClock biggieClock(WIDTH, HEIGHT, 5, 35, 0);
    biggieClock.setClockPosition();
    biggieClock.SetRectFill(Color(99, 9, 22));
    biggieClock.setOutline(Color(35, 3, 6));

    biggieClock.SetSpeed(-2, 2);
    biggieClock.startClock();
    // end of creation

    int frameRate = 0; // clocks move very fast, fraameRte slows down
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        //     smiley.setTileTexture("./surprised.png");
        // }

        // if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        //     smiley.setTileTexture("./smiley.png");
        // }

        window.clear();
        // window.draw(smiley);

        // draw clocks
        window.draw(gangstaClock);
        window.draw(tuPacClock);
        window.draw(biggieClock);

        window.display();

        // only moves clocks 1:13 times
        if (frameRate % 13 == 0) // slow down clock!!!
        {
            if (gangstaClock.CountCheck() == true) // clocks should move and keep counting
            {
                gangstaClock.movePlace(window);
                gangstaClock.getSeconds(); // changes clock text
            }

            if (tuPacClock.CountCheck() == true)
            {
                tuPacClock.movePlace(window);
                tuPacClock.getSeconds();
            }

            if (biggieClock.CountCheck() == true)
            {
                biggieClock.movePlace(window);
                biggieClock.getSeconds();
            }
        }
        frameRate++;

        if (gangstaClock.GetStop() >= gangstaClock.getElapsed('d')) // gangstaClock is decrementing
        {
            gangstaClock.SetCounting(false);
        }
        if (tuPacClock.GetStop() <= tuPacClock.getElapsed('u')) //
        {
            tuPacClock.SetCounting(false);
        }
        if (biggieClock.GetStop() <= biggieClock.getElapsed('u')) //
        {
            biggieClock.SetCounting(false);
        }

        // when all clocks stop close window
        if (gangstaClock.CountCheck() == false && tuPacClock.CountCheck() == false && biggieClock.CountCheck() == false)
        {
            window.close();
        }
    }

    return 0;
}
