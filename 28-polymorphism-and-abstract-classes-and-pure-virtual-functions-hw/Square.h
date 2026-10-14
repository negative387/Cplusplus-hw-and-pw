#pragma once
#include "Shape.h"
#include <iostream>
#include <fstream>

class Square : public Shape {
private:
    int xTopLeftCorner = 0;
    int yTopLeftCorner = 0;
    int sideLength = 1;

public:
    Square();

    Square(int xTopLeftCorner, int yTopLeftCorner, int sideLength);

    int getXTopLeftCorner() const;
    int getYTopLeftCorner() const;
    int getSideLength() const;

    void setXTopLeftCorner(int xTopLeftCorner);
    void setYTopLeftCorner(int yTopLeftCorner);
    void setSideLength(int sideLength);

    void show() const override;

    void save() const override;

    void load() override;
};