#pragma once
#include "Shape.h"
#include <iostream>
#include <fstream>

class Circle : public Shape {
private:
    int xCenter = 0;
    int yCenter = 0;
    int radius = 1;

public:
    Circle();

    Circle(int xCenter, int yCenter, int radius);

    int getXCenter() const;
    int getYCenter() const;
    int getRadius() const;

    void setXCenter(int xCenter);
    void setYCenter(int yCenter);
    void setRadius(int radius);

    void show() const override;

    void save() const override;

    void load() override;
};