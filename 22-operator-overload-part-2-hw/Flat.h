#pragma once
#include <iostream>

class Flat {

private:
    std::string ownerName = "Undefined";
    int area = 0;
    int price = 0;
    int number = 0;

public:

    Flat();

    Flat(const std::string &ownerName, int area, int price, int number);

    const std::string& getOwnerName() const;
    int getArea() const;
    int getPrice() const;
    int getNumber() const;

    void setOwnerName(const std::string &ownerName);
    void setArea(int area);
    void setPrice(int price);
    void setNumber(int number);

    Flat& operator=(const Flat &other);

    friend bool operator==(const Flat &left, const Flat &right);
    friend bool operator>(const Flat &left, const Flat &right);

    friend std::ostream& operator<<(std::ostream& out, const Flat &flat);
};