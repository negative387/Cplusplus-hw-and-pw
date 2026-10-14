#pragma once
#include "Shape.h"
#include <iostream>
#include <fstream>

class Ellipse : public Shape {
private:
    int xTopLeftCorner = 0;
    int yTopLeftCorner = 0;
    int width = 2;
    int height = 2;

public:
    Ellipse();

    Ellipse(int xTopLeftCorner, int yTopLeftCorner, int width, int height);

    int getXTopLeftCorner() const;
    int getYTopLeftCorner() const;
    int getWidth() const;
    int getHeight() const;

    void setXTopLeftCorner(int xTopLeftCorner);
    void setYTopLeftCorner(int yTopLeftCorner);
    void setWidth(int width);
    void setHeight(int height);

    void show() const override;

    void save() const override;

    void load() override;
};