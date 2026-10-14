#pragma once

class Shape {
public:
    virtual ~Shape();

    virtual void show() const = 0;
    virtual void save() const = 0;
    virtual void load() = 0;
};