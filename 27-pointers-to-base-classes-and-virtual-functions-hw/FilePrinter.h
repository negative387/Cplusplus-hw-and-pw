#pragma once
#include <iostream>
#include <fstream>

class FilePrinter {

public:
    virtual void Display (const char *path) const;

    virtual ~FilePrinter();
};