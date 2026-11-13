#include <iostream>
#include "TextGraphics.h"
#include "Shapes.h"

int main() {
    srand(time(0));  //seed RNG with current time
    char input = 0;
    TextGraphics graphics;

    std::vector<Shape*> v;

    unsigned long long frameCount = 0;

    while (input != ESCAPE)  //frame loop
    {
        ///input////////////////////////////////////////////////////////
        input = graphics.readKey();

        if(input == 'r') //restart
        {
            deleteVector(v);
        }

        if (input == 'c')
        {
            v.push_back(new Circle(rand() % 5 + 1, rand() % graphics.width(), rand() % graphics.height()));
        }

        if (input == 't')
        {
            v.push_back(new Rect(rand() % 6 + 1, rand() % 6 + 1, rand() % graphics.width(), rand() % graphics.height()));
        }

        if (input == 'x') {
            v.push_back(new Square(rand() % 4 + 1, rand() % graphics.width(), rand() % graphics.height()));
        }

        ///update///////////////////////////////////////////////////////

        for(Shape* p : v)
        {
            p->moveCenter(rand() % 3 - 1, 1);
        }

        ///Clear and draw////////////////////////////////////////////////

        graphics.clearScreen();  //Clear the previous frame


        std::string c = "Press c to draw a random circle";
        graphics.putStringAt(0, graphics.width() / 2 - c.size() / 2, "Press c to draw a random circle", Color::Yellow); 
        
        std::string t = "Press t to draw a random rectangle";
        graphics.putStringAt(1, graphics.width() / 2 - t.size() / 2, "Press t to draw a random rectangle", Color::Red);

        std::string x = "Press x to draw a random square";
        graphics.putStringAt(2, graphics.width() / 2 - x.size() / 2, "Press x to draw a random square", Color::Green);




        for(Shape* p : v)
        {
            p->draw(graphics);
        }

        graphics.draw();  //Display current frame on the screen

        ///sleep////////////////////////////////////////////////////////
        frameCount++;
        graphics.sleepMs(20);  //50 fps
    }

    return 0;
}
