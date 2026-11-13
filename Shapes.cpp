#include "Shapes.h"

Shape::Shape(double x, double y) :xCenter(x), yCenter(y) {}

void Shape::moveCenter(double dx, double dy) {
    xCenter += dx;
    yCenter += dy;
}

void Circle::draw(TextGraphics& tg) const {
    for (int i = 0; i < tg.height(); i++)
    {
        for (int j = 0; j < tg.width(); j++)
        {
            if (((j - xCenter) * (j - xCenter)) / (1.0 * radius * radius) + ((i - yCenter) * (i - yCenter)) / (1.0 * radius * radius) <= 1.0)
            {
                tg.putCharAt(i, j, '*', Color::Cyan);
            }
        }
    }
}

Circle::Circle(double r, double x, double y) :Shape(x, y), radius(r) {}

void Rect::draw(TextGraphics& tg) const {
    //To do:  draw me!
    //tg.putCharAt(yCenter, xCenter, '$', Color::Red);

    for (int j = 0; j < tg.width(); j++) {
        for (int i = 0; i < tg.height(); i++) {
            if (j <= xCenter + width / 2 && j >= xCenter - width / 2) {
                if (i <= yCenter + height / 2 && i >= yCenter - height / 2) {
                    tg.putCharAt(i, j , '&', Color::Yellow); 
                }
            }
        }
    }

}

Rect::Rect(double w, double h, double x, double y) : Shape(x, y), width(w), height(h) {   
}

Square::Square(double s, double x, double y) :Rect(s, s, x, y) {

}
Diamond::Diamond(FIXME, FIXME, FIXME) : FIXME(FIXME, FIXME, FIXME, FIXME) {




}

void deleteVector(vector<Shape*>& v) {
    for (auto p : v)
    {
        delete p;
    }
    v.clear();
}
