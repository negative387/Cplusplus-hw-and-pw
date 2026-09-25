#pragma once
#include <iostream>

class Overcoat {

private:
    std::string name = "Undefined";
    std::string type = "Undefined";
    std::string color = "Undefined";
    int price = 0;

public:

    Overcoat();

    Overcoat(const std::string &name, const std::string &type, const std::string &color, int price);

    const std::string& getName() const;
    const std::string& getType() const;
    const std::string& getColor() const;
    int getPrice() const;

    void setName(const std::string &name);
    void setType(const std::string &type);
    void setColor(const std::string &color);
    void setPrice(int price);

    Overcoat& operator=(const Overcoat &other);

    friend bool operator==(const Overcoat &left, const Overcoat &right);
    friend bool operator>(const Overcoat &left, const Overcoat &right);

    friend std::ostream& operator<<(std::ostream& out, const Overcoat &overcoat);
};